/*
** EPITECH PROJECT, 2018
** main 102Archi
** File description:
** archi
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/my.h"

int my_put_int_list(linked_list_t **list, float *array)
{
    linked_list_t *element;

    element = malloc(sizeof(*element));
    element->data = array;
    element->next = *list;
    *list = element;
    return (0);
}

float *mutipicate_matrix(float *matrix, float *mat2)
{
    float temp[9] = {matrix[0], matrix[1], matrix[2], matrix[3],
        matrix[4], matrix[5], matrix[6], matrix[7], matrix[8]};
    int nbr_of_1 = 0;

    for (int i = 0; i < 9; i++)
        nbr_of_1 += (matrix[i] == 1.00) ? 1 : 0;
    if (nbr_of_1 == 9) {
        for (int i = 0; i < 9; i++)
            matrix[i] = mat2[i];
    } else {
        matrix[0] = temp[0] * mat2[0] + temp[1] * mat2[3] + temp[2] * mat2[6];
        matrix[1] = temp[0] * mat2[1] + temp[1] * mat2[4] + temp[2] * mat2[7];
        matrix[2] = temp[0] * mat2[2] + temp[1] * mat2[5] + temp[2] * mat2[8];
        matrix[3] = temp[3] * mat2[0] + temp[4] * mat2[3] + temp[5] * mat2[6];
        matrix[4] = temp[3] * mat2[1] + temp[4] * mat2[4] + temp[5] * mat2[7];
        matrix[5] = temp[3] * mat2[2] + temp[4] * mat2[5] + temp[5] * mat2[8];
        matrix[6] = temp[6] * mat2[0] + temp[7] * mat2[3] + temp[8] * mat2[6];
        matrix[7] = temp[6] * mat2[1] + temp[7] * mat2[4] + temp[8] * mat2[7];
        matrix[8] = temp[6] * mat2[2] + temp[7] * mat2[5] + temp[8] * mat2[8];
    }
    return (matrix);
}

void manage_argument_each_case(char const **av, float x, float y, int nb_arg)
{
    linked_list_t *list = NULL;
    int i = 0;

    for (int i = 3; i < nb_arg - 1; i++) {
        if (av[i][0] == '-' && av[i][1] == 't') {
            my_put_int_list(&list, translation(x, y, av, i));
            i++;
        }
        else if (av[i][0] == '-' && av[i][1] == 'z') {
            my_put_int_list(&list, scale(x, y, av, i));
            i++;
        }
        else if (av[i][0] == '-' && av[i][1] == 'r')
            my_put_int_list(&list, rotation(x, y, av, i));
        else if (av[i][0] == '-' && av[i][1] == 's')
            my_put_int_list(&list, reflection(x, y, av, i));
        i++;
    }
    my_show_list(list, x, y);
}

int main(int ac, char const **av)
{

    float x = 0.00;
    float y = 0.00;

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h')
        index_commmand();
    else if (ac >= 5) {
        manage_error(ac, av);
        x = atof(av[1]);
        y = atof(av[2]);
        manage_argument_each_case(av, x, y, ac);
    } else
        return (84);
    return (0);
}
