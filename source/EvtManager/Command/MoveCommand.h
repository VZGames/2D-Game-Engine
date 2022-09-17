#ifndef MOVECOMMAND_H
#define MOVECOMMAND_H

#include "ICommand.h"
#include "../../Physics/Vector2D.h"

class MoveCommand: public ICommand
{

private:
    f_Vector2D m_OldPosition, m_NewPosition;

private:
    void goTo(); //speed, from -> to

public:
    MoveCommand();

    // ICommand interface
public:
    void execute();
};

#endif // MOVECOMMAND_H
