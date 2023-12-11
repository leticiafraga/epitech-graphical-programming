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

static int manage_mouse_click(game_parts *game, target *t)
{
    sfMouseButtonEvent event = game->event.mouseButton;
    sfFloatRect pos = sfSprite_getGlobalBounds(t->sprite);

    if (sfFloatRect_contains(&pos, event.x, event.y) == sfTrue) {
        return 1;
    }
    return 0;
}

int analyse_events(game_parts *game, target *t)
{
    while (sfRenderWindow_pollEvent(game->window, &(game->event))) {
        if (game->event.type == sfEvtClosed)
            close_window(game->window);
        if (game->event.type == sfEvtMouseButtonPressed)
            return manage_mouse_click(game, t);
    }
    return 0;
}

int manage_menu_click(sfMouseButtonEvent event, target **menu)
{
    sfFloatRect pos;

    for (int i = 0; i < 2; i++) {
        pos = sfSprite_getGlobalBounds(menu[i]->sprite);
        if (sfFloatRect_contains(&pos, event.x, event.y) == sfTrue) {
            return i + 1;
        }
    }
    return 0;
}

int analyse_menu_events(game_parts *game, target **menu)
{
    while (sfRenderWindow_pollEvent(game->window, &(game->event))) {
        if (game->event.type == sfEvtClosed)
            close_window(game->window);
        if (game->event.type == sfEvtMouseButtonPressed)
            return manage_menu_click(game->event.mouseButton, menu);
    }
    return 0;
}
