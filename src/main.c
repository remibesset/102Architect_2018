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


float *mutipicate_matrix(float *m, float *m2)
{
    float m3[9] = {m[0], m[1], m[2], m[3], m[4], m[5], m[6], m[7], m[8]};

    m[0] = m3[0] * m2[0] + m3[1] * m2[3] + m3[2] * m2[6];
    m[1] = m3[0] * m2[1] + m3[1] * m2[4] + m3[2] * m2[7];
    m[2] = m3[0] * m2[2] + m3[1] * m2[5] + m3[2] * m2[8];
    m[3] = m3[3] * m2[0] + m3[4] * m2[3] + m3[5] * m2[6];
    m[4] = m3[3] * m2[1] + m3[4] * m2[4] + m3[5] * m2[7];
    m[5] = m3[3] * m2[2] + m3[4] * m2[5] + m3[5] * m2[8];
    m[6] = m3[6] * m2[0] + m3[7] * m2[3] + m3[8] * m2[6];
    m[7] = m3[6] * m2[1] + m3[7] * m2[4] + m3[8] * m2[7];
    m[8] = m3[6] * m2[2] + m3[7] * m2[5] + m3[8] * m2[8];
    return (m);
}

float *reflection(float x, float y, char const **av, float *matrix_reflection_base)
{
    float a = atof(av[4]);
    a = (a * M_PI) / 180;
    float cos_vx = cosf(a * 2);
    float sin_vx = sinf(a * 2);
    int vx_i = atoi(av[4]);
    float matrix_reflection[] = {cos_vx, sin_vx, 0.00, sin_vx, -cos_vx, 0.00, 0.00, 0.00, 1.00};

    printf("Reflection over an axis with an inclination angle of %d degrees\n", vx_i);
    for (int i = 0; i < 9; i++) {
        if (matrix_reflection[i] < 0 && matrix_reflection[i] > -0.009) {
            matrix_reflection[i] = -matrix_reflection[i];
            matrix_reflection_base[i] = matrix_reflection[i];
            printf("%.2f  ", matrix_reflection[i]);
        } else {
            matrix_reflection_base[i] = matrix_reflection[i];
            printf("%.2f  ", matrix_reflection[i]);
        }
        if (i % 3 == 2)
            printf("\n");
    }
    printf("(%.0f, %.0f) => (%.2f, %.2f)\n", x, y, (matrix_reflection[0] + matrix_reflection[1]) * x, (matrix_reflection[3] + matrix_reflection[4]) * y);
    return (matrix_reflection_base);
}

float *rotation(float x, float y, char const **av, float *matrix_rotation_base)
{
    float a = atof(av[4]);
    a = (a * M_PI) / 180;
    float cos_vx = cosf(a);
    float sin_vx = sinf(atof(av[4])* M_PI / 180);
    int vx_i = atoi(av[4]);
    float matrix_rotation[] = {cos_vx, (sin_vx * -1), 0.00, sin_vx, cos_vx, 0.00, 0.00, 0.00, 1.00};
    
    printf("Rotation by a %d degree angle\n", vx_i);
    for (int i = 0; i < 9; i++) {
        if (matrix_rotation[i] < 0 && matrix_rotation[i] > -0.009) {
            matrix_rotation[i] = -matrix_rotation[i];
            matrix_rotation_base[i] = matrix_rotation[i];
            printf("%.2f  ", matrix_rotation[i]);
        } else {
            matrix_rotation_base[i] = matrix_rotation[i];
            printf("%.2f  ", matrix_rotation[i]);
        }
        if (i % 3 == 2)
            printf("\n");
    }
    printf("(%.0f, %.0f) => (%.2f, %.2f)\n", x, y, matrix_rotation[4], matrix_rotation[3]);
    return (matrix_rotation_base);
}

float *scale(float x, float y, char const **av, float *matrix_scale_base)
{
    float vx = atof(av[4]);
    float vy = atof(av[5]);
    int vx_i = atof(av[4]);
    int vy_i = atof(av[5]);
    float matrix_sacle[] = {vx, 0.00, 0.00, 0.00, vy, 0.00, 0.00, 0.00, 1.00};

    printf("Scaling by factors %d and %d\n", vx_i, vy_i);
    for (int i = 0; i < 9; i++) {
        matrix_scale_base[i] = matrix_sacle[i];
        printf("%.2f  ", matrix_sacle[i]);
        if (i % 3 == 2)
            printf("\n");
    }
    printf("(%.0f, %.0f) => (%.2f, %.2f)\n", x, y, vx * x, vy * y);
    return (matrix_scale_base);
}

float *translation(float x, float y, char const **av, float *matrix_translat_base)
{
    float vx = atof(av[4]);
    float vy = atof(av[5]);
    int vx_i = atof(av[4]);
    int vy_i = atof(av[5]);
    float matrix_translat[] = {1.00, 0.00, vx, 0.00, 1.00, vy, 0.00, 0.00, 1.00};

    printf("Translation along vector (%d , %d)\n", vx_i, vy_i);
    for (int i = 0; i < 9; i++) {
        matrix_translat_base[i] = matrix_translat[i];
        printf("%.2f  ", matrix_translat[i]);
        if (i % 3 == 2)
            printf("\n");
    }
    printf("(%.0f, %.0f) => (%.2f, %.2f)\n", x, y, vx + x, vy + y);
    return (matrix_translat_base);
}

void manage_argument_each_case(char const **av, int x, int y)
{
    float matrix_base[] = {1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00};
    float *matrix = malloc(sizeof(int) *9);
    for (int i = 0; i < 9; i++) {
        matrix[i] = 1.00;
    }

    if (av[3][0] == '-' && av[3][1] == 't') {
       mutipicate_matrix(matrix, translation(x, y, av, matrix_base));
    }
    if (av[3][0] == '-' && av[3][1] == 'z') {
       matrix = scale(x, y, av, matrix_base);
    }
    if (av[3][0] == '-' && av[3][1] == 'r') {
       matrix = rotation(x, y, av, matrix_base);
    }
    if (av[3][0] == '-' && av[3][1] == 's') {
       matrix = reflection(x, y, av, matrix_base);        
    }
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
        manage_argument_each_case(av, x, y);
    else
        return (84);
    return (0);
}