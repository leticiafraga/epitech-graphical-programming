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
#include "include/radar.h"

void destroy_sprite(spr *spr)
{
    sfSprite_destroy(spr->sprite);
    sfTexture_destroy(spr->texture);
    free(spr);
}

spr *init_basic_sprite(const char *filename, int x, int y)
{
    spr *bg = malloc(sizeof(spr));
    sfVector2f init_bg = {x, y};

    bg->sprite = new_sprite();
    bg->texture = sfTexture_createFromFile(filename, NULL);
    sfSprite_setPosition(bg->sprite, init_bg);
    sfSprite_setTexture(bg->sprite, bg->texture, sfTrue);
    return bg;
}

void reinit_target(target *t)
{
    sfVector2f init_sprite = {-50, rand() % 500};

    if (t->reverse)
        init_sprite.x = 850;
    sfSprite_setPosition(t->sprite, init_sprite);
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
