#include "pw_filter.h"


/*
#define GET_HELP                            0   // 0x00 0000_0000 -h
#define DEFAULT_CHAR_OUTPUT                 1   // 0x01 0000_0001
#define RULE_OUT_SP_CHAR_OUTPUT             2   // 0x02 0000_0010 -s
#define RULE_OUT_UPPER_ALPHABET_CHAR_OUTPUT 4   // 0x04 0000_0100 -u
#define RULE_OUT_LOWER_ALPHABET_CHAR_OUTPUT 8   // 0x08 0000_1000 -l
#define RULE_OUT_DIGIT_CHAR_OUTPUT          16  // 0x10 0001_0000 -n
#define CUSTOM_CHAR_MODEL_OUTPUT            32  // 0x20 0010_0000 -c
#define CUSTOM_CHAR_GROUP_MODEL_OUTPUT      64  // 0x40 0100_0000 -c
*/

char filter_pipe(char ch){

    if( mode == 0x1f ){
        print_ERROR("You have ruled out all of the possibilities of pw char output", \
                    __FUNCTION__,\
                    __LINE__);
    }
    if( mode & RULE_OUT_SP_CHAR_OUTPUT && \
        filter_rule_out_all_special_char(ch) == -1){
        return -1;
    }
    if( mode & RULE_OUT_UPPER_ALPHABET_CHAR_OUTPUT && \
        filter_rule_out_alphabet_uppercase(ch) == -1){
        return -1;
    }
    if( mode & RULE_OUT_LOWER_ALPHABET_CHAR_OUTPUT && \
        filter_rule_out_alphabet_lowercase(ch) == -1){
        return -1;
    }
    if( mode & RULE_OUT_DIGIT_CHAR_OUTPUT && \
        filter_rule_out_digit(ch) == -1){
        return -1;
    }
    if( mode & CUSTOM_CHAR_MODEL_OUTPUT && \
        filter_custom_char_model(ch) == -1){
        return -1;
    }
    return ch;
}

char filter_custom_char_model(char ch){
    for(size_t i=0 ; i<model_len ; i++){
        if(ch == model[i])
            return ch;
    }
    return -1;
}

char filter_only_printable_char(char ch){
    if(ch >= '!' && ch <= '~'){
        return ch;
    }
    return -1;
}

char filter_rule_out_alphabet_lowercase(char ch){
    if(ch >= 'a' && ch <= 'z'){
        return -1;
    }
    return ch;
}

char filter_rule_out_alphabet_uppercase(char ch){
    if(ch >= 'A' && ch <= 'Z'){
        return -1;
    }
    return ch;
}

char filter_rule_out_digit(char ch){
    if(ch >= '0' && ch <= '9'){
        return -1;
    }
    return ch;
}

char filter_rule_out_all_special_char(char ch){
    if((ch >= '!' && ch <= '/') || (ch >= ':' && ch <= '@') || \
       (ch >= '[' && ch <= '`') || (ch >= '{' && ch <= '~')){
        return -1;
    }
    return ch;
}
