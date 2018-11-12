#ifndef CRAFTCLONE_FREEMOVECAMERA_H
#define CRAFTCLONE_FREEMOVECAMERA_H

#include "Camera.h"
#include "../input/MouseWatcher.h"

class FreeMoveCamera : public Camera {
public:
    void loadViewMatrix(Shader shader) override;
    void processInput(GLFWwindow* window, float deltaTime);
    float speed = 5.0f;
private:
    glm::vec3 front = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
    MouseWatcher mouseWatcher; // TODO: hook up through messenger
};


#endif //CRAFTCLONE_FREEMOVECAMERA_H
