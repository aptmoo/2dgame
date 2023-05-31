#include "entity.h"

#include <stdlib.h>
#include <string.h>

/* See entity.h */
entity_t* entities;
int numents;

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

    entities = realloc(entities, sizeof(numents + 1));
    numents++;

    entity_t* ent = &entities[numents - 1]; /* I fucking love pointer arithmetic */
    memset(ent, 0, sizeof(entity_t));
    
    return ent;
}
