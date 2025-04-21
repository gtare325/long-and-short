#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 256
int main(int argc, char *argv[]) {
    if (argc !=3) {
        printf("Usage: %s search_string filename\n", argv[0]);
        return -1;
    }

    char *search_term = argv[1];
    char *filename = argv[2];

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return -1;
    }

    char line[MAX_LINE];
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, search_term)) {
            printf("%s", line);
        }
    }

    fclose(file);
    return 0;
}