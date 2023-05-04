/*
** EPITECH PROJECT, 2023
** B-CCP-400-NCY-4-1-panoramix-silviu.zaino [WSL: Ubuntu-20.04]
** File description:
** usefull
*/

#include "../inc/include.h"

void destroy_prg(general_struct_t *general_struct)
{
    printf("Erreur : destruction du programme\n");
    free(general_struct);
    exit(84);
}

general_struct_t *init_prg(int ac, char **av, general_struct_t *general_struct)
{
    if (ac != 5)
        destroy_prg(general_struct);
    general_struct->current_pot = 0;
    general_struct->nb_villager = atoi(av[1]);
    general_struct->pot_size = atoi(av[2]);
    general_struct->nb_fight = atoi(av[3]);
    general_struct->nb_refills = atoi(av[4]);
    if (general_struct->nb_villager <= 0 || general_struct->pot_size <= 0 ||
        general_struct->nb_fight <= 0 || general_struct->nb_refills <= 0)
        destroy_prg(general_struct);
    if ((general_struct->fights = malloc(sizeof(int) * \
    general_struct->nb_villager)) == NULL)
        destroy_prg(general_struct);
    for (int i = 0; i < general_struct->nb_villager; i++)
        general_struct->fights[i] = general_struct->nb_fight;
    general_struct->current_pot = general_struct->pot_size;
    general_struct->remaining_villagers = general_struct->nb_villager;
    return general_struct;
}
