#include "args.h"

size_t pw_len;
unsigned char mode;

ssize_t option_validate(char *option){
    size_t len = strlen(option);
    if(len == 2 && *option == '-'){
        return 1;
    }
    return -1;
}

void options(char opt){
    switch(opt){ 
        case 'h':{
            help();
            exit(1);
        }
        case 's':{
            mode |= RULE_OUT_SP_CHAR_OUTPUT;
            break;
        }
        case 'u':{
            mode |= RULE_OUT_UPPER_ALPHABET_CHAR_OUTPUT;
            break;
        }
        case 'l':{
            mode |= RULE_OUT_LOWER_ALPHABET_CHAR_OUTPUT;
            break;
        }
        case 'n':{
            mode |= RULE_OUT_DIGIT_CHAR_OUTPUT;
            break;
        }
        defualt:
            break;
    }
}

void mode_settings(int argc, char *argv[]){
    if(argc < 2 || argc > 7){
        print_ERROR("Input args error, please check manual", __FUNCTION__, __LINE__);
    }
    mode = DEFAULT_CHAR_OUTPUT;
    for(size_t i=1 ; i<argc ; i++){
        if(option_validate(argv[i]) != -1){
            options(*(argv[i]+1));
        }
    }
    // printf("mode : %x\n", mode);
}


int pw_len_validate(char *str){
    size_t len = strlen(str);
    for(size_t i=0 ; i<len ; i++){
        if(*(str+i) >= '0' && *(str+i) <= '9'){
            continue;
        }
        return -1;
    }
    return 1;
}

void parse_pwlen_input(int argc, char *argv[]){
    int sscanf_match_status;
    int status = 0;

    for(size_t i=1 ; i<argc ; i++){
        // looking for and validate pw length (number string) input
        if( *(argv[i]) != '-' && (1 == pw_len_validate(argv[i])) ){    
            sscanf_match_status = sscanf(argv[i], "%lu", &pw_len);
            // printf("pw_len : %lu\n", pw_len);
            status++;
            if(sscanf_match_status != 1){
                print_ERROR("sscanf match status failed", __FUNCTION__, __LINE__);
            }
            if(pw_len <= 0 || pw_len > 2600){
                print_ERROR("password length is out of range", __FUNCTION__, __LINE__);
            }
        }
    }
    if(status != 1){
        print_ERROR("There is no password_length or more than 1 password_length input,\n      \
password_length should be 0 ~ 2500,\n      \
no negtive sign or other special characters,\n      \
sscanf match status failed", __FUNCTION__, __LINE__);
    }
}