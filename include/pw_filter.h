#ifndef __PW_FILTER_H__
#define __PW_FILTER_H__

#include <stdio.h>
#include "../include/args.h"
#include "../include/help.h"

#define GET_HELP 0                              // 0x00 0000_0000
#define DEFAULT_CHAR_OUTPUT 1                   // 0x01 0000_0001
#define RULE_OUT_SP_CHAR_OUTPUT 2               // 0x02 0000_0010 -s
#define RULE_OUT_UPPER_ALPHABET_CHAR_OUTPUT 4   // 0x04 0000_0100 -u
#define RULE_OUT_LOWER_ALPHABET_CHAR_OUTPUT 8   // 0x08 0000_1000 -l
#define RULE_OUT_DIGIT_CHAR_OUTPUT 16           // 0x10 0001_0000 -n

char filter_pipe(char ch);

char filter_only_printable_char(char ch);

char filter_rule_out_alphabet_lowercase(char ch);

char filter_rule_out_alphabet_uppercase(char ch);

char filter_rule_out_digit(char ch);

char filter_rule_out_all_special_char(char ch);

#endif /*__PW_FILTER_H__*/