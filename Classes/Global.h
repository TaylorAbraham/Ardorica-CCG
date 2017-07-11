#ifndef __GLOBAL_H__
#define __GLOBAL_H__

class Global
{
public:
    // TODO: Use unique pointers to stop leaks from object pointers
    static std::map<std::string, Card*> cards;
};
