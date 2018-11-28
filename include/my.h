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

void my_putchar(char c);
int my_strlen(char const *str);
char *my_revstr(char *str);
int get_the_sign(char const *str);
char *my_getnbr(char const *str);
void my_putstr(char *str);

#endif
