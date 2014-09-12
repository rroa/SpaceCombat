#include "Game.h"

#ifdef EMSCRIPTEN
    #include <emscripten.h>
#endif

// Game Window Size
//
const int WIDTH         = 1136;
const int HEIGHT        = 640;

void loop()
{
    spacecombat::Game theGame( "Space Combat", WIDTH, HEIGHT );
    theGame.OnExecute();
}

int main(int argc, char** argv)
{    
    
#ifdef EMSCRIPTEN    
    emscripten_set_main_loop( loop, 0, true );
#else
    loop();    
#endif
    return 0;
}
