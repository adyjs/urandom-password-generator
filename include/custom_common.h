#ifndef __CUSTOM_COMMON_H__
#define __CUSTOM_COMMON_H__
        

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "print_error.h"


#define MODEL_SIZE 100
#define GROUP_MODEL_SIZE 100
#define GROUP_MODEL_DETAIL_SIZE 50

extern unsigned char model[MODEL_SIZE];
extern unsigned char group_model[GROUP_MODEL_SIZE];
extern unsigned char group_model_detail[GROUP_MODEL_DETAIL_SIZE];

extern size_t model_len;
extern size_t group_model_len;
extern size_t group_model_detail_len;

void remove_dup(void);
void remove_bracket_and_shift(void);
void model_verify(void);

void group_remove_dup(void);
void group_remove_bracket_and_shift(void);
void group_model_verify(void);

char printable_char_verify(unsigned char ch);


#endif /*__CUSTOM_COMMON_H__*/

