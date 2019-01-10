#ifndef BLACKCOMB_MOUSEWATCHER_H
#define BLACKCOMB_MOUSEWATCHER_H

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

namespace blackcomb::base {
    class Window;
}

namespace blackcomb::input {
/**
 * Keeps track of mouse position and informs other components about the mouse.
 */
    class MouseWatcher {
    public:
        void update(base::Window& window);
        glm::vec2 getMouseCoords();
        static bool shouldWatch; ///< Should we be watching for mouse input?
        float mouseSensitivity = 0.05f; ///< Controls the sensitivity of mouse tracking.
    private:
        double lastMouseX = 400, lastMouseY = 300;
        bool mouseUnseen = true;
        glm::vec2 mouseCoords;
    };
}

#endif //BLACKCOMB_MOUSEWATCHER_H
