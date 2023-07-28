/*
** EPITECH PROJECT, 2023
** B-CCP-400-PAR-4-1-panoramix-laetitia.bousch
** File description:
** funct_verif
*/

#include "panoramix.h"

bool funct_verifie_numbers(char **av, int ac)
{
    long nbr = 0;
    char *end = NULL;

    for (int i = 0; i < ac; i++) {
        nbr = strtoul(av[i], &end, 10);
        if (strcmp(end, "") != 0) {
            dprintf(2, "USAGE: ./panoramix <nb_villagers> <pot_size> " \
            "<nb_fights> <nb_refills>\n\tValue isn't number %s\n", av[i]);
            return false;
        }
        if (nbr <= 0) {
            dprintf(2, "USAGE: ./panoramix <nb_villagers> <pot_size> " \
            "<nb_fights> <nb_refills>\n\tValue must be %s > 0\n", av[i]);
            return false;
        }
    }
    return true;
}
