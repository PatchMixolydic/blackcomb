#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "blackcomb/entities/FreeMoveCamera.h"

void FreeMoveCamera::loadViewMatrix(Shader shader) {
    glm::mat4 view(1.0f);
    view = glm::lookAt(pos, pos + front, up);
    shader.setUniformMat4F("view", glm::value_ptr(view));
}

/**
 * Process input and move the camera accordingly
 *
 * @param window The pointer to the window that the mouse should be tracked over.
 * @param deltaTime Time since the last tick.
 */
void FreeMoveCamera::processInput(GLFWwindow* window, float deltaTime) {
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        setPos(pos + speed * deltaTime * front);
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        setPos(pos - speed * deltaTime * front);
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        setPos(pos - glm::normalize(glm::cross(front, up)) * speed * deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        setPos(pos + glm::normalize(glm::cross(front, up)) * speed * deltaTime);
    }

    if (!MouseWatcher::hasFocus) return;

    glm::vec2 mouseDelta = mouseWatcher.update(window);

    setH(rotation.y + mouseDelta.x);
    setP(std::min(std::max(rotation.x + mouseDelta.y, -89.0f), 89.0f));
    glm::vec3 camFront;
    camFront.x = cos(glm::radians(rotation.x)) * cos(glm::radians(rotation.y));
    camFront.y = sin(glm::radians(rotation.x));
    camFront.z = cos(glm::radians(rotation.x)) * sin(glm::radians(rotation.y));
    front = glm::normalize(camFront);
}
