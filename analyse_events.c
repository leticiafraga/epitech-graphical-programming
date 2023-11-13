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
    sfVector2f offset = {0, rand() % 500};

    if (sfFloatRect_contains(&pos, event.x, event.y) == sfTrue) {
        sfSprite_setPosition(sprite, offset);
        return 1;
    }
    return 0;
}

int analyse_events(sfRenderWindow *window, sfEvent event, sfSprite *sprite)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            close_window(window);
        if (event.type == sfEvtMouseButtonPressed)
            return manage_mouse_click(event.mouseButton, sprite);
    }
    return 0;
}
