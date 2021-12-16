#include "custom_common.h"

void remove_dup(void){
    for(size_t i=0 ; i<model_len-1 ; i++){
        for(size_t j=i+1 ; j<model_len ; j++){
            if(model[i] == model[j]){
                for(size_t k=j ; k<model_len-1 ; k++){
                    model[k] = model[k+1];
                }
                model_len -= 1;
            }
        }
    }
}

void remove_bracket_and_shift(void){
    for(size_t i=0 ; i<model_len-1 ; i++){
        model[i] = model[i+1];
    }
    model[model_len - 1] = '\0';
    model[model_len - 2] = '\0';
    model_len -= 2;
}

void model_verify(void){
    if(model[0] != '[' || model[model_len - 1] != ']'){
        print_ERROR("Custom characters model must start with '[' and end with ']', \
also model string length must under 100.", __FUNCTION__, __LINE__);
    }
}


void group_remove_dup(void){
    for(size_t i=0 ; i<group_model_len-1 ; i++){
        for(size_t j=i+1 ; j<group_model_len ; j++){
            if(group_model[i] == group_model[j]){
                for(size_t k=j ; k<group_model_len-1 ; k++){
                    group_model[k] = group_model[k+1];
                }
                group_model_len -= 1;
            }
        }
    }
}

void group_remove_bracket_and_shift(void){
    for(size_t i=0 ; i<group_model_len-1 ; i++){
        group_model[i] = group_model[i+1];
    }
    group_model[group_model_len - 1] = '\0';
    group_model[group_model_len - 2] = '\0';
    group_model_len -= 2;
}

void group_model_verify(void){
    if(group_model[0] != '[' || group_model[group_model_len - 1] != ']'){
        print_ERROR("Custom characters model must start with '[' and end with ']', \
also model string length must under 100.", __FUNCTION__, __LINE__);
    }
}

char printable_char_verify(unsigned char ch){
    if(ch >= '!' && ch <= '~'){
        return 1;
    }
    return -1;
}
