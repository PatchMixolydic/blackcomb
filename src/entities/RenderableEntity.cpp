#include <glm/gtc/type_ptr.hpp>
#include <blackcomb/entities/RenderableEntity.h>

RenderableEntity::RenderableEntity(Model& model) : model(model) {}

void RenderableEntity::render(Shader shader) {
    shader.setUniformMat4F("model", glm::value_ptr(transform));
    model.render();
}
