#ifndef CMU_GLFW_WINDOW_H
#define CMU_GLFW_WINDOW_H

#include <string>

#include "GLFW/glfw3.h"

namespace CMU
{
    namespace Window
    {
        namespace GLFW
        {
            class Window
            {
            public:
                Window(int w, int h, int x, int y, std::string title);
                ~Window();

                bool IsRunning();

                void PollEvents();
                void SwapBuffers();

            private:
                bool InitGLFW();
                bool CreateGLFWWindow();
                bool InitGLEW();

            private:
                int m_Width, m_Height, m_X, m_Y;
                std::string m_Title;

                GLFWwindow* m_GLFWWindow;
            };
        } // namespace GLFW
        
    } // namespace Window
    
} // namespace CMU


#endif