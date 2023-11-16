/*
** EPITECH PROJECT, 2023
** init
** File description:
** init
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/System/Clock.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/hunter.h"

static sfIntRect *display_rect(void)
{
    sfIntRect *rect = malloc(sizeof(sfIntRect));

    rect->top = 0;
    rect->left = 0;
    rect->width = 110;
    rect->height = 110;
    return rect;
}

game_parts *init_game(void)
{
    game_parts *game = malloc(sizeof(game_parts));
    sfVideoMode mode = {800, 600, 32};

    game->clock = sfClock_create();
    game->window = sfRenderWindow_create(
        mode, "ducks", sfDefaultStyle, NULL);
    return game;
}

duck *init_duck(void)
{
    duck *d = malloc(sizeof(duck));

    d->rect = display_rect();
    d->texture = sfTexture_createFromFile("assets/duck.png", NULL);
    d->sprite = new_sprite();
    return d;
}
