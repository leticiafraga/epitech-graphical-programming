/*
** EPITECH PROJECT, 2023
** lives utils
** File description:
** lives utils
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/System/Clock.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/hunter.h"

sfText* init_text_lives(sfFont* font)
{
    sfText* text;
    sfVector2f offset = {60, 5};

    if (!font)
        return 0;
    text = sfText_create();
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 40);
    sfText_setPosition(text, offset);
    return text;
}

life *init_life(sfFont *font)
{
    life *l = malloc(sizeof(life));

    l->text_lives = init_text_lives(font);
    l->heart = init_heart();
    l->n = 3;
    return l;
}

spr *init_heart(void)
{
    spr *heart = malloc(sizeof(spr));
    sfVector2f init_sprite = {10, 10};

    heart->texture = sfTexture_createFromFile("assets/heart.png", NULL);
    heart->sprite = new_sprite();
    sfSprite_setTexture(heart->sprite, heart->texture, sfTrue);
    sfSprite_setPosition(heart->sprite, init_sprite);
    return heart;
}

void display_lives(sfRenderWindow *window, life *l)
{
    sfText *text = l->text_lives;
    sfColor color = {0, 0, 0, 255};
    spr *heart = l->heart;
    char *str = my_nbrtostr(l->n);

    sfRenderWindow_drawSprite(window, heart->sprite, NULL);
    sfText_setColor(text, color);
    sfText_setString(text, str);
    free(str);
    sfRenderWindow_drawText(window, text, NULL);
}

void destroy_life(life *l)
{
    destroy_sprite(l->heart);
    sfText_destroy(l->text_lives);
    free(l);
}
