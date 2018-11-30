/*
** EPITECH PROJECT, 2018
** display
** File description:
** display
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/my.h"

void my_show_list(linked_list_t *list, float x, float y)
{
    linked_list_t *tmp;
    float *matrix = malloc(sizeof(int) * 9);
    float resultx = 0.00;
    float resulty = 0.00;

    tmp = list;
    for (int i = 0; i < 9; i++)
        matrix[i] = 1.00;
    while (tmp != NULL) {
        mutipicate_matrix(matrix, tmp->data);
        tmp = tmp->next;
    }
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 2)
            printf("%-4.2f\n", matrix[i]);
        else
            printf("%-7.2f", matrix[i]);
    }
    resultx = x * matrix[0] + y * matrix[1] + matrix[2];
    resulty = x * matrix[3] + y * matrix[4] + matrix[5];
    printf("(%.0f, %.0f) => (%.2f, %.2f)\n", x, y, resultx, resulty);
}

void index_commmand(void)
{
    printf("USAGE\n");
    printf("\t./102architect x y transfo1 arg11 [arg12] [transfo2 arg12");
    printf(" [arg22]] ...\n\n");
    printf("DESCRIPTION\n");
    printf("\tx      abscissa of the original point \n");
    printf("\ty      ordinate of the original point \n\n");
    printf("\ttransfo arg1 [arg2] \n");
    printf("\t-t i j     translation along vector (i, j)\n");
    printf("\t-z m n     scaling by factors m (x-axis) and n (y-axis)\n");
    printf("\t-r d       rotation centered in O by a d degree angle\n");
    printf("\t-s d       reflection over the axis passing through O with an");
    printf("inclination \n\t\t   angle of d degrees");
    printf("\n");
}