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
#include "include/radar.h"

sfText* init_text(sfFont* font)
{
    sfText* text;
    sfVector2f offset = {1700, 0};
    sfColor color = {0, 0, 0, 200};

    if (!font)
        return 0;
    text = sfText_create();
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 40);
    sfText_setPosition(text, offset);
    sfText_setColor(text, color);
    return text;
}

void display_timer(sfRenderWindow *window, sfText* text, sfClock *timer)
{
    sfTime time;
    sfSprite *sprite;
    float seconds;
    int all_states = 0;
    char *str;

    time = sfClock_getElapsedTime(timer);
    seconds = time.microseconds / 1000000.0;
    str = my_getfloat(seconds, 2);
    sfText_setString(text, str);
    free(str);
    sfRenderWindow_drawText(window, text, NULL);
}
