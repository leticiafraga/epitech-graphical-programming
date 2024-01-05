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
    #include "entities.h"

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
    airplane **planes;
    tower **towers;
    int plane_cnt;
    int tower_cnt;
} game_parts;

typedef struct corner {
    sfIntRect area;
    unsigned int nb_circles;
    airplane **circles;
} corner;

game_parts *init_game(void);
sfText* init_text(sfFont* font);
target **init_menu(void);
spr *init_cursor(game_parts *game);
spr *init_basic_sprite(const char *filename, int x, int y);
void init_sprite(sfSprite *sprite);
sfSprite *new_sprite(void);
void reinit_target(target *t);

sfIntRect *display_rect_dim(int w, int h);

sound *init_sound(void);
void add_sound(const char *filename);
void play_sound(sound *s);

void render(game_parts *game);
int render_cursor(game_parts *game);
void move_rect(sfIntRect *rect, int offset, int max_value);
void position_rect(sfIntRect *rect, int pos);
int handle_move(target *t, sfIntRect *rect,
    sfClock *clock, int score);
void set_cursor_target(game_parts *game, sfVector2i mouse);

int analyse_events(game_parts *game);
int analyse_menu_events(game_parts *game, target **menu);
void render_menu(game_parts *game, target **menu, spr *bg, spr *title);

void destroy_sprite(spr *spr);
void destroy(game_parts *game);
void close_window(sfRenderWindow* window);

sfCircleShape *create_circle(sfVector2f position, float radius);
sfCircleShape **init_circles(int n);
void mv_circles(sfCircleShape **circles, int n);
void draw_circles(sfRenderWindow *window, sfCircleShape **circles, int n);
int set_planes_corner(corner **corners, airplane **circles, int n);
corner **init_corners(
    int width, int height, airplane **circles, int n);
void check_collisions(corner **corners);

int handle_file(game_parts *game, char *str);
char **load_lines(char const *filepath, int nb_rows);

int handle_move_planes(airplane **planes, int n, sfClock *clock);
sfVector2i get_next_nb(char *str, int i);
void create_plane(game_parts *game, char *str);
void create_tower(game_parts *game, char *str);
float radian_to_degree(float radian);
int is_intersecting_planes(sfRectangleShape *c1, sfRectangleShape *c2);
#endif
