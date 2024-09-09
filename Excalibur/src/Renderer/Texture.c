#define STB_IMAGE_IMPLEMENTATION

#include "Texture.h"

#include <stb_image.h>
#include <glad/glad.h>

void InitializeTexture(Texture* texture, const char* path)
{
    texture->isBound = true;
    texture->data = stbi_load(path, &texture->width, &texture->height, &texture->numberOfChannels, 0);

    glGenTextures(1, &texture->rendererID);
    glBindTexture(GL_TEXTURE_2D, texture);


    if (texture->data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texture->width, texture->height, 0, GL_RGB, GL_UNSIGNED_BYTE, texture->data);
        glGenerateMipmap(GL_TEXTURE_2D);
    } else
        LOG_ERROR("Failed to load texture: %s", path);

}

void BindTexture(Texture* texture)
{

}

void UnBindTexture(Texture* texture)
{

}

void DeleteTexture(Texture* texture)
{
    stbi_image_free(texture->data);
}