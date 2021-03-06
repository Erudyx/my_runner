/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** special_case
*/

#include "my_runner.h"

int special_case(char *arg)
{
    char *msg = "Arguments possible:"
    "\n\t-i           -> infinite mode\n\t-h / --help  -> display this help"
    "\n\nCommands:\n\n\tspace: fly\n\tE: attack\n\nHave a good time!\n";

    if (my_strcmp(arg, "-h") == 1 || my_strcmp(arg, "--help") == 1) {
        my_putstr("Welcome to the Dark Forest Rush!\n\n");
        my_putstr(msg);
    } else if (my_strcmp(arg, "-i") == 1)
        return (core_infinite());
    if (my_strcmp(arg, "spawn_pattern") == 1)
        return (core(arg));
    else {
        my_putstr("Wrong token\n\n");
        my_putstr(msg);
    }
    return (ERROR);
}