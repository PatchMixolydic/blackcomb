#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <iostream>
#include "blackcomb/misc/BlackcombException.h"
#include "blackcomb/base/AppBase.h"

namespace blackcomb::base {
    AppBase::AppBase(std::string winTitle) {
        stbi_set_flip_vertically_on_load(true);
        glfwInit();

        getWindow().hide();
        getWindow().setWindowTitle(winTitle);
        getWindow().makeContextCurrent();

        if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
            throw misc::BlackcombException("Failed to initialize GLAD");
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
    base::Window& AppBase::getWindow() {
        if (!window) {
            window = base::Window();
        }
        return window.value();
    }

    /**
     * Call this function to run your application.
     * Starts a loop that every frame updates delta time, handles input, clears colour and depth bits, calls update(), swaps the buffers, and polls for events.
     * Can be overriden for fine grained control, but it is recommended you override AppBase.update instead.
     */
    void AppBase::run() {
        while (!getWindow().shouldClose()) {
            float now = static_cast<float>(glfwGetTime());
            deltaTime = now - lastFrame;
            lastFrame = now;
            processInput();
            getWindow().mouseWatcher.update(getWindow());
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            update();

            glfwSwapBuffers(getWindow().getHandle());
            glfwPollEvents();
        }

    }

    /**
     * Called once per frame after run() is called.
     */
    void AppBase::update() {}

    /**
     * Input handling code. Run once per frame after run() is called.
     */
    void AppBase::processInput() {}
}
