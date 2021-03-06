/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** core_infinite
*/

#include "my_runner.h"
#include "csfml.h"

int core_infinite(void)
{
    csfml_t info;
    obj_t obj;
    background_t bg;
    int status = 0;

    load_parameters(&info);
    if (main_menu(info.params, true) == CLOSE)
        return (CLOSE);
    init_info(&info);
    init_background(&bg);
    init_obj(&obj);
    status = game_infinite(&info, &obj, &bg);
    free_all(&info, &obj, &bg);
    save_game(info.params);
    return (status);
}

int game_infinite(csfml_t *info, obj_t *obj, background_t *bg)
{
    int status = 0;

    while (sfRenderWindow_isOpen(info->window) && status == 0) {
        sfRenderWindow_pollEvent(info->window, &info->my_event);
        status = run_game_infinite(info, obj, bg);
        if (info->my_event.type == sfEvtClosed)
            status = CLOSE;
    }
    return (status);
}

int run_game_infinite(csfml_t *info, obj_t *obj, background_t *bg)
{
    anim_bg(info, bg);
    gest_player(info, obj->player);
    spawn_enemies(info, &obj->enemy);
    spawn_xp(info, &obj->xp);
    collision(info, obj);
    scale_score_infinite(info, obj->player);
    sfRenderWindow_display(info->window);
    if (obj->player->health->hp == 0)
        return (LOSE);
    return (0);
}