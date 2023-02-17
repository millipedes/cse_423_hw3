/**
 * @file   constants_macros.h
 * @brief  This file contains the macros/constants used by the whole program.
 * @author Matthew C. Lindeman
 * @date   January 27, 2023
 * @bug    None known
 * @todo   Nothing
 */
#ifndef CONST_H
#define CONST_H

#define MAX_LEXEME_SIZE 1024
#define MAX_PATH_SIZE   1024
#define TAB_MULTIPLE    8

#define IS_TAB_SPACE(c)   ((c == ' ')      \
                           || (c == '\t')) ? 1 : 0
#define IS_NEWLINE(c)     ((c == '\r')     \
                           || (c == '\n')) ? 1 : 0
#define IS_WHITESPACE(c)  ((c == '\r')     \
                           || (c == '\n')  \
                           || (c == ' ')   \
                           || (c == '\t')) ? 1 : 0
#define NOT_WHITESPACE(c) !IS_WHITESPACE(c) ? 1 : 0


#define BOLD_COLOR  "\e[1m"
#define ERROR_COLOR "\033[97m"
#define END_COLOR   "\033[0m"

#endif
