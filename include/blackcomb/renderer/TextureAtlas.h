#ifndef BLACKCOMB_TEXTUREATLAS_H
#define BLACKCOMB_TEXTUREATLAS_H

#include <string>
#include "Texture.h"
#include "../misc/Coords.h"

namespace blackcomb::renderer {
/**
 * Handles looking up textures within a texture atlas.
 */
    class TextureAtlas {
    public:
        TextureAtlas(const std::string& textureFilename, int textureWidth, int textureHeight);
        Texture getTexture();
        misc::UVRect getCoordsForTexture(int texture);

    private:
        Texture atlas;
        int textureWidth;
        int textureHeight;
        int numColumns;
        int numRows;
        float centerOffsetX, centerOffsetY;
    };
}

#endif //BLACKCOMB_TEXTUREATLAS_H
