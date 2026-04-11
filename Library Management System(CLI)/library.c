#include <stdio.h>
#include <string.h>

#define MAX 100

struct Book {
    int id;
    char title[50];
    char author[50];
    int isIssued;
};

struct Book library[MAX];
int count = 0;
 
// Add Book
void addBook() {
    printf("Enter Book ID: ");
    scanf("%d", &library[count].id);
    getchar();

    printf("Enter Title: ");
    fgets(library[count].title, 50, stdin);

    printf("Enter Author: ");
    fgets(library[count].author, 50, stdin);

    library[count].isIssued = 0;
    count++;

    printf("Book added successfully!\n");
}

// View Books
void viewBooks() {
    if (count == 0) {
        printf("No books available.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("\nID: %d\n", library[i].id);
        printf("Title: %s", library[i].title);
        printf("Author: %s", library[i].author);
        printf("Status: %s\n", library[i].isIssued ? "Issued" : "Available");
    }
}

// Search Book
void searchBook() {
    char keyword[50];
    getchar();
    printf("Enter title keyword: ");
    fgets(keyword, 50, stdin);

    for (int i = 0; i < count; i++) {
        if (strstr(library[i].title, keyword)) {
            printf("\nFound Book:\n");
            printf("ID: %d\nTitle: %sAuthor: %s", library[i].id,
                   library[i].title, library[i].author);
            return;
        }
    }
    printf("Book not found.\n");
}

// Issue Book
void issueBook() {
    int id;
    printf("Enter Book ID to issue: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (library[i].id == id) {
            if (library[i].isIssued) {
                printf("Already issued.\n");
            } else {
                library[i].isIssued = 1;
                printf("Book issued successfully!\n");
            }
            return;
        }
    }
    printf("Book not found.\n");
}

// Return Book
void returnBook() {
    int id;
    printf("Enter Book ID to return: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (library[i].id == id) {
            if (!library[i].isIssued) {
                printf("Book was not issued.\n");
            } else {
                library[i].isIssued = 0;
                printf("Book returned successfully!\n");
            }
            return;
        }
    }
    printf("Book not found.\n");
}

// Delete Book
void deleteBook() {
    int id;
    printf("Enter Book ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (library[i].id == id) {
            for (int j = i; j < count - 1; j++) {
                library[j] = library[j + 1];
            }
            count--;
            printf("Book deleted successfully!\n");
            return;
        }
    }
    printf("Book not found.\n");
}

// Count Books
void totalBooks() {
    printf("Total books: %d\n", count);
}

int main() {
    int choice;

    while (1) {
        printf("\n===== Library Menu =====\n");
        printf("1. Add Book\n");
        printf("2. View Books\n");
        printf("3. Search Book\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Delete Book\n");
        printf("7. Total Books\n");
        printf("8. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(); break;
            case 2: viewBooks(); break;
            case 3: searchBook(); break;
            case 4: issueBook(); break;
            case 5: returnBook(); break;
            case 6: deleteBook(); break;
            case 7: totalBooks(); break;
            case 8: return 0;
            default: printf("Invalid choice\n");
        }
    }
}
