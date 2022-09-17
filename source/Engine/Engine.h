#ifndef __ENGINE_H__
#define __ENGINE_H__

#define _WINDOW_WIDTH 960
#define _WINDOW_HEIGHT 640

#include <iostream>

/// SDL2 libs
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_net.h>

class Engine
{

    /// private variables
private:
    Engine();
    SDL_Window *m_Window;
    static Engine *s_Instance;

    /// private functions
private:
    void HandleEvents();
    void Render();
    void Update();

    /// public variables
public:
    static SDL_Renderer *s_Renderer;
    static bool s_Running;

public:
    ~Engine();
    static Engine *GetInstance() { return s_Instance = (s_Instance == nullptr) ? new Engine() : s_Instance; }
    static bool Running() { return s_Running; };

    /// overloading

    friend std::ostream &operator<<(std::ostream &p_Out, Engine &p_Engine);

    /// end overloading

    bool Init(const char *p_Title, int p_WinWidth = _WINDOW_WIDTH, int p_WinHeight = _WINDOW_HEIGHT);
    void Loop();
    void Clean();
    void Quit();
};
#endif /// __ENGINE_H__
