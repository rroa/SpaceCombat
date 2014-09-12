#include "Game.h"

// Game Window Size
//
const int WIDTH         = 1136;
const int HEIGHT        = 640;

int main(int argc, char** argv)
{    
    spacecombat::Game theGame( "Space Combat", WIDTH, HEIGHT );
    return theGame.OnExecute( );
}
