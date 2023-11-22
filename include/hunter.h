/*
** EPITECH PROJECT, 2023
** HUNTER
** File description:
** HUNTER lib header
*/

#ifndef HUNTER_H
    #define HUNTER_H
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <stdlib.h>

typedef struct game_parts {
    sfVideoMode mode;
    sfRenderWindow *window;
    sfEvent event;
    sfClock *clock;
    sfFont *font;
} game_parts;

typedef struct spr {
    sfTexture *texture;
    sfSprite *sprite;
} spr;

typedef struct target {
    sfIntRect *rect;
    sfTexture *texture;
    sfSprite *sprite;
} target;

typedef struct life {
    sfText *text_lives;
    spr *heart;
    int n;
} life;

void destroy(game_parts *game);
void render(game_parts *game, target *d);
game_parts *init_game(void);
target *init_duck(void);
sfText* init_text(sfFont* font);
sfText* init_text_lives(sfFont* font);
spr *init_heart(void);
spr *init_menu(void);
life *init_life(sfFont *font);
void display_score(sfRenderWindow *window, sfText* text, int score);
void display_lives(sfRenderWindow *window,
    sfText *text, int score, spr *heart);
int analyse_events(game_parts *game, sfSprite *sprite);
int analyse_menu_events(game_parts *game, spr *menu);
void render_menu(sfRenderWindow *window, spr *d);
void close_window(sfRenderWindow* window);
void move_rect(sfIntRect *rect, int offset, int max_value);
spr *init_cursor(game_parts *game);
void init_sprite(sfSprite *sprite);
sfSprite *new_sprite(void);
void destroy_sprite(spr *spr);
void destroy_target(target *t);
void destroy_life(life *l);
void render_cursor(game_parts *game, spr *d);
#endif
