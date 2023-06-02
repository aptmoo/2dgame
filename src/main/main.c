#include <stdlib.h>
#include <stdio.h>

#include "scene/entity.h"
#include "scene/scene.h"
#include "scene/spatial.h"

int main(int argc, char const *argv[])
{
    SC_Init();
    entity_t* e = ENT_GetNewEntity();
    ENT_CallSpawnFunc(e);
    e->type = ENT_NONE;
    ENT_CallSpawnFunc(e);
    e->origin[0] = 100;
    e->origin[2] = 33;
    SP_RegisterEntity(e);
    printf("%f %f %f\n", e->origin[0], e->origin[1], e->origin[2]);


    entity_t* e2 = SP_GetCell(e->origin);
    printf("%f %f %f\n", e2->origin[0], e2->origin[1], e2->origin[2]);

    
    return 0;
}
