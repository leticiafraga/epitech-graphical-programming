/*
** EPITECH PROJECT, 2023
** analyse_events
** File description:
** analyses events
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/radar.h"

static int manage_key_click(game_parts *game)
{
    sfKeyEvent key = game->event.key;

    if (key.code == sfKeyL)
        game->show_hitbox *= -1;
    return 0;
}

int analyse_events(game_parts *game)
{
    while (sfRenderWindow_pollEvent(game->window, &(game->event))) {
        if (game->event.type == sfEvtClosed)
            close_window(game->window);
        if (game->event.type == sfEvtMouseButtonPressed)
            return 0;
        if (game->event.type == sfEvtKeyPressed)
            return manage_key_click(game);
    }
    return 0;
}

int analyse_menu_events(game_parts *game, target **menu)
{
    while (sfRenderWindow_pollEvent(game->window, &(game->event))) {
        if (game->event.type == sfEvtClosed)
            close_window(game->window);
        if (game->event.type == sfEvtMouseButtonPressed)
            return 0;
    }
    return 0;
}
