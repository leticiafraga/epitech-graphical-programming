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
    return game;
}

target **init_menu(void)
{
    target **menu = malloc(sizeof(spr *) * 2);
    sfVector2f init_sprite = {400 - 65, 300};

    for (int i = 0; i < 2; i++) {
        menu[i] = malloc(sizeof(spr));
        menu[i]->sprite = sfSprite_create();
        sfSprite_setPosition(menu[i]->sprite, init_sprite);
        init_sprite.y += 55;
    }
    menu[0]->texture = sfTexture_createFromFile("assets/start-btn.png", NULL);
    menu[1]->texture = sfTexture_createFromFile(
        "assets/options-btn.png", NULL);
    for (int i = 0; i < 2; i++) {
        sfSprite_setTexture(menu[i]->sprite, menu[i]->texture, sfTrue);
        menu[i]->rect = display_rect_dim(143, 44);
        sfSprite_setTextureRect(menu[i]->sprite, *(menu[i]->rect));
    }
    return menu;
}

spr *init_cursor(game_parts *game)
{
    spr *d = malloc(sizeof(spr));
    sfSprite *sprite = sfSprite_create();

    d->texture = sfTexture_createFromFile("assets/target.png", NULL);
    d->sprite = sprite;
    return d;
}
