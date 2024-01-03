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

int is_intersecting_circles(sfCircleShape *c1, sfCircleShape *c2)
{
    sfVector2f p1 = sfCircleShape_getPosition(c1);
    sfVector2f p2 = sfCircleShape_getPosition(c2);
    float dist_sq = to_square(
        (sfCircleShape_getRadius(c1) + sfCircleShape_getRadius(c2)));
    sfVector2f center1 = {
        p1.x + sfCircleShape_getRadius(c1),
        p1.y + sfCircleShape_getRadius(c1)
    };
    sfVector2f center2 = {
        p2.x + sfCircleShape_getRadius(c2),
        p2.y + sfCircleShape_getRadius(c2)
    };
    float x = to_square(center1.x - center2.x);
    float y = to_square(center1.y - center2.y);

    if ((x + y) <= dist_sq)
        return 1;
    return 0;
}
