#include <stdio.h>
#include <string.h>

#define word_length 10
#define ascii_length 300

void store_it(FILE *file, char morse_codes[ascii_length][word_length]);
void decode(char morse_codes[ascii_length][word_length], char morse[word_length]);

int main(){
    FILE *file;
    char morse_codes[ascii_length][word_length];
    char morse[word_length];
    
    file = fopen("alphabet.in", "r");
    if (file == NULL){
        printf("Error opening the file");
        return 1;
    }
    else{    store_it(file, morse_codes);
    }
    fclose(file);
    fgets(morse,word_length,stdin);
    decode(morse_codes, morse);
    return 0;
    
}
void store_it(FILE *file, char morse_codes[ascii_length][word_length]){

    char letter;
    char code[word_length];

    while (fscanf(file, "%c\t%s\n", &letter, code) != EOF){
        strcpy(morse_codes[(int)letter], code);
    }
/*
    for (int i = 0; i < ascii_length; i++){
        if (morse_codes[i][0] != '\0'){
            printf("%c %s\n", i, morse_codes[i]);
        }
    }
*/
}


