/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** init
*/

#include "my_runner.h"
#include "csfml.h"

void init_info(csfml_t *info)
{
    info->clock = malloc(sizeof(my_clock_t));
    info->window = create_window(WINDOW_LEN, WINDOW_HEIGHT);
    sfRenderWindow_setFramerateLimit(info->window, 30);
    info->clock->time_elapsed = sfClock_create();
    info->clock->bg_anim = sfClock_create();
    info->clock->player_anim = sfClock_create();
    info->clock->fireball_as = sfClock_create();
    info->clock->fireball_anim = sfClock_create();
    info->clock->compute_score = sfClock_create();
    info->clock->enemy_anim = sfClock_create();
    info->clock->enemies_spawn = sfClock_create();
    info->clock->xp_spawn = sfClock_create();
    info->clock->xp_anim = sfClock_create();
    info->music = sfMusic_createFromFile("data/code_lyoko_yassir.ogg");
    sfMusic_setLoop(info->music, sfTrue);
    sfMusic_setVolume(info->music, 50);
    sfMusic_play(info->music);
    init_txt(info);
}

sfRenderWindow *create_window(int width, int height)
{
    sfVideoMode video_mode;
    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = 32;

    return (sfRenderWindow_create(video_mode, "my_runner",
                                    sfDefaultStyle, NULL));
}

void init_txt(csfml_t *info)
{
    sfFont *font = sfFont_createFromFile("data/Amatic-Bold.ttf");
    sfVector2f pos;

    pos.x = 20;
    pos.y = 5;
    info->txt = sfText_create();
    sfText_setFont(info->txt, font);
    sfText_setColor(info->txt, sfWhite);
    sfText_setPosition(info->txt, pos);
    sfText_setCharacterSize(info->txt, 50);
}