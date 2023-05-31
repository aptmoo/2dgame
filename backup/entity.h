#ifndef ENTITY_H
#define ENTITY_H
#include "common/types.h"
#include "common/math.h"

typedef enum
{
    ENTITY_NONE = 0,
    ENTITY_TEST,
    ENTITY_WORLD    // Only one of these is supposed to exist at id 0,
    // and exists only so that other ents can refer to it as its owner.
    // ID 0 is not valid in all other situations.
} entity_type_t;

// TODO: Change order of data for optimization reasons
typedef struct entity_s
{
    // Entity info
    BOOL used;
    char* name;
    usize id;
    entity_type_t type;

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

    // Function pointers
    void(*Think)(struct entity_s* self, f64 delta);

    // A void ptr so an entity can allocate private data,
    // Models, Script data, etc.
    void* data;

    // Spatial grid data
    struct entity_s* gprev;
    struct entity_s* gnext;
} entity_t;

#endif