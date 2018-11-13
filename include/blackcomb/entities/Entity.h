#ifndef CRAFTCLONE_ENTITY_H
#define CRAFTCLONE_ENTITY_H


#include <glm/glm.hpp>

/**
 * A generic entity class. Has a position, rotation, and scale. Has an "update" function.
 */
class Entity {
public:
    Entity();
    void setPos(glm::vec3 position);
    void setPos(float x, float y, float z);
    void setX(float x);
    void setY(float y);
    void setZ(float z);
    void setRotation(glm::vec3 rotation);
    void setRotation(float x, float y, float z);
    void setHpr(glm::vec3 hpr);
    void setHpr(float h, float p, float r);
    void setH(float h);
    void setP(float p);
    void setR(float r);
    void setScale(glm::vec3 scale);
    void setScale(float sx, float sy, float sz);
    void setScale(float scale);
    void setSx(float sx);
    void setSy(float sy);
    void setSz(float sz);
    virtual void update();
protected:
    void updateTransMat();
    glm::vec3 pos = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 rotation = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f);
    glm::mat4 transform = glm::mat4(1.0f);
};


#endif //CRAFTCLONE_ENTITY_H
