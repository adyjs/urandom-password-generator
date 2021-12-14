#include "help.h"



void help(void){
    printf("Password Generator\n");
    printf("\n");
    printf("\n");
    printf("USAGE:\n");
    printf("  pw_gen password_length [-option_1 | -option_2 | ... ]\n");
    printf("\n");
    printf("Must arg:\n");
    printf("  password_length range : 1 ~ 2600\n");
    printf("\n");
    printf("Options:\n");
    printf("  -h : help\n");
    printf("  -s : rule out the output of the special characters\n");
    printf("  -n : rule out the output of the digit characters\n");
    printf("  -u : rule out the output of the uppercase of alphabet characters\n");
    printf("  -l : rule out the output of the lowercase of alphabet characters\n");
    printf("\n");
    printf("\n");
    // printf("  -x : only the hexadecimal number\n");
}