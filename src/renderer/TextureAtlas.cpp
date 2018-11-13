#include <blackcomb/renderer/TextureAtlas.h>

TextureAtlas::TextureAtlas(std::string textureFilename, int textureWidth, int textureHeight) :
textureWidth(textureWidth), textureHeight(textureHeight), atlas(Texture(textureFilename.c_str())) {
    numColumns = atlas.getWidth() / textureWidth;
    numRows = atlas.getHeight() / textureHeight;
    centerOffsetX = 1.0f / (numColumns);
    centerOffsetY = 1.0f / (numRows);
}

Texture TextureAtlas::getTexture() {
    return atlas;
}

UVRect TextureAtlas::getCoordsForTexture(int texture) {
    float leftX = texture % numColumns;
    float botY = (numRows - 1) - (texture / numColumns);
    leftX /= (float)numColumns;
    botY /= (float)numRows;
    UVCoord botLeft = {leftX, botY};
    UVCoord topRight = {leftX + centerOffsetX, botY + centerOffsetY};
    return {botLeft, topRight};
}
