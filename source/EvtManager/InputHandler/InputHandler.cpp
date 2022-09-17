#include "InputHandler.h"
#include "../../Engine/Engine.h"

SDL_Event InputHandler::s_Event;
InputHandler *InputHandler::s_Instance = nullptr;

void InputHandler::Listen()
{
    while (SDL_PollEvent(&s_Event))
    {
        switch (s_Event.type)
        {
        case SDL_QUIT:
            Engine::s_Running = false;
            break;
        case SDL_KEYDOWN:
        case SDL_KEYUP:
            m_KeyBoardState = SDL_GetKeyboardState(nullptr);
            break;
        default:
            break;
        }
    }
}

bool InputHandler::GetKeyDown(SDL_Scancode p_NumKey)
{
    if (m_KeyBoardState[p_NumKey])
    {
        return 1;
    }
    return 0;
}

InputHandler::InputHandler()
{
    m_KeyBoardState = SDL_GetKeyboardState(nullptr);
}
