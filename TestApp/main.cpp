#include "Application.h"

int main(int argc, char** argv)
{
    Application app(1280, 720, 2100, 100, "C++ Modular Utility Test");

    app.Loop();

    return 0;
}