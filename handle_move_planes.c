/*
** EPITECH PROJECT, 2023
** handle_move_planes
** File description:
** handle_move_planes
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/System/Clock.h>
#include <stdlib.h>
#include <math.h>
#include "include/my.h"
#include "include/radar.h"

int contains(sfRectangleShape *rect, sfVector2f point)
{
    sfVector2f pos = sfRectangleShape_getPosition(rect);
    sfVector2f size = {30, 30};

    if ((point.x >= pos.x - size.x / 2 && point.x <= pos.x + size.x / 2) &&
        (point.y >= pos.y - size.y / 2 && point.y <= pos.y + size.y / 2))
        return 1;
    return 0;
}

static int move_target(airplane *plane)
{
    float angle = plane->angle;
    float hip = plane->speed / 5;
    sfVector2f pos = sfSprite_getPosition(plane->sprite);

    if (plane->state != 0)
        return 0;
    sfSprite_move(plane->sprite, plane->offset);
    sfRectangleShape_move(plane->rect, plane->offset);
    if (contains(plane->rect, plane->arrival)) {
        plane->state = 1;
    }
    return 1;
}

int handle_move_planes(airplane **planes, int n, sfClock *clock,
    sfRenderWindow *window)
{
    sfTime time;
    sfSprite *sprite;
    float seconds;
    int all_states = 0;

    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.1) {
        sfClock_restart(clock);
        for (int i = 0; i < n; i ++) {
            all_states += move_target(planes[i]);
        }
        if (all_states == 0)
            close_window(window);
    }
    return 0;
}
