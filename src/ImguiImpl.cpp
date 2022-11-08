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

        m_Values.resize(m_SliderSize);
        for (int i = 0; i < m_SliderSize; ++i)
        {
            m_Values[i] = i + 1;
        }
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(m_Values.begin(), m_Values.end(), g);
        m_StartIndex = 0;
        m_SwapCount = 0;
        m_Clock = 0.f;

        m_SortingAlgorithmsLabels = (char **)malloc(sizeof(char *) * 10);
        for (int i = 0; i < 10; ++i)
        {
            m_SortingAlgorithmsLabels[i] = (char *)malloc(sizeof(char) * 20);
        }

        strcpy(m_SortingAlgorithmsLabels[0], "Bubble Sort");
        strcpy(m_SortingAlgorithmsLabels[1], "Selection Sort");
        strcpy(m_SortingAlgorithmsLabels[2], "Insertion Sort");
        strcpy(m_SortingAlgorithmsLabels[3], "Merge Sort");
        strcpy(m_SortingAlgorithmsLabels[4], "Quick Sort");
        strcpy(m_SortingAlgorithmsLabels[5], "Heap Sort");
        strcpy(m_SortingAlgorithmsLabels[6], "Radix Sort");

        m_SortingAlgorithms["Bubble Sort"] = std::make_shared<BubbleSort<float>>(&m_Values);
        m_SortingAlgorithms["Bubble Sort"]->SetRenderCallback([this]()
                                                              { this->Render(); });
        m_SortingAlgorithms["Selection Sort"] = std::make_shared<SelectionSort<float>>(&m_Values);
        m_SortingAlgorithms["Selection Sort"]->SetRenderCallback([this]()
                                                                 { this->Render(); });
        m_CurrentSortingAlgorithm = m_SortingAlgorithms["Bubble Sort"];
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
            if (m_CurrentSortingAlgorithm != nullptr)
            {
                m_CurrentSortingAlgorithm->Tick();
            }

            m_Timer = 0.f;
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

                    // ImGui::Combo("Sorting Algorithm", &m_CurrentSortingAlgorithmIndex, m_SortingAlgorithmsLabels, 10);
                    if (ImGui::Combo("Sorting Algorithm", &m_CurrentSortingAlgorithmIndex, m_SortingAlgorithmsLabels, 10))
                    {
                        m_CurrentSortingAlgorithm = m_SortingAlgorithms[m_SortingAlgorithmsLabels[m_CurrentSortingAlgorithmIndex]];
                        std::random_device rd;
                        std::mt19937 g(rd());
                        std::shuffle(m_Values.begin(), m_Values.end(), g);
                        m_StartIndex = 0;
                        m_SwapCount = 0;
                        m_Clock = 0.f;
                        if (m_CurrentSortingAlgorithm != nullptr)
                            m_CurrentSortingAlgorithm->Reset();
                    }

                    // Slider label instead of the default one to avoid the inline display
                    ImGui::Text("Size of the Array");
                    // this slider act on the size of the array, it will generate a new array of random numbers on change
                    if (ImGui::SliderInt("", &m_SliderSize, m_SliderMin, m_SliderMax, "%d", ImGuiSliderFlags_None))
                    {

                        m_Values.resize(m_SliderSize);
                        for (int i = 0; i < m_SliderSize; ++i)
                        {
                            m_Values[i] = i + 1;
                        }
                        std::random_device rd;
                        std::mt19937 g(rd());
                        std::shuffle(m_Values.begin(), m_Values.end(), g);
                        m_StartIndex = 0;
                        m_SwapCount = 0;
                        m_Clock = 0.f;
                        if (m_CurrentSortingAlgorithm != nullptr)
                            m_CurrentSortingAlgorithm->Reset();
                    }

                    ImGui::SameLine();
                    ImGui::BeginGroup();
                    {
                        ImGui::PushID("Properties###Buttons");
                        if (ImGui::Button("Shuffle", {-FLT_MIN, 19.f}))
                        {
                            std::random_device rd;
                            std::mt19937 g(rd());
                            std::shuffle(m_Values.begin(), m_Values.end(), g);
                            m_StartIndex = 0;
                            m_SwapCount = 0;
                            m_Clock = 0.f;
                            if (m_CurrentSortingAlgorithm != nullptr)
                                m_CurrentSortingAlgorithm->Reset();
                        }

                        // ImGui::SameLine();
                        if (ImGui::Button("Sort", {-FLT_MIN, 19.f}))
                        {
                            std::sort(m_Values.begin(), m_Values.end());
                        }
                        ImGui::PopID();
                    }
                    ImGui::EndGroup();

                    ImGui::SliderFloat("Delay", &m_SliderDelay, 0.0f, 0.1f, "%.3f", ImGuiSliderFlags_None);

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
                    ImGui::Text("Clock: %.2f", m_Clock);

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
                    m_StartIndex = 0;
                    m_SwapCount = 0;
                    m_Clock = 0.f;
                }

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
