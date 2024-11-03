#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int bookID;
    char title[100];
    char author[50];
    int year;
    float price;
} Book;

int main() {
    Book books[1000];
    int N = 0, choice, id;
    float total;
    FILE *file;

    file = fopen("books.dat", "rb");
    if (file != NULL) {
        fread(&N, sizeof(int), 1, file);
        fread(books, sizeof(Book), N, file);
        fclose(file);
        printf("Loaded existing data from books.dat\n");
    } else {
        printf("No existing data found. Starting fresh.\n");
    }while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add a Book\n");
        printf("2. Display All Books\n");
        printf("3. Search for Book by ID\n");
        printf("4. Calculate Total Value of Books\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (N >= 1000) {
                printf("Library is full. Cannot add more books.\n");
                continue;
            }
            printf("Enter book details:\n");
            printf("ID: ");
            scanf("%d", &books[N].bookID);
            printf("Title: ");
            scanf(" %[^\n]", books[N].title);
            printf("Author: ");
            scanf(" %[^\n]", books[N].author);
            printf("Year: ");
            scanf("%d", &books[N].year);
            printf("Price (SAR): ");
            scanf("%f", &books[N].price);
            N++;

            file = fopen("books.dat", "wb");
            if (file != NULL) {
                fwrite(&N, sizeof(int), 1, file);
                fwrite(books, sizeof(Book), N, file);
                fclose(file);
                printf("Data saved to books.dat\n");
            } else {
                printf("Error: Could not save data.\n");
            }
  } else if (choice == 2) {
            if (N == 0) {
                printf("No books to display.\n");
            } else {
                printf("Book Details:\n");
                for (int i = 0; i < N; i++) {
                    printf("ID: %d, Title: %s, Author: %s, Year: %d, Price: %.2f SAR\n",
                           books[i].bookID, books[i].title, books[i].author, books[i].year, books[i].price);
                }
            }

        } else if (choice == 3) {
            printf("Enter Book ID to search: ");
            scanf("%d", &id);
            int found = 0;
            for (int i = 0; i < N; i++) {
                if (books[i].bookID == id) {
                    printf("Book found:\n");
                    printf("ID: %d, Title: %s, Author: %s, Year: %d, Price: %.2f SAR\n",
                           books[i].bookID, books[i].title, books[i].author, books[i].year, books[i].price);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("Book with ID %d not found.\n", id);
            }

        } else if (choice == 4) {
            total = 0;
            for (int i = 0; i < N; i++) {
                total += books[i].price;
            }
            printf("Total Value of Books: %.2f SAR\n", total);

        } else if (choice == 5) {
            file = fopen("books.dat", "wb");
            if (file != NULL) {
                fwrite(&N, sizeof(int), 1, file);
                fwrite(books, sizeof(Book), N, file);
                fclose(file);
                printf("Saving data to books.dat and Exiting...\n");
            } else {
                printf("Error: Could not save data.\n");
            }
            break;

        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
