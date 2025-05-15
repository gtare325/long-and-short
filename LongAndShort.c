#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 256

void to_upper(char *str) {
    for(int i=0; str[i]; i++) {
        if(str[i] >= 'a' && str[i] <= 'z') {
            str[i]-=32;
        }
    }
}

void to_lower(char *str) {
    for(int i=0; str[i]; i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i]+=32;
        }
    }
}

int main(int argc, char *argv[1]) {
    if(argc != 4) {
        printf("Usage: %s input.txt short.txt long.txt\n", argv[0]);
        return 1;
    }
    
    FILE *input = fopen(argv[1], "r");
    if(input == NULL) {
        printf("error: Could not open input file %s\n", argv[1]);
        return 1;
    }

    FILE *shortFile = fopen(argv[2], "w");
    if(shortFile == NULL) {
        printf("Error: Coud not open short output file %s\n", argv[2]);
        fclose(input);
        return 1;
    }

    FILE *longFile = fopen(argv[3], "w");
    if (longFile == NULL) {
        printf("error: Could not open long output file %s\n", argv[3]);
        fclose(input);
        fclose(shortFile);
        return 1;
    }

    char line[MAX_LINE];
    int shortCount = 0;
    int longCount = 0;

    while(fgets(line, sizeof(line), input)) {
        int len = strlen(line);

        if(line[len-1] == '\n') {
            line[len-1] = '\0';
        }

        if(strlen(line) < 20) {
            to_upper(line);
            fprintf(shortFile, "%s\n", line);
            shortCount++;
        }
        else {
            to_lower(line);
            fprintf(longFile, "%s\n", line);
            longCount++;
        }
    }

    fclose(input);
    fclose(shortFile);
    fclose(longFile);

    printf("%d lines written to %s\n", shortCount, argv[2]);
    printf("%d lines written to %s\n", longCount, argv[3]);

    return 0;
}
