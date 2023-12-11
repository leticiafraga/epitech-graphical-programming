/*
** EPITECH PROJECT, 2023
** RADAR
** File description:
** RADAR lib header
*/

#ifndef RADAR_H
    #define RADAR_H
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
    int reverse;
} target;

typedef struct sound {
    sfSoundBuffer *buffer;
    sfSound *sound;
} sound;

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

typedef struct corner {
    sfIntRect area;
    unsigned int nb_circles;
    sfCircleShape **circles;
} corner;

game_parts *init_game(void);
target *init_duck(void);
target *init_duck_img(const char *img);
sfText* init_text(sfFont* font);
target **init_menu(void);
spr *init_cursor(game_parts *game);
spr *init_basic_sprite(const char *filename, int x, int y);
void init_sprite(sfSprite *sprite);
sfSprite *new_sprite(void);
void set_rev_target(target *d);
void reinit_target(target *t);

void display_score(sfRenderWindow *window, sfText* text, int score);
sfIntRect *display_rect_dim(int w, int h);
int analyse_events(game_parts *game, target *t);

sound *init_sound(void);
void add_sound(const char *filename);
void play_sound(sound *s);

void render(game_parts *game, target *d);
int render_cursor(game_parts *game, spr *d);
void move_rect(sfIntRect *rect, int offset, int max_value);
void position_rect(sfIntRect *rect, int pos);
int handle_move(target *t, sfIntRect *rect,
    sfClock *clock, int score);
void set_cursor_target(game_parts *game, sfVector2i mouse);

int analyse_menu_events(game_parts *game, target **menu);
int handle_menu(game_parts *game);
void render_menu(game_parts *game, target **menu, spr *bg, spr *title);

void destroy_sprite(spr *spr);
void destroy_target(target *t);
void destroy(game_parts *game);
void close_window(sfRenderWindow* window);


sfCircleShape *create_circle(sfVector2f position, float radius);
int is_intersecting_circles(sfCircleShape *c1, sfCircleShape *c2);
sfCircleShape **init_circles(int n);
void mv_circles(sfCircleShape **circles, int n);
void draw_circles(sfRenderWindow *window, sfCircleShape **circles, int n);
int set_circles_corner(corner **corners, sfCircleShape **circles, int n);
corner **init_corners(
    int width, int height, sfCircleShape **circles, int n);
int handle_move_circles(
    corner **corners, sfCircleShape **circles, sfClock *clock, int n);
void check_collisions(corner **corners);
#endif
