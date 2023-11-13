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

sfIntRect **display_rect(void)
{
    sfIntRect **rect = malloc(sizeof(sfIntRect *));

    rect[0] = malloc(sizeof(sfIntRect));
    rect[1] = malloc(sizeof(sfIntRect));
    rect[0]->top = 0;
    rect[0]->left = 0;
    rect[0]->width = 110;
    rect[0]->height = 110;
    rect[1]->top = 0;
    rect[1]->left = 0;
    rect[1]->width = 110;
    rect[1]->height = 110;
    return rect;
}

void destroy(sfSprite *sprite, sfTexture *texture, sfRenderWindow *window)
{
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
    sfRenderWindow_destroy(window);
}

void handle_move(sfSprite *sprite, sfIntRect *rect, sfClock *clock)
{
    sfTime time;
    sfVector2f offset = {5, 0};

    time = sfClock_getElapsedTime(clock);
    if (time.microseconds / 1000000.0 > 0.5) {
        sfClock_restart(clock);
        move_rect(rect, 110, 330);
        sfSprite_move(sprite, offset);
    }
}

int main(void)
{
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow *window;
    sfIntRect **rect = display_rect();
    sfTexture *texture = sfTexture_createFromFile("assets/duck.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfEvent event;
    sfClock *clock = sfClock_create();

    window = sfRenderWindow_create(mode, "ducks", sfDefaultStyle, NULL);
    while (sfRenderWindow_isOpen(window)) {
        handle_move(sprite, rect[0], clock);
        sfRenderWindow_clear(window, sfBlack);
        sfSprite_setTexture(sprite, texture, sfTrue);
        sfSprite_setTextureRect(sprite, *rect[0]);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
        analyse_events(window, event, sprite);
    }
    destroy(sprite, texture, window);
    return 0;
}
