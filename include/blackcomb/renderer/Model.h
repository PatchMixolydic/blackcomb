#ifndef BLACKCOMB_MODEL_H
#define BLACKCOMB_MODEL_H

#include "Texture.h"
#include "Mesh.h"
#include "Shader.h"

namespace blackcomb::renderer {
    /**
     * Contains both a [Mesh](@ref Mesh) and a [Model](@ref Model) so that they may be rendered in tandem.
     */
    class Model {
    public:
        Model();
        Model(Mesh mesh, Texture texture);
        void cleanup();
        void render();
        Mesh mesh;
        Texture texture;
    };
}

#endif //BLACKCOMB_MODEL_H
