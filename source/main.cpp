#include <stdlib.h>
#include <iostream>

#include "Engine/Engine.h"

int main(int argc, char *args[])
{
    Engine::GetInstance()->Init("2D GAME ENGINE");
    Engine::GetInstance()->Loop();
    Engine::GetInstance()->Clean();
    Engine::GetInstance()->Quit();

    return EXIT_SUCCESS;
}