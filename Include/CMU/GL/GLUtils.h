#ifndef GL_GLUTILS_H
#define GL_GLUTILS_H

#include "GL/glew.h"

namespace CMU
{
    namespace GL
    {
        inline unsigned int GetSizeOfType(unsigned int type)
        {
            switch (type)
            {
                case(GL_BYTE)           : return 1;
                case(GL_UNSIGNED_BYTE)  : return 1;
                case(GL_SHORT)          : return 2;
                case(GL_UNSIGNED_SHORT) : return 2;
                case(GL_INT)            : return 4;
                case(GL_UNSIGNED_INT)   : return 4;
                case(GL_FIXED)          : return 4;
                case(GL_HALF_FLOAT)     : return 2;
                case(GL_FLOAT)          : return 4;
                case(GL_2_BYTES)        : return 2;
                case(GL_3_BYTES)        : return 3;
                case(GL_4_BYTES)        : return 4;
                case(GL_DOUBLE)         : return 8;
                default: return 4;
            }
        }
    } // namespace GL
} // namespace CMU

#endif