/*
** EPITECH PROJECT, 2023
** pano2
** File description:
** funct_druid
*/

#include "panoramix.h"

void *funct_druid(druid_t *arg)
{
    printf("Druid: I'm ready... but sleepy...\n");
    while ((arg->nb_refills > 0)) {
        if (arg->info->villagers_finish == arg->info->villagers_max) {
            break;
        }
        sem_wait(&arg->info->sem_druid);
        pthread_mutex_lock(&arg->info->mutex_druid);
        arg->info->pot_popo = arg->info->pot_size;
        arg->nb_refills -= 1;
        printf("Druid: Ah! Yes, yes, I'm awake! Working on it! Beware I can" \
        " only make %d more refills after this one.\n", arg->nb_refills);
        sem_post(&arg->info->sem_villager);
        pthread_mutex_unlock(&arg->info->mutex_druid);
    }
    if (arg->nb_refills == 0) {
        printf("Druid: I'm out of viscum. I'm going back to... zZz\n");
    }
    return NULL;
}
