/*
** EPITECH PROJECT, 2023
** Concurrent [WSL: Ubuntu-20.04]
** File description:
** villager_thread
*/

#include "../inc/include.h"

bool go_to_fight(int id)
{
    if (general_struct->current_pot > 0) {
        general_struct->current_pot--;
        pthread_mutex_unlock(&mutex);
        general_struct->fights[id] -= 1;
        printf("Villager %i: Take that roman scum! ", id);
        printf("Only %i left.\n", general_struct->fights[id]);
        return false;
    }
    return true;
}

bool villager_game_loop(int id)
{
    pthread_mutex_lock(&mutex);
    printf("Villager %i: I need a drink... ", id);
    printf("I see %i servings left.\n", general_struct->current_pot);
    if (!go_to_fight(id))
        return false;
    if (general_struct->nb_refills > 0) {
        printf("Villager %i: Hey Pano wake up! We need more potion.\n", id);
        sem_post(&druid_semaphore);
        sem_wait(&villager_semaphore);
        if (!go_to_fight(id))
            return false;
    }
    pthread_mutex_unlock(&mutex);
    return true;
}

void *villager_management(void *param)
{
    int id = (long)param;
    printf("Villager %i: Going into battle!\n", id);
    while (general_struct->fights[id] != 0) {
        if (villager_game_loop(id))
            break;
    }
    printf("Villager %i: I'm going to sleep now.\n", id);
    return 0;
}
