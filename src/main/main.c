#include <stdlib.h>
#include <stdio.h>

#include "scene/entity.h"
#include "scene/spatial.h"

int main(int argc, char const *argv[])
{
    ENT_InitEntities(0);
    entity_t* e = ENT_GetNewEntity();
    e->origin[0] = 100;
    e->origin[2] = 33;
    SP_RegisterEntity(e);
    printf("%f %f %f\n", e->origin[0], e->origin[1], e->origin[2]);


    entity_t* e2 = SP_GetCell(e->origin);
    printf("%f %f %f\n", e2->origin[0], e2->origin[1], e2->origin[2]);

    
    return 0;
}
