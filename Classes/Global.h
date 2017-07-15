#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#include "Card.h"

class Global
{
public:
    static std::map<std::string, std::unique_ptr<Card>> cards;
private:
};

#endif // __GLOBAL_H__
