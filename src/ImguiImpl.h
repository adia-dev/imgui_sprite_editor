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

        int m_SliderSize = 100;

        int m_SliderMin = 1;
        int m_SliderMax = 10000;

        float m_Clock = 0.f;
        float m_Timer = std::numeric_limits<float>::max();
        float m_SliderDelay = 0.1f;

        int m_SwapCount = 0;
        int m_StartIndex = 0;

        std::vector<float> m_Values;
        std::map<int, SortingAlgorithm<float>> m_SortingAlgorithms;
        char **m_SortingAlgorithmsLabels = nullptr;
        int m_CurrentSortingAlgorithmIndex = 0;
        SortingAlgorithm<float> *m_CurrentSortingAlgorithm = nullptr;

        ImGuiWindowFlags m_Tab_flags = ImGuiWindowFlags_NoScrollbar;
        ImVec4 m_ClearColor = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

        // ImGuiIO ptr
        std::unique_ptr<ImGuiIO> m_ImGuiIO = nullptr;
    };
} // namespace sa

#endif
