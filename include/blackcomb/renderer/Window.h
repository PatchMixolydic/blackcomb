#ifndef CRAFTCLONE_WINDOW_H
#define CRAFTCLONE_WINDOW_H

#include <GLFW/glfw3.h>
#include "../misc/Coords.h"

const unsigned int DefaultWidth = 800;
const unsigned int DefaultHeight = 600;

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
private:
    GLFWwindow* handle;
};


#endif //CRAFTCLONE_WINDOW_H
