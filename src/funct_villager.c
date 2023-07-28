/*
** EPITECH PROJECT, 2023
** pano2
** File description:
** funct_villager
*/

#include "panoramix.h"

static void funct_villager_nb_fights(villagers_t *arg)
{
    while (arg->nb_fights < arg->nb_fights_max) {
        pthread_mutex_lock(&arg->info->mutex_villager);
        printf("Villager %d: I need a drink... I see %d servings left. \n",
            arg->id, arg->info->pot_popo);
        if (arg->info->pot_popo == 0) {
            printf("Villager %d: Hey Pano wake up! We need more potion.\n",
                    arg->id);
            sem_post(&arg->info->sem_druid);
            sem_wait(&arg->info->sem_villager);
        }
        arg->info->pot_popo -= 1;
        arg->nb_fights += 1;
        printf("Villager %d: Take that roman scum! Only %d left.\n",
            arg->id, (arg->nb_fights_max - arg->nb_fights));
        pthread_mutex_unlock(&arg->info->mutex_villager);
    }
}

void *funct_villager(villagers_t *arg)
{
    printf("Villager %d: Going into battle!\n", arg->id);
    funct_villager_nb_fights(arg);
    if (arg->nb_fights >= arg->nb_fights_max) {
        printf("Villager %d: I'm going to sleep now.\n", arg->id);
        pthread_mutex_lock(&arg->info->mutex_villager);
        arg->info->villagers_finish += 1;
        pthread_mutex_unlock(&arg->info->mutex_villager);
    }
    if (arg->info->villagers_finish >= arg->info->villagers_max) {
        sem_post(&arg->info->sem_druid);
    }
    return NULL;
}
