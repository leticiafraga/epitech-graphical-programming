/*
** EPITECH PROJECT, 2023
** RENDER
** File description:
** RENDER
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/System/Clock.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/hunter.h"

void destroy(sfSprite *sprite, sfTexture *texture, sfRenderWindow *window)
{
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
    sfRenderWindow_destroy(window);
}

void render(sfRenderWindow *window, sfSprite *sprite,
    sfTexture *texture, sfIntRect *rect)
{
    sfRenderWindow_clear(window, sfBlue);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTextureRect(sprite, *rect);
    sfRenderWindow_drawSprite(window, sprite, NULL);
}

sfSprite *init_sprite(void)
{
    sfSprite *sprite = sfSprite_create();
    sfVector2f init_sprite = {-50, rand() % 500};

    sfSprite_setPosition(sprite, init_sprite);
    return sprite;
}
