#ifndef SC_SCENE_H
#define SC_SCENE_H
#include "common/types.h"
#include "common/math.h"

typedef enum
{
    ENTITY_NONE = 0,
    ENTITY_TEST = 1,
} entity_type_t;

// TODO: Change order of data for optimization reasons
typedef struct
{
    // Entity info
    BOOL used;
    char* name;
    usize id;

    // Transform data
    vec3 origin;
    quat angles;
    float scale;

    // Transform is only recalculated when dirty is set to true
    mat4x4 transform;
    BOOL dirty;

    // Physics data
    float weight;
    aabb3 bbox;

    // A void ptr so an entity can allocate private data,
    // Models, Script data, etc.
    void* data;
} entity_t;

/**
 * @brief Init a scene, and allocate a certain amount of unused entities.
 * 
 * @param preallocEnts The amount of entities to be allocated early.
 * Useful if you already know how much ents a map has.
 */
void SC_InitScene(usize preallocEnts);

/**
 * @brief Allocate a new entity, or reuse one from before.
 * 
 * @return entity_t* 
 */
entity_t* SC_GetNewEntity();

/**
 * @brief Delete an entity by resetting it and setting used to false.
 * Does nothing when id is not valid.
 * Resets (again) when the entity at id is already set to unused.
 * 
 * @param id The id of the entity to be removed.
 */
void SC_DeleteEntityID(usize id);

#endif