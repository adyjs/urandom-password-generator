#ifndef __INFO_H__
#define __INFO_H__

#include <stdio.h>
#include <malloc.h>
#include "./args.h"
#include "./pw_filter.h"

#define INITIAL_MSG "Password Generator\n\nSelected Mode :\n"

extern char *mode_info;

void msg_concat_routine(char *msg);

void option_info_check(void);

void mode_info_display_before_start(void);

void msg_after_finished(void);

#endif /*__INFO_H__*/