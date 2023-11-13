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

void handle_move(sfSprite *sprite, sfIntRect *rect, sfClock *clock, int score)
{
    sfTime time;
    sfVector2f offset = {10 + score, 0};
    float seconds;

    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.2) {
        sfClock_restart(clock);
        move_rect(rect, 110, 330);
        sfSprite_move(sprite, offset);
    }
}

int main(void)
{
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow *window;
    sfIntRect *rect = display_rect();
    sfTexture *texture = sfTexture_createFromFile("assets/duck.png", NULL);
    sfSprite *sprite = init_sprite();
    sfEvent event;
    sfClock *clock = sfClock_create();
    int score = 0;

    window = sfRenderWindow_create(mode, "ducks", sfDefaultStyle, NULL);
    while (sfRenderWindow_isOpen(window)) {
        handle_move(sprite, rect, clock, score);
        render(window, sprite, texture, rect);
        sfRenderWindow_drawText(window, display_score(score), NULL);
        sfRenderWindow_display(window);
        score += analyse_events(window, event, sprite);
    }
    destroy(sprite, texture, window);
    return 0;
}
