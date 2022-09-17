#ifndef __ICOMMAND_H__
#define __ICOMMAND_H__

class ICommand
{
private:
    /* data */
public:
    virtual ~ICommand(){};
    virtual void execute() = 0;
};
#endif // __ICOMMAND_H__
