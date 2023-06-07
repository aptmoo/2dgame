#include "e_spamconsole.h"
#include <stdio.h>

void E_SpamconsoleThink(entity_t *self, double delta)
{
    printf("Think %f\n", delta);
}

void E_SpamconsoleTouch(entity_t *self, entity_t *other, touchtype_t type)
{
    printf("Touch %d %d\n", other->id, type);
}

void E_SpamconsoleHurt(entity_t *self, entity_t *other, damagetype_t type, int amount)
{
    printf("Hurt inflictor %d type %d amount %d\n", other->id, type);
}

void E_SpamConsoleSpawn(entity_t *self)
{
    self->Think = E_SpamconsoleThink;
    self->Touch = E_SpamconsoleTouch;
    self->Hurt = E_SpamconsoleHurt;
}