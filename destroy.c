/*
** EPITECH PROJECT, 2023
** destroy
** File description:
** destroy
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/System/Clock.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/radar.h"

void destroy_target(target *t)
{
    sfSprite_destroy(t->sprite);
    sfTexture_destroy(t->texture);
    free(t->rect);
    free(t);
}

static void destroy_planes(airplane **planes, int n)
{
    airplane *plane;

    for (int i = 0; i < n; i++) {
        plane = planes[i];
        sfSprite_destroy(plane->sprite);
        sfRectangleShape_destroy(plane->rect);
        sfTexture_destroy(plane->texture);
        free(plane);
    }
    free(planes);
}

static void destroy_towers(tower **towers, int n)
{
    tower *t;

    for (int i = 0; i < n; i++) {
        t = towers[i];
        sfSprite_destroy(t->sprite);
        sfCircleShape_destroy(t->circle);
        sfTexture_destroy(t->texture);
        free(t);
    }
    free(towers);
}

void destroy(game_parts *game, corner **corners)
{
    for (int i = 0; i < 4; i++) {
        free(corners[i]);
    }
    free(corners);
    destroy_planes(game->planes, game->plane_cnt);
    destroy_towers(game->towers, game->tower_cnt);
    sfClock_destroy(game->clock);
    sfRenderWindow_destroy(game->window);
    sfFont_destroy(game->font);
    destroy_sprite(game->bg);
    free(game);
}
