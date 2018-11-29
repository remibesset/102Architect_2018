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

float *mutipicate_matrix(float *m, float *m2);

int my_put_int_list(linked_list_t **list, float *array)
{
    linked_list_t *element;

    element = malloc(sizeof(*element));
    element->data = array;
    element->next = *list;
    *list = element;
    return (0);
}

int my_show_list(linked_list_t *list, float x, float y)
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
        printf("%.2f  ", matrix[i]);
        if (i % 3 == 2)
            printf("\n");
    }
    resultx = x * matrix[0] + y * matrix[1] + matrix[2];
    resulty = x * matrix[3] + y * matrix[4] + matrix[5];
    printf("(%.0f, %.0f) => (%.2f, %.2f)\n", x, y, resultx, resulty);
    return (0);
}

float *mutipicate_matrix(float *matrix, float *matrix2)
{
    float temp[9] = {matrix[0], matrix[1], matrix[2], matrix[3], matrix[4], matrix[5], matrix[6], matrix[7], matrix[8]};
    int nbr_of_1 = 0;
    for (int i = 0; i < 9; i++) {
        if (matrix[i] == 1.00)
            nbr_of_1++;
    }
    if (nbr_of_1 == 9) {
        for (int i = 0; i < 9; i++)
            matrix[i] = matrix2[i];
    } else {
        matrix[0] = temp[0] * matrix2[0] + temp[1] * matrix2[3] + temp[2] * matrix2[6];
        matrix[1] = temp[0] * matrix2[1] + temp[1] * matrix2[4] + temp[2] * matrix2[7];
        matrix[2] = temp[0] * matrix2[2] + temp[1] * matrix2[5] + temp[2] * matrix2[8];
        matrix[3] = temp[3] * matrix2[0] + temp[4] * matrix2[3] + temp[5] * matrix2[6];
        matrix[4] = temp[3] * matrix2[1] + temp[4] * matrix2[4] + temp[5] * matrix2[7];
        matrix[5] = temp[3] * matrix2[2] + temp[4] * matrix2[5] + temp[5] * matrix2[8];
        matrix[6] = temp[6] * matrix2[0] + temp[7] * matrix2[3] + temp[8] * matrix2[6];
        matrix[7] = temp[6] * matrix2[1] + temp[7] * matrix2[4] + temp[8] * matrix2[7];
        matrix[8] = temp[6] * matrix2[2] + temp[7] * matrix2[5] + temp[8] * matrix2[8];
    }
    return (matrix);
}

float *reflection(float x, float y, char const **av, int i, float *matrix_reflection_base)
{
    float a = atof(av[i + 1]);
    a = (a * M_PI) / 180;
    float cos_vx = cosf(a * 2);
    float sin_vx = sinf(a * 2);
    int vx_i = atoi(av[i + 1]);
    float *matrix_reflection = malloc(sizeof(float) * 9);
    float resultx = 0.00;
    float resulty = 0.00;

    int_reflection(&matrix_reflection, cos_vx, sin_vx);
    printf("Reflection over an axis with an inclination angle of %d degrees\n", vx_i);
    for (int i = 0; i < 9; i++) {
        if (matrix_reflection[i] < 0 && matrix_reflection[i] > -0.009) {
            matrix_reflection[i] = -matrix_reflection[i];
            //printf("%.2f", matrix_reflection[i]);
        } 
        // else {
        //     printf("%.2f", matrix_reflection[i]);
        // }
        // if (i % 3 == 2)
        //     printf("\n");
        // else
        //     printf(" ");
    }
    // resultx = x * matrix_reflection[0] + y * matrix_reflection[1];
    // resulty = x * matrix_reflection[3] + y * matrix_reflection[4];
    // printf("(%.0f, %.0f) => (%.2f, %.2f)\n", x, y, resultx, resulty);
    return (matrix_reflection);
}

float *rotation(float x, float y, char const **av, int i, float *matrix_rotation_base)
{
    float a = atof(av[i + 1]);
    a = (a * M_PI) / 180;
    float cos_vx = cosf(a);
    float sin_vx = sinf(a);
    int vx_i = atoi(av[i + 1]);
    float *matrix_rotation = malloc(sizeof(float) * 9);
    float resultx = 0.00;
    float resulty = 0.00;
    
    int_rotation(&matrix_rotation, cos_vx, sin_vx);
    //{cos_vx, (sin_vx * -1), 0.00, sin_vx, cos_vx, 0.00, 0.00, 0.00, 1.00}
    printf("Rotation by a %d degree angle\n", vx_i);
    for (int i = 0; i < 9; i++) {
        if (matrix_rotation[i] < 0 && matrix_rotation[i] > -0.009) {
            matrix_rotation[i] = -matrix_rotation[i];
            //printf("%.2f", matrix_rotation[i]);
        } 
        // else {
        //     printf("%.2f", matrix_rotation[i]);
        // }
        // if (i % 3 == 2)
        //     printf("\n");
        // else
        //     printf(" ");
    }
    // resultx = x * matrix_rotation[0] + y * matrix_rotation[1];
    // resulty = x * matrix_rotation[3] + y * matrix_rotation[4];
    // printf("(%.0f, %.0f) => (%.2f, %.2f)\n", x, y, resultx, resulty);
    return (matrix_rotation);
}

float *scale(float x, float y, char const **av, int i, float *matrix_scale_base)
{
    float vx = atof(av[i + 1]);
    float vy = atof(av[i + 2]);
    int vx_i = atof(av[i + 1]);
    int vy_i = atof(av[i + 2]);
    float *matrix_scale = malloc(sizeof(float) * 9);

    int_scale(&matrix_scale, vx, vy);
    printf("Scaling by factors %d and %d\n", vx_i, vy_i);
    // for (int i = 0; i < 9; i++) {
    //     printf("%.2f", matrix_scale[i]);
    //     if (i % 3 == 2)
    //         printf("\n");
    //     else
    //         printf(" ");
    // }
    // printf("(%.0f, %.0f) => (%.2f, %.2f)\n", x, y, vx * x, vy * y);
    return (matrix_scale);
}

float *translation(float x, float y, char const **av, int i, float *matrix_translat_base)
{
    float vx = atof(av[i + 1]);
    float vy = atof(av[i + 2]);
    int vx_i = atof(av[i + 1]);
    int vy_i = atof(av[i + 2]);
    int j = 0;
    float *matrix_translat = malloc(sizeof(float) * 9);

    int_translat(&matrix_translat, vx, vy);

    printf("Translation along vector (%d, %d)\n", vx_i, vy_i);
    // for (int i = 0; i < 9; i++) {
    //     printf("%.2f", matrix_translat[i]);
    //     if (i % 3 == 2)
    //         printf("\n");
    //     else
    //         printf(" ");
    // }
    // printf("(%.0f, %.0f) => (%.2f, %.2f)\n", x, y, vx + x, vy + y);
    return (matrix_translat);
}

void manage_argument_each_case(char const **av, float x, float y, int nb_arg)
{
    float matrix_base[] = {1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00};
    float *matrix = malloc(sizeof(int) *9);
    linked_list_t *list;
    int i = 0;
    
    list = NULL;
    for (int i = 0; i < 9; i++)
        matrix[i] = matrix_base[i];
    for (int i = 3; i < nb_arg - 1; i++) {
        if (av[i][0] == '-' && av[i][1] == 't') {
            if (av[i + 1][0] != '\0' && av[i + 2][0] != '\0') {
                my_put_int_list(&list, translation(x, y, av, i, matrix_base));
                i += 2;
            }
        }
        else if (av[i][0] == '-' && av[i][1] == 'z') {
            if (av[i + 1][0] != '\0' && av[i + 2][0] != '\0') {
                my_put_int_list(&list, scale(x, y, av, i, matrix_base));
                i += 2;
            }
        }
        else if (av[i][0] == '-' && av[i][1] == 'r') {
            if (av[i + 1][0] != '\0') {
                my_put_int_list(&list, rotation(x, y, av, i, matrix_base));
                i++;
            }
        }
        else if (av[i][0] == '-' && av[i][1] == 's') {
            if (av[i + 1][0] != '\0') {
                my_put_int_list(&list, reflection(x, y, av, i, matrix_base));
                i++;
            }
        }
    }
    my_show_list(list, x, y);
}

int main(int ac, char const **av)
{
    char src[] = "USAGE\n \
    ./102architect x y transfo1 arg11 [arg12] [transfo2 arg12 [arg22]] ...\n\n\
    DESCRIPTION\n\
    x abscissa of the original point \n\
    y ordinate of the original point \n\n\
    transfo arg1 [arg2] \n\
    -t i j     translation along vector (i, j)\n\
    -z m n     scaling by factors m (x-axis) and n (y-axis)\n\
    -r d       rotation centered in O by a d degree angle\n\
    -s d       reflection over the axis passing through O with an inclination\n\
   \t\tangle of d degrees";
    float x = atof(av[1]);
    float y = atof(av[2]);

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h')
        printf("%s \n", src);
    else if (ac >= 5)
        manage_argument_each_case(av, x, y, ac);
    else
        return (84);
    return (0);
}