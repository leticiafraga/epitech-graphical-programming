/*
** EPITECH PROJECT, 2023
** is_intersecting_circles
** File description:
** is_intersecting_circles
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <math.h>
#include "include/my.h"
#include "include/radar.h"

float to_square(float n)
{
    return n * n;
}

int is_intersecting_tower(sfRectangleShape *plane, tower *t)
{
    sfVector2f pos = sfRectangleShape_getPosition(plane);
    sfVector2f distance = {to_square(pos.x - t->coordinates.x),
        to_square(pos.y - t->coordinates.y)};
    float radius_sq = to_square(t->radius);

    return distance.x < radius_sq && distance.y < radius_sq;
}

int is_intersecting_planes(sfRectangleShape *c1, sfRectangleShape *c2)
{
    sfVector2f size1 = sfRectangleShape_getSize(c1);
    sfVector2f size2 = sfRectangleShape_getSize(c2);
    sfVector2f p1 = sfRectangleShape_getPosition(c1);
    sfVector2f p2 = sfRectangleShape_getPosition(c2);
    sfVector2f actual1 = {p1.x - (size1.x / 2), p1.y - (size1.y / 2)};
    sfVector2f actual2 = {p2.x - (size2.x / 2), p2.y - (size2.y / 2)};
    int collision_x = (actual1.x + size1.x) >= actual2.x &&
        (actual2.x + size2.x) >= actual1.x;
    int collision_y = (actual1.y + size1.y) >= actual2.y &&
        (actual2.y + size2.y) >= actual1.y;

    return collision_x && collision_y;
}
