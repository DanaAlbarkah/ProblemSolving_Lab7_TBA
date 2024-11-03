#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int shift = 3;
    char choice, inputChoice;
    char text[1000], result[1000];
    char filename[100];
    FILE *file;
 printf("Welcome to the Caesar Cipher Program!\n");
    printf("Do you want to perform (E)ncryption or (D)ecryption? ");
    scanf(" %c", &choice);

    printf("Do you want to process data from a (F)ile or enter a (S)tring? ");
    scanf(" %c", &inputChoice);

    if (inputChoice == 'F' || inputChoice == 'f') {
        printf("Enter the filename: ");
        scanf("%s", filename);

        file = fopen(filename, "r");
        if (!file) {
            printf("Error: Could not open file.\n");
            return 1;
        }

        fread(text, sizeof(char), sizeof(text) - 1, file);
        fclose(file);
        text[strcspn(text, "\n")] = '\0';

    } else if (inputChoice == 'S' || inputChoice == 's') {
        printf("Please enter the text: ");
        scanf(" %[^\n]", text);
    } else {
        printf("Invalid input choice.\n");
        return 1;   }

    for (int i = 0; text[i] != '\0'; i++) {
        if (choice == 'E' || choice == 'e') {
            if (text[i] >= 'A' && text[i] <= 'Z') {
                result[i] = ((text[i] - 'A' + shift) % 26) + 'A';
            } else if (text[i] >= 'a' && text[i] <= 'z') {
                result[i] = ((text[i] - 'a' + shift) % 26) + 'a';
            } else {
                result[i] = text[i];
            }
        } else if (choice == 'D' || choice == 'd') {
            if (text[i] >= 'A' && text[i] <= 'Z') {
                result[i] = ((text[i] - 'A' - shift + 26) % 26) + 'A';
            } else if (text[i] >= 'a' && text[i] <= 'z') {
                result[i] = ((text[i] - 'a' - shift + 26) % 26) + 'a';
            } else {
                result[i] = text[i];
            }
        } else {
            printf("Invalid choice.\n");
            return 1;
        }
    }

    result[strlen(text)] = '\0';

    printf("Result: %s\n", result);

    return 0;}
   
