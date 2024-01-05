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

sfColor colors[4] = {
    {255, 0, 0, 255},
    {0, 255, 0, 255},
    {0, 0, 255, 255},
    {255, 255, 0, 255},
};

int is_intersecting_corners(sfIntRect c1, sfRectangleShape *c2)
{
    sfVector2f size1 = {c1.width, c1.height};
    sfVector2f size2 = sfRectangleShape_getSize(c2);
    sfVector2f p1 = {c1.left, c1.top};
    sfVector2f p2 = sfRectangleShape_getPosition(c2);
    sfVector2f actual1 = p1;
    sfVector2f actual2 = {p2.x - (size2.x / 2), p2.y - (size2.y / 2)};
    int collision_x = (actual1.x + size1.x) >= actual2.x &&
        (actual2.x + size2.x) >= actual1.x;
    int collision_y = (actual1.y + size1.y) >= actual2.y &&
        (actual2.y + size2.y) >= actual1.y;

    return collision_x && collision_y;
}

static void init_first_corner(corner **corners,
    airplane **circles, int n)
{
    for (int i = 0; i < n; i++)
        corners[0]->circles[i] = circles[i];
    corners[0]->nb_circles = n;
}

corner **init_corners(
    int width, int height, airplane **circles, int n)
{
    corner **corners = malloc(sizeof(corner *) * 4);
    int wstep = width / 2;
    int hstep = height / 2;
    sfIntRect rect = {0, 0, wstep, hstep};

    for (int i = 0; i < 4; i++) {
        corners[i] = malloc(sizeof(corner));
        corners[i]->area = rect;
        corners[i]->circles = malloc(sizeof(airplane *) * n);
        rect.left += wstep;
        if (rect.left >= width) {
            rect.left = 0;
            rect.top += hstep;
        }
        corners[i]->nb_circles = 0;
    }
    init_first_corner(corners, circles, n);
    return corners;
}

static void it_corners(
    corner **corners, airplane *circle, sfVector2f center)
{
    for (int j = 0; j < 4; j++) {
        if (is_intersecting_corners(corners[j]->area, circle->rect)) {
            corners[j]->circles[corners[j]->nb_circles] = circle;
            corners[j]->nb_circles ++;
        }
    }
}

int set_circles_corner(corner **corners, airplane **planes, int n)
{
    sfVector2f pos;

    for (int i = 0; i < 4; i++) {
        corners[i]->nb_circles = 0;
    }
    for (int i = 0; i < n; i++) {
        if (planes[i]->state == 0) {
            pos = sfRectangleShape_getPosition(planes[i]->rect);
            it_corners(corners, planes[i], pos);
        }
    }
}
