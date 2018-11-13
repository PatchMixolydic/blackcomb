#ifndef CRAFTCLONE_TEXTUREATLAS_H
#define CRAFTCLONE_TEXTUREATLAS_H

#include <string>
#include "Texture.h"
#include "../misc/Coords.h"

/**
 * Handles looking up textures within a texture atlas.
 */
class TextureAtlas {
public:
    TextureAtlas(std::string textureFilename, int textureWidth, int textureHeight);
    Texture getTexture();
    UVRect getCoordsForTexture(int texture);

private:
    Texture atlas;
    int textureWidth;
    int textureHeight;
    int numColumns;
    int numRows;
    float centerOffsetX, centerOffsetY;
};

#endif //CRAFTCLONE_TEXTUREATLAS_H
