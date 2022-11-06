#ifndef IMGUIIMPL_H
#define IMGUIIMPL_H

#pragma once
#include "GLFWImpl.h"

namespace sa
{

    struct SortingAlgorithm
    {
        SortingAlgorithm()
        {
        }
        SortingAlgorithm(const std::string &name) : name(name) {}
        SortingAlgorithm(const char *name, std::function<void(std::vector<int> &)> sort)
            : name(name), sort(std::move(sort)) {}
        std::string name;
        std::function<void(std::vector<int> &)> sort;
    };

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
        bool m_showMainWindow = true;

        int m_slider_size = 100;

        int m_slider_min = 1;
        int m_slider_max = 1000;

        std::vector<float> m_values;
        std::map<int, SortingAlgorithm> m_sortingAlgorithms;
        char **m_sortingAlgorithmsLabels = nullptr;
        int m_currentSortingAlgorithmIndex = 0;
        SortingAlgorithm *m_currentSortingAlgorithm = nullptr;

        ImGuiWindowFlags m_tab_flags = ImGuiWindowFlags_NoScrollbar;
        ImVec4 m_ClearColor = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
    };
} // namespace sa

#endif
