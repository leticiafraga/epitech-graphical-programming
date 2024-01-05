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

static void check_intersections(airplane *plane1, airplane *plane2)
{
    if (is_intersecting_planes(plane1->rect, plane2->rect) == 1) {
        plane1->state = 2;
        plane2->state = 2;
    }
}

static void check_collisions_planes(airplane **circles, int n)
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            check_intersections(circles[i], circles[j]);
        }
    }
}

void check_collisions(corner **corners)
{
    for (int i = 0; i < 4; i++) {
        check_collisions_planes(corners[i]->circles, corners[i]->nb_circles);
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
