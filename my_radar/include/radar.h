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
    sfClock *timer;
    sfFont *font;
    spr *bg;
    airplane **planes;
    tower **towers;
    int plane_cnt;
    int tower_cnt;
    int show_hitbox;
    int show_sprites;
} game_parts;

typedef struct corner {
    sfIntRect area;
    unsigned int nb_circles;
    airplane **circles;
} corner;

game_parts *init_game(file_cnt *cnt);
sfText* init_text(sfFont* font);
spr *init_basic_sprite(const char *filename, int x, int y);
void init_sprite(sfSprite *sprite);
sfSprite *new_sprite(void);

sfIntRect *display_rect_dim(int w, int h);

sound *init_sound(void);
void add_sound(const char *filename);
void play_sound(sound *s);

void render(game_parts *game);
void move_rect(sfIntRect *rect, int offset, int max_value);
void position_rect(sfIntRect *rect, int pos);

int analyse_events(game_parts *game);

void destroy_sprite(spr *spr);
void destroy(game_parts *game, corner **corners);
void close_window(sfRenderWindow* window);

int set_planes_corner(corner **corners, airplane **circles, int n);
corner **init_corners(
    int width, int height, airplane **circles, int n);
void check_collisions(corner **corners, tower **towers, int tower_cnt);

file_cnt *validate_file(char *str);
int handle_file(game_parts *game, char *str, file_cnt* cnt);
char **load_lines(char const *filepath, int nb_rows);

int handle_move_planes(airplane **planes, int n, sfClock *clock,
    sfRenderWindow *window);
sfVector2i get_next_nb(char *str, int i);
void create_plane(game_parts *game, char *str);
void create_tower(game_parts *game, char *str);
float radian_to_degree(float radian);

int is_intersecting_planes(sfRectangleShape *c1, sfRectangleShape *c2);
int is_intersecting_tower(sfRectangleShape *plane, tower *t);

void display_timer(sfRenderWindow *window, sfText* text, sfClock *timer);

int put_error_file(void);
int put_error_file_format(void);
sfVector2i get_next_nb(char *str, int i);
float radian_to_degree(float radian);

#endif
