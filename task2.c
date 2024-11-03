#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE *file = fopen("task2test.txt", "r");
    if (file == NULL) {
        printf("Could not open file.\n");
        return 1;
    }

    char line[256];
    int lineCount = 0, wordCount = 0, charCount = 0;
    int inWord = 0;

    while (fgets(line, sizeof(line), file)) {
        lineCount++;
        
        for (int i = 0; line[i] != '\0'; i++) {
            charCount++;

            if (line[i]==' ' || line[i]=='\t' || line[i]== '\n') {
                inWord = 0;
            } else if (!inWord) {
                inWord = 1;
                wordCount++;
            }
        }
    }

    fclose(file);

    printf("Lines: %d\n", lineCount);
    printf("Words: %d\n", wordCount);
    printf("Characters: %d\n", charCount);

    return 0;
}
