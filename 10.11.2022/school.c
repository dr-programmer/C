#include <stdio.h>
#include "schoolclass.h"
#include "schoolroom.h"

struct School
{
    struct SchoolClass classes[20];
    struct SchoolRoom rooms[10];
};
