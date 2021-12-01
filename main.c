/*
** EPITECH PROJECT, 2021
** MY_LS
** File description:
** No file there , just an epitech header example
*/

#include "include/my_ls.h"

int my_print_verif(data_t *data)
{
    for (int i = 0; i < data->nb_dir; i++) {
        my_printf("\ndir: '%s' >>\n", data->directory[i]->path);
        for (int j = 0; j < data->directory[i]->nb_files; j++) {
            my_printf("    | %s %d %s %s %d %s %s | type: %d\n",
                      data->directory[i]->files[j]->perm,
                      data->directory[i]->files[j]->nb,
                      data->directory[i]->files[j]->user,
                      data->directory[i]->files[j]->group,
                      data->directory[i]->files[j]->size,
                      data->directory[i]->files[j]->modification,
                      data->directory[i]->files[j]->path,
                      data->directory[i]->files[j]->type);
        }
    }
    return 0;
}

int main(int ac, char **av)
{
    data_t* data = malloc(sizeof(data_t));
    init_data(data, av);
    get_directory(data, av, ac);
    get_flags(data, av, ac);
    check_files(data);
    fill_files(data);
    for (int i = 0; i < data->nb_dir; i++)
        (data->t == 0) ? sort_files_in_directory(data->directory[i]) :
        sort_files_in_directory_by_date(data->directory[i]);
    format_result(data);
    return 0;
}
