#ifndef IMGUIIMPL_H
#define IMGUIIMPL_H

#pragma once
#include "SortingAlgorithm.h"

namespace sa
{

    class ImguiImpl
    {
    public:
        ImguiImpl(GLFWImpl &glfwImpl);
        ~ImguiImpl();

        void Play();

    private:
        void Init();

        virtual void Update();
        void Render();
        void RenderAdditionalPlatformWindows();
        void Shutdown();

        GLFWImpl &m_GLFWImpl;

        bool m_ShowDemoWindow = true;
        bool m_ShowMainWindow = true;

        int m_Slider_size = 100;

        int m_Slider_min = 1;
        int m_Slider_max = 1000;

        std::vector<float> m_Values;
        std::map<int, SortingAlgorithm<float>> m_SortingAlgorithms;
        char **m_SortingAlgorithmsLabels = nullptr;
        int m_CurrentSortingAlgorithmIndex = 0;
        SortingAlgorithm<float> *m_CurrentSortingAlgorithm = nullptr;

        ImGuiWindowFlags m_Tab_flags = ImGuiWindowFlags_NoScrollbar;
        ImVec4 m_ClearColor = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
    };
} // namespace sa

#endif
