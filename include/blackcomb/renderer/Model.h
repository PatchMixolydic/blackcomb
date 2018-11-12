#ifndef CRAFTCLONE_MODEL_H
#define CRAFTCLONE_MODEL_H

#include "Texture.h"
#include "Mesh.h"
#include "Shader.h"

class Model {
public:
    Model();
    Model(Mesh mesh, Texture texture);
    void cleanup();
    void render();
    Mesh mesh;
    Texture texture;
};

#endif //CRAFTCLONE_MODEL_H
