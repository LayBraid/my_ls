/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** No file there , just an epitech header example
*/

#ifndef MY_LS_MY_LS_H
    #define MY_LS_MY_LS_H

    #include <dirent.h>
    #include <stdio.h>
    #include <string.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <unistd.h>
    #include <pwd.h>
    #include <grp.h>

    #include "errno.h"
    #include "time_utils.h"

    #include "struct.h"
    #include "my.h"
    #include "files.h"
    #include "directory.h"
    #include "data.h"
    #include "flags.h"
    #include "sort.h"
    #include "formating.h"
    #include "time_utils.h"
    #include "recursive.h"

    #define ERROR_NO_FILE_DIRECTORY "No such file or directory\n"
    #define ERROR_STAT "Error stat n12\n"

int my_ls(int ac, char **av);

#endif
