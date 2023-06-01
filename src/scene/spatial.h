#ifndef SC_SPATIAL_H
#define SC_SPATIAL_H
#include "entity.h"

/**
 * @brief Register an previously spawned entity, 
 * and place it on the appropriate cell.
 * 
 * @param entity 
 */
void SP_RegisterEntity(entity_t* entity);

/**
 * @brief Update an entity already registered on the grid.
 * 
 * @param entity 
 */
void SP_UpdateEntity(entity_t* entity);

entity_t* SP_GetCell(vec3 pos);

#endif