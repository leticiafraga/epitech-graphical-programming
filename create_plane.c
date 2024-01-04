/*
** EPITECH PROJECT, 2023
** main fns
** File description:
** main fns
*/
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include "include/my.h"
#include "include/radar.h"

static float get_angle(sfVector2f arrival, sfVector2f departure)
{
    float tan = ((arrival.y - departure.y) / (arrival.x - departure.x));
    float angle = atan(tan);

    if (sin(angle) < 0)
        angle += M_PI;
    return angle;
}

static sfVector2f get_offset(airplane *plane)
{
    sfVector2f arrival = plane->arrival;
    sfVector2f departure = plane->departure;
    float angle = plane->angle;
    float speed = plane->speed;
    float hip = speed / 5;
    float sy = sin(angle) * hip;
    float sx = cos(angle) * hip;
    sfVector2f offset = {sx, sy};

    return offset;
}

static void set_plane_info(airplane *plane, int *info)
{
    plane->departure.x = info[0];
    plane->departure.y = info[1];
    plane->arrival.x = info[2];
    plane->arrival.y = info[3];
    plane->speed = info[4];
    plane->delay = info[5];
}

static void set_plane_sprite(airplane *plane)
{
    sfVector2f scale = {0.1, 0.1};

    plane->sprite = sfSprite_create();
    plane->texture = sfTexture_createFromFile("assets/plane.png", NULL);
    sfSprite_setTexture(plane->sprite, plane->texture, sfFalse);
    sfSprite_setScale(plane->sprite, scale);
    sfSprite_setPosition(plane->sprite, plane->departure);
    sfSprite_setRotation(plane->sprite, radian_to_degree(plane->angle));
}

static void create_struct_plane(game_parts *game, int *info)
{
    airplane *plane = malloc(sizeof(airplane));

    set_plane_info(plane, info);
    plane->angle = get_angle(plane->arrival, plane->departure);
    plane->offset = get_offset(plane);
    set_plane_sprite(plane);
    game->planes[game->plane_cnt] = plane;
    game->plane_cnt += 1;
}

void create_plane(game_parts *game, char *str)
{
    sfVector2i result;
    int i = 0;
    int it = 0;
    int info[10];

    while (str[i] != '\0') {
        if (is_number(str[i])) {
            result = get_next_nb(str, i);
            i = result.x;
            info[it] = result.y;
            it++;
        } else
            i++;
    }
    create_struct_plane(game, info);
}
