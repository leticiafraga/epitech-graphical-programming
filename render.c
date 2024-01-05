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

static void render_plane(game_parts *game, airplane *plane,
    float seconds)
{
    sfRenderWindow *window = game->window;

    if (plane->state == -1 && plane->delay <= seconds) {
        plane->state = 0;
    }
    if (plane->state != 0)
        return;
    if (game->show_sprites == 1)
        sfRenderWindow_drawSprite(window, plane->sprite, NULL);
    if (game->show_hitbox == 1)
        sfRenderWindow_drawRectangleShape(
            window, plane->rect, NULL);
}

static void render_tower(game_parts *game, tower *t)
{
    if (game->show_sprites == 1)
        sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
    if (game->show_hitbox == 1)
        sfRenderWindow_drawCircleShape(
            game->window, t->circle, NULL);
}

void render(game_parts *game)
{
    float seconds = get_seconds(game->timer);

    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_drawSprite(game->window, game->bg->sprite, NULL);
    for (int i = 0; i < game->tower_cnt; i++) {
        render_tower(game, game->towers[i]);
    }
    for (int i = 0; i < game->plane_cnt; i++) {
        render_plane(game, game->planes[i], seconds);
    }
}
