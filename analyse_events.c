/*
** EPITECH PROJECT, 2023
** analyse_events
** File description:
** analyses events
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/hunter.h"

static void add_sound(void)
{
    sfSoundBuffer *buffer = sfSoundBuffer_createFromFile("assets/quack.wav");
    sfSound *sound = sfSound_create();

    if (buffer) {
        sfSound_setBuffer(sound, buffer);
        if (sound)
            sfSound_play(sound);
    }
}

int manage_mouse_click(sfMouseButtonEvent event, sfSprite *sprite)
{
    sfFloatRect pos = sfSprite_getGlobalBounds(sprite);

    if (sfFloatRect_contains(&pos, event.x, event.y) == sfTrue) {
        init_sprite(sprite);
        add_sound();
        return 1;
    }
    return 0;
}

int analyse_events(game_parts *game, sfSprite *sprite)
{
    while (sfRenderWindow_pollEvent(game->window, &(game->event))) {
        if (game->event.type == sfEvtClosed)
            close_window(game->window);
        if (game->event.type == sfEvtMouseButtonPressed)
            return manage_mouse_click(game->event.mouseButton, sprite);
    }
    return 0;
}

int manage_menu_click(sfMouseButtonEvent event, target **menu)
{
    sfFloatRect pos;

    for (int i = 0; i < 2; i++) {
        pos = sfSprite_getGlobalBounds(menu[i]->sprite);
        if (sfFloatRect_contains(&pos, event.x, event.y) == sfTrue) {
            return i + 1;
        }
    }
    return 0;
}

int analyse_menu_events(game_parts *game, target **menu)
{
    while (sfRenderWindow_pollEvent(game->window, &(game->event))) {
        if (game->event.type == sfEvtClosed)
            close_window(game->window);
        if (game->event.type == sfEvtMouseButtonPressed)
            return manage_menu_click(game->event.mouseButton, menu);
    }
    return 0;
}
