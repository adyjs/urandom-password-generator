#ifndef __ARGS_H__
#define __ARGS_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include "print_error.h"
#include "pw_filter.h"
#include "custom_character_model_parser.h"
#include "custom_character_group_model_parser.h"

/*
#define GET_HELP                            0   // 0x00 0000_0000 -h
#define DEFAULT_CHAR_OUTPUT                 1   // 0x01 0000_0001
#define RULE_OUT_SP_CHAR_OUTPUT             2   // 0x02 0000_0010 -s
#define RULE_OUT_UPPER_ALPHABET_CHAR_OUTPUT 4   // 0x04 0000_0100 -u
#define RULE_OUT_LOWER_ALPHABET_CHAR_OUTPUT 8   // 0x08 0000_1000 -l
#define RULE_OUT_DIGIT_CHAR_OUTPUT          16  // 0x10 0001_0000 -n
#define CUSTOM_CHAR_MODEL_OUTPUT            32  // 0x20 0010_0000 -c
#define CUSTOM_CHAR_GROUP_MODEL_OUTPUT      64  // 0x40 0100_0000 -g
*/

#define DEFAULT_READ_COUNT 4096

extern size_t pw_len;

extern unsigned char mode;

ssize_t option_validate(char *option);

void options(char opt);

void mode_settings(int argc, char *argv[]);

int pw_len_validate(char *str);

void parse_pwlen_input(int argc, char *argv[]);

#endif /*__ARGS_H__*/