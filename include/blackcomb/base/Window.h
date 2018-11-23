#ifndef CRAFTCLONE_WINDOW_H
#define CRAFTCLONE_WINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "blackcomb/input/MouseWatcher.h"
#include "blackcomb/misc/Coords.h"

namespace blackcombBase {
    constexpr unsigned int DefaultWinWidth = 800;
    constexpr unsigned int DefaultWinHeight = 600;
    constexpr char DefaultWinName[] = "Blackcomb Application";

/**
 * Object-oriented wrapper for GLFW's window functions.
 */
    class Window {
    public:
        Window();
        Window(const char* name);
        Window(int width, int height);
        Window(int width, int height, const char* name);
        void setInputMode(int mode, int value);
        void setShouldClose(bool shouldClose);
        bool shouldClose();
        int getKey(int key);
        int getMouseButton(int button);
        void makeContextCurrent();
        GLFWwindow* getHandle();
        Point2i getDims();
        void setFramebufferSizeCallback(GLFWframebuffersizefun fbSizeCallback);
        static void defaultSizeCallback(GLFWwindow* handle, int width, int height);
        void setWindowTitle(const std::string& title);
        void hide();
        void show();
        input::MouseWatcher mouseWatcher;
    private:
        GLFWwindow* handle;
    };
}

#endif //CRAFTCLONE_WINDOW_H
