#include <stb_image.h>
#include <iostream>
#include "blackcomb/renderer/Texture.h"

Texture::Texture(const char* filename) {
    glGenTextures(1, &textureId);
    glBindTexture(GL_TEXTURE_2D, textureId);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    int numChan;
    unsigned char* imgData = stbi_load(filename, &width, &height, &numChan, 0);
    if (imgData == nullptr) {
        std::cerr << "Failed to load atlas " << filename << std::endl;
        imgData = stbi_load(MissingTextureFilename, &width, &height, &numChan, 0);
    }
    GLenum imageFormat;
    if (numChan == 3) {
        imageFormat = GL_RGB;
    } else {
        imageFormat = GL_RGBA;
    }
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, imageFormat, GL_UNSIGNED_BYTE, imgData);
    glGenerateMipmap(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(imgData);
}

int Texture::getWidth() {
    return width;
}

int Texture::getHeight(){
    return height;
}

void Texture::bind() {
    glBindTexture(GL_TEXTURE_2D, textureId);
}

void Texture::unbind() {
    glBindTexture(GL_TEXTURE_2D, 0);
}
