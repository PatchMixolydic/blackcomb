#ifndef CRAFTCLONE_APPBASE_H
#define CRAFTCLONE_APPBASE_H

#include <memory>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Window.h"

/**
 * A convenient base for any Blackcomb application.
 */
class AppBase {
public:
    AppBase(std::string winTitle = renderer::DefaultWinName);
    ~AppBase();
    renderer::Window& getWindow();
    virtual void run();
    virtual void update();
    virtual void processInput();
    float deltaTime = 0.0f;
    float lastFrame = static_cast<float>(glfwGetTime());
private:
    std::optional<renderer::Window> window;
};


#endif //CRAFTCLONE_APPBASE_H
