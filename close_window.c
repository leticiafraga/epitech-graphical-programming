/*
** EPITECH PROJECT, 2023
** close_window
** File description:
** close_window
*/
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/hunter.h"
void close_window(sfRenderWindow* window)
{
    sfRenderWindow_close(window);
}
