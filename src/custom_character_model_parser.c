#include "custom_character_model_parser.h"

#define MODEL_SIZE 100
char model[MODEL_SIZE];
size_t model_len;

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
    remove_dup();
    remove_bracket_and_shift();
}


char printable_char_verify(char ch){
    if(ch >= '!' && ch <= '~'){
        return 1;
    }
    return -1;
}
void custom_model_parser(void){
    memset(model, '\0', MODEL_SIZE);
    char ch;
    printf("Input your custom characters model between [] : ");
    do{
        ch = fgetc(stdin);
        if(printable_char_verify(ch) != -1){
            // printf("%lu %c\n", count, ch);
            model[model_len++] = ch;
        }
    }while((model_len < MODEL_SIZE) && (ch != '\n'));
    // printf("%s %lu\n", model, model_len);
    model_verify();
}
