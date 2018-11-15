#include "blackcomb/input/MouseWatcher.h"

bool MouseWatcher::hasFocus = true;

glm::vec2 MouseWatcher::update(GLFWwindow* window) {
    if (!hasFocus) {
        return glm::vec2(lastMouseX, lastMouseY);
    }

    double mouseX, mouseY;
    glfwGetCursorPos(window, &mouseX, &mouseY);

    if (mouseUnseen) {
        lastMouseX = mouseX;
        lastMouseY = mouseY;
        mouseUnseen = false;
    }

    double mouseDeltaX = mouseX - lastMouseX;
    double mouseDeltaY = lastMouseY - mouseY;
    lastMouseX = mouseX;
    lastMouseY = mouseY;

    mouseDeltaX *= mouseSensitivity;
    mouseDeltaY *= mouseSensitivity;

    return glm::vec2(mouseDeltaX, mouseDeltaY);
}
