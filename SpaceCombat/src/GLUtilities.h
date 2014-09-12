#pragma once

#ifndef _GL_UTILITIES_H_
#define _GL_UTILITIES_H_

namespace spacecombat
{    
    void SetGLOrtho( int width, int height )
    {
        float halfWidth  = width * 0.5f;
        float halfHeight = height * 0.5f;

        glViewport( 0, 0, width, height );
        glMatrixMode( GL_PROJECTION );
        glLoadIdentity();
        glOrtho( -halfWidth, halfWidth, -halfHeight, halfHeight, -1, 1  );      
        glMatrixMode( GL_MODELVIEW );
    }
}

#endif