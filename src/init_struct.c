/*
** EPITECH PROJECT, 2023
** B-CCP-400-PAR-4-1-panoramix-laetitia.bousch
** File description:
** init_struct
*/

#include "panoramix.h"

static void init_struct_villagers(villagers_t *tmp, info_t *info,
                                    int fight, int nb_villagers)
{
    for (int i = 0; i < nb_villagers; i++) {
        tmp[i].id = i;
        tmp[i].info = info;
        tmp[i].nb_fights_max = fight;
        tmp[i].nb_fights = 0;
        tmp[i].status = false;
        pthread_create(&tmp[i].thread, NULL, &funct_villager, &tmp[i]);
    }
}

void init_struct(char **arg, druid_t *druid, info_t *info,
                villagers_t *villagers)
{
    info->pot_popo = atoi(arg[1]);
    info->pot_size = atoi(arg[1]);
    info->villagers_finish = 0;
    info->villagers_max = atoi(arg[0]);
    if (sem_init(&info->sem_druid, 0, 0) != 0)
        return;
    if (sem_init(&info->sem_villager, 0, 0) != 0)
        return;
    if (pthread_mutex_init(&info->mutex_druid, NULL) != 0)
        return;
    if (pthread_mutex_init(&info->mutex_villager, NULL) != 0)
        return;
    druid->info = info;
    druid->nb_refills = atoi(arg[3]);
    pthread_create(&druid->thread, NULL,
    &funct_druid, druid);
    init_struct_villagers(villagers, info, atoi(arg[2]), atoi(arg[0]));
}
