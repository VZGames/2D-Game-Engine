#include "Engine.h"
#include "../EvtManager/InputHandler/InputHandler.h"

Engine *Engine::s_Instance = nullptr;
SDL_Renderer *Engine::s_Renderer = nullptr;
bool Engine::s_Running = false;

Engine::Engine()
{
}

std::ostream &operator<<(std::ostream &p_Out, Engine &p_Engine)
{
    p_Out << "Engine\t"
          << "Running: " << p_Engine.Running()
          << "\n";
    return p_Out;
}

Engine::~Engine()
{
}

bool Engine::Init(const char *p_Title, int p_WinWidth, int p_WinHeight)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 0;
    }
    if (SDLNet_Init() != 0)
    {
        SDL_Log("Unable to initialize SDL Net: %s", SDL_GetError());
        return 0;
    }
    if (!(IMG_Init(IMG_INIT_PNG)))
    {
        SDL_Log("Unable to initialize SDL Image: %s", SDL_GetError());
        return 0;
    }
    if (TTF_Init() != 0)
    {
        SDL_Log("Unable to initialize SDL Font: %s", SDL_GetError());
        return 0;
    }

    /*
        Create Window with:
        - title
        - initial x position
        - initial y position
        - flags
    */
    SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
    m_Window = SDL_CreateWindow(p_Title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_WinWidth, p_WinHeight, window_flags);
    // Check that the window was successfully created
    if (m_Window == NULL)
    {
        // In the case that the window could not be made...
        SDL_Log("Could not create window: %s\n", SDL_GetError());
    }

    s_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED);

    if (s_Renderer)
    {
        // Select the color for drawing.
        SDL_SetRenderDrawColor(s_Renderer, 255, 255, 255, 255);
    }

    s_Running = true;

    return 1;
}

void Engine::Loop()
{

    std::cout << *this;
    while (s_Running)
    {
        HandleEvents();
        Update();
        Render();
    }
}

void Engine::HandleEvents()
{
    InputHandler::GetInstance()->Listen();
}

void Engine::Render()
{
}

void Engine::Update()
{
}

void Engine::Clean()
{
    // Close and destroy the window and the renderer
    SDL_DestroyWindow(m_Window);
    SDL_DestroyRenderer(s_Renderer);
}

void Engine::Quit()
{
    // Clean up
    SDL_Quit();
    TTF_Quit();
    IMG_Quit();
    SDLNet_Quit();
}
