#include "Game.h"
#include "GLUtilities.h"

#include <iostream>

namespace spacecombat
{
    Game::Game( const std::string& title, const int& width, const int& height )
        : m_title           ( title )        
        , m_width           ( width )
        , m_height          ( height )
        , m_fullScreen      ( false )
        , m_nUpdates        ( 0 )
        , m_deltaTime       ( 0.0 )
    {
        // Initializing the main window pointer
        //
        m_mainwindow = NULL;

        // Setting the game state
        //
        m_state = GameState::RUNNING;   
    }

    bool Game::OnInit( )
    {
        if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 ) 
        {            
            return false;
        }

        // Setting the windows title
        //
        SDL_WM_SetCaption( m_title.c_str(), "icon goes here." );

        // Setting GL attributes
        //
        SDL_GL_SetAttribute( SDL_GL_RED_SIZE,            8 );
        SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE,          8 );
        SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE,           8 );
        SDL_GL_SetAttribute( SDL_GL_ALPHA_SIZE,          8 );
        
        SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE,          16 );
        SDL_GL_SetAttribute( SDL_GL_BUFFER_SIZE,         32 );

        SDL_GL_SetAttribute( SDL_GL_ACCUM_RED_SIZE,      8 );
        SDL_GL_SetAttribute( SDL_GL_ACCUM_GREEN_SIZE,    8 );
        SDL_GL_SetAttribute( SDL_GL_ACCUM_BLUE_SIZE,     8 );
        SDL_GL_SetAttribute( SDL_GL_ACCUM_ALPHA_SIZE,    8 );

        /*
         * There's something about multi-sampling that my VM doesn't like
         * SDL_GL_SetAttribute( SDL_GL_MULTISAMPLEBUFFERS,  1 );
         * SDL_GL_SetAttribute( SDL_GL_MULTISAMPLESAMPLES,  2 );
         */        

        // Creating the drawing canvas and GL context at the same time
        // got to admit even though is a simple function call to the API
        // this feels very, very, very, very weird. Like 1990's weird.
        // http://www.libsdl.org/release/SDL-1.2.15/docs/html/sdlsetvideomode.html
        //

        /*
            SDL_HWSURFACE - Create the video surface in video memory
            SDL_GL_DOUBLEBUFFER - Enable hardware double buffering; only valid with SDL_HWSURFACE
            SDL_OPENGL - Create an OpenGL rendering context.
        */
        if(( m_mainwindow = SDL_SetVideoMode( m_width, m_height, 32, 
            SDL_HWSURFACE | SDL_GL_DOUBLEBUFFER | SDL_OPENGL)) == NULL) 
        {
            std::cout << "Unable to set video mode: " << SDL_GetError() << std::endl;

            return false;
        }

        // Setting GL Ortho
        // TODO: Maybe move this out?
        //
        SetGLOrtho( m_width, m_height );

        glEnable( GL_TEXTURE_2D );
        glEnable( GL_BLEND );

        glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );        

        return true;
    }

    void Game::OnEvent( SDL_Event* event )
    {       
        SDLEvent::OnEvent( event );
    }

    void Game::OnCleanup( )
    {
        SDL_FreeSurface( m_mainwindow );
        SDL_Quit( );
    }

    int Game::OnExecute( )
    {
        if( OnInit( ) == false ) 
        {
            std::cout << "SDL Init error!\n";
            return -1;
        }

        SDL_Event event;
        while( m_state == GameState::RUNNING ) 
        {
            if( SDL_PollEvent( &event ))
            {   
                // Clean exit if window is closed
                //
                if( event.type == SDL_QUIT ) 
                {
                    OnExit( );
                }

                // Handle the current event
                //
                OnEvent( &event );
            }            

            // Update
            //
            OnLoop( );

            // Draw
            //
            OnRender( );

            // TODO: Implement time handling
            //
            ++m_nUpdates;
        }

        OnCleanup( );

        return 0;    
    }

    void Game::OnKeyDown( SDL_KeyboardEvent keyBoardEvent )
    {}

    void Game::OnKeyUp( SDL_KeyboardEvent keyBoardEvent )
    {
        if( keyBoardEvent.keysym.sym == SDLK_ESCAPE )
        {            
            OnExit( );
        }
    }

    void Game::OnResize( int width, int height )
    {
        m_width     = width;
        m_height    = height;

        SetGLOrtho( m_width, m_height );
    }

    void Game::OnExit( )
    {
        m_state = GameState::QUIT;
    }

    void Game::OnLoop( )
    {}

    void Game::OnRender( )
    {
        // Clear buffer
        //
        glClearColor( 0.1f, 0.1f, 0.15f, 1.0f );
        glClear( GL_COLOR_BUFFER_BIT );

        glLoadIdentity( );

        glBegin( GL_QUADS);
            glColor3f( 1, 0, 0 ); glVertex3f( 0, 0, 0     );
            glColor3f( 1, 1, 0 ); glVertex3f( 100, 0, 0   );
            glColor3f( 1, 0, 1 ); glVertex3f( 100, 100, 0 );
            glColor3f( 1, 1, 1 ); glVertex3f( 0, 100, 0   );
        glEnd();

        // Bringing the back buffer to the front
        //
        SDL_GL_SwapBuffers();
    }
}