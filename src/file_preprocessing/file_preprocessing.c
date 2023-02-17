/**
 * @file   file_preprocessing.c
 * @brief  This file contains the functions required for the file_preprocessing
 * that needs to happen to command line arguments.
 * @author Matthew C. Lindeman
 * @date   February 05, 2023
 * @bug    None known
 * @todo   Nothing
 */
#include "include/file_preprocessing.h"

/**
 * This function initializes a path wrapper given a particular path.
 * @param path_file - The file string of the path and file.
 * @return   the_pw - The newly inited path_file.
 */
path_wrapper * init_path_wrapper(char * path_file) {
  path_wrapper * the_pw = calloc(1, sizeof(struct PATH_WRAPPER_T));
  int path_size = end_path_pos(path_file);
  int total_path_file_size = strnlen(path_file, MAX_PATH_SIZE);
  if(path_size == 0) {
    the_pw->path = NULL;
    the_pw->filename = calloc(total_path_file_size + 1, sizeof(char));
    strncpy(the_pw->filename, path_file, total_path_file_size);
  } else {
    the_pw->path = calloc(path_size + 1, sizeof(char));
    strncpy(the_pw->path, path_file, path_size);
    the_pw->filename = calloc((total_path_file_size - path_size) + 1,
        sizeof(char));
    strncpy(the_pw->filename, path_file + path_size,
        (total_path_file_size - path_size));
  }
  if(!contains_py_extension(the_pw->filename))
    the_pw->filename = add_py_extension(the_pw->filename);
  the_pw = make_path_file(the_pw);
  return the_pw;
}

/**
 * This is a helper function to determine if the given filename has the .py
 * extension.
 * @param filename - The filename to check.
 * @return       1 - Has it.
 *               0 - Does not have it.
 */
int contains_py_extension(char * filename) {
  int filename_size = strnlen(filename, MAX_PATH_SIZE);
  if(!strncmp(filename + (filename_size - PY_EXTENSION_SIZE), PY_EXTENSION,
        MAX_PATH_SIZE))
    return 1;
  else
    return 0;
}

/**
 * This function determines the end position of the path (i.e. including the
 * last '/').
 * @param path_file - The string including a path and file.
 * @return       .\ - Position of the last '/'.
 */
int end_path_pos(char * path_file) {
  if(!strrchr(path_file, PATH_DELIMITER))
    return 0;
  else
    return ((int)(strrchr(path_file, PATH_DELIMITER) - path_file) + 1);
}

/**
 * This function adds the .py extention to a given string.
 * @param  filename - The name of the file to add the extension to.
 * @return filename - The filename with the .py extension.
 */
char * add_py_extension(char * filename) {
  int filename_size = strnlen(filename, MAX_PATH_SIZE);
  filename = realloc(filename, (filename_size + PY_EXTENSION_SIZE + 1)
      * sizeof(char));
  strncat(filename, PY_EXTENSION, PY_EXTENSION_SIZE);
  return filename;
}

/**
 * This function makes the path_file field of the path wrapper data structure
 * (i.e. the path with the filename, what will be passed to fopen).
 * @param  the_pw - The path wrapper data structure which will be updated with
 * this field.
 * @return the_pw - The updated path wrapper data structure.
 */
path_wrapper * make_path_file(path_wrapper * the_pw) {
  if(the_pw->path) {
    int path_file_size = strnlen(the_pw->filename, MAX_PATH_SIZE)
      + strnlen(the_pw->path, MAX_PATH_SIZE);
    the_pw->path_file = calloc(path_file_size + 1, sizeof(char));
    strncat(the_pw->path_file, the_pw->path, MAX_PATH_SIZE);
    strncat(the_pw->path_file, the_pw->filename, MAX_PATH_SIZE);
    return the_pw;
  } else {
    int path_file_size = strnlen(the_pw->filename, MAX_PATH_SIZE);
    the_pw->path_file = calloc(path_file_size + 1, sizeof(char));
    strncat(the_pw->path_file, the_pw->filename, MAX_PATH_SIZE);
    return the_pw;
  }
}

/**
 * This function debugs the path wrapper data stucutre.
 * @param the_pw - The path wrapper data structure to be debugged.
 * @return   N/a
 */
void debug_path_wrapper(path_wrapper * the_pw) {
  printf("[PATH_WRAPPER]\n");
  if(the_pw->path)
    printf("`%s`%s`\n", the_pw->path, the_pw->filename);
  else
    printf("`%s`\n", the_pw->filename);
  printf("`%s`\n", the_pw->path_file);
}

/**
 * This function frees the path wrapper data stucutre.
 * @param the_pw - The path wrapper data structure to be freed.
 * @return   N/a
 */
void free_path_wrapper(path_wrapper * the_pw) {
  if(the_pw) {
    if(the_pw->filename)
      free(the_pw->filename);
    if(the_pw->path)
      free(the_pw->path);
    if(the_pw->path_file)
      free(the_pw->path_file);
    free(the_pw);
  }
}
