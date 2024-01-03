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
    sfVector2i *departure;
    sfVector2i *arrival;
    int speed;
    int delay;
} airplane;

typedef struct tower {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2i *coordinates;
    int radius;
} tower;

#endif