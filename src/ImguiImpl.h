#ifndef IMGUIIMPL_H
#define IMGUIIMPL_H

#pragma once
#include "BubbleSort.h"

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
        void Resize();
        void Shuffle();
        void Reset();

        void Render();
        void RenderAdditionalPlatformWindows();
        void RenderGLFW();
        void RenderMenuBar();
        void RenderSideBar();
        void RenderProperties();
        void RenderData();
        void RenderSpecs();
        void RenderViewport();

        void Shutdown();

        GLFWImpl &m_GLFWImpl;

        bool m_ShowDemoWindow = true;
        bool m_ShowMainWindow = true;

        int m_SliderSize = 100;

        int m_SliderMin = 1;
        int m_SliderMax = 10000;

        float m_Clock = 0.f;
        float m_Timer = std::numeric_limits<float>::max();
        float m_SliderDelay = 0.01f;

        int m_SwapCount = 0;
        int m_ComparisonCount = 0;
        int m_CollectionAccessCount = 0;
        int m_StartIndex = 0;

        std::vector<float> m_Values;

        // Sorting Algorithms variables
        char **m_SortingAlgorithmsLabels = nullptr;
        std::map<std::string, std::shared_ptr<SortingAlgorithm<float>>> m_SortingAlgorithms;
        std::shared_ptr<SortingAlgorithm<float>> m_CurrentSortingAlgorithm = nullptr;
        int m_CurrentSortingAlgorithmIndex = 0;

        ImGuiWindowFlags m_Tab_flags = ImGuiWindowFlags_NoScrollbar;
        ImVec4 m_ClearColor = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
    };
} // namespace sa

#endif
