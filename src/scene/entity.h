#ifndef SC_ENTITY_H
#define SC_ENTITY_H
#include "common/types.h"
#include "common/math.h"

typedef enum
{
    ENT_NONE = 0,
    ENT_WORLDSPAWN,
    ENT_SPAMCONSOLE
} etype_t;

typedef struct
{
    unsigned visible    : 1;
    unsigned active     : 1;
    unsigned outline    : 1;
} eflags_t;

typedef struct entity_s
{
    /* Entity properties */
    etype_t type;
    eflags_t flags;
    u64 id;
    BOOL used;

    /* Transform */
    vec3 origin;
    quat angles;
    float scale;

    /* Linked list ptrs for the spatial grid */
    struct entity_s* gnext; 
    struct entity_s* gprev;
} entity_t;

extern entity_t* entities;
extern u64 numents;

/**
 * @brief Inititialize the entity system. 
 * Allocates initialEnts + 1 entities.
 * ID 0 is worlspawn.
 * 
 * @param intitialEnts 
 */
void ENT_InitEntities(u64 intitialEnts);

/**
 * @brief Get an new or unused entity.
 * 
 * @return entity_t* 
 */
entity_t* ENT_GetNewEntity();

#endif