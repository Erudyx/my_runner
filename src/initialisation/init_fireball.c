/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** init_fireball
*/

#include "csfml.h"
#include "my_runner.h"
#include "game_parameters.h"

void new_fireball(fireball_t **fireball, sfVector2f *pos)
{
    fireball_t *new = NULL;
    sfSoundBuffer *buffer = NULL;

    if (*fireball == NULL) {
        *fireball = init_fireball(pos);
    } else {
        new = *fireball;
        while (new->next != NULL){
            new = new->next;
        }
        new->next = init_fireball(pos);
    }
    if ((*fireball)->launch != NULL)
        free ((*fireball)->launch);
    (*fireball)->launch = sfSound_create();
    buffer = sfSoundBuffer_createFromFile("data/lauch.wav");
    sfSound_setBuffer((*fireball)->launch, buffer);
    sfSound_play((*fireball)->launch);
}

fireball_t *init_fireball(sfVector2f *pos)
{
    fireball_t *new = malloc(sizeof(fireball_t));

    new->rect = malloc(sizeof(sfIntRect));
    new->pos = malloc(sizeof(sfVector2f));
    new->texture = sfTexture_createFromFile("data/fireball.png",
                                                            NULL);
    new->sprite = sfSprite_create();
    new->rect->height = FIREBALL_HEIGHT;
    new->rect->width = FIREBALL_WIDTH;
    new->rect->left = 0;
    new->rect->top = 0;
    new->pos->x = pos->x;
    new->pos->y = pos->y;
    new->used = false;
    new->next = NULL;
    sfSprite_setTexture(new->sprite, new->texture,
                        sfTrue);
    new->launch = NULL;
    return (new);
}