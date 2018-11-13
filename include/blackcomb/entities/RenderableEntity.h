#ifndef CRAFTCLONE_RENDERABLEENTITY_H
#define CRAFTCLONE_RENDERABLEENTITY_H

#include "Entity.h"
#include "../renderer/Model.h"

/**
 * An entity that has a model and can thus be rendered.
 */
class RenderableEntity : public Entity {
public:
    RenderableEntity(Model& model);
    void render(Shader shader);
private:
    Model model;
};


#endif //CRAFTCLONE_RENDERABLEENTITY_H
