#include "ImguiImpl.h"

namespace example
{

    ImguiImpl::ImguiImpl(GLFWImpl &glfwImpl)
        : m_GLFWImpl(glfwImpl)
    {
        // Setup Dear ImGui context
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO &io = ImGui::GetIO();
        (void)io;

        // Configures IO
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
        // IM_ASSERT(font != NULL);
    }

    ImguiImpl::~ImguiImpl()
    {
    }

    void ImguiImpl::Init()
    {
        auto emptyLambda = [](const std::vector<int> &) {};
        m_sortingAlgorithms[1] = SortingAlgorithm("Bubble Sort", emptyLambda);
        m_sortingAlgorithms[2] = SortingAlgorithm("Selection Sort", emptyLambda);
        m_sortingAlgorithms[3] = SortingAlgorithm("Insertion Sort", emptyLambda);
        m_sortingAlgorithms[4] = SortingAlgorithm("Merge Sort", emptyLambda);
        m_sortingAlgorithms[5] = SortingAlgorithm("Quick Sort", emptyLambda);
        m_sortingAlgorithms[6] = SortingAlgorithm("Heap Sort", emptyLambda);
        m_sortingAlgorithms[7] = SortingAlgorithm("Shell Sort", emptyLambda);
        m_sortingAlgorithms[8] = SortingAlgorithm("Radix Sort", emptyLambda);
        m_sortingAlgorithms[9] = SortingAlgorithm("Counting Sort", emptyLambda);
        m_sortingAlgorithms[10] = SortingAlgorithm("Bucket Sort", emptyLambda);
        m_sortingAlgorithms[11] = SortingAlgorithm("Cocktail Sort", emptyLambda);
        m_sortingAlgorithms[12] = SortingAlgorithm("Comb Sort", emptyLambda);
        m_sortingAlgorithms[13] = SortingAlgorithm("Cycle Sort", emptyLambda);
        m_sortingAlgorithms[14] = SortingAlgorithm("Gnome Sort", emptyLambda);
        m_sortingAlgorithms[15] = SortingAlgorithm("Pancake Sort", emptyLambda);
        m_sortingAlgorithms[16] = SortingAlgorithm("Bogo Sort", emptyLambda);
        m_sortingAlgorithms[17] = SortingAlgorithm("Bitonic Sort", emptyLambda);
        m_sortingAlgorithms[18] = SortingAlgorithm("Pigeonhole Sort", emptyLambda);
        m_sortingAlgorithms[19] = SortingAlgorithm("Strand Sort", emptyLambda);
        m_sortingAlgorithms[20] = SortingAlgorithm("Tree Sort", emptyLambda);
        m_sortingAlgorithms[21] = SortingAlgorithm("Stooge Sort", emptyLambda);
        m_sortingAlgorithms[22] = SortingAlgorithm("Tim Sort", emptyLambda);
        m_sortingAlgorithms[23] = SortingAlgorithm("Cube Sort", emptyLambda);
        m_sortingAlgorithms[24] = SortingAlgorithm("Block Sort", emptyLambda);
        m_sortingAlgorithms[25] = SortingAlgorithm("Smooth Sort", emptyLambda);
        m_sortingAlgorithms[26] = SortingAlgorithm("Odd-Even Sort", emptyLambda);
        m_sortingAlgorithms[27] = SortingAlgorithm("Quick3 Sort", emptyLambda);
        m_sortingAlgorithms[28] = SortingAlgorithm("Library Sort", emptyLambda);
        m_sortingAlgorithms[29] = SortingAlgorithm("Bead Sort", emptyLambda);
        m_sortingAlgorithms[30] = SortingAlgorithm("Flash Sort", emptyLambda);

        m_sortingAlgorithmsLabels = (char **)(malloc(sizeof(char *) * m_sortingAlgorithms.size()));

        for (auto [key, value] : m_sortingAlgorithms)
        {
            m_sortingAlgorithmsLabels[key - 1] = (char *)(malloc(sizeof(char) * value.name.size()));
            strncpy(m_sortingAlgorithmsLabels[key - 1], value.name.c_str(), value.name.size() + 1);
        }

        m_currentSortingAlgorithm = &(m_sortingAlgorithms[1]);
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

        ImGui::Begin("Sorting Algorithms Visualizer", &m_showMainWindow, window_flags);
        {

            ImGui::PopStyleVar(2);

            ImGuiIO &io = ImGui::GetIO();
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
                ImGui::Begin("Properties", NULL, m_tab_flags);
                {
                    ImGui::PushID("Properties");
                    // create a const char* array with the names of the algorithms

                    ImGui::Combo("Sorting Algorithm", &m_currentSortingAlgorithmIndex, m_sortingAlgorithmsLabels, 10);

                    // Slider label instead of the default one to avoid the inline display
                    ImGui::Text("Size of the Array");
                    // this slider act on the size of the array, it will generate a new array of random numbers on change
                    ImGui::SliderInt("", &m_slider_size, m_slider_min, m_slider_max, "%d", ImGuiSliderFlags_None);

                    ImGui::PopID();
                }
                ImGui::End();

                ImGui::Begin("Data", NULL, m_tab_flags);
                ImGui::End();

                ImGui::Begin("Specs", NULL, m_tab_flags);
                ImGui::End();
            }
            ImGui::EndGroup();

            ImGui::Begin("Viewport", NULL, m_tab_flags);
            {
                ImGui::PushID("viewport");
                if (m_slider_size != m_values.size())
                {
                    m_values.resize(m_slider_size);
                    std::generate(m_values.begin(), m_values.end(), [this]()
                                  { return rand() % (m_slider_size - 1) + 1; });
                }

                ImVec2 windowSize = ImGui::GetWindowSize();
                ImGui::PlotLines("", m_values.data(), m_values.size(), 0, "", 0, m_slider_size, ImVec2(windowSize.x, 40.f));

                ImGui::PlotHistogram("", m_values.data(), m_slider_size, 0, NULL, 0.0f, (float)m_slider_size, ImVec2(windowSize.x, windowSize.y - 40.f));
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
} // namespace example
