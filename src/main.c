/*
** EPITECH PROJECT, 2023
** B-CCP-400-NCY-4-1-panoramix-silviu.zaino [WSL: Ubuntu-20.04]
** File description:
** main
*/

#include "../inc/include.h"

general_struct_t *general_struct;
pthread_mutex_t mutex;
sem_t druid_semaphore;
sem_t villager_semaphore;

int run_prg(general_struct_t *general_struct)
{
    pthread_t *threads = malloc(sizeof(pthread_t) * \
    (general_struct->nb_villager + 2));

    if (threads == NULL)
        return 84;
    pthread_create(&threads[general_struct->nb_villager], NULL, \
    druid_management, NULL);
    for (long i = 0; i < general_struct->nb_villager; i++)
        if (pthread_create(&threads[i], NULL, villager_management, (void *)i))
            printf("Error: failed to create thread\n");
    for (int i = 0; i < general_struct->nb_villager; i++)
        if (pthread_join(threads[i], NULL))
            printf("Error: failed to join thread\n");
    pthread_cancel(threads[general_struct->nb_villager]);
    free(threads);
    return 0;
}

int main(int ac, char **av)
{
    general_struct = malloc(sizeof(general_struct_t));
    general_struct = init_prg(ac, av, general_struct);
    if (!general_struct)
        destroy_prg(general_struct);
    sem_init(&druid_semaphore, 0, 0);
    sem_init(&villager_semaphore, 0, 0);
    pthread_mutex_init(&mutex, NULL);
    if (run_prg(general_struct) == 84)
        return 84;
    free(general_struct);
    return 0;
}
