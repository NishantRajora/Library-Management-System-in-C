#include<stdio.h>
#include<string.h>


void menu();
void lin();
void addBook();
void searchBooks();
void viewBooks();
void deleteBook();


void main()
{
    printf("+-----------------------------------------------------------------+\n");
    printf("|                                                                 |\n");
    printf("|                   LIBRARY MANAGEMENT SYSTEM                     |\n");
    printf("|                                                                 |\n");
    printf("|       By-                                                       |\n");
    printf("|            Monika          Neha            Nishant Rajora       |\n");
    printf("|            23csu203        23csu209        23csu220             |\n");
    printf("|                                                                 |\n");
    printf("+-----------------------------------------------------------------+\n\n");
    lin();
}



void lin() {
    char us[10], pass[10], m[] = "n", p[] = "1234";
    int n = 1;

    do {
        printf("Login Page\n");
        printf("username => ");
        scanf("%s", us);
        printf("password => ");
        scanf("%s", pass);

        if ((strcmp(us, m) == 0) && (strcmp(pass, p) == 0)) {
            n = 0;
            menu();
        } 
        else{
            printf("Try Again....\n");
        }
    } 
    while (n == 1); 
}


void menu()
{
    int c = 0;
    do
    {
        printf("+-----------------------------------------------------------------+\n");
        printf("|                   MAIN MENU                                     |\n");
        printf("+-----------------------------------------------------------------+\n");
        printf("|    1.  Add Books                                                |\n");
        printf("|    2.  Search Books                                             |\n");
        printf("|    3.  View Books                                               |\n");
        printf("|    4.  Delete Book                                              |\n");
        printf("|    5.  Exit                                                     |\n");
        printf("+-----------------------------------------------------------------+\n\n");
        printf("Enter choice => ");
        scanf("%d",&c);
        switch (c) {
        case 1:
            addBook();
            break;
        case 2:
            searchBooks();
            break;
        case 3:
            viewBooks();
            break;
        case 4:
            deleteBook();
            break;
        case 5:
            printf("\nThank you.....\n");
            break;
        default:
            printf("\n!!! INVALID INPUT !!! \n Try again...\n");
        }
    } while (c != 5);
}



struct Book {
    char title[100];
    char author[100];
    char bookcode[15];
};


void addBook() {

    struct Book book;

    printf("Add a New Book\n");

    printf("Enter Book Title => ");
    scanf(" %s", book.title);

    printf("Enter Author => ");
    scanf(" %s", book.author);

    printf("Enter Book Code => ");
    scanf(" %s", book.bookcode);

    FILE *file = fopen("bookdata.txt", "a");

    if (file == NULL) {
        printf("Error opening the file for writing.\n");
        return;
    }

    fprintf(file, "Title: %s\nAuthor: %s\nBook Code: %s\n\n", book.title, book.author, book.bookcode);
    fclose(file);

    printf("Book data added\n");
}


void searchBooks() {
    char kword[100];
    int found = 0;
    printf("Search Books\n");
    printf("Enter search keyword (Title, Author, or Book Code): ");
    scanf(" %s", kword);

    FILE *file = fopen("bookdata.txt", "r");
    if (file == NULL) {
        printf("Error opening the file for reading.\n");
        return;
    }

    struct Book book;
    while (fscanf(file, "Title: %s\nAuthor: %s\nBook Code: %s\n\n", book.title, book.author, book.bookcode) != EOF) {
        if (strstr(book.title, kword) != NULL || strstr(book.author, kword) != NULL || strstr(book.bookcode, kword) != NULL) {

            printf("Title: %s\nAuthor: %s\nBook Code: %s\n\n", book.title, book.author, book.bookcode);
            found = 1;
        }
    }

    fclose(file);

    if (!found) {
        printf("No matching books found.\n");
    }
}


void viewBooks() {
    printf("View Books\n");

    FILE *file = fopen("bookdata.txt", "r");
    if (file == NULL) {
        printf("Error opening the file for reading.\n");
        return;
    }

    struct Book book;
    int bc = 0;

    while (fscanf(file, "Title: %s\nAuthor: %s\nBook Code: %s\n\n", book.title, book.author, book.bookcode) != EOF) {
        bc++;
        printf("Book %d:\n", bc);
        printf("Title: %s\nAuthor: %s\nBook Code: %s\n\n", book.title, book.author, book.bookcode);
    }

    fclose(file);

    if (bc == 0) {
        printf("No books found in the library.\n");
    }
}



void deleteBook() {
    char kword[100];
    int found = 0;
    printf("Delete a Book\n");
    printf("Enter search keyword (Title, Author, or Book Code) to delete a book: ");
    scanf(" %s", kword);

    FILE *ifile = fopen("bookdata.txt", "r");
    if (ifile == NULL) {
        printf("Error opening the file for reading.\n");
        return;
    }

    FILE *ofile = fopen("tempbookdata.txt", "w");
    if (ofile == NULL) {
        printf("Error creating the temporary file.\n");
        fclose(ifile);
        return;
    }

    struct Book book;

    while (fscanf(ifile, "Title: %s\nAuthor: %s\nBook Code: %s\n\n", book.title, book.author, book.bookcode) != EOF) {
        if (strstr(book.title, kword) == NULL && strstr(book.author, kword) == NULL && strstr(book.bookcode, kword) == NULL) {

            fprintf(ofile, "Title: %s\nAuthor: %s\nBook Code: %s\n\n", book.title, book.author, book.bookcode);
        } else {
            found = 1;
        }
    }

    fclose(ifile);
    fclose(ofile);

    if (found) {
        remove("bookdata.txt");
        
        rename("tempbookdata.txt", "bookdata.txt");
        printf("Book has been deleted.\n");
    } else {
        printf("No matching books found for deletion.\n");
        remove("tempbookdata.txt");
    }
}


        