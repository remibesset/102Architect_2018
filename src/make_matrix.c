/*
** EPITECH PROJECT, 2018
** make matrix
** File description:
** matrix
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/my.h"

float *reflection(float x, float y, char const **av, int i)
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
    printf("Reflection over an axis with an inclination angle of \
%d degrees\n", vx_i);
    for (int i = 0; i < 9; i++) {
        if (matrix_reflection[i] < 0 && matrix_reflection[i] > -0.009) {
            matrix_reflection[i] = -matrix_reflection[i];
        }
    }
    return (matrix_reflection);
}

float *rotation(float x, float y, char const **av, int i)
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
    printf("Rotation by a %d degree angle\n", vx_i);
    for (int i = 0; i < 9; i++) {
        if (matrix_rotation[i] < 0 && matrix_rotation[i] > -0.009) {
            matrix_rotation[i] = -matrix_rotation[i];
        }
    }
    return (matrix_rotation);
}

float *scale(float x, float y, char const **av, int i)
{
    float vx = atof(av[i + 1]);
    float vy = atof(av[i + 2]);
    int vx_i = atof(av[i + 1]);
    int vy_i = atof(av[i + 2]);
    float *matrix_scale = malloc(sizeof(float) * 9);

    int_scale(&matrix_scale, vx, vy);
    printf("Scaling by factors %d and %d\n", vx_i, vy_i);
    return (matrix_scale);
}

float *translation(float x, float y, char const **av, int i)
{
    float vx = atof(av[i + 1]);
    float vy = atof(av[i + 2]);
    int vx_i = atof(av[i + 1]);
    int vy_i = atof(av[i + 2]);
    int j = 0;
    float *matrix_translat = malloc(sizeof(float) * 9);

    int_translat(&matrix_translat, vx, vy);
    printf("Translation along vector (%d, %d)\n", vx_i, vy_i);
    return (matrix_translat);
}
