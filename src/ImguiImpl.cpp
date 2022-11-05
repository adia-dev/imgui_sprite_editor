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

void ImguiImpl::Play()
{

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

    const ImGuiViewport* viewport = ImGui::GetMainViewport();
    ImGui::SetNextWindowPos(viewport->WorkPos);
    ImGui::SetNextWindowSize(viewport->WorkSize);
    ImGui::SetNextWindowViewport(viewport->ID);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);

    ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
    window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
    window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;

    if (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode)
        window_flags |= ImGuiWindowFlags_NoBackground;


    ImGui::Begin("Sorting Algorithms Visualizer", &m_showMainWindow, window_flags);

    ImGui::PopStyleVar(2);

    ImGuiIO& io = ImGui::GetIO();
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



    // Create a button
    if (ImGui::Button("Button"))
    {
        // Do stuff
    }

    // Create a min and max slider
    static float f = 0.0f;
    ImGui::SliderFloat("float", &f, 0.0f, 1.0f);

    ImGui::End();
    // End Main Window

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
