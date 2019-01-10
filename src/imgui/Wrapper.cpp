#include "blackcomb/imgui/Wrapper.h"

namespace blackcomb::imgui {
    /**
     * Initialize the imgui context and bindings.
     * @param windowPtr The handle of the window to draw to
     * @param glslVersion The GLSL version, defined as in a shader file (ie. "#version 150"), or nullptr for imgui's default.
     * @param installCallbacks Whether or not imgui should register its callbacks with OpenGL.
     */
    void Wrapper::initialize(GLFWwindow* windowPtr, const char* glslVersion, bool installCallbacks) {
        // Setup context
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        // Use dark theme by default because this engine is RAD
        ImGui::StyleColorsDark();
        // Setup platform bindings
        ImGui_ImplGlfw_InitForOpenGL(windowPtr, installCallbacks);
        ImGui_ImplOpenGL3_Init(glslVersion);
    }

    /**
     * Should be called each frame you are drawing an imgui object, before rendering anything.
     * Informs imgui that a new frame has begun.
     */
    void Wrapper::beginFrame(){
        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
    }

    /**
     * Should be called when you are done drawing all of your imgui objects.
     * Draws the UI to the screen.
     */
    void Wrapper::render() {
        // Rendering
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

    /**
     * Should be called when you are done with imgui, probably in AppBase::destroy.
     */
    void Wrapper::destroy() {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
    }
}
