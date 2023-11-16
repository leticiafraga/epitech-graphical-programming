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

void destroy(sfSprite *sprite, sfTexture *texture,
    sfRenderWindow *window, sfIntRect *rect);
void render(sfRenderWindow *window, sfSprite *sprite,
    sfTexture *texture, sfIntRect *rect);
sfText* init_text(void);
sfText *display_score(sfText *text, int score);
int analyse_events(sfRenderWindow *window, sfEvent event, sfSprite *sprite);
void close_window(sfRenderWindow* window);
void move_rect(sfIntRect *rect, int offset, int max_value);
void init_sprite(sfSprite *sprite);
sfSprite *new_sprite(void);

#endif
