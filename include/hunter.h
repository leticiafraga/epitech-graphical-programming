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

typedef struct game_parts {
    sfVideoMode mode;
    sfRenderWindow *window;
    sfEvent event;
    sfClock *clock;
} game_parts;

typedef struct duck {
    sfIntRect *rect;
    sfTexture *texture;
    sfSprite *sprite;
} duck;

void destroy(game_parts *game, duck *d);
void render(sfRenderWindow *window, duck *d);
game_parts *init_game(void);
duck *init_duck(void);
sfText* init_text(void);
sfText *display_score(sfText *text, int score);
int analyse_events(sfRenderWindow *window, sfEvent event, sfSprite *sprite);
void close_window(sfRenderWindow* window);
void move_rect(sfIntRect *rect, int offset, int max_value);
void init_sprite(sfSprite *sprite);
sfSprite *new_sprite(void);

#endif
