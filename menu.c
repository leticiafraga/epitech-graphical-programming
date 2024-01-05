/*
** EPITECH PROJECT, 2023
** menu
** File description:
** menu
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/System/Clock.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/radar.h"

void render_menu(game_parts *game, target **menu, spr *bg, spr *title)
{
    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_drawSprite(game->window, bg->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, title->sprite, NULL);
    for (int i = 0; i < 2; i++) {
        sfRenderWindow_drawSprite(game->window, menu[i]->sprite, NULL);
    }
}

int handle_menu(game_parts *game)
{
    target **menu = init_menu();
    int state = analyse_menu_events(game, menu);
    spr *bg = init_basic_sprite("assets/lock-screen.png", 0, 0);
    spr *title = init_basic_sprite("assets/logo.png", 400 - 250, 100);

    while (sfRenderWindow_isOpen(game->window) && state == 0) {
        render_menu(game, menu, bg, title);
        sfRenderWindow_display(game->window);
        state = analyse_menu_events(game, menu);
    }
    free(menu);
    destroy_sprite(bg);
    return state;
}
