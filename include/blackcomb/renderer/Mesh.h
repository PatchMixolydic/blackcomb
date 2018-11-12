#ifndef CRAFTCLONE_MESH_H
#define CRAFTCLONE_MESH_H

#include <glad/glad.h>
#include <vector>
#include "../misc/Coords.h"

struct Vertex {
    Point3 pos;
    Color color;
    UVCoord uv;
};

class Mesh {
public:
    Mesh(std::vector<GLfloat> modelData, std::vector<GLuint> indices);
    Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indices);
    void cleanup();
    void render();
    GLuint vao = 0;
    unsigned long numVerts, numIndices;
private:
    GLuint ebo, vbo;
};


#endif //CRAFTCLONE_MESH_H
