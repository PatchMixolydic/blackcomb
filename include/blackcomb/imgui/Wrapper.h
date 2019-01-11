#ifndef IMGUITEST_IMGUIWRAPPER_H
#define IMGUITEST_IMGUIWRAPPER_H

#include <blackcomb/imgui/imgui.h>
#include <blackcomb/imgui/imgui_impl_glfw.h>
#include <blackcomb/imgui/imgui_impl_opengl3.h>

namespace blackcomb::imgui {
    /**
     * A conveniece wrapper for Dear IMGUI's initialization and destruction.
     *
     * For additional documentation on Dear IMGUI, see https://github.com/ocornut/imgui/wiki.
     */
    class Wrapper {
    public:
        static void createContext();
        static void simpleConfig();
        static void initialize(GLFWwindow* windowPtr, const char* glslVersion = nullptr, bool installCallbacks = true);
        static void beginFrame();
        static void render();
        static void destroy();
    };
}


#endif //IMGUITEST_IMGUIWRAPPER_H
