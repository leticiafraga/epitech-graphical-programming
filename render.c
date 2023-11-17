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

void destroy(game_parts *game, target *d)
{
    sfSprite_destroy(d->sprite);
    sfTexture_destroy(d->texture);
    sfClock_destroy(game->clock);
    sfRenderWindow_destroy(game->window);
    free(game);
    free(d->rect);
}

void render_cursor(game_parts *game, target *d)
{
    target *cursor = init_cursor(game);
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f mousef = {mouse.x, mouse.y};
    sfFloatRect pos = sfSprite_getGlobalBounds(d->sprite);

    sfSprite_setTexture(cursor->sprite, cursor->texture, sfTrue);
    if (sfFloatRect_contains(&pos, mouse.x, mouse.y)) {
        sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
        mouse = sfMouse_getPositionRenderWindow(game->window);
        mousef.x = mouse.x - 21;
        mousef.y = mouse.y - 21;
        sfSprite_setPosition(cursor->sprite, mousef);
        sfRenderWindow_drawSprite(game->window, cursor->sprite, NULL);
    } else
        sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
    destroy_sprite(cursor);
}

void render(game_parts *game, target *d)
{
    sfRenderWindow_clear(game->window, sfBlue);
    sfSprite_setTexture(d->sprite, d->texture, sfTrue);
    sfSprite_setTextureRect(d->sprite, *(d->rect));
    sfRenderWindow_drawSprite(game->window, d->sprite, NULL);
    render_cursor(game, d);
}
