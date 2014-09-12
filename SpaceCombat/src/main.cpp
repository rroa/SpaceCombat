#include "Game.h"

#ifdef EMSCRIPTEN
    #include <emscripten.h>
#endif

// Game Window Size
//
const int WIDTH         = 1136;
const int HEIGHT        = 640;

int main(int argc, char** argv)
{    
    spacecombat::Game theGame( "Space Combat", WIDTH, HEIGHT );
#ifdef EMSCRIPTEN    
    //emscripten_set_main_loop( theGame.OnExecute(), 60, true );    
#else
    theGame.OnExecute();    
#endif
    return 0;
}
