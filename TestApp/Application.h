#ifndef APPLICATION_H
#define APPLICATION_H

#include "CMU/Window/GLFW/Window.h"

class Application
{
public:
    Application(int w, int h, int x, int y, std::string title);
    ~Application();

    void Loop();

private:
    CMU::Window::GLFW::Window* m_CMUWindow;
};

#endif