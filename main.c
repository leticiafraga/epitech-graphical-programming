/*
** EPITECH PROJECT, 2023
** CSFML
** File description:
** CSFML exp
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/hunter.h"

sfUint8 *create_pixels(void)
{
    int n = 800 * 600 * 4;
    sfUint8 *pixels = malloc(800 * 600 * 32 / 8);

    for (int i = 0; i < n; i += 4) {
        pixels[i] = (i / 100) % 255;
        pixels[i + 1] = 50;
        pixels[i + 2] = 0;
        pixels[i + 3] = 255;
    }
    return pixels;
}

void destroy(sfSprite* sprite, sfTexture* texture, sfRenderWindow* window)
{
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
    sfRenderWindow_destroy(window);
}

int main(void)
{
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow* window;
    sfUint8 *pixels = create_pixels();
    sfTexture* texture;
    sfSprite* sprite;
    sfEvent event;

    texture = sfTexture_create(800, 600);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    window = sfRenderWindow_create(mode, "SFML window", sfDefaultStyle, NULL);
    while (sfRenderWindow_isOpen(window)) {
        sfTexture_updateFromPixels(texture, pixels, 800, 600, 0, 0);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
        analyse_events(window, event);
    }
    destroy(sprite, texture, window);
    return 0;
}
