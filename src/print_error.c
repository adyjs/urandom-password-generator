#include "print_error.h"

void print_ERROR(const char *err_msg, const char *err_func, const int err_line_num){
    printf("\n");
    printf("ERROR %s, %s, line: %d\n", err_msg, err_func, err_line_num);
    help();
    exit(1);
}
