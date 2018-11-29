/*
** EPITECH PROJECT, 2018
** my
** File description:
** .h
*/

#ifndef MY_H
#define MY_H

#define M_PI 3.14159265358979323846

typedef struct coordonate {
    float x;
    float y;
}coordonate_t;

typedef struct linked_list
{
    float *data;
    struct linked_list *next;
} linked_list_t;

void my_putchar(char c);
int my_strlen(char const *str);
char *my_revstr(char *str);
int get_the_sign(char const *str);
char *my_getnbr(char const *str);
void my_putstr(char *str);
void int_reflection(float **matrix_reflection, float cos_vx, float sin_vx);
void int_rotation(float **matrix_rotation, float cos_vx, float sin_vx);
void int_scale(float **matrix_scale, float vx, float vy);
void int_translat(float **matrix_translat, float vx, float vy);

#endif
