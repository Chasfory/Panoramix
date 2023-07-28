/*
** EPITECH PROJECT, 2023
** B-CCP-400-PAR-4-1-panoramix-laetitia.bousch
** File description:
** main
*/

#include "panoramix.h"

int main(int ac, char **av)
{
    if (ac == 2) {
        if (strcmp(av[1], "-h") == 0 || strcmp(av[1], "-help") == 0) {
            funct_help();
            return 0;
        }
    } else if (ac == 5) {
        return funct_village(&av[1], (ac - 1));
    }
    dprintf(2, "USAGE: ./panoramix <nb_villagers> <pot_size> <nb_fights> " \
    "<nb_refills>\n");
    return 84;
}
