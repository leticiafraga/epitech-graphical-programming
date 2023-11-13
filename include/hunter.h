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

void analyse_events(sfRenderWindow *window, sfEvent event);
void close_window(sfRenderWindow* window);

#endif
