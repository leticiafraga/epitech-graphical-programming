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
    sfRenderWindow_setFramerateLimit(game->window, 45);
    return game;
}

target *init_duck(void)
{
    target *d = malloc(sizeof(target));

    d->rect = display_rect();
    d->texture = sfTexture_createFromFile("assets/duck.png", NULL);
    d->sprite = new_sprite();
    return d;
}

spr *init_menu(void)
{
    spr *d = malloc(sizeof(spr));
    sfSprite *sprite = sfSprite_create();
    sfVector2f init_sprite = {400 - 55, 300 - 55};

    sfSprite_setPosition(sprite, init_sprite);
    d->texture = sfTexture_createFromFile("assets/start.png", NULL);
    d->sprite = sprite;
    return d;
}

spr *init_cursor(game_parts *game)
{
    spr *d = malloc(sizeof(spr));
    sfSprite *sprite = sfSprite_create();

    d->texture = sfTexture_createFromFile("assets/target.png", NULL);
    d->sprite = sprite;
    return d;
}
