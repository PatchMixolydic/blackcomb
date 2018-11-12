#ifndef CRAFTCLONE_MOUSEWATCHER_H
#define CRAFTCLONE_MOUSEWATCHER_H

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

class MouseWatcher {
public:
    glm::vec2 update(GLFWwindow* window);
    static bool hasFocus;
    float mouseSensitivity = 0.05f;
private:
    double lastMouseX = 400, lastMouseY = 300;
    bool mouseUnseen = true;
};

#endif //CRAFTCLONE_MOUSEWATCHER_H
