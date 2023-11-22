/*
** EPITECH PROJECT, 2023
** lives utils
** File description:
** lives utils
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/System/Clock.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/hunter.h"

life *init_life(sfFont *font)
{
    life *l = malloc(sizeof(life));

    l->text_lives = init_text_lives(font);
    l->heart = init_heart();
    l->n = 3;
    return l;
}

void destroy_life(life *l)
{
    destroy_sprite(l->heart);
    sfText_destroy(l->text_lives);
    free(l);
}
