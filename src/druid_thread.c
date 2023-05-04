/*
** EPITECH PROJECT, 2023
** Concurrent [WSL: Ubuntu-20.04]
** File description:
** druid_thread
*/

#include "../inc/include.h"

bool pot_refill(void)
{
    if (general_struct->current_pot == 0) {
        general_struct->nb_refills--;
        general_struct->current_pot = general_struct->pot_size;
        printf("Druid: Ah! Yes, yes. I'm awake! Working on it! Beware I can ");
        printf("only make %d more refills ", general_struct->nb_refills);
        printf("after this one.\n");
        sem_post(&villager_semaphore);
        if (general_struct->nb_refills == 0)
            return true;
    }
    return false;
}

void *druid_management(void *null)
{
    (void)null;
    printf("Druid: I'm ready... but sleepy...\n");
    while (true) {
        sem_wait(&druid_semaphore);
        if (general_struct->nb_refills == 0)
            break;
        if (pot_refill())
            break;
    }
    printf("Druid: I'm out of viscum. I'm going back to... zZz\n");
    return NULL;
}
