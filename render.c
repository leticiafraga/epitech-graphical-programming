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
#include "include/radar.h"

static float get_seconds(sfClock *timer)
{
    sfTime time = sfClock_getElapsedTime(timer);

    return time.microseconds / 1000000.0;
}

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

int render_cursor(game_parts *game)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);

    set_cursor_target(game, mouse);
    return 0;
}

void render_plane(sfRenderWindow *window, airplane *plane,
    float seconds)
{
    if (plane->state == -1 && plane->delay <= seconds) {
        plane->state = 0;
    }
    if (plane->state != 0)
        return;
    sfRenderWindow_drawSprite(window, plane->sprite, NULL);
    sfRenderWindow_drawRectangleShape(
        window, plane->rect, NULL);
}

void render(game_parts *game)
{
    float seconds = get_seconds(game->timer);

    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_drawSprite(game->window, game->bg->sprite, NULL);
    for (int i = 0; i < game->tower_cnt; i++) {
        sfRenderWindow_drawSprite(game->window, game->towers[i]->sprite, NULL);
        sfRenderWindow_drawCircleShape(
        game->window, game->towers[i]->circle, NULL);
    }
    for (int i = 0; i < game->plane_cnt; i++) {
        render_plane(game->window, game->planes[i], seconds);
    }
    render_cursor(game);
}
