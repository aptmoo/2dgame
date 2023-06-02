#ifndef SC_SCENE_H
#define SC_SCENE_H
#include "entity.h"

#include "common/types.h"
#include "common/math.h"

/**
 * @brief Init the scene system.
 * 
 */
void SC_Init();

entity_t* SC_SpawnEntity(etype_t type);

#endif