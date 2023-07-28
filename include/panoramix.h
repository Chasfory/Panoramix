/*
** EPITECH PROJECT, 2023
** B-CCP-400-PAR-4-1-panoramix-laetitia.bousch
** File description:
** panoramix
*/

#ifndef PANORAMIX_H_
    #define PANORAMIX_H_

    #include <stdio.h>
    #include <string.h>
    #include <stdbool.h>
    #include <stdlib.h>
    #include <pthread.h>
    #include <semaphore.h>

typedef struct info_s {
    pthread_mutex_t mutex_druid;
    pthread_mutex_t mutex_villager;
    sem_t sem_villager;
    sem_t sem_druid;
    int villagers_finish;
    int villagers_max;
    int pot_popo;
    int pot_size;
} info_t;

typedef struct villagers_s {
    info_t *info;
    pthread_t thread;
    bool status;
    int nb_fights_max;
    int nb_fights;
    int id;
} villagers_t;

typedef struct druid_s {
    info_t *info;
    pthread_t thread;
    int nb_refills;
} druid_t;

typedef struct panoramix_s {
    villagers_t *villagers;
    druid_t druid;
    int nb_villagers;
} panoramix_t;

int funct_village(char **arg, int ac);
bool funct_verifie_numbers(char **av, int ac);
void *funct_druid(druid_t *arg);
void *funct_villager(villagers_t *arg);
void init_struct(char **arg, druid_t *druid, info_t *info,
                villagers_t *villagers);
void funct_help(void);
void funct_free(druid_t druid, villagers_t *villagers,
                info_t info, int nb_villagers);

#endif /* !PANORAMIX_H_ */
