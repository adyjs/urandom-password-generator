#include "pw_filter.h"

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
    if( mode & CUSTOM_CHAR_GROUP_MODEL_OUTPUT && \
        filter_custom_char_group_model(ch) == -1){
        return -1;
    }
    return ch;
}

char filter_custom_char_group_model(char ch){
    if(group_model_detail[0] == 1 && ch >= 'a' && ch <= 'z'){
        return ch;
    }
    if(group_model_detail[1] == 1 && ch >= 'A' && ch <= 'Z'){
        return ch;
    }
    if(group_model_detail[2] == 1 && ch >= '0' && ch <= '9'){
        return ch;
    }
    for(size_t i=3 ; i<group_model_detail_len ; i++){
        if(ch == group_model_detail[i]){
            return ch;
        }
    }
    
    return -1;
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
