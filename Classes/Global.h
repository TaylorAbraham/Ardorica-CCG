#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#include "Card.h"

class Global
{
public:
    extern std::map<std::string, std::unique_ptr<Card>> cards;
};

#endif // __GLOBAL_H__
