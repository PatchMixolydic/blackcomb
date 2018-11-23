#include "blackcomb/base/Window.h"
#include "blackcomb/input/MouseWatcher.h"

using namespace input;

bool MouseWatcher::hasFocus = true;

/**
 * Update the mouse position.
 * @param window The window to watch for mouse motion in.
 * @return The change in mouse position.
 */
void MouseWatcher::update(renderer::Window& window) {
    if (!hasFocus) {
        mouseCoords = glm::vec2(0, 0);
        return;
    }

    double mouseX, mouseY;
    glfwGetCursorPos(window.getHandle(), &mouseX, &mouseY);

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

    mouseCoords = glm::vec2(mouseDeltaX, mouseDeltaY);
}

glm::vec2 MouseWatcher::getMouseCoords() {
    return mouseCoords;
}
