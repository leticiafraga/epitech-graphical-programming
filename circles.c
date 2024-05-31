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

static void check_intersections(
    airplane *plane1, airplane *plane2, tower **towers, int tower_cnt)
{
    for (int i = 0; i < tower_cnt; i++) {
        if (is_intersecting_tower(plane1->rect, towers[i]) ||
            is_intersecting_tower(plane2->rect, towers[i]))
            return;
    }
    if (is_intersecting_planes(plane1->rect, plane2->rect) == 1) {
        plane1->state = 2;
        plane2->state = 2;
    }
}

static void check_collisions_planes(
    airplane **circles, int n, tower **towers, int tower_cnt)
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            check_intersections(circles[i], circles[j],
                towers, tower_cnt);
        }
    }
}

void check_collisions(corner **corners, tower **towers, int tower_cnt)
{
    for (int i = 0; i < 4; i++) {
        check_collisions_planes(corners[i]->circles, corners[i]->nb_circles,
            towers, tower_cnt);
    }
}
