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
#include "include/hunter.h"

static int manage_mouse_click(game_parts *game, target *t)
{
    sfMouseButtonEvent event = game->event.mouseButton;
    sfFloatRect pos = sfSprite_getGlobalBounds(t->sprite);

    if (sfFloatRect_contains(&pos, event.x, event.y) == sfTrue) {
        reinit_target(t);
        play_sound(game->s);
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

int analyse_go_events(game_parts *game, target *t)
{
    sfFloatRect pos;

    pos = sfSprite_getGlobalBounds(t->sprite);
    while (sfRenderWindow_pollEvent(game->window, &(game->event))) {
        if (game->event.type == sfEvtClosed)
            close_window(game->window);
        if (game->event.type == sfEvtMouseButtonPressed
            && sfFloatRect_contains(
                &pos, game->event.mouseButton.x,
                game->event.mouseButton.y) == sfTrue) {
            return 0;
        }
    }
    return 3;
}
