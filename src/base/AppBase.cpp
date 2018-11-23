#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <iostream>
#include "blackcomb/misc/EngineException.h"
#include "blackcomb/base/AppBase.h"

AppBase::AppBase(std::string winTitle) {
    stbi_set_flip_vertically_on_load(true);
    glfwInit();

    getWindow().hide();
    getWindow().setWindowTitle(winTitle);
    getWindow().makeContextCurrent();
    getWindow().setInputMode(GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        throw EngineException("Failed to initialize GLAD");
    }

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
    getWindow().show();
}

AppBase::~AppBase() {
    glfwTerminate();
}

/**
 * A getter for the window, since the window is lazily generated.
 */
renderer::Window& AppBase::getWindow() {
    if (!window) {
        window = renderer::Window();
    }
    return window.value();
}

void AppBase::run() {
    while (!getWindow().shouldClose()) {
        float now = static_cast<float>(glfwGetTime());
        deltaTime = now - lastFrame;
        lastFrame = now;
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        update();

        glfwSwapBuffers(getWindow().getHandle());
        glfwPollEvents();
    }

}

void AppBase::update() {}

void AppBase::processInput() {}
