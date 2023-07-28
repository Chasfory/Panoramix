/*
** EPITECH PROJECT, 2023
** pano2
** File description:
** funct_free
*/

#include "panoramix.h"

void funct_free(druid_t druid, villagers_t *villagers,
                info_t info, int nb_villagers)
{
    for (int i = 0; i < nb_villagers; i++) {
        pthread_exit(&villagers[i].thread);
    }
    free(villagers);
    pthread_exit(druid.thread);
    sem_destroy(&info.sem_druid);
    sem_destroy(&info.sem_villager);
}
