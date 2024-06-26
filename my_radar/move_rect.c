/*
** EPITECH PROJECT, 2023
** move_rect
** File description:
** moves rect
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/radar.h"

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->left += offset;
    if (rect->left >= max_value)
        rect->left = 0;
}

void position_rect(sfIntRect *rect, int pos)
{
    rect->left = pos;
}
