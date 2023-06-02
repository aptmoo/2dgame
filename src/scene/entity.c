#include "entity.h"

#include <stdlib.h>
#include <string.h>

/* See entity.h */
static entity_t* entities;
static int numents;

/* Empty funcs to avoid null ptr exceptions when touching/hurting another entity with no funcs */
void EntityEmptyThink(entity_t *self, double delta){};
void EntityEmptyTouch(entity_t *self, entity_t *other, touchtype_t type){};
void EntityEmptyHurt(entity_t *self, entity_t *other, damagetype_t type){};
void EntityEmptySpawn(entity_t *self)
{
    self->Think = EntityEmptyThink;
    self->Touch = EntityEmptyTouch;
    self->Hurt = EntityEmptyHurt;
}

typedef struct
{
    etype_t type;
    void (*Spawn)(void *);
} spawnfunc_t;

spawnfunc_t spawnfuncs[] =
{

    {ENT_NONE, EntityEmptySpawn},
    {ENT_INVALID, NULL}
};

void ENT_InitEntities(u64 intitialEnts)
{
    intitialEnts++;
    numents = intitialEnts;
    entities = calloc(intitialEnts, sizeof(entity_t));  /* Calloc conveniently zeroes out allocated memory */

    for(int i = 0; i < numents; i++)
    {
        entities[i].id = i;
        /* 
        Only the id has to be set. This is because used and type are already
        set to ENT_NONE and false, wich have the value of 0.
        */
    }

    /* 
    Entity id 0 is always worlspawn. 
    Worlspawn only exists as a neutral(no team) parent for other ents.
    */
    entities[0].used = TRUE;
    entities[0].type = ENT_WORLDSPAWN;
}

entity_t* ENT_GetNewEntity()
{
    for(int i = 1; i < numents; i++)
    {
        entity_t* ent = &entities[i];
        if(ent->used = FALSE)
        {
            memset(ent, 0, sizeof(entity_t));   /* Quick'n dirty reset */
            ent->id = i;
            ent->used = TRUE;
            return ent;
        }
    }

    entities = realloc(entities, sizeof(entity_t) * (numents + 1));
    numents++;

    entity_t* ent = &entities[numents - 1]; /* I fucking love pointer arithmetic */
    memset(ent, 0, sizeof(entity_t));
    
    return ent;
}

void ENT_CallSpawnFunc(entity_t *entity)
{
    for(spawnfunc_t* func = spawnfuncs; func->type; func++)
    {
        if(func->type == entity->type)
        {
            func->Spawn(entity);
        }
    }
}

void ENT_InvalidateEntityID(u64 id)
{
    if(id > numents)
        return;
    
    entity_t* ent = &entities[id];
    
    if(ent->gprev != NULL)
        ent->gprev->gnext = ent->gnext;
    
    if(ent->gnext != NULL)
        ent->gnext->gprev = ent->gprev;

    memset(ent, 0, sizeof(entity_t));
    ent->id = id;
}

void ENT_GetAllEntities(entity_t *ents, u64 *size)
{
    ents = &entities[0];
    *size = numents;
}