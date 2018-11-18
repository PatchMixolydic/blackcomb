#ifndef CRAFTCLONE_MOUSEWATCHER_H
#define CRAFTCLONE_MOUSEWATCHER_H

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

namespace input {
/**
 * Keeps track of mouse position and informs other components about the mouse.
 */
    class MouseWatcher {
    public:
        glm::vec2 update(renderer::Window& window);
        static bool hasFocus; ///< Does the window have focus?
        float mouseSensitivity = 0.05f; ///< Controls the sensitivity of mouse tracking.
    private:
        double lastMouseX = 400, lastMouseY = 300;
        bool mouseUnseen = true;
    };
}

#endif //CRAFTCLONE_MOUSEWATCHER_H
