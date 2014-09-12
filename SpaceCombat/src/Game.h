#pragma once

#ifndef _GAME_H_
#define _GAME_H_

// SDL
//
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>

// STL
//
#include <string>

//==============================================================================
namespace spacecombat
{
    class Game 
    {
        public:
            struct GameState
            {
                enum State
                {                
                    RUNNING = 1,
                    PAUSED  = 2,
                    QUIT    = 4
                };
            };

            /* =============================================================
            * CTOR
            * ============================================================= */

            Game                ( const std::string& title, const int& width, const int& height );

            /* =============================================================
            * PUBLIC FUNCTIONS
            * ============================================================= */

            // SDL
            //
            bool OnInit         ( );
            void OnEvent        ( SDL_Event* event );               
            void OnCleanup      ( );

            // App
            //      
            int  OnExecute      ( );
            void OnKeyDown      ( SDL_KeyboardEvent keyBoardEvent );
            void OnKeyUp        ( SDL_KeyboardEvent keyBoardEvent );
            void OnResize       ( int width, int height );
            void OnExit         ( );

            // Game heartbeat
            //
            void OnLoop         ( );
            void OnRender       ( );
        private:
            /* =============================================================
            * MEMBERS
            * ============================================================= */

            // GAME
            //
            std::string         m_title;
            int                 m_width;
            int                 m_height;
            bool                m_fullScreen;
            unsigned int        m_nUpdates;
            double              m_deltaTime;
            GameState::State    m_state;

            // RENDERING
            //
            SDL_Surface*        m_mainwindow;
    };
}

//==============================================================================

#endif