#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <blackcomb/entities/Entity.h>

Entity::Entity() {
    updateTransMat();
}

void Entity::setPos(glm::vec3 position) {
    pos = position;
    updateTransMat();
}

void Entity::setPos(float x, float y, float z) {
    setPos(glm::vec3(x, y, z));
}

void Entity::setX(float x) {
    setPos(glm::vec3(x, pos.y, pos.z));
}

void Entity::setY(float y) {
    setPos(glm::vec3(pos.x, y, pos.z));
}

void Entity::setZ(float z) {
    setPos(glm::vec3(pos.x, pos.y, z));
}

void Entity::setRotation(glm::vec3 rotation) {
    this->rotation = rotation;
    updateTransMat();
}

void Entity::setRotation(float x, float y, float z) {
    setRotation(glm::vec3(x, y, z));
}

void Entity::setHpr(glm::vec3 rotation) {
    setRotation(glm::vec3(rotation.y, rotation.x, rotation.z));
}

void Entity::setHpr(float h, float p, float r) {
    setRotation(glm::vec3(p, h, r));
}

void Entity::setH(float h) {
    setRotation(glm::vec3(rotation.x, h, rotation.z));
}

void Entity::setP(float p) {
    setRotation(glm::vec3(p, rotation.y, rotation.z));
}

void Entity::setR(float r) {
    setRotation(glm::vec3(rotation.x, rotation.y, r));
}

void Entity::setScale(glm::vec3 scale) {
    this->scale = scale;
    updateTransMat();
}

void Entity::setScale(float sx, float sy, float sz) {
    setScale(glm::vec3(sx, sy, sz));
}

void Entity::setScale(float scale) {
    setScale(glm::vec3(scale, scale, scale));
}

void Entity::setSx(float sx) {
    setScale(glm::vec3(sx, scale.y, scale.z));
}

void Entity::setSy(float sy) {
    setScale(glm::vec3(scale.x, sy, scale.z));
}

void Entity::setSz(float sz) {
    setScale(glm::vec3(scale.x, scale.y, sz));
}

void Entity::updateTransMat() {
    transform = glm::mat4(1.0f);
    transform = glm::translate(transform, pos);
    transform = glm::rotate(transform, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
    transform = glm::rotate(transform, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
    transform = glm::rotate(transform, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
    transform = glm::scale(transform, scale);
}

void Entity::update() {}
