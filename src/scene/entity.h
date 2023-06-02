#ifndef SC_ENTITY_H
#define SC_ENTITY_H
#include "common/types.h"
#include "common/math.h"

#include "physics.h"
#include "combat.h"

typedef enum
{
    ENT_INVALID = 0,
    ENT_NONE,
    ENT_WORLDSPAWN,
    ENT_SPAMCONSOLE,
    ENT_TRIGGER
} etype_t;

typedef struct
{
    unsigned visible    : 1;
    unsigned active     : 1;
    unsigned persistent : 1;
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

    /* Needed for grid */
    vec3 oldOrigin;

    /* Entity funcs */
    void(*Think)(struct entity_s* self, double delta);
    void(*Touch)(struct entity_s* self, struct entity_s* other, touchtype_t type);
    void(*Hurt)(struct entity_s *self, struct entity_s *other, damagetype_t type);

    /* Status effect counters, decrease every tick */
    unsigned int fire, poison, cold;

    /* Linked list ptrs for the spatial grid */
    struct entity_s *gnext;
    struct entity_s* gprev;
} entity_t;

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

/**
 * @brief Call entity spawn func. Type needs to be set beforehand.
 * 
 * @param entity 
 */
void ENT_CallSpawnFunc(entity_t* entity);

/**
 * @brief Invalidate an entity, by using its id.
 * Also deletes its grid data.
 * 
 * @param id 
 */
void ENT_InvalidateEntityID(u64 id);

/**
 * @brief Get all entities.
 * 
 * @param entities
 * @param size
 */
void ENT_GetAllEntities(entity_t* entities, u64* size);

#endif