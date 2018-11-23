#ifndef CRAFTCLONE_APPBASE_H
#define CRAFTCLONE_APPBASE_H

#include <memory>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Window.h"

namespace blackcombBase {
    /**
     * A convenient base for any Blackcomb application.
     */
    class AppBase {
    public:
        AppBase(std::string winTitle = blackcombBase::DefaultWinName);
        ~AppBase();
        blackcombBase::Window& getWindow();
        virtual void run();
        virtual void update();
        virtual void processInput();
        float deltaTime = 0.0f;
        float lastFrame = static_cast<float>(glfwGetTime());
    private:
        std::optional<blackcombBase::Window> window;
    };
}


#endif //CRAFTCLONE_APPBASE_H
