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
#include "include/hunter.h"

void destroy_target(target *t)
{
    sfSprite_destroy(t->sprite);
    sfTexture_destroy(t->texture);
    free(t->rect);
    free(t);
}

void destroy(game_parts *game)
{
    sfClock_destroy(game->clock);
    sfRenderWindow_destroy(game->window);
    sfFont_destroy(game->font);
    free(game);
}
