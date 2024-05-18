#include<stdio.h>
#include<string.h> 
int main(int argc, char* argv[]) {
    if (argc != 3 || (strcmp(argv[1], "-c") && strcmp(argv[1], "-w"))) {
        printf("Usage: %s [-c|-w] \n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[2], "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", argv[2]);  
        return 1;
    }

    int character_count = 0, word_count = 1;
    int prev_char = ' ';

    while (fscanf(file, "%c", &prev_char) != EOF) {
        character_count++;
        if (prev_char == ' ' || prev_char == ',' || prev_char == '\t' || prev_char == '\n') {
            word_count++;
        }
    }

    fclose(file);

    if (!strcmp(argv[1], "-c")) {
        printf("Characters: %d\n", character_count);
    }
    else if (!strcmp(argv[1], "-w")) {
        printf("Words: %d\n", word_count - 1);
    }

    return 0;
}

