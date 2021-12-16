#ifndef __PW_FILTER_H__
#define __PW_FILTER_H__

#include <stdio.h>
#include "args.h"
#include "help.h"
#include "custom_character_model_parser.h"

#define GET_HELP                            0   // 0x00 0000_0000 -h
#define DEFAULT_CHAR_OUTPUT                 1   // 0x01 0000_0001
#define RULE_OUT_SP_CHAR_OUTPUT             2   // 0x02 0000_0010 -s
#define RULE_OUT_UPPER_ALPHABET_CHAR_OUTPUT 4   // 0x04 0000_0100 -u
#define RULE_OUT_LOWER_ALPHABET_CHAR_OUTPUT 8   // 0x08 0000_1000 -l
#define RULE_OUT_DIGIT_CHAR_OUTPUT          16  // 0x10 0001_0000 -n
#define CUSTOM_CHAR_MODEL_OUTPUT            32  // 0x20 0010_0000 -c
#define CUSTOM_CHAR_GROUP_MODEL_OUTPUT      64  // 0x40 0100_0000 -g

char filter_pipe(char ch);

char filter_only_printable_char(char ch);

char filter_rule_out_alphabet_lowercase(char ch);

char filter_rule_out_alphabet_uppercase(char ch);

char filter_rule_out_digit(char ch);

char filter_rule_out_all_special_char(char ch);

char filter_custom_char_model(char ch);

char filter_custom_char_group_model(char ch);


#endif /*__PW_FILTER_H__*/