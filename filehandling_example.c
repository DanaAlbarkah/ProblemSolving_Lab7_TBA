#include<stdio.h>

int main(){
    FILE *file;
    char data[100];

    // Creating and writing to a file
    file = fopen("example.txt","w");
    if(file == NULL) {
        printf("Error! Could not open file. \n");
        return 1;
    }
    fprintf(file,"This is a file handling example.\n");
    fprintf(file,"This is the second line.\n");
    fprintf(file,"This is the third line.\n");
    fclose(file);
    
    // Reading from a file
    file = fopen("example.txt","r");
    if(file == NULL){
        printf("Error! Couldn't open file.\n");
        return 1;
    }
    while (fgets(data,100,file) != NULL) {
        printf("%s",data);
    }
    fclose(file);
    return 0;
}