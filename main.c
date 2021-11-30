/*
** EPITECH PROJECT, 2021
** BLANK_PROJECT_C
** File description:
** No file there , just an epitech header example
*/

#include "include/my_ls.h"

int see_param(data_t* data)
{
    printf("R: %d", data->flags->R);
    printf("d: %d", data->flags->d);
    return 0;
}

int simple_print(void)
{
    DIR *dir = opendir(".");
    struct dirent *buf;
    char *str = "";

    while ((buf=readdir(dir)) != NULL) {
        if (buf->d_name[0] != '.') {
            str = my_strcat(str, buf->d_name);
            str = my_strcat_c(str, ' ');
        }
    }
    closedir(dir);
    str[my_strlen(str)] = '\n';
    my_putstr(str);
    return 0;
}

int nb_files(char **av)
{
    int nb = 0;

    for (int i = 0; av[i]; i++) {
        if (av[i][0] != '-')
            nb++;
    }
    return nb;
}

void get_files(data_t* data, char **av)
{
    char **files = malloc(sizeof(char *) * data->nb_files);
    for (int i = 0; av[i]; i++) {
        if (av[i][0] != '-') {
            files[i] = malloc(sizeof(char) * (my_strlen(av[i]) + 1));
            files[i] = av[i];
        }
    }
    data->files = files;
}

int check_files(data_t* data)
{
    char *str;

    for (int i = 0; i < data->nb_files; i++) {
        str = data->files[i];
        if (str[my_strlen(str)] != '/')
            str = my_strcat(str, "/");
        str = my_strcat(str, ".");
        if (opendir(str) == NULL) {
            switch (errno) {
                case ENOTDIR:
                    my_putstr(ERROR_NO_FILE_DIRECTORY);
                    return (84);
            }
        }
    }
    return 1;
}

int main(int ac, char **av)
{
    char* test[] = {"c", "b", "a"};

    /*data_t* data = malloc(sizeof(data_t));
    data->nb_files = nb_files(av);
    if (ac == 1)
        simple_print();
    else {
        get_files(data, av);
        check_files(data);
    }*/

    /*DIR *dir = opendir(".");
    struct dirent *buf;
    char * file_name;
    struct stat* test;
    while ((buf=readdir(dir)) != NULL) {
        file_name = buf->d_name;
        lstat(file_name, test);
        printf("%u | %s\n", test->st_uid, file_name);
    }
    closedir(dir);*/
    return 0;
}
