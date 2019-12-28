/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** xp
*/

#include <math.h>
#include "my_runner.h"
#include "csfml.h"
#include "game_parameters.h"

void spawn_xp(csfml_t *info, xp_t **xp)
{
    sfTime time = sfClock_getElapsedTime(info->clock->xp_spawn);

    if (time.microseconds >= (8000000)) {
        new_xp(xp);
        sfClock_restart(info->clock->xp_spawn);
    }
    if (*xp == NULL)
        return;
    move_xp(xp, info);
}

void move_xp(xp_t **xp,  csfml_t *info)
{
    xp_t *tmp = *xp;
    xp_t *del = *xp;
    sfTime time = sfClock_getElapsedTime(info->clock->xp_anim);

    while (tmp != NULL && time.microseconds > 10000) {
        tmp->pos->x -= (12 * (DIFFICULTY + 1));
        tmp->pos->y += cos(tmp->pos->x / 100) * 12;
        tmp = tmp->next;
    }
    if ((*xp)->pos->x < -135) {
        *xp = (*xp)->next;
        free (del);
    }
    display_xp(info, *xp);
    free (tmp);
    if (time.microseconds > 10000)
        sfClock_restart(info->clock->xp_anim);
}

void display_xp(csfml_t *info, xp_t *xp)
{
    xp_t *tmp = xp;

    while (tmp != NULL) {
        sfSprite_setPosition(tmp->sprite, *tmp->pos);
        sfRenderWindow_drawSprite(info->window, tmp->sprite, NULL);
        tmp = tmp->next;
    }
    free (tmp);
}