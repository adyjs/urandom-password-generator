#include "info.h"

char *mode_info = NULL;

void msg_concat_routine(char *msg){
    size_t msg_len;
    size_t malloced_len;
    size_t len_total;
    msg_len = strlen(msg);
    malloced_len = malloc_usable_size(mode_info);
    len_total = msg_len + malloced_len;
    mode_info = realloc(mode_info, len_total * sizeof(char));
    strcat(mode_info, msg);
}

void option_info_check(void){
    size_t msg_len = strlen(INITIAL_MSG);
    size_t malloced_len = 0;
    size_t len_total;

    mode_info = malloc(msg_len * sizeof(char));
    strcpy(mode_info, INITIAL_MSG);

    if(mode == DEFAULT_CHAR_OUTPUT){
        msg_concat_routine("  -Default Ouput\n");
    }
    if(mode & RULE_OUT_SP_CHAR_OUTPUT){
        msg_concat_routine("  -No Special Characters\n");
    }
    if(mode & RULE_OUT_UPPER_ALPHABET_CHAR_OUTPUT){
        msg_concat_routine("  -No Uppercase Alphabet Characters\n");
    }
    if(mode & RULE_OUT_LOWER_ALPHABET_CHAR_OUTPUT){
        msg_concat_routine("  -No Lowercase Alphabet Characters\n");
    }    
    if(mode & RULE_OUT_DIGIT_CHAR_OUTPUT){
        msg_concat_routine("  -No Digit Number Characters\n");
    }
    if(mode & CUSTOM_CHAR_MODEL_OUTPUT){
        msg_concat_routine("  -Custom Characters Model : [");
        msg_concat_routine(model);
        msg_concat_routine("]");
    }
    if(mode & CUSTOM_CHAR_GROUP_MODEL_OUTPUT){
        msg_concat_routine("  -Custom Characters Group Model : [");
        msg_concat_routine(model);
        msg_concat_routine("]");
    }
    

    msg_concat_routine("\n\n===Password Generating From Here===\n");
}

void mode_info_display_before_start(void){
    option_info_check();
    printf("%s", mode_info);
    free(mode_info);
}

void msg_after_finished(void){
    printf("\n===End===\n\n");
}
