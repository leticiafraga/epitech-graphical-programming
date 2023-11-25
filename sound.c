/*
** EPITECH PROJECT, 2023
** sound
** File description:
** sound
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/hunter.h"

sound *init_sound(void)
{
    sound *s = malloc(sizeof(sound));

    s->buffer = sfSoundBuffer_createFromFile("assets/quack.wav");
    s->sound = sfSound_create();
    if (s->buffer) {
        sfSound_setBuffer(s->sound, s->buffer);
    }
    return s;
}

void destroy_sound(sound *s)
{
    free(s);
}

void play_sound(sound *s)
{
    if (s->sound)
        sfSound_play(s->sound);
}

void add_sound(const char *filename)
{
    sfSoundBuffer *buffer = sfSoundBuffer_createFromFile(filename);
    sfSound *sound = sfSound_create();

    if (buffer) {
        sfSound_setBuffer(sound, buffer);
        if (sound)
            sfSound_play(sound);
    }
}
