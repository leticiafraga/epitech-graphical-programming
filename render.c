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

void set_cursor_target(game_parts *game, sfVector2i mouse)
{
    spr *cursor = init_cursor(game);
    sfVector2f mousef = {mouse.x, mouse.y};

    sfSprite_setTexture(cursor->sprite, cursor->texture, sfTrue);
    sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
    mouse = sfMouse_getPositionRenderWindow(game->window);
    mousef.x = mouse.x - 21;
    mousef.y = mouse.y - 21;
    sfSprite_setPosition(cursor->sprite, mousef);
    sfRenderWindow_drawSprite(game->window, cursor->sprite, NULL);
    destroy_sprite(cursor);
}

int render_cursor(game_parts *game, spr *d)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);
    sfFloatRect pos = sfSprite_getGlobalBounds(d->sprite);

    if (sfFloatRect_contains(&pos, mouse.x, mouse.y)) {
        set_cursor_target(game, mouse);
        return 1;
    }
    sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
    return 0;
}

void render(game_parts *game, target *d)
{
    spr s;

    s.sprite = d->sprite;
    s.texture = d->texture;
    sfRenderWindow_clear(game->window, sfBlue);
    sfRenderWindow_drawSprite(game->window, game->bg->sprite, NULL);
    sfSprite_setTexture(d->sprite, d->texture, sfTrue);
    sfSprite_setTextureRect(d->sprite, *(d->rect));
    sfRenderWindow_drawSprite(game->window, d->sprite, NULL);
    render_cursor(game, &s);
}
