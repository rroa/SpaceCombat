#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>

int main(int argc, char** argv)
{
    SDL_Surface *screen;

    // Slightly different SDL initialization
    //
    if ( SDL_Init(SDL_INIT_VIDEO) != 0 ) 
    {
        printf("Unable to initialize SDL: %s\n", SDL_GetError());
        return 1;
    }

    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );

    screen = SDL_SetVideoMode( 640, 480, 16, SDL_OPENGL );
    if ( !screen ) 
    {
        printf("Unable to set video mode: %s\n", SDL_GetError());
        return 1;
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);    
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glClearColor(1.0, 0.0, 0.0, 0.0);
    
    glColor3f(1.0, 0.0, 0.0);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glBegin(GL_QUADS);
        glVertex2f(-0.5, -0.5);
        glVertex2f(-0.5, 0.5);
        glVertex2f(0.5, 0.5);
        glVertex2f(0.5, -0.5);
    glEnd();
    glFlush();

    // Bringing the back buffer to the front
    //
    SDL_GL_SwapBuffers();

    // This will allow us to see the window
    //
    SDL_Delay(3000);

    // Quit SDL
    //
    SDL_Quit();

    return 0;
}
