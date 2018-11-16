#ifndef CRAFTCLONE_CAMERA_H
#define CRAFTCLONE_CAMERA_H

#include "Entity.h"
#include "../renderer/Shader.h"
#include "../renderer/Window.h"

/**
 * An entity that can be used as a camera.
 * Contains functions that allow you to get the view and projection matrices.
 */
class Camera : public Entity {
public:
    virtual void loadViewMatrix(Shader shader);
    void loadProjectionMatrix(Shader shader, Window window);
    float fov = 90.0f; ///< Field of view of the camera.
};

#endif //CRAFTCLONE_CAMERA_H
