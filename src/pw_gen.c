#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "help.h"
#include "print_error.h"
#include "args.h"
#include "pw_source.h"
#include "pw_filter.h"
#include "info.h"


int main(int argc, char *argv[]){

    mode_settings(argc, argv);
    parse_pwlen_input(argc, argv);

    int fd = open(PW_SOURCE, O_RDONLY);
    if(fd == -1){
        print_ERROR("open failed", __FUNCTION__, __LINE__);
    }

    unsigned char buf[DEFAULT_READ_COUNT] = {'\0'};
    size_t count = 0;
    size_t effectively_count = 0;
    ssize_t read_count;
    char ch;

    mode_info_display_before_start();
    while(effectively_count < pw_len){
        // printf("\n count %lu, effectively_count %lu, read time\n", count, effectively_count);
        count = 0;
        read_count = read(fd, buf, DEFAULT_READ_COUNT);
        if(read_count == -1){
            print_ERROR("read failed", __FUNCTION__, __LINE__);
        }
        
        while(effectively_count < pw_len){
            ch = buf[count];
            if(filter_only_printable_char(ch) != -1){
                if(filter_pipe(ch) != -1){
                    printf("%c", ch);
                    effectively_count++;
                }
            }
            count++;
            if(count == read_count){
                break;
            }
        }
    }
    msg_after_finished();

    return 0;
}