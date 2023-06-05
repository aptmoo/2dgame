#include "scene.h"
#include "spatial.h"


void SC_Init()
{
    ENT_InitEntities(0);

}

entity_t *SC_SpawnEntity(etype_t type)
{
    entity_t* entity;
    entity = ENT_GetNewEntity();
    entity->type = type;
    ENT_CallSpawnFunc(entity);
    SP_RegisterEntity(entity);

    return entity;
}