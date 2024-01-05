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
#include "include/radar.h"

game_parts *init_game(file_cnt *cnt)
{
    game_parts *game = malloc(sizeof(game_parts));
    sfVideoMode mode = {1920, 1080, 32};

    game->clock = sfClock_create();
    game->timer = sfClock_create();
    game->window = sfRenderWindow_create(
        mode, "MY_RADAR", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(game->window, 100);
    game->font = sfFont_createFromFile("arial.ttf");
    game->bg = init_basic_sprite("assets/bg.png", 0, 0);
    game->planes = malloc(sizeof(airplane *) * cnt->plane_cnt);
    game->towers = malloc(sizeof(tower *) * cnt->tower_cnt);
    game->plane_cnt = 0;
    game->tower_cnt = 0;
    game->show_hitbox = 1;
    game->show_sprites = 1;
    return game;
}

spr *init_cursor(game_parts *game)
{
    spr *d = malloc(sizeof(spr));
    sfSprite *sprite = sfSprite_create();

    d->texture = sfTexture_createFromFile("assets/target.png", NULL);
    d->sprite = sprite;
    return d;
}
