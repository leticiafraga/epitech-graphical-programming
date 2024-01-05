/*
** EPITECH PROJECT, 2023
** main fns
** File description:
** main fns
*/
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include "include/my.h"
#include "include/radar.h"

static void set_circle(tower *t)
{
    sfVector2u text = sfTexture_getSize(t->texture);
    sfVector2f pos = {t->coordinates.x - t->radius,
        t->coordinates.y - t->radius};

    t->circle = sfCircleShape_create();
    sfCircleShape_setRadius(t->circle, t->radius);
    sfCircleShape_setPosition(t->circle, pos);
    sfCircleShape_setOutlineColor(t->circle, sfBlack);
    sfCircleShape_setOutlineThickness(t->circle, 1);
    sfCircleShape_setFillColor(t->circle, sfTransparent);
}

static void set_tower_sprite(tower *t)
{
    sfVector2f scale = {0.05, 0.05};
    sfVector2u text;
    sfVector2f pos;

    t->sprite = sfSprite_create();
    t->texture = sfTexture_createFromFile("assets/tower.png", NULL);
    text = sfTexture_getSize(t->texture);
    pos.x = t->coordinates.x - (text.x * (scale.x / 2));
    pos.y = t->coordinates.y - (text.y * (scale.x / 2));
    sfSprite_setTexture(t->sprite, t->texture, sfFalse);
    sfSprite_setScale(t->sprite, scale);
    sfSprite_setPosition(t->sprite, pos);
    set_circle(t);
}

static void create_struct_tower(game_parts *game, int *info)
{
    tower *t = malloc(sizeof(tower));

    game->towers[game->tower_cnt] = t;
    game->tower_cnt += 1;
    t->coordinates.x = info[0];
    t->coordinates.y = info[1];
    t->radius = info[2];
    set_tower_sprite(t);
}

void create_tower(game_parts *game, char *str)
{
    sfVector2i result;
    int i = 0;
    int it = 0;
    int info[10];

    while (str[i] != '\0') {
        if (is_number(str[i])) {
            result = get_next_nb(str, i);
            i = result.x;
            info[it] = result.y;
            it++;
        } else
            i++;
    }
    create_struct_tower(game, info);
}
