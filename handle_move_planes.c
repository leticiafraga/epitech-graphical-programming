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

static int move_target(airplane *plane)
{
    float angle = plane->angle;
    float hip = plane->speed / 5;
    sfVector2f pos = sfSprite_getPosition(plane->sprite);

    sfSprite_move(plane->sprite, plane->offset);
    return 0;
}

int handle_move_planes(airplane **planes, int n, sfClock *clock)
{
    sfTime time;
    sfSprite *sprite;
    float seconds;

    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.2) {
        sfClock_restart(clock);
        for (int i = 0; i < n; i ++) {
            move_target(planes[i]);
        }
    }
    return 0;
}
