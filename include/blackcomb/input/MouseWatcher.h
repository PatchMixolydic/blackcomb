#ifndef CRAFTCLONE_MOUSEWATCHER_H
#define CRAFTCLONE_MOUSEWATCHER_H

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

namespace renderer {
    class Window;
}

namespace input {
/**
 * Keeps track of mouse position and informs other components about the mouse.
 */
    class MouseWatcher {
    public:
        void update(renderer::Window& window);
        glm::vec2 getMouseCoords();
        static bool hasFocus; ///< Does the window have focus?
        float mouseSensitivity = 0.05f; ///< Controls the sensitivity of mouse tracking.
    private:
        double lastMouseX = 400, lastMouseY = 300;
        bool mouseUnseen = true;
        glm::vec2 mouseCoords;
    };
}

#endif //CRAFTCLONE_MOUSEWATCHER_H
