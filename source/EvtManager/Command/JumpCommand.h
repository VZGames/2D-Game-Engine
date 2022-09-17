#ifndef JUMPCOMMAND_H
#define JUMPCOMMAND_H

#include "ICommand.h"

class JumpCommand: public ICommand
{

private:
    void jump();

public:
    JumpCommand();

    // ICommand interface
public:
    void execute();
};

#endif // JUMPCOMMAND_H
