#ifndef __CUSTOM_CHARACTER_MODEL_PARSER_H__
#define __CUSTOM_CHARACTER_MODEL_PARSER_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "print_error.h"

#define MODEL_SIZE 100
extern char model[MODEL_SIZE];
extern size_t model_len;

void custom_char_model_parser(int, char *[]);



void remove_dup(void);

void remove_bracket_and_shift(void);
void model_verify(void);
char printable_char_verify(char ch);
void custom_model_parser(void);

#endif /*__CUSTOM_CHARACTER_MODEL_PARSE_H__*/

