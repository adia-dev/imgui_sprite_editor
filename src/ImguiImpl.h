#ifndef IMGUIIMPL_H
#define IMGUIIMPL_H

#pragma once
#include "GLFWImpl.h"

namespace example
{
    class ImguiImpl
    {
    public:
        ImguiImpl(GLFWImpl &glfwImpl);
        ~ImguiImpl();

        void Play();

    private:
        virtual void Update();
        void Render();
        void RenderAdditionalPlatformWindows();
        void Shutdown();

        GLFWImpl &m_GLFWImpl;

        bool m_ShowDemoWindow = true;
        bool m_showMainWindow = true;

        int m_slider_size = 100;

        ImGuiWindowFlags m_tab_flags = ImGuiWindowFlags_None;
        ImVec4 m_ClearColor = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
    };
} // namespace example

#endif
