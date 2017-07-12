#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#include "Card.h"

class Global
{
public:
    // TODO: Use unique pointers to stop leaks from object pointers
    static std::map<std::string, Card*> cards;
};

#endif // __GLOBAL_H__
