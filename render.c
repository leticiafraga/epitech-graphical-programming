/*
** EPITECH PROJECT, 2023
** RENDER
** File description:
** RENDER
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/System/Clock.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/hunter.h"

void destroy(game_parts *game, duck *d)
{
    sfSprite_destroy(d->sprite);
    sfTexture_destroy(d->texture);
    sfClock_destroy(game->clock);
    sfRenderWindow_destroy(game->window);
    free(game);
    free(d->rect);
}

void render(sfRenderWindow *window, duck *d)
{
    sfRenderWindow_clear(window, sfBlue);
    sfSprite_setTexture(d->sprite, d->texture, sfTrue);
    sfSprite_setTextureRect(d->sprite, *(d->rect));
    sfRenderWindow_drawSprite(window, d->sprite, NULL);
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
