#pragma once

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct Texture_t
{
    uint32_t rendererID;
    bool isBound;

    uint32_t width;
    uint32_t height;
    uint32_t numberOfChannels;
    uint8_t* data;
} Texture;

void InitializeTexture(Texture* texture, const char* path);
void BindTexture(Texture* texture);
void UnBindTexture(Texture* texture);
void DeleteTexture(Texture* texture);