#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <map>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include "../Physics/Vector2D.h"

class TextureManager
{
private:
    TextureManager();

private:
    std::map<const char*, SDL_Texture*> m_TxtureDict;
    static TextureManager *s_Instance;

public:
    void LoadTexture(const char *p_TextureID, const char *p_FilePath);
    void Draw(char *p_TextureID, d_Vector2D p_Pos, int p_Width, int p_Height, SDL_RendererFlip p_Flip = SDL_FLIP_NONE);
    void DrawTile(const char *p_TileID, int p_TileSize, d_Vector2D p_Pos, int p_Row, int p_Frame, SDL_RendererFlip p_Flip = SDL_FLIP_NONE);
    void DrawFrame(const char *p_TextureID, d_Vector2D p_Pos, int p_Width, int p_Height, int p_Row, int p_Frame, SDL_RendererFlip p_Flip = SDL_FLIP_NONE, double p_Angle = 0);
    void Drop(const char *p_TextureID);
    void Clean();

public:
    static TextureManager *GetInstance() {return s_Instance = (s_Instance == nullptr) ? new TextureManager():s_Instance;};

};

#endif // TEXTUREMANAGER_H
