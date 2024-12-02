#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define word_length 10
#define ascii_length 300
#define message_size 300

void store_it(FILE *file, char morse_codes[ascii_length][word_length]);
void encode(FILE *input_file, FILE *output_file, char morse_codes[ascii_length][word_length]);
void decode(FILE *input_file, FILE *output_file, char morse_codes[ascii_length][word_length]);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file> <E/D/X>\n", argv[0]);
        return 1;
    }
    FILE *file;
    char morse_codes[ascii_length][word_length];
    char morse[word_length];
    char* input_filename = argv[1];   
    char* output_filename = argv[2];       
    char choice;

    // Store Morse codes from the file
    file = fopen("alphabet.in", "r");
    if (file == NULL) {
        printf("Error opening the file\n");
        return 1;
    }
    store_it(file, morse_codes);
    fclose(file);

    // Get user inout
    printf("(E)ncode (D)ecode e(X)it \n");
    scanf("%c", &choice);

    // Open them
    FILE *input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error opening the input file\n");
        return 1;
    }
    FILE *output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error opening the output file\n");
        fclose(input_file);
        return 1;
    }

    // switch case
    switch (choice) {
        case 'E':
            encode(input_file, output_file, morse_codes);
            break;
        case 'D':
            decode(input_file, output_file, morse_codes);
            break;
        case 'X':
            return 0;
        default:
            printf("Invalid choice\n");
            break;
    }

    // Close files
    fclose(input_file);
    fclose(output_file);

    return 0;
}

void store_it(FILE *file, char morse_codes[ascii_length][word_length]) {
    char letter;
    char code[word_length];

    while (fscanf(file, "%c\t%s\n", &letter, code) != EOF) {
        strcpy(morse_codes[(int)letter], code);
    }
}

void encode(FILE *input_file, FILE *output_file, char morse_codes[ascii_length][word_length]) {
    char letter;
    char message[message_size] = "";
    while ((letter = fgetc(input_file)) != EOF) {
        letter = toupper(letter);
        if (letter >= 0 && letter < ascii_length && morse_codes[(int)letter][0] != '\0') {
            strcat(message, morse_codes[(int)letter]);
            strcat(message, " ");
        } else if (letter == ' ') {
            strcat(message, "/ ");                  
        } else {
            strcat(message, "? ");
        }
    }
    printf("Encoded message: %s\n", message);   
    fprintf(output_file, "%s\n", message);
}

void decode(FILE *input_file, FILE *output_file, char morse_codes[ascii_length][word_length]) {
    char morse[word_length];
    char message[message_size] = "";    
    while (fscanf(input_file, "%s", morse) != EOF) {
        if (strcmp(morse, "/") == 0) {
            strcat(message, " ");
            fputc(' ', output_file);               
        } else {
            int found = 0;
            for (int i = 0; i < ascii_length && !found; i++) {
                if (strcmp(morse_codes[i], morse) == 0) {
                    char decoded_char[2] = {i, '\0'};
                    strcat(message, decoded_char);
                    fputc(i, output_file);
                    found = 1;
                }
            }
        }
    }
    printf("Decoded message: %s\n", message);           
    fputc('\n', output_file);
}
