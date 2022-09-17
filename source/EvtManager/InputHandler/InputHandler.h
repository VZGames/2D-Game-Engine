#ifndef __InputHandler_H__
#define __InputHandler_H__

#include <iostream>
#include <SDL2/SDL_events.h>

class InputHandler
{
private:
    InputHandler();
    const Uint8 *m_KeyBoardState;
    static SDL_Event s_Event;
    static InputHandler *s_Instance;

public:
    void Listen();
    bool GetKeyDown(SDL_Scancode p_NumKey); // key is Pressed?
    static InputHandler *GetInstance() { return s_Instance = (s_Instance == nullptr) ? new InputHandler() : s_Instance; }
};

#endif // __InputHandler_H__
