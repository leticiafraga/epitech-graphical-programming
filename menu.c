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
#include "include/hunter.h"

static void handle_cursor(game_parts *game, spr **menu)
{
    for (int i = 0; i < 2; i++) {
        if (render_cursor(game, menu[i]))
            break;
    }
}

void render_menu(sfRenderWindow *window, spr **menu)
{
    sfRenderWindow_clear(window, sfBlue);
    for (int i = 0; i < 2; i++) {
        sfRenderWindow_drawSprite(window, menu[i]->sprite, NULL);
    }
}

int handle_menu(game_parts *game)
{
    spr **menu = init_menu();
    int state = analyse_menu_events(game, menu);

    render_menu(game->window, menu);
    handle_cursor(game, menu);
    sfRenderWindow_display(game->window);
    state = analyse_menu_events(game, menu);
    destroy_sprite(menu[0]);
    return state;
}
