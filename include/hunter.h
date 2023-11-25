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

typedef struct spr {
    sfTexture *texture;
    sfSprite *sprite;
} spr;

typedef struct target {
    sfIntRect *rect;
    sfTexture *texture;
    sfSprite *sprite;
} target;

typedef struct sound {
    sfSoundBuffer *buffer;
    sfSound *sound;
} sound;

typedef struct life {
    sfText *text_lives;
    spr *heart;
    int n;
} life;

typedef struct game_parts {
    sfVideoMode mode;
    sfRenderWindow *window;
    sfEvent event;
    sfClock *clock;
    sfFont *font;
    spr *bg;
    target *t;
    sound *s;
} game_parts;

game_parts *init_game(void);
target *init_duck(void);
target *init_duck_img(const char *img);
sfText* init_text(sfFont* font);
sfText* init_text_lives(sfFont* font);
spr *init_heart(void);
target **init_menu(void);
life *init_life(sfFont *font);
spr *init_cursor(game_parts *game);
spr *init_basic_sprite(const char *filename, int x, int y);
void init_sprite(sfSprite *sprite);
sfSprite *new_sprite(void);

void display_score(sfRenderWindow *window, sfText* text, int score);
void display_lives(sfRenderWindow *window, life *l);
int analyse_events(game_parts *game, sfSprite *sprite);

sound *init_sound(void);
void add_sound(const char *filename);
void play_sound(sound *s);

void render(game_parts *game, target *d);
int render_cursor(game_parts *game, spr *d);
void move_rect(sfIntRect *rect, int offset, int max_value);
void position_rect(sfIntRect *rect, int pos);
int handle_move(sfSprite *sprite, sfIntRect *rect,
    sfClock *clock, int score);
void set_cursor_target(game_parts *game, sfVector2i mouse);

int analyse_menu_events(game_parts *game, target **menu);
int handle_menu(game_parts *game);
void render_menu(game_parts *game, target **menu, spr *bg);
int handle_options(game_parts *game);

void destroy_sprite(spr *spr);
void destroy_target(target *t);
void destroy_life(life *l);
void destroy(game_parts *game);
void close_window(sfRenderWindow* window);
#endif
