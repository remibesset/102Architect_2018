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

void manage_argument_each_case(char const **av, float x, float y, int nb_arg);
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
int it_is_a_number(char const *av);
void it_is_good_flag(char const *str);
void manage_number(char const **av, int *i, int nb_number, int ac);
void there_is_number_after(char const **av, int *i, int ac);
int manage_error(int ac, char const **av);
void my_show_list(linked_list_t *list, float x, float y);
void index_commmand(void);
float *mutipicate_matrix(float *matrix, float *matrix2);
float *reflection(float x, float y, char const **av, int i);
float *rotation(float x, float y, char const **av, int i);
float *scale(float x, float y, char const **av, int i);
float *translation(float x, float y, char const **av, int i);

#endif
