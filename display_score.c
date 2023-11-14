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

sfText *display_score(int score)
{
    sfFont* font;
    sfText* text;
    sfVector2f offset = {700, 0};
    char *str = my_nbrtostr(score);

    font = sfFont_createFromFile("arial.ttf");
    if (!font)
        return 0;
    text = sfText_create();
    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 50);
    sfText_setPosition(text, offset);
    free(str);
    return text;
}
