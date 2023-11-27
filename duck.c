/*
** EPITECH PROJECT, 2023
** init
** File description:
** init
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/System/Clock.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/hunter.h"

sfIntRect *display_rect_dim(int w, int h)
{
    sfIntRect *rect = malloc(sizeof(sfIntRect));

    rect->top = 0;
    rect->left = 0;
    rect->width = w;
    rect->height = h;
    return rect;
}

static sfIntRect *display_rect(void)
{
    return display_rect_dim(110, 110);
}

target *init_duck(void)
{
    return init_duck_img("assets/duck.png");
}

target *init_duck_img(const char *img)
{
    target *d = malloc(sizeof(target));

    d->rect = display_rect();
    d->texture = sfTexture_createFromFile(img, NULL);
    d->sprite = new_sprite();
    return d;
}
