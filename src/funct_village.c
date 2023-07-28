/*
** EPITECH PROJECT, 2023
** B-CCP-400-PAR-4-1-panoramix-laetitia.bousch
** File description:
** funct_village
*/

#include "panoramix.h"

int funct_village(char **arg, int ac)
{
    druid_t druid;
    villagers_t *villagers = malloc(sizeof(villagers_t) * atoi(arg[0]));
    info_t info;

    if (villagers == NULL) {
        return 84;
    }
    if (funct_verifie_numbers(arg, ac) == false) {
        return 84;
    }
    init_struct(arg, &druid, &info, villagers);
    pthread_join(druid.thread, NULL);
    for (int i = 0; i < atoi(arg[0]); i++) {
        pthread_join(villagers[i].thread, NULL);
    }
    funct_free(druid, villagers, info, atoi(arg[0]));
    return 0;
}
