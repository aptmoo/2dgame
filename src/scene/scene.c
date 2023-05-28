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
    preallocEnts++;
    sd.entities = malloc(preallocEnts * sizeof(entity_t));
    sd.numEnts = preallocEnts;

    for(int i = 0; i < sd.numEnts; i++)
    {
        sd.entities[i].used = FALSE;
        sd.entities[i].id = i;
        sd.entities[i].name = STR_CopyString("prealloc");
    }

    sd.entities[0].type = ENTITY_WORLD;
    sd.entities[0].used = TRUE;
    
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

void SC_DeleteEntityID(usize id)
{
    if(id > sd.numEnts || id == 0)
        return;
    
    entity_t* ent = &sd.entities[id];
    free(ent->name);    // Name must be free store allocated.
    if(ent->data != NULL)
        free(ent->data);
    memset(ent, 0, sizeof(entity_t));
    ent->id = id;   // Make sure id doesn't change.
}

