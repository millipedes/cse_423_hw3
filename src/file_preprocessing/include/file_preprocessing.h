/**
 * @file   file_preprocessing.h
 * @brief  This file contains the function definitions for file_preprocessing.c
 * @author Matthew C. Lindeman
 * @date   February 05, 2023
 * @bug    None known
 * @todo   Nothing
 */
#ifndef FIL_H
#define FIL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../main/include/constants_macros.h"

#define PATH_DELIMITER    '/'
#define PY_EXTENSION      ".py"
// Determines the size of PY_EXTENSION
#define PY_EXTENSION_SIZE strnlen(PY_EXTENSION, MAX_PATH_SIZE)

typedef struct PATH_WRAPPER_T {
  char * filename;
  char * path;
  char * path_file;
} path_wrapper;

path_wrapper * init_path_wrapper(char * path_file);
int contains_py_extension(char * filename);
int end_path_pos(char * path_file);
char * add_py_extension(char * filename);
path_wrapper * make_path_file(path_wrapper * the_pw);
void debug_path_wrapper(path_wrapper * the_pw);
void free_path_wrapper(path_wrapper * the_pw);

#endif
