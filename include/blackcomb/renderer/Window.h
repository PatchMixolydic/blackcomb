#ifndef CRAFTCLONE_WINDOW_H
#define CRAFTCLONE_WINDOW_H

#include <GLFW/glfw3.h>
#include "../misc/Coords.h"

namespace renderer {
    const unsigned int DefaultWidth = 800;
    const unsigned int DefaultHeight = 600;

/**
 * Object-oriented wrapper for GLFW's window functions.
 */
    class Window {
    public:
        Window(const char* name);
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
        void setWindowTitle(const std::string& title);
    private:
        GLFWwindow* handle;
    };
}

#endif //CRAFTCLONE_WINDOW_H
