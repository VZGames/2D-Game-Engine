#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

class TextureManager
{

private:
    TextureManager();
    static TextureManager *s_Instance;

public:
    static TextureManager *GetInstance() {return s_Instance = (s_Instance == nullptr) ? new TextureManager():s_Instance;};

    void Draw();
    void DrawTile();
    void DrawFrame();
    void Drop();

};

#endif // TEXTUREMANAGER_H
