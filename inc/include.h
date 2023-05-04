/*
** EPITECH PROJECT, 2023
** B-CCP-400-NCY-4-1-panoramix-silviu.zaino [WSL: Ubuntu-20.04]
** File description:
** include
*/

#ifndef INCLUDE_H_
    #define INCLUDE_H_

    #include <stdbool.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <pthread.h>
    #include <semaphore.h>

    typedef struct {
        int nb_villager;
        int remaining_villagers;
        int pot_size;
        int nb_fight;
        int nb_refills;
        int current_pot;
        int *fights;
    } general_struct_t;

    extern general_struct_t *general_struct;
    extern pthread_mutex_t mutex;
    extern sem_t druid_semaphore;
    extern sem_t villager_semaphore;

    general_struct_t *init_prg(int ac, char **av,
        general_struct_t *general_struct);
    void destroy_prg(general_struct_t *general_struct);
    void *druid_management(void *);
    void *villager_management(void *param);
    bool villager_game_loop(int id);

#endif /* !INCLUDE_H_ */
