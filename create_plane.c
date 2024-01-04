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

    if ((arrival.x - departure.x) < 0)
        angle += M_PI;
    return angle;
}

static sfVector2f get_offset(airplane *plane)
{
    sfVector2f arrival = plane->arrival;
    sfVector2f departure = plane->departure;
    float angle = plane->angle;
    float speed = plane->speed;
    float hip = speed / 10;
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

static void set_rect(airplane *plane, sfVector2f size)
{
    sfVector2f origin = {13, 13};

    sfRectangleShape_setOrigin(plane->rect, origin);
    sfRectangleShape_setPosition(plane->rect, plane->departure);
    sfRectangleShape_setSize(plane->rect, size);
    sfRectangleShape_setRotation(plane->rect, radian_to_degree(plane->angle));
    sfRectangleShape_setOutlineColor(plane->rect, sfBlack);
    sfRectangleShape_setOutlineThickness(plane->rect, 1);
    sfRectangleShape_setFillColor(plane->rect, sfTransparent);
}

static void set_plane_sprite(airplane *plane)
{
    sfVector2f scale = {0.1, 0.1};
    sfVector2f size = {26, 26};
    sfVector2f origin = {120, 120};

    plane->sprite = sfSprite_create();
    plane->texture = sfTexture_createFromFile("assets/plane.png", NULL);
    plane->rect = sfRectangleShape_create();
    sfSprite_setOrigin(plane->sprite, origin);
    sfSprite_setTexture(plane->sprite, plane->texture, sfFalse);
    sfSprite_setScale(plane->sprite, scale);
    sfSprite_setPosition(plane->sprite, plane->departure);
    sfSprite_setRotation(plane->sprite, radian_to_degree(plane->angle));
    set_rect(plane, size);
}

static void create_struct_plane(game_parts *game, int *info)
{
    airplane *plane = malloc(sizeof(airplane));
    sfVector2f size = {4, 4};

    set_plane_info(plane, info);
    plane->angle = get_angle(plane->arrival, plane->departure);
    plane->offset = get_offset(plane);
    set_plane_sprite(plane);
    plane->arrival_rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(plane->arrival_rect, plane->arrival);
    sfRectangleShape_setSize(plane->arrival_rect, size);
    sfRectangleShape_setOutlineColor(plane->arrival_rect, sfBlack);
    sfRectangleShape_setOutlineThickness(plane->arrival_rect, 1);
    sfRectangleShape_setFillColor(plane->arrival_rect, sfTransparent);
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
