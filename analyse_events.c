/*
** EPITECH PROJECT, 2023
** analyse_events
** File description:
** analyses events
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "include/my.h"

int handle_event(sfEvent *event)
{
    if (event->type == sfEvtKeyReleased) {
    }
}

void manage_mouse_click(sfMouseButtonEvent event)
{
    mini_printf("Mouse x=%d y=%d\n", event.x, event.y);
}

void analyse_events(sfRenderWindow *window, sfEvent event)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        handle_event(&event);
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtMouseButtonPressed)
            manage_mouse_click(event.mouseButton);
    }
}
