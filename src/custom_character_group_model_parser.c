#include "custom_character_group_model_parser.h"


unsigned char group_model[GROUP_MODEL_SIZE];
unsigned char group_model_detail[GROUP_MODEL_DETAIL_SIZE];
size_t group_model_len;
size_t group_model_detail_len;

/*
group_model array[] = {
    lowercase alphabet flag,
    uppercase alphabet flag,
    number flag,
    special characters ...,
}
*/
void group_model_parse(void){
    size_t count = 3;
    // printf("count : %lu\n", count);
    // for(size_t i=0 ; i<6 ; i++){
    //     printf("in %d %c\n", group_model_detail[i], group_model_detail[i]);
    // }
    for(size_t i=0 ; i<group_model_len ; i++){
        if(group_model[i] >= 'a' && group_model[i] <= 'z'){
            group_model_detail[0] = 1;
            continue;
        }
        if(group_model[i] >= 'A' && group_model[i] <= 'Z'){
            group_model_detail[1] = 1;
            continue;
        }
        if(group_model[i] >= '0' && group_model[i] <= '9'){
            group_model_detail[2] = 1;
            continue;
        }
        // printf("before %lu %u %c\n", i, group_model[i], group_model[i]);
        group_model_detail[count++] = group_model[i];
    }
    group_model_detail_len = count;
    
    // printf("count : %lu\n", count);
    // for(size_t i=0 ; i<count ; i++){
    //     printf("in %d %c\n", group_model_detail[i], group_model_detail[i]);
    // }
    // exit(1);
}

void custom_char_group_model_parser(void){
    memset(group_model, '\0', GROUP_MODEL_SIZE);
    memset(group_model_detail, '\0', GROUP_MODEL_DETAIL_SIZE);
    unsigned char ch;
    printf("Input your custom characters group model between [] : ");
    do{
        ch = fgetc(stdin);
        if(printable_char_verify(ch) != -1){
            // printf("%lu %c\n", count, ch);
            group_model[group_model_len++] = ch;
        }
    }while((group_model_len < GROUP_MODEL_SIZE) && (ch != '\n'));
    // printf("%s %lu\n", group_model, group_model_len);
    group_model_verify();
    group_remove_dup();
    group_remove_bracket_and_shift();
    group_model_parse();
}
