// Dear ImGui: standalone example application for GLFW + OpenGL 3, using programmable pipeline
// (GLFW is a cross-platform general purpose library for handling windows, inputs, OpenGL/Vulkan/Metal graphics context creation, etc.)
// If you are new to Dear ImGui, read documentation from the docs/ folder + read the top of imgui.cpp.
// Read online: https://github.com/ocornut/imgui/tree/master/docs

#include "ImguiImpl.h"

int main(int, char **)
{

    example::GLFWImpl glfwImpl;
    example::ImguiImpl imguiImpl(glfwImpl);

    imguiImpl.Play();

    return 0;
}
