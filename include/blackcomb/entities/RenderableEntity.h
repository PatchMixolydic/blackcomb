#ifndef BLACKCOMB_RENDERABLEENTITY_H
#define BLACKCOMB_RENDERABLEENTITY_H

#include "BaseEntity.h"
#include "../renderer/Model.h"

namespace entity {
/**
 * An entity that has a model and can thus be rendered.
 */
    class RenderableEntity : public BaseEntity {
    public:
        RenderableEntity(renderer::Model &model);
        void render(renderer::Shader& shader);
    private:
        renderer::Model model;
    };
}

#endif //BLACKCOMB_RENDERABLEENTITY_H
