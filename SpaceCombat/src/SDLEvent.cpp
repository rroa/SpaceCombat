#include "SDLEvent.h"

namespace spacecombat
{
    SDLEvent::SDLEvent()
    {}

    SDLEvent::~SDLEvent()
    {}

    void SDLEvent::OnEvent( SDL_Event* event ) 
    {        
        switch(event->type) 
        {
            case SDL_ACTIVEEVENT:
                HandleWindowEvents( event );
                break;            

            case SDL_KEYDOWN:            
                OnKeyDown( event->key );
                break;            

            case SDL_KEYUP:
                OnKeyUp( event->key );                
                break;            

            case SDL_MOUSEMOTION:
                OnMouseMove( event->motion.x,
                             event->motion.y,
                             event->motion.xrel,
                             event->motion.yrel,
                             ( event->motion.state & SDL_BUTTON( SDL_BUTTON_LEFT   )) != 0,   // Left button clicked
                             ( event->motion.state & SDL_BUTTON( SDL_BUTTON_RIGHT  )) != 0,   // Right button clicked
                             ( event->motion.state & SDL_BUTTON( SDL_BUTTON_MIDDLE )) != 0 ); // Middle button clicked
                break;            

            case SDL_MOUSEBUTTONDOWN:
                HandleMouseButtonDownEvents( event );
                break;

            case SDL_MOUSEBUTTONUP:
                HandleMouseButtonUpEvents( event );
                break;            
#ifdef EMSCRIPTEN
            case SDL_FINGERMOTION:
                OnFingerMotion( event );
                break;

            case SDL_FINGERDOWN:
                OnFingerDown( event );
                break;

            case SDL_FINGERUP:
                OnFingerUp( event );
                break;
#endif
            case SDL_QUIT: {
                OnExit();
                break;
            }

            case SDL_SYSWMEVENT: {
                //Ignore
                break;
            }

            case SDL_VIDEORESIZE: {
                OnResize(event->resize.w,event->resize.h);
                break;
            }

            case SDL_VIDEOEXPOSE: {
                OnExpose();
                break;
            }

            default: {
                OnUser(event->user.type,event->user.code,event->user.data1,event->user.data2);
                break;
            }
        }    
    }

    void SDLEvent::HandleWindowEvents( SDL_Event* event )
    {       
        switch( event->active.state ) 
        {
            case SDL_APPMOUSEFOCUS:
                if( event->active.gain )
                {
                    OnMouseFocus();
                }
                else
                {
                    OnMouseBlur();
                }
                break;

            case SDL_APPINPUTFOCUS:
                if( event->active.gain )
                {
                    OnInputFocus();
                }
                else
                {
                    OnInputBlur();
                }
                break;                
            case SDL_APPACTIVE:             
                if ( event->active.gain )
                {
                    OnRestore();
                }
                else
                {
                    OnMinimize();
                }
                break;                 
        }   
    }

    void SDLEvent::HandleMouseButtonDownEvents( SDL_Event* event )
    {        
        switch( event->button.button ) 
        {
            case SDL_BUTTON_LEFT:
                OnLButtonDown(event->button.x,event->button.y);
                break;

            case SDL_BUTTON_RIGHT:
                OnRButtonDown(event->button.x,event->button.y);
                break;
            
            case SDL_BUTTON_MIDDLE:
                OnMButtonDown(event->button.x,event->button.y);
                break;            
        }
    }

    void SDLEvent::HandleMouseButtonUpEvents( SDL_Event* event )
    {
        switch( event->button.button )
        {
            case SDL_BUTTON_LEFT:
                OnLButtonUp(event->button.x,event->button.y);
                break;
            
            case SDL_BUTTON_RIGHT:
                OnRButtonUp(event->button.x,event->button.y);
                break;
            
            case SDL_BUTTON_MIDDLE:
                OnMButtonUp(event->button.x,event->button.y);
                break;            
        }
    }
}