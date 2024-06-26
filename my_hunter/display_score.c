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

sfText* init_text(sfFont* font)
{
    sfText* text;
    sfVector2f offset = {700, 0};
    sfColor color = {0, 0, 0, 255};

    if (!font)
        return 0;
    text = sfText_create();
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 40);
    sfText_setPosition(text, offset);
    sfText_setColor(text, color);
    return text;
}

void display_score(sfRenderWindow *window, sfText* text, int score)
{
    char *str = my_nbrtostr(score);

    sfText_setString(text, str);
    free(str);
    sfRenderWindow_drawText(window, text, NULL);
}
