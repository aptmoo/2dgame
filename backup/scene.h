#ifndef SC_SCENE_H
#define SC_SCENE_H
#include "entity.h"

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
 * @brief Gets the entity at id. Returns null if the id is not valid.
 * 
 * @param id 
 * @return entity_t* 
 */
entity_t* SC_GetEntityID(usize id);

/**
 * @brief Delete an entity by resetting it and setting used to false.
 * Does nothing when id is not valid.
 * Resets (again) when the entity at id is already set to unused.
 * 
 * @param id The id of the entity to be removed.
 */
void SC_DeleteEntityID(usize id);

/**
 * @brief Find a entity in the grid.
 * 
 * @param pos 
 * @return entity_t* 
 */
entity_t* SC_GetEntityAtLocation(vec3 pos);

/**
 * @brief Get the internal entity array, and its size.
 * Dont use this unless its absolutely neccesary!
 * 
 * @param size 
 * @param ents 
 */
void SC_GetScenePtr(usize* size, entity_t* ents);

#endif