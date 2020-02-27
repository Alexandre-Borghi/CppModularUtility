#include <iostream>
#include <string>

#define GLEW_STATIC
#include "GL/glew.h"
#include "GL/gl.h"

#include "GLFW/glfw3.h"

#include "CMU/Window/GLFW/Window.h"

namespace CMU
{
    namespace Window
    {
        namespace GLFW
        {
            Window::Window(int w, int h, int x, int y, std::string title)
                : m_Width(w), m_Height(h), m_X(x), m_Y(y), m_Title(title)
            {
                if (!InitGLFW()) return;
                if (!CreateGLFWWindow()) return;
                if (!InitGLEW()) return;
            }

            Window::~Window()
            {
                glfwTerminate();
            }

            bool Window::IsRunning()
            {
                return !glfwWindowShouldClose(m_GLFWWindow);
            }

            void Window::PollEvents()
            {
                glfwPollEvents();
            }

            void Window::SwapBuffers()
            {
                glfwSwapBuffers(m_GLFWWindow);
            }

            // Private functions

            bool Window::InitGLFW()
            {
                if (!glfwInit())
                {
                    // TODO: Add better logging when Log module is ready

                    std::cout << "[ERROR] | [CMU:Window:GLFW:Window] | Failed to initialize GLFW" << std::endl;

                    return false;
                }

                std::cout << "[INFO] | [CMU:Window:GLFW:Window] | GLFW initialized successfully" << std::endl;
                
                return true;
            }

            bool Window::CreateGLFWWindow()
            {
                m_GLFWWindow = glfwCreateWindow(m_Width, m_Height, m_Title.c_str(), nullptr, nullptr);

                if (!m_GLFWWindow)
                {
                    // TODO: Add better logging when Log module is ready

                    std::cout << "[ERROR] | [CMU:Window:GLFW:Window] | Failed to create GLFW window" << std::endl;

                    glfwTerminate();

                    return false;
                }
                else
                {
                    // TODO: Add better logging when Log module is ready

                    std::cout << "[INFO] | [CMU:Window:GLFW:Window] | GLFW window created successfully" << std::endl;

                    return true;
                }
            }

            bool Window::InitGLEW()
            {
                glfwMakeContextCurrent(m_GLFWWindow);

                std::cout << "[INFO] | [CMU:Window:GLFW:Window] | OpenGL context set" << std::endl;

                glewExperimental = GL_TRUE;
                if (glewInit() != GLEW_OK)
                {
                    // TODO: Add better logging when Log module is ready

                    std::cout << "[ERROR] | [CMU:Window:GLFW:Window] | Failed to initialize GLEW" << std::endl;

                    return false;
                }

                std::cout << "[INFO] | [CMU:Window:GLFW:Window] | GLEW initialized successfully" << std::endl;
            }
        } // namespace GLFW
        
    } // namespace Window
    
} // namespace CMU
