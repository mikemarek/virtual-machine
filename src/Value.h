#ifndef VALUE_H
#define VALUE_H

#include "DataTypes.h"

struct value
{
    DataTypes type;

    union
    {
        char  b;
        short s;
        int   i;
        float f;
    };
};

#endif
