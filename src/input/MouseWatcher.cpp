#include "blackcomb/input/MouseWatcher.h"

using namespace input;

bool MouseWatcher::hasFocus = true;

/**
 * Update the mouse position.
 * @param window The window to watch for mouse motion in.
 * @return The change in mouse position.
 */
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
