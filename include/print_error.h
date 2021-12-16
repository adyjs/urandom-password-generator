#ifndef __PRINT_ERROR_H__
#define __PRINT_ERROR_H__

#include <stdio.h>
#include <stdlib.h>
#include "help.h"

void print_ERROR(const char *err_msg, \
                 const char *err_func, \
                 const int err_line_num);

#endif