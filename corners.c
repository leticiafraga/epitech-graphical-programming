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

static void init_first_corner(corner **corners,
    sfCircleShape **circles, int n)
{
    for (int i = 0; i < n; i++)
        corners[0]->circles[i] = circles[i];
    corners[0]->nb_circles = n;
}

corner **init_corners(
    int width, int height, sfCircleShape **circles, int n)
{
    corner **corners = malloc(sizeof(corner *) * 4);
    int wstep = width / 2;
    int hstep = height / 2;
    sfIntRect rect = {0, 0, wstep, hstep};

    for (int i = 0; i < 4; i++) {
        corners[i] = malloc(sizeof(corner));
        corners[i]->area = rect;
        corners[i]->circles = malloc(sizeof(sfCircleShape *) * n);
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
    corner **corners, sfCircleShape *circle, sfVector2f center)
{
    sfVector2f pos = sfCircleShape_getPosition(circle);
    float r = sfCircleShape_getRadius(circle);
    sfIntRect query = {pos.x, pos.y, r * 2, r * 2};

    for (int j = 0; j < 4; j++) {
        if (sfIntRect_intersects(&(corners[j]->area), &query, NULL)) {
            corners[j]->circles[corners[j]->nb_circles] = circle;
            corners[j]->nb_circles ++;
            sfCircleShape_setOutlineColor(circle, colors[j]);
        }
    }
}

int set_circles_corner(corner **corners, sfCircleShape **circles, int n)
{
    sfVector2f p1;
    sfVector2f center;

    for (int i = 0; i < 4; i++) {
        corners[i]->nb_circles = 0;
    }
    for (int i = 0; i < n; i++) {
        p1 = sfCircleShape_getPosition(circles[i]);
        center.x = p1.x + sfCircleShape_getRadius(circles[i]);
        center.y = p1.y + sfCircleShape_getRadius(circles[i]);
        it_corners(corners, circles[i], center);
    }
}
