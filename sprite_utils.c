/*
** EPITECH PROJECT, 2023
** SPRITE
** File description:
** SPRITE
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/System/Clock.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/hunter.h"

void destroy_sprite(target *spr)
{
    sfSprite_destroy(spr->sprite);
    sfTexture_destroy(spr->texture);
    free(spr);
}

void init_sprite(sfSprite *sprite)
{
    sfVector2f init_sprite = {-50, rand() % 500};

    sfSprite_setPosition(sprite, init_sprite);
}

sfSprite *new_sprite(void)
{
    sfSprite *sprite = sfSprite_create();

    init_sprite(sprite);
    return sprite;
}
