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

    font = sfFont_createFromFile("arial.ttf");
    if (!font)
        return 0;
    text = sfText_create();
    sfText_setString(text, my_nbrtostr(score));
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 50);
    sfText_setPosition(text, offset);
    return text;
}
