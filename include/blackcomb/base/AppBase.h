#ifndef BLACKCOMB_APPBASE_H
#define BLACKCOMB_APPBASE_H

#include <memory>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Window.h"

namespace blackcomb::base {
    /**
     * A convenient base for any Blackcomb application.
     */
    class AppBase {
    public:
        AppBase(std::string winTitle = base::DefaultWinName);
        ~AppBase();
        base::Window& getWindow();
        virtual void run();
        virtual void update();
        virtual void processInput();
        float deltaTime = 0.0f;
        float lastFrame = static_cast<float>(glfwGetTime());
    private:
        std::optional<base::Window> window;
    };
}


#endif //BLACKCOMB_APPBASE_H
