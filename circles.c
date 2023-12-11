/*
** EPITECH PROJECT, 2023
** MY_RADAR
** File description:
** MY_RADAR
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/System/Clock.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/radar.h"

static void check_collisions_circles(sfCircleShape **circles, int n)
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (is_intersecting_circles(circles[i], circles[j]) == 1) {
                sfCircleShape_setFillColor(circles[i], sfWhite);
                sfCircleShape_setFillColor(circles[j], sfWhite);
            }
        }
    }
}

void check_collisions(corner **corners)
{
    for (int i = 0; i < 4; i++) {
        check_collisions_circles(corners[i]->circles, corners[i]->nb_circles);
    }
}

sfCircleShape **init_circles(int n)
{
    sfCircleShape **all_circles = malloc(sizeof(sfCircleShape *) * n);
    sfVector2f position;

    for (int i = 0; i < n; i++) {
        position.x = rand() % 1900;
        position.y = rand() % 1080;
        all_circles[i] = create_circle(position, 10);
    }
    return all_circles;
}

void mv_circles(sfCircleShape **circles, int n)
{
    sfVector2f offset;

    for (int i = 0; i < n; i++) {
        offset.x += (rand() % 3) - 1;
        offset.y += (rand() % 3) - 1;
        sfCircleShape_move(circles[i], offset);
        sfCircleShape_setFillColor(circles[i], sfTransparent);
    }
}

void draw_circles(sfRenderWindow *window, sfCircleShape **circles, int n)
{
    for (int i = 0; i < n; i++) {
        sfRenderWindow_drawCircleShape(window, circles[i], NULL);
    }
    sfRenderWindow_display(window);
}

int handle_move_circles(
    corner **corners, sfCircleShape **circles, sfClock *clock, int n)
{
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.1) {
        sfClock_restart(clock);
        mv_circles(circles, n);
        set_circles_corner(corners, circles, n);
        check_collisions(corners);
    }
    return 0;
}
