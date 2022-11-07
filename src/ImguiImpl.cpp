#include "ImguiImpl.h"

namespace sa
{

    ImguiImpl::ImguiImpl(GLFWImpl &glfwImpl)
        : m_GLFWImpl(glfwImpl)
    {
        // Setup Dear ImGui context
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();

        // Configures IO
        ImGuiIO &io = ImGui::GetIO();
        (void)io;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // Enable Keyboard Controls
        // io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;   // Enable Docking
        io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable; // Enable Multi-Viewport / Platform Windows
        // io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
        // io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

        // Setup Dear ImGui style
        ImGui::StyleColorsDark();
        // ImGui::StyleColorsLight();

        // When viewports are enabled we tweak WindowRounding/WindowBg so platform windows can look identical to regular ones.
        ImGuiStyle &style = ImGui::GetStyle();
        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            style.WindowRounding = 0.0f;
            style.Colors[ImGuiCol_WindowBg].w = 1.0f;
        }

        // Setup Platform/Renderer backends
        ImGui_ImplGlfw_InitForOpenGL(m_GLFWImpl.GetWindow(), true);
        ImGui_ImplOpenGL3_Init(m_GLFWImpl.GetGLSLVersionCStr());

        // Load Fonts
        // - If no fonts are loaded, dear imgui will use the default font. You can also load multiple fonts and use ImGui::PushFont()/PopFont() to select them.
        // - AddFontFromFileTTF() will return the ImFont* so you can store it if you need to select the font among multiple.
        // - If the file cannot be loaded, the function will return NULL. Please handle those errors in your application (e.g. use an assertion, or display an error and quit).
        // - The fonts will be rasterized at a given size (w/ oversampling) and stored into a texture when calling ImFontAtlas::Build()/GetTexDataAsXXXX(), which ImGui_ImplXXXX_NewFrame below will call.
        // - Use '#define IMGUI_ENABLE_FREETYPE' in your imconfig file to use Freetype for higher quality font rendering.
        // - Read 'docs/FONTS.md' for more instructions and details.
        // - Remember that in C/C++ if you want to include a backslash \ in a string literal you need to write a double backslash \\ !
        // io.Fonts->AddFontDefault();
        // io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\segoeui.ttf", 18.0f);
        // io.Fonts->AddFontFromFileTTF("../../misc/fonts/DroidSans.ttf", 16.0f);
        // io.Fonts->AddFontFromFileTTF("../../misc/fonts/Roboto-Medium.ttf", 16.0f);
        // io.Fonts->AddFontFromFileTTF("../../misc/fonts/Cousine-Regular.ttf", 15.0f);
        // ImFont* font = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\ArialUni.ttf", 18.0f, NULL, io.Fonts->GetGlyphRangesJapanese());
        // Im_ASSERT(font != NULL);
    }

    ImguiImpl::~ImguiImpl()
    {
    }

    void ImguiImpl::Init()
    {

        m_SortingAlgorithms[1] = SortingAlgorithm<float>("Bubble Sort      (non implemented !)", EMPTY_LAMDA(float));
        m_SortingAlgorithms[2] = SortingAlgorithm<float>("Selection Sort   (non implemented !)", EMPTY_LAMDA(float));
        m_SortingAlgorithms[3] = SortingAlgorithm<float>("Insertion Sort   (non implemented !)", EMPTY_LAMDA(float));
        m_SortingAlgorithms[4] = SortingAlgorithm<float>("Merge Sort       (non implemented !)", EMPTY_LAMDA(float));
        m_SortingAlgorithms[5] = SortingAlgorithm<float>("Quick Sort       (non implemented !)", EMPTY_LAMDA(float));
        m_SortingAlgorithms[6] = SortingAlgorithm<float>("Heap Sort        (non implemented !)", EMPTY_LAMDA(float));
        m_SortingAlgorithms[7] = SortingAlgorithm<float>("Shell Sort       (non implemented !)", EMPTY_LAMDA(float));
        m_SortingAlgorithms[8] = SortingAlgorithm<float>("Radix Sort       (non implemented !)", EMPTY_LAMDA(float));
        m_SortingAlgorithms[9] = SortingAlgorithm<float>("Counting Sort    (non implemented !)", EMPTY_LAMDA(float));
        m_SortingAlgorithms[10] = SortingAlgorithm<float>("Bucket Sort      (non implemented !)", EMPTY_LAMDA(float));
        m_SortingAlgorithms[11] = SortingAlgorithm<float>("Cocktail Sort    (non implemented !)", EMPTY_LAMDA(float));
        m_SortingAlgorithms[12] = SortingAlgorithm<float>("Comb Sort        (non implemented !)", EMPTY_LAMDA(float));
        m_SortingAlgorithms[13] = SortingAlgorithm<float>("Cycle Sort       (non implemented !)", EMPTY_LAMDA(float));
        m_SortingAlgorithms[14] = SortingAlgorithm<float>("Gnome Sort       (non implemented !)", EMPTY_LAMDA(float));
        m_SortingAlgorithms[15] = SortingAlgorithm<float>("Pancake Sort     (non implemented !)", EMPTY_LAMDA(float));
        m_SortingAlgorithms[16] = SortingAlgorithm<float>("Bogo Sort        (non implemented !)", EMPTY_LAMDA(float));
        m_SortingAlgorithms[17] = SortingAlgorithm<float>("Bitonic Sort     (non implemented !)", EMPTY_LAMDA(float));
        m_SortingAlgorithms[18] = SortingAlgorithm<float>("Pigeonhole Sort  (non implemented !)", EMPTY_LAMDA(float));
        m_SortingAlgorithms[19] = SortingAlgorithm<float>("Strand Sort      (non implemented !)", EMPTY_LAMDA(float));
        m_SortingAlgorithms[20] = SortingAlgorithm<float>("Tree Sort        (non implemented !)", EMPTY_LAMDA(float));
        m_SortingAlgorithms[21] = SortingAlgorithm<float>("Stooge Sort      (non implemented !)", EMPTY_LAMDA(float));
        m_SortingAlgorithms[22] = SortingAlgorithm<float>("Tim Sort         (non implemented !)", EMPTY_LAMDA(float));
        m_SortingAlgorithms[23] = SortingAlgorithm<float>("Cube Sort        (non implemented !)", EMPTY_LAMDA(float));
        m_SortingAlgorithms[24] = SortingAlgorithm<float>("Block Sort       (non implemented !)", EMPTY_LAMDA(float));
        m_SortingAlgorithms[25] = SortingAlgorithm<float>("Smooth Sort      (non implemented !)", EMPTY_LAMDA(float));
        m_SortingAlgorithms[26] = SortingAlgorithm<float>("Odd-Even Sort    (non implemented !)", EMPTY_LAMDA(float));
        m_SortingAlgorithms[27] = SortingAlgorithm<float>("Quick3 Sort      (non implemented !)", EMPTY_LAMDA(float));
        m_SortingAlgorithms[28] = SortingAlgorithm<float>("Library Sort     (non implemented !)", EMPTY_LAMDA(float));
        m_SortingAlgorithms[29] = SortingAlgorithm<float>("Bead Sort        (non implemented !)", EMPTY_LAMDA(float));
        m_SortingAlgorithms[30] = SortingAlgorithm<float>("Flash Sort       (non implemented !)", EMPTY_LAMDA(float));

        m_SortingAlgorithmsLabels = (char **)(malloc(sizeof(char *) * m_SortingAlgorithms.size()));

        for (auto [key, value] : m_SortingAlgorithms)
        {
            m_SortingAlgorithmsLabels[key - 1] = (char *)(malloc(sizeof(char) * value.getName().size()));
            strncpy(m_SortingAlgorithmsLabels[key - 1], value.getName().c_str(), value.getName().size() + 1);
        }

        m_CurrentSortingAlgorithm = &(m_SortingAlgorithms[1]);

        m_Values.resize(m_SliderSize);
        for (int i = 0; i < m_SliderSize; ++i)
        {
            m_Values[i] = i + 1;
        }
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(m_Values.begin(), m_Values.end(), g);
    }

    void ImguiImpl::Play()
    {

        Init();
        while (m_GLFWImpl.IsRunning())
        {
            m_GLFWImpl.PollEvents();
            Update();
            Render();
        }

        Shutdown();
    }

    void ImguiImpl::Update()
    {
        ImGuiIO &io = ImGui::GetIO();
        (void)io;
        m_Timer += io.DeltaTime;
        if (m_Timer >= m_SliderDelay)
        {
            m_Timer = 0.f;

            static int i = 0;
            static int j = 0;

            if (i <= m_Values.size() - 1 || !std::is_sorted(m_Values.begin(), m_Values.end()))
            {

                if (m_Values[j] > m_Values[j + 1])
                {
                    int temp = m_Values[j];
                    m_Values[j] = m_Values[j + 1];
                    m_Values[j + 1] = temp;
                    m_SwapCount++;
                    Render();
                }
                j++;

                if (j == m_Values.size() - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }

    void ImguiImpl::Render()
    {

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // Main window, this window will hold the viewport and the preferences
        /*
                                  ─────────────────────────────────┐
                                  │      │                         │
                                  │      │                         │
                                  ├──────│                         │
                                  │      │                         │
                                  │      │                         │
                                  │      │                         │
                                  ├──────┤                         │
                                  │      │                         │
                                  └──────┴─────────────────────────┘
                   */

        static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;

        const ImGuiViewport *viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowPos(viewport->WorkPos);
        ImGui::SetNextWindowSize(viewport->WorkSize);
        ImGui::SetNextWindowViewport(viewport->ID);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);

        ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
        window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
        window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus | ImGuiWindowFlags_NoScrollbar;

        if (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode)
            window_flags |= ImGuiWindowFlags_NoBackground;

        ImGui::Begin("Sorting Algorithms Visualizer", &m_ShowMainWindow, window_flags);
        {

            ImGui::PopStyleVar(2);
            ImGuiIO &io = ImGui::GetIO();
            (void)io;
            if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
            {
                ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
                ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);
            }

            if (ImGui::BeginMenuBar())
            {
                if (ImGui::BeginMenu("File"))
                {
                    if (ImGui::MenuItem("Open..", "Ctrl+O"))
                    {
                        // Do stuff
                    }
                    if (ImGui::MenuItem("Save", "Ctrl+S"))
                    {
                        // Do stuff
                    }

                    ImGui::Separator();
                    if (ImGui::MenuItem(m_ShowDemoWindow ? "Hide Demo Window" : "Show Demo Window", ""))
                    {
                        m_ShowDemoWindow = !m_ShowDemoWindow;
                    }

                    ImGui::Separator();
                    if (ImGui::MenuItem("Close", "Ctrl+W"))
                    {
                        m_GLFWImpl.Close();
                    }
                    ImGui::EndMenu();
                }
                ImGui::EndMenuBar();
            }

            // demo window
            if (m_ShowDemoWindow)
                ImGui::ShowDemoWindow(&m_ShowDemoWindow);

            // Left group, contains: properties, table, specs
            ImGui::BeginGroup();
            {
                // no vertical scrolling
                ImGui::Begin("Properties", NULL, m_Tab_flags);
                {
                    ImGui::PushID("Properties");
                    // create a const char* array with the names of the algorithms

                    ImGui::Combo("Sorting Algorithm", &m_CurrentSortingAlgorithmIndex, m_SortingAlgorithmsLabels, 10);

                    // Slider label instead of the default one to avoid the inline display
                    ImGui::Text("Size of the Array");
                    // this slider act on the size of the array, it will generate a new array of random numbers on change
                    ImGui::SliderInt("", &m_SliderSize, m_SliderMin, m_SliderMax, "%d", ImGuiSliderFlags_None);

                    ImGui::SameLine();
                    ImGui::BeginGroup();
                    {
                        ImGui::PushID("Properties###Buttons");
                        if (ImGui::Button("Shuffle", {-FLT_MIN, 19.f}))
                        {
                            std::random_device rd;
                            std::mt19937 g(rd());
                            std::shuffle(m_Values.begin(), m_Values.end(), g);
                        }

                        // ImGui::SameLine();
                        if (ImGui::Button("Sort", {-FLT_MIN, 19.f}))
                        {
                            std::sort(m_Values.begin(), m_Values.end());
                        }
                        ImGui::PopID();
                    }
                    ImGui::EndGroup();

                    ImGui::Text("Sorting Step Delay");
                    ImGui::SliderFloat("SliderFloat (0 -> 1)", &m_SliderDelay, 0.0f, 1.0f, "%.3f", ImGuiSliderFlags_None);

                    ImGui::Text("Status:");
                    ImGui::SameLine();
                    if (std::is_sorted(m_Values.begin(), m_Values.end()))
                    {
                        ImGui::TextColored(ImVec4(0.0f, 1.0f, 0.0f, 1.0f), "sorted");
                    }
                    else
                    {
                        ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "sorted");
                    }

                    ImGui::PopID();
                }
                ImGui::End();

                ImGui::Begin("Data", NULL, m_Tab_flags);
                {
                    ImGui::PushID("Data");

                    if (ImGui::BeginListBox("###data-listbox", {-FLT_MIN, -FLT_MIN}))
                    {
                        for (auto i : m_Values)
                        {
                            ImGui::Selectable(std::to_string((int)i).c_str(), false);
                        }
                        ImGui::EndListBox();
                    }

                    ImGui::PopID();
                }
                ImGui::End();

                ImGui::Begin("Specs", NULL, m_Tab_flags);
                {
                    ImGui::PushID("Specs");
                    ImGui::Text("Swap: %d", m_SwapCount);
                    ImGui::PopID();
                }
                ImGui::End();
            }
            ImGui::EndGroup();

            ImGui::Begin("Viewport", NULL, m_Tab_flags);
            {
                ImGui::PushID("viewport");
                if (m_SliderSize != m_Values.size())
                {
                    m_Values.resize(m_SliderSize);

                    for (int i = 0; i < m_SliderSize; ++i)
                    {
                        m_Values[i] = i + 1;
                    }

                    std::random_device rd;
                    std::mt19937 g(rd());
                    std::shuffle(m_Values.begin(), m_Values.end(), g);
                }

                ImVec2 windowSize = ImGui::GetWindowSize();
                ImGui::PlotLines("", m_Values.data(), m_Values.size(), 0, "", 0, m_SliderSize, ImVec2(ImGui::GetContentRegionAvail().x, 40.f));

                ImGui::PlotHistogram("", m_Values.data(), m_SliderSize, 0, NULL, 0.0f, (float)m_SliderSize, ImGui::GetContentRegionAvail());
                ImGui::PopID();
            }
            ImGui::End();
        }
        ImGui::End();

        ImGui::Render();

        int display_w, display_h;
        glfwGetFramebufferSize(m_GLFWImpl.GetWindow(), &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(m_ClearColor.x * m_ClearColor.w, m_ClearColor.y * m_ClearColor.w, m_ClearColor.z * m_ClearColor.w, m_ClearColor.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        // Update and Render additional Platform Windows
        // (Platform functions may change the current OpenGL context, so we save/restore it to make it easier to paste this code elsewhere.
        //  For this specific demo app we could also call glfwMakeContextCurrent(window) directly)
        RenderAdditionalPlatformWindows();

        glfwSwapBuffers(m_GLFWImpl.GetWindow());
    }

    void ImguiImpl::RenderAdditionalPlatformWindows()
    {
        ImGuiIO &io = ImGui::GetIO();
        (void)io;
        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            GLFWwindow *backup_current_context = glfwGetCurrentContext();
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
            glfwMakeContextCurrent(backup_current_context);
        }
    }

    void
    ImguiImpl::Shutdown()
    {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
    }
} // namespace sa
