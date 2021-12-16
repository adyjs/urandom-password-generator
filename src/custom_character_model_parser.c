#include "custom_character_model_parser.h"

#define MODEL_SIZE 100
unsigned char model[MODEL_SIZE];
size_t model_len;

void custom_char_model_parser(void){
    memset(model, '\0', MODEL_SIZE);
    unsigned char ch;
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
    remove_dup();
    remove_bracket_and_shift();
}
