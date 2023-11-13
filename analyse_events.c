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

void manage_mouse_click(sfMouseButtonEvent event, sfIntRect *rect)
{
    if (sfIntRect_contains(rect, event.x, event.y) == sfTrue)
        mini_printf("DUCK\n");
}

void analyse_events(sfRenderWindow *window, sfEvent event, sfIntRect *rect)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            close_window(window);
        if (event.type == sfEvtMouseButtonPressed)
            manage_mouse_click(event.mouseButton, rect);
    }
}
