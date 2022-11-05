#ifndef GLFWIMPL_H
#define GLFWIMPL_H

#pragma once

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <stdio.h>
#define GL_SILENCE_DEPRECATION
#if defined(IMGUI_IMPL_OPENGL_ES2)
#include <GLES2/gl2.h>
#endif
#include <GLFW/glfw3.h> // Will drag system OpenGL headers
#include <memory>
#include <string>

// [Win32] Our example includes a copy of glfw3.lib pre-compiled with VS2010 to maximize ease of testing and compatibility with old VS compilers.
// To link with VS2010-era libraries, VS2015+ requires linking with legacy_stdio_definitions.lib, which we do using this pragma.
// Your own project should not be affected, as you are likely to link with a newer binary of GLFW that is adequate for your version of Visual Studio.
#if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
#pragma comment(lib, "legacy_stdio_definitions")
#endif

namespace example
{
    class GLFWImpl
    {
    public:
        GLFWImpl();
        ~GLFWImpl();

        void PollEvents();

        bool IsRunning() const { return !glfwWindowShouldClose(m_Window); }

        void Close() { glfwSetWindowShouldClose(m_Window, GLFW_TRUE); }

        GLFWwindow *GetWindow() const { return m_Window; }

        const std::string &GetGLSLVersion() const { return m_glsl_version; }
        const char *GetGLSLVersionCStr() const { return m_glsl_version.c_str(); }

    private:
        static void glfw_error_callback(int error, const char *description)
        {
            fprintf(stderr, "Glfw Error %d: %s\n", error, description);
        }

        GLFWwindow *m_Window = nullptr;
        std::string m_WindowTitle = "Dear ImGui GLFW+OpenGL3 example";
        std::string m_glsl_version = "#version 130";
    };
} // namespace example

#endif