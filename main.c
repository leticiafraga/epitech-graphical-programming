/*
** EPITECH PROJECT, 2023
** CSFML
** File description:
** CSFML exp
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/System/Clock.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/hunter.h"

sfIntRect *display_rect(void)
{
    sfIntRect *rect = malloc(sizeof(sfIntRect));

    rect->top = 0;
    rect->left = 0;
    rect->width = 110;
    rect->height = 110;
    return rect;
}

void destroy(sfSprite *sprite, sfTexture *texture, sfRenderWindow *window)
{
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
    sfRenderWindow_destroy(window);
}

void handle_move(sfIntRect *rect, sfClock *clock)
{
    sfTime time;

    time = sfClock_getElapsedTime(clock);
    if (time.microseconds / 1000000.0 > 0.5) {
        sfClock_restart(clock);
        move_rect(rect, 110, 330);
    }
}

int main(void)
{
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow *window;
    sfIntRect *rect = display_rect();
    sfTexture *texture = sfTexture_createFromFile("assets/duck.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfEvent event;
    sfClock *clock = sfClock_create();

    window = sfRenderWindow_create(mode, "SFML window", sfDefaultStyle, NULL);
    while (sfRenderWindow_isOpen(window)) {
        handle_move(rect, clock);
        sfRenderWindow_clear(window, sfBlack);
        sfSprite_setTexture(sprite, texture, sfTrue);
        sfSprite_setTextureRect(sprite, *rect);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
        analyse_events(window, event);
    }
    destroy(sprite, texture, window);
    return 0;
}
