/*
** EPITECH PROJECT, 2018
** init matrix
** File description:
** init
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/my.h"

void int_reflection(float **matrix_reflection, float cos_vx, float sin_vx)
{
    (*matrix_reflection)[0] = cos_vx;
    (*matrix_reflection)[1] = sin_vx;
    (*matrix_reflection)[2] = 0.00;
    (*matrix_reflection)[3] = sin_vx;
    (*matrix_reflection)[4] = -cos_vx;
    (*matrix_reflection)[5] = 0.00;
    (*matrix_reflection)[6] = 0.00;
    (*matrix_reflection)[7] = 0.00;
    (*matrix_reflection)[8] = 1.00;
}

void int_rotation(float **matrix_rotation, float cos_vx, float sin_vx)
{
    (*matrix_rotation)[0] = cos_vx;
    (*matrix_rotation)[1] = (sin_vx * -1);
    (*matrix_rotation)[2] = 0.00;
    (*matrix_rotation)[3] = sin_vx;
    (*matrix_rotation)[4] = cos_vx;
    (*matrix_rotation)[5] = 0.00;
    (*matrix_rotation)[6] = 0.00;
    (*matrix_rotation)[7] = 0.00;
    (*matrix_rotation)[8] = 1.00;
}

void int_scale(float **matrix_scale, float vx, float vy)
{
    (*matrix_scale)[0] = vx;
    (*matrix_scale)[1] = 0.00;
    (*matrix_scale)[2] = 0.00;
    (*matrix_scale)[3] = 0.00;
    (*matrix_scale)[4] = vy;
    (*matrix_scale)[5] = 0.00;
    (*matrix_scale)[6] = 0.00;
    (*matrix_scale)[7] = 0.00;
    (*matrix_scale)[8] = 1.00;
}

void int_translat(float **matrix_translat, float vx, float vy)
{
    (*matrix_translat)[0] = 1.00;
    (*matrix_translat)[1] = 0.00;
    (*matrix_translat)[2] = vx;
    (*matrix_translat)[3] = 0.00;
    (*matrix_translat)[4] = 1.00;
    (*matrix_translat)[5] = vy;
    (*matrix_translat)[6] = 0.00;
    (*matrix_translat)[7] = 0.00;
    (*matrix_translat)[8] = 1.00;
}