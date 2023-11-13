/*
** EPITECH PROJECT, 2023
** HUNTER
** File description:
** HUNTER lib header
*/

#ifndef HUNTER_H
    #define HUNTER_H
    #include <SFML/Graphics.h>
    #include <stdlib.h>

void analyse_events(sfRenderWindow *window, sfEvent event, sfSprite *sprite);
void close_window(sfRenderWindow* window);
void move_rect(sfIntRect *rect, int offset, int max_value);

#endif
