#include "help.h"



void help(void){
    printf("\n");
    printf("Password Generator\n");
    printf("    This generator is based-on /dev/urandom of Linux system,\n");
    printf("    by using some rules for selecting the ASCII printable characters output from /dev/urandom.\n");
    printf("\n");
    printf("USAGE:\n");
    printf("    pw-generator password_length [-option_1 | -option_2 | ... ]\n");
    printf("\n");
    printf("Must arg:\n");
    printf("    password_length range : 1 ~ 2600\n");
    printf("\n");
    printf("Options:\n");
    printf("    [empty]  : Empty option is default mode that would randomly output ASCII printable characters\n");
    printf("    -h       : Help\n");
    printf("    -s       : Rule out the output of the special characters\n");
    printf("    -n       : Rule out the output of the digit characters\n");
    printf("    -u       : Rule out the output of the uppercase of alphabet characters\n");
    printf("    -l       : Rule out the output of the lowercase of alphabet characters\n");
    printf("    -c       : Customthe output of ASCII printable characters\n");
    printf("    -g       : Customthe output of group of ASCII printable characters\n");
    printf("\n");
    printf("Notice:\n");
    printf("  Some options will conflict each other, some are exclusive options,\n");
    printf("\n");
    printf("  for example :\n");
    printf("      -s -n -u -l, if using these options simultaneously, then there is no output,\n");
    printf("      because all characters had been ruled out\n");
    printf("\n");
    printf("      -c -g, These are 2 exclusive modes\n");
    printf("\n");
    printf("  examples : [-s -c], [-n -g], [-s -c -g]\n");
    printf("      In first examples, the -s option in [-s -c], -s option will be ignored\n");
    printf("      In second examples, the -n option in [-n -g], -n option will be ignored\n");
    printf("      In third examples, the -s -g option in [-s -c -g], -s -g option will be ignored\n");
    printf("\n");
    printf("\n");
    printf("\n");
    // printf("  -x : only the hexadecimal number\n");
}