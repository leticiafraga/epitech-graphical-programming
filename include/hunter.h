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

typedef struct target {
    sfIntRect *rect;
    sfTexture *texture;
    sfSprite *sprite;
} target;

void destroy(game_parts *game, target *d);
void render(game_parts *game, target *d);
game_parts *init_game(void);
target *init_duck(void);
sfText* init_text(void);
target *init_menu(void);
sfText *display_score(sfText *text, int score);
int analyse_events(game_parts *game, sfSprite *sprite);
int analyse_menu_events(game_parts *game, target *menu);
void render_menu(sfRenderWindow *window, target *d);
void close_window(sfRenderWindow* window);
void move_rect(sfIntRect *rect, int offset, int max_value);
target *init_cursor(game_parts *game);
void init_sprite(sfSprite *sprite);
sfSprite *new_sprite(void);

#endif
