#include "scene.h"
#include <stdlib.h>

#include "common/strutils.h"

static struct
{
    entity_t* entities;
    usize numEnts;
} sd;


void SC_InitScene(usize preallocEnts)
{
    sd.entities = malloc(preallocEnts * sizeof(entity_t));
    sd.numEnts = preallocEnts;

    for(int i = 0; i < sd.numEnts; i++)
    {
        sd.entities[i].used = FALSE;
        sd.entities[i].id = i;
        sd.entities[i].name = STR_CopyString("prealloc");
    }
}

entity_t* SC_GetNewEntity()
{
    for(int i = 0; i < sd.numEnts; i++)
    {
        entity_t* ent = &sd.entities[i];
        if(ent->used == FALSE)
        {
            ent->used = TRUE;
            return ent;
        }
    }

    sd.entities = realloc(sd.entities, sizeof(entity_t) * (sd.numEnts + 1));
    sd.numEnts++;
    sd.entities[sd.numEnts].id = sd.numEnts;
    return &sd.entities[sd.numEnts];
}