#include "spatial.h"

#define GRID_SIZE 4096
#define CELL_SIZE 16
entity_t* grid[GRID_SIZE][GRID_SIZE];

void SP_RegisterEntity(entity_t* entity)
{
    usize cellx = (usize)(entity->origin[0] / CELL_SIZE);
    usize celly = (usize)(entity->origin[2] / CELL_SIZE);

    entity->gprev = NULL;
    entity->gnext = grid[cellx][celly];
    grid[cellx][celly] = entity;

    if(entity->gnext != NULL)
        entity->gnext->gprev = entity;
}

void SP_UpdateEntity(entity_t* entity)
{
    usize oldCellx = (usize)(entity->origin[0] / CELL_SIZE);
    usize oldCelly = (usize)(entity->origin[2] / CELL_SIZE);

    usize cellx = (usize)(entity->origin[0] / CELL_SIZE);
    usize celly = (usize)(entity->origin[2] / CELL_SIZE);

    if(entity->origin[0] == entity->oldOrigin[0] && entity->origin[2] == entity->oldOrigin[2])
        return;

    if(entity->gprev != NULL)
        entity->gprev->gnext = entity->gnext;
    
    if(entity->gnext != NULL)
        entity->gnext->gprev = entity->gprev;

    if(grid[oldCellx][oldCelly]->id == entity->id)
        grid[oldCellx][oldCelly] = entity->gnext;

    /* Update oldPosition. 
    TODO: Should this be done here? 
    */
    vec3_dup(entity->oldOrigin, entity->origin);
    
    SP_RegisterEntity(entity);  /* "Hack" to make sure the entity gets placed on the grid */
}

entity_t* SP_GetCell(vec3 pos)
{
    usize cellx = (usize)(pos[0] / CELL_SIZE);
    usize celly = (usize)(pos[2] / CELL_SIZE);

    return grid[cellx][celly];
}