#ifndef CRAFTCLONE_TEXTURE_H
#define CRAFTCLONE_TEXTURE_H

#include <glad/glad.h>

namespace renderer {
    constexpr char MissingTextureFilename[] = "res/maps/unknown.png";

    /**
     * Loads and stores a texture.
     */
    class Texture {
    public:
        Texture(const char* filename);
        int getWidth();
        int getHeight();
        void bind();
        static void unbind();
        GLuint textureId;
    private:
        int width, height;
    };
}

#endif //CRAFTCLONE_TEXTURE_H
