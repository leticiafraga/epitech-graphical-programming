/*
** EPITECH PROJECT, 2023
** analyse_events
** File description:
** analyses events
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/hunter.h"

int manage_mouse_click(sfMouseButtonEvent event, sfSprite *sprite)
{
    sfFloatRect pos = sfSprite_getGlobalBounds(sprite);

    if (sfFloatRect_contains(&pos, event.x, event.y) == sfTrue) {
        init_sprite(sprite);
        return 1;
    }
    return 0;
}

int analyse_events(game_parts *game, sfSprite *sprite)
{
    while (sfRenderWindow_pollEvent(game->window, &(game->event))) {
        if (game->event.type == sfEvtClosed)
            close_window(game->window);
        if (game->event.type == sfEvtMouseButtonPressed)
            return manage_mouse_click(game->event.mouseButton, sprite);
    }
    return 0;
}

int manage_menu_click(sfMouseButtonEvent event, sfSprite *sprite)
{
    sfFloatRect pos = sfSprite_getGlobalBounds(sprite);

    if (sfFloatRect_contains(&pos, event.x, event.y) == sfTrue) {
        return 1;
    }
    return 0;
}

void render_menu(sfRenderWindow *window, target *d)
{
    sfRenderWindow_clear(window, sfBlue);
    sfSprite_setTexture(d->sprite, d->texture, sfTrue);
    sfRenderWindow_drawSprite(window, d->sprite, NULL);
}

int analyse_menu_events(game_parts *game, target *menu)
{
    while (sfRenderWindow_pollEvent(game->window, &(game->event))) {
        if (game->event.type == sfEvtClosed)
            close_window(game->window);
        if (game->event.type == sfEvtMouseButtonPressed)
            return manage_menu_click(game->event.mouseButton, menu->sprite);
    }
    return 0;
}
