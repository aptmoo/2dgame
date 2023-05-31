#include "scene.h"

#include "common/strutils.h"

#include <stdlib.h>

#define GRID_SIZE 4096
#define CELL_SIZE 16
static struct
{
    entity_t* entities;
    usize numEnts;

    entity_t* gcells[GRID_SIZE][GRID_SIZE];
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
        entity_t* ent;
        ent = &sd.entities[i];
        if(ent->used == FALSE)
        {
            ent->used = TRUE;
            return ent;
        }
    }

    entity_t* ent;
    sd.entities = realloc(sd.entities, sizeof(entity_t) * (sd.numEnts + 1));
    ent = &sd.entities[sd.numEnts];
    sd.numEnts++;
    memset(ent, 0, sizeof(entity_t));
    
    ent->used = TRUE;
    ent->name = STR_CopyString("Entity");
    usize cellx = (usize)(ent->origin[0] / CELL_SIZE);
    usize celly = (usize)(ent->origin[2] / CELL_SIZE);
    ent->gprev = NULL;
    ent->gnext = sd.gcells[cellx][celly];
    sd.gcells[cellx][celly] = ent;

    if(ent->gnext != NULL)
        ent->gnext->gprev = ent;

    return ent;
}

/**
 * @brief Gets the entity at id. Returns null if the id is not valid.
 * 
 * @param id 
 * @return entity_t* 
 */
entity_t* SC_GetEntityID(usize id)
{
    if(id > sd.numEnts)
        return NULL;
    return &sd.entities[id];
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

entity_t* SC_GetEntityAtLocation(vec3 pos)
{
    usize cellx = (usize)(pos[0] / CELL_SIZE);
    usize celly = (usize)(pos[2] / CELL_SIZE);
    return sd.gcells[cellx][celly];
}

void SC_GetScenePtr(usize* size, entity_t* ents)
{
    *size = sd.numEnts;
    ents = sd.entities;
}