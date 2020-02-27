#ifndef GL_UTILS_H
#define GL_UTILS_H

#include <iostream>

#include <signal.h>

#include "GL/glew.h"

#define ASSERT(x) if (!(x)) raise(SIGTRAP);
#define GLCall(x) CMU::GL::Log::ClearErrors();\
    x;\
    ASSERT(CMU::GL::Log::LogCall(#x, __FILE__, __LINE__));


namespace CMU
{
    namespace GL
    {
        namespace Log
        {
            inline void ClearErrors ()
            {
                while (glGetError() != GL_NO_ERROR);
            }


            inline bool LogCall (const char* function, const char* file, int line)
            {
                while (GLenum error = glGetError())
                {
                    std::cout << "<OpenGL Error> (" << error << ") : In function " 
                        << function << ", file " << file << " at line " << line << std::endl;
                    
                    return false;
                }

                return true;
            }
        } // namespace Log


    } // namespace GL
} // namespace CMU


#endif