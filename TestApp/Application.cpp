#include "GL/glew.h"

#include "Application.h"

#include <string>

#include "CMU/GL/GFX.h"
#include "CMU/GL/Log/Utils.h"

#include <math.h>

Application::Application(int w, int h, int x, int y, std::string title)
{
    m_CMUWindow = new CMU::Window::GLFW::Window(w, h, x, y, title);
}

Application::~Application()
{
    delete m_CMUWindow;
}

void Application::Loop()
{
    float vertices[] = {
        -0.5f,  0.5f, // Top-left
         0.5f,  0.5f, // Top-right
         0.5f, -0.5f, // Bottom-right
        -0.5f, -0.5f  // Bottom-left
    };

    unsigned int elements[] = {
        0, 1, 2,
        2, 3, 0
    };

    CMU::GL::GFX::VertexArray va;
    va.Bind();

    CMU::GL::GFX::VertexBuffer vb(vertices, 4 * 2 * sizeof(float));
    vb.Bind();

    CMU::GL::GFX::VertexBufferLayout layout;
    layout.Push(GL_FLOAT, 2, GL_FALSE);

    va.AddBuffer(vb, layout);

    CMU::GL::GFX::IndexBuffer ib(elements, 6);
    ib.Bind();

    CMU::GL::GFX::Shader shader("TestApp/Res/Shaders/Basic.shader");
    shader.Bind();
    shader.SetUniform4f("u_Color", 1.0, 1.0, 0.2, 1.0);

    // Main loop of the program

    unsigned int frameCount = 0;

    while (m_CMUWindow->IsRunning())
    {
        // Clearing

        GLCall(glClearColor(0.7, 0.7, 0.7, 1.0));
        GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));

        // Drawing

        shader.SetUniform4f("u_Color", sin((float)frameCount / 100), sin((float)frameCount / 200), sin((float)frameCount / 300), 1.0);

        glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, 0);

        m_CMUWindow->SwapBuffers();
        m_CMUWindow->PollEvents();

        frameCount++;
    }
}