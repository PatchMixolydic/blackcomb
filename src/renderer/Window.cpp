#include <iostream>
#include <blackcomb/renderer/Window.h>
#include <blackcomb/misc/Coords.h>

#include "../../include/blackcomb/renderer/Window.h"

Window::Window(const char* name) : Window::Window(DefaultWidth, DefaultHeight, name) {}

Window::Window(int width, int height, const char* name) {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    handle = glfwCreateWindow(width, height, name, nullptr, nullptr);
    if (handle == nullptr) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        return;
    }
}

void Window::makeContextCurrent() {
    glfwMakeContextCurrent(handle);
}

void Window::setInputMode(int mode, int value) {
    glfwSetInputMode(handle, mode, value);
}

void Window::setShouldClose(bool shouldClose) {
    glfwSetWindowShouldClose(handle, shouldClose);
}

bool Window::shouldClose() {
    return (GLboolean)glfwWindowShouldClose(handle);
}

int Window::getKey(int key) {
    return glfwGetKey(handle, key);
}

int Window::getMouseButton(int button) {
    return glfwGetMouseButton(handle, button);
}

GLFWwindow* Window::getHandle() {
    return handle;
}

Point2i Window::getDims() {
    int width, height;
    glfwGetWindowSize(handle, &width, &height);
    return {width, height};
}

void Window::setFramebufferSizeCallback(GLFWframebuffersizefun fbSizeCallback) {
    glfwSetFramebufferSizeCallback(handle, fbSizeCallback);
}
