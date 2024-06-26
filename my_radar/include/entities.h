/*
** EPITECH PROJECT, 2023
** ENTITIES_H
** File description:
** RADAR lib header
*/

#ifndef ENTITIES_H
    #define ENTITIES_H
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <stdlib.h>

typedef struct airplane {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f departure;
    sfVector2f arrival;
    int speed;
    int delay;
    float angle;
    sfVector2f offset;
    sfRectangleShape *rect;
    int state;
} airplane;

typedef struct tower {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f coordinates;
    int radius;
    sfCircleShape *circle;
} tower;

typedef struct file_cnt {
    int plane_cnt;
    int tower_cnt;
} file_cnt;

#endif
