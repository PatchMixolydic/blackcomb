#ifndef CRAFTCLONE_CAMERA_H
#define CRAFTCLONE_CAMERA_H

#include "Entity.h"
#include "../renderer/Shader.h"
#include "../renderer/Window.h"

/**
 * A repositionable camera entity.
 */
class Camera : public Entity {
public:
    virtual void loadViewMatrix(Shader shader);
    void loadProjectionMatrix(Shader shader, Window window);
    float fov = 90.0f;
};

#endif //CRAFTCLONE_CAMERA_H
