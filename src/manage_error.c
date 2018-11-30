/*
** EPITECH PROJECT, 2018
** manage error
** File description:
** error
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/my.h"

int it_is_a_number(char const *av)
{
    int i = 0;

    while (av[i] != '\0') {
        if ((av[i] < '0' || av[i] > '9') && av[i] != '-') {
            exit(84);
        }
        i++;
    }
    return (1);
}

void it_is_good_flag(char const *str)
{
    int i = 1;
    int j = 0;
    char array[] = {'t', 'z', 'r', 's'};
    int passed = 0;

    if (my_strlen(str) != 2)
        exit(84);
    while (str[i] != '\0') {
        for (j = 0; j < 4 ; j++) {
            passed = (str[i] == array[j]) ? 1 : 0;
            if (passed == 1)
                break;
        }
        if (passed == 0)
            exit(84);
        i++;
    }
}

void manage_number(char const **av, int *i, int nb_number, int ac)
{
    (*i)++;
    if (nb_number == 2) {
        if (*i + 1 >= ac)
            exit(84);
        if ((it_is_a_number(av[*i]) != 1 && it_is_a_number(av[*i + 1]) != 1) &&
        (av[*i][0] == '\0' && av[*i + 1][0] == '\0')) {
            exit(84);
        } else {
            (*i)++;
        }
    }
    else if (nb_number == 1) {
        if (*i >= ac)
            exit(84);
        if (it_is_a_number(av[*i]) != 1 && av[*i][0] == '\0') {
            exit(84);
        }
    }
}

void there_is_number_after(char const **av, int *i, int ac)
{
    if (av[*i][0] == '-' && av[*i][1] == 't') {
        manage_number(av, i, 2, ac);
    } else if (av[*i][0] == '-' && av[*i][1] == 'z') {
        manage_number(av, i, 2, ac);
    } else if (av[*i][0] == '-' && av[*i][1] == 'r') {
        manage_number(av, i, 1, ac);
    } else if (av[*i][0] == '-' && av[*i][1] == 's') {
        manage_number(av, i, 1, ac);
    }
}

int manage_error(int ac, char const **av)
{
    float x = atof(av[1]);
    float y = atof(av[2]);
    int i = 1;
    int j = 0;

    if (it_is_a_number(av[1]) != 1 || it_is_a_number(av[2]) != 1) {
        exit(84);
    }
    for (int i = 3; i < ac; i++) {
        if (av[i][0] == '-') {
            it_is_good_flag(av[i]);
            there_is_number_after(av, &i, ac);
        } else {
            exit(84);
        }
    }
    return (0);
}