#include <stdio.h>
#include <string.h>
#define MAX_BOOKS 100
#include "datatype.h"
#include <ctype.h>
#include <conio.h>

struct Book books[MAX_BOOKS];
int bookCount = 0;
#define MAX_ADMIN 50

void menuSach() {
    printf("***Book Management System Using C***\n");
    printf("\n");
    printf("               MENU                     \n");
    printf("      =======================\n");
    printf("      [1] Add A New Book.\n");
    printf("      [2] Show All Books.\n");
    printf("      [3] Search A Book.\n");
    printf("      [4] Edit A Book.\n");
    printf("      [5] Delete A Book.\n");
    printf("      [6] Sort Books by Price.\n");
    printf("      [7] Read Books From File");
    printf("      [0] Exit the Program.\n");
    printf("      ==========================\n");
    printf("Enter The Choice: ");
}

void displayMenuLibrary(){
	int choice;
    do {
        menuSach();
        scanf("%d", &choice);
		
		while (getchar() != '\n');
        switch (choice) {
            case 1:
                addBook();
                
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                searchBookByTitle();
                break;
            case 4:
                editBook();
                break;
            case 5:
                deleteBook();
                break;
            case 6:
                sortBooksByPrice();
                break;
            case 7:
            	ReadListBooksFromFile();
            	break; 
            case 0:
                printf("Exiting program. Thank you!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);
}


//Tiet 1
void displayBooks() {
   
    if (bookCount == 0) {
        printf("There are no books in the list.\n");
        return;
    }

    printf("                         **** All Books ****\n");
    printf("|============|===========================|======================|============|============|=================|\n");
    printf("| %-10s | %-25s | %-20s | %-10s | %-10s | %-15s |\n", "ID", "Title", "Author", "Quantity", "Price", "Publication");
    printf("|============|===========================|======================|============|============|=================|\n");

	int i;  
    for (i = 0; i < bookCount; i++) {
        printf("| %-10s | %-25s | %-20s | %-10d | %-10d | %02d/%02d/%04d      |\n", 
               books[i].bookId, 
               books[i].title, 
               books[i].author, 
               books[i].quantity, 
               books[i].price,
               books[i].publication.day,
               books[i].publication.month,
               books[i].publication.year);
      
        printf("|------------|---------------------------|----------------------|------------|------------|-----------------|\n");
    }

    printf("\n");
    char choice;
    do {
        printf("Go back (b)? or Exit (0)?: ");
        scanf(" %c", &choice);
        if (choice == 'b') {
            return; 
        } else if (choice == '0') {
            printf("==========Thank You==========\n");
            printf("==========See You Soon==========\n\n");
            printf("--------------------------------------");
            exit(0); 
        } else {
            printf("Invalid choice. Please enter 'b' or '0'.\n");
        }
    } while (choice != 'b' && choice != '0');
    printf("\n");
    printf("\n");
    printf("\n");
}


//Tiet 4
int isValidDate(int day, int month, int year) {
   
    if (year < 1 || month < 1 || month > 12 || day < 1) {
        return 0;
    }

 
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        daysInMonth[1] = 29; 
    }

    if (day > daysInMonth[month - 1]) {
        return 0;
    }

    return 1;
}


//Tiet 1
void addBook() {
    printf("                         **** Add A New Book ****\n");
    if (bookCount >= MAX_BOOKS) {
        printf("Cannot add book, list is full.\n");
        return;
    }

    struct Book newBook;
    int valid;

  do {
    valid = 1; 
    char inputBuffer[10]; 

    printf("Enter the Book ID: ");
    fgets(inputBuffer, sizeof(inputBuffer), stdin);

    
    inputBuffer[strcspn(inputBuffer, "\n")] = '\0';

    if (strlen(inputBuffer) == 0) {
        printf("Error: Book ID cannot be empty. Please try again.\n");
        valid = 0;
    } else if (strlen(inputBuffer) > 10) {
        printf("Error: Book ID must be <= 10 characters. Please try again.\n");
        valid = 0;
    } else {
        
        int i;
        for (i = 0; i < bookCount; i++) {
            if (strcmp(books[i].bookId, inputBuffer) == 0) {
                printf("Error: Book ID '%s' already exists.\n", inputBuffer);
                valid = 0;
                break;
            }
        }
    }

	if (valid) {
	    strcpy(newBook.bookId, inputBuffer); 
	}

   } while (!valid);


    do {
        valid = 1; 
        char inputBuffer[30];
        printf("Enter the Title: ");
        fgets(inputBuffer, sizeof(inputBuffer), stdin);
        inputBuffer[strcspn(inputBuffer, "\n")] = '\0';
        
        if (strlen(inputBuffer) == 0) {
	        printf("Error: Title book cannot be empty. Please try again.\n");
	        valid = 0;
        }
        else if (strlen(inputBuffer) > 30) {
            printf("Error: Title must be <= 30 characters.\n");
            valid = 0;
        } else {
        	int i;
            for (i = 0; i < bookCount; i++) {
                if (strcmp(books[i].title, inputBuffer) == 0) {
                    printf("Error: Book Title '%s' already exists.\n", inputBuffer);
                    valid = 0;
                    break;
                }
            }
        }
	 if (valid) {
		strcpy(newBook.title, inputBuffer); 
	 }
    } while (!valid);


    do {
        valid = 1; 
        char inputBuffer[20];
        printf("Enter the Author: ");
        fgets(inputBuffer, sizeof(inputBuffer), stdin);
        inputBuffer[strcspn(inputBuffer, "\n")] = '\0';
        
        if (strlen(inputBuffer) == 0) {
	        printf("Error: Author book cannot be empty. Please try again.\n");
	        valid = 0;
        }
        else if (strlen(inputBuffer) > 30) {
            printf("Error: Author must be <= 20 characters.\n");
            valid = 0;
        } else {
            valid = 1;
        }
        if (valid) {
		   strcpy(newBook.author, inputBuffer); 
	    }
    } while (!valid);

  
	do {
	    valid = 1; 
	    char inputBuffer[20];
	    printf("Enter the Quantity: ");
	    fgets(inputBuffer, sizeof(inputBuffer), stdin);
	    inputBuffer[strcspn(inputBuffer, "\n")] = '\0'; 
	
	    if (strlen(inputBuffer) == 0) {
	        printf("Error: Quantity cannot be empty. Please enter a positive number.\n");
	        valid = 0;
	    } else {
	        int quantity = atoi(inputBuffer); 
	        if (quantity <= 0) {
	            printf("Error: Quantity must be a positive number.\n");
	            valid = 0;
	        } else {
	            newBook.quantity = quantity;
	        }
	    }
	} while (!valid);
	
	do {
	    valid = 1; 
	    char inputBuffer[20];
	    printf("Enter the Price: ");
	    fgets(inputBuffer, sizeof(inputBuffer), stdin);
	    inputBuffer[strcspn(inputBuffer, "\n")] = '\0';
	
	    if (strlen(inputBuffer) == 0) {
	        printf("Error: Price cannot be empty. Please enter a positive number.\n");
	        valid = 0;
	    } else {
	        int price = atoi(inputBuffer); 
	        if (price <= 0) {
	            printf("Error: Price must be a positive number.\n");
	            valid = 0;
	        } else {
	            newBook.price = price;
	        }
	    }
	} while (!valid);

    
     do {
	    valid = 1;
	    char inputBuffer[50];
	    printf("Enter the Publication Date (dd mm yyyy): ");
	    fgets(inputBuffer, sizeof(inputBuffer), stdin);
	    inputBuffer[strcspn(inputBuffer, "\n")] = '\0'; 
	
	    if (strlen(inputBuffer) == 0) {
	        printf("Error: Publication date cannot be empty. Please enter a valid date.\n");
	        valid = 0;
	    } else {
	        int day, month, year;
	        if (sscanf(inputBuffer, "%d %d %d", &day, &month, &year) != 3 || 
	            !isValidDate(day, month, year)) {
	            printf("Error: Invalid publication date. Please enter a valid date in the format dd mm yyyy.\n");
	            valid = 0;
	        } else {
	            newBook.publication.day = day;
	            newBook.publication.month = month;
	            newBook.publication.year = year;
	        }
	    }
	} while (!valid);
    
  
    books[bookCount] = newBook;
    bookCount++;

    saveBooksToFile();

    printf("\n");
    printf("Book Added Successfully.\n");
    printf("\n");

    char choice;
    do {
        printf("Go back (b)? or Exit (0)?: ");
        scanf(" %c", &choice);
        if (choice == 'b') {
            return; 
        } else if (choice == '0') {
            printf("==========Thank You==========\n");
            printf("==========See You Soon==========\n\n");
            printf("--------------------------------------\n");
            exit(0); 
        } else {
            printf("Invalid choice. Please enter 'b' or '0'.\n");
        }
    } while (choice != 'b' && choice != '0');
}


//Tiet 2
void editBook() {
    printf("                         **** Edit A Book ****\n");
    char id[10];
    
    printf("Enter the Book ID : ");
    scanf("%s", id);

    int index = -1;
    int i;
    for (i = 0; i < bookCount; i++) {
        if (strcmp(books[i].bookId, id) == 0) {
            index = i;
            break;
        }
    }
    
  

    if (index == -1) {
        printf("Error: Book with ID '%s' not found.\n", id);
        return;
    }
    
    printf("One Book Found for ID: %s\n\n", books[index].bookId);
	printf("Book Information\n");
	printf("------------------------------\n");
	printf("%-15s: %s\n", "ID", books[index].bookId);
	printf("%-15s: %s\n", "Title", books[index].title);
	printf("%-15s: %s\n", "Author", books[index].author);
	printf("%-15s: %d\n", "Quantity", books[index].quantity);
	printf("%-15s: %d\n", "Price", books[index].price);
	printf("%-15s: %02d/%02d/%04d\n\n", "Publication Date", 
	       books[index].publication.day, 
	       books[index].publication.month, 
	       books[index].publication.year);
	printf("------------------------------\n");
	printf("                  ***************Update The New Book *****\n");
	int valid;
    do {
        valid = 1; 
        char inputBuffer[30];
        printf("Enter the new Title: ");
        fgets(inputBuffer, sizeof(inputBuffer), stdin);
        inputBuffer[strcspn(inputBuffer, "\n")] = '\0';
        
        if (strlen(inputBuffer) == 0) {
	        printf("Error: Title book cannot be empty. Please try again.\n");
	        valid = 0;
        }
        else if (strlen(inputBuffer) > 30) {
            printf("Error: Title must be <= 30 characters.\n");
            valid = 0;
        } else {
        	int i;
            for (i = 0; i < bookCount; i++) {
                if (strcmp(books[i].title, inputBuffer) == 0) {
                    printf("Error: Book Title '%s' already exists.\n", inputBuffer);
                    valid = 0;
                    break;
                }
            }
        }
	 if (valid) {
		strcpy(books[index].title, inputBuffer); 
	 }
    } while (!valid);

   
     do {
        valid = 1; 
        char inputBuffer[20];
        printf("Enter the new Author: ");
        fgets(inputBuffer, sizeof(inputBuffer), stdin);
        inputBuffer[strcspn(inputBuffer, "\n")] = '\0';
        
        if (strlen(inputBuffer) == 0) {
	        printf("Error: Author book cannot be empty. Please try again.\n");
	        valid = 0;
        }
        else if (strlen(inputBuffer) > 30) {
            printf("Error: Author must be <= 20 characters.\n");
            valid = 0;
        } else {
            valid = 1;
        }
        if (valid) {
		   strcpy(books[index].author, inputBuffer); 
	    }
    } while (!valid);
    
    

    do {
	    valid = 1; 
	    char inputBuffer[20];
	    printf("Enter the Quantity: ");
	    fgets(inputBuffer, sizeof(inputBuffer), stdin);
	    inputBuffer[strcspn(inputBuffer, "\n")] = '\0'; 
	
	    if (strlen(inputBuffer) == 0) {
	        printf("Error: Quantity cannot be empty. Please enter a positive number.\n");
	        valid = 0;
	    } else {
	        int quantity = atoi(inputBuffer); 
	        if (quantity <= 0) {
	            printf("Error: Quantity must be a positive number.\n");
	            valid = 0;
	        } else {
	            books[index].quantity = quantity;
	        }
	    }
	} while (!valid);

    do {
	    valid = 1; 
	    char inputBuffer[20];
	    printf("Enter the Price: ");
	    fgets(inputBuffer, sizeof(inputBuffer), stdin);
	    inputBuffer[strcspn(inputBuffer, "\n")] = '\0';
	
	    if (strlen(inputBuffer) == 0) {
	        printf("Error: Price cannot be empty. Please enter a positive number.\n");
	        valid = 0;
	    } else {
	        int price = atoi(inputBuffer); 
	        if (price <= 0) {
	            printf("Error: Price must be a positive number.\n");
	            valid = 0;
	        } else {
	            books[index].price = price;
	        }
	    }
	} while (!valid);

	 do {
	    valid = 1;
	    char inputBuffer[50];
	    printf("Enter the Publication Date (dd mm yyyy): ");
	    fgets(inputBuffer, sizeof(inputBuffer), stdin);
	    inputBuffer[strcspn(inputBuffer, "\n")] = '\0'; // Lo?i b? ký t? newline
	
	    if (strlen(inputBuffer) == 0) {
	        printf("Error: Publication date cannot be empty. Please enter a valid date.\n");
	        valid = 0;
	    } else {
	        int day, month, year;
	        if (sscanf(inputBuffer, "%d %d %d", &day, &month, &year) != 3 || 
	            !isValidDate(day, month, year)) {
	            printf("Error: Invalid publication date. Please enter a valid date in the format dd mm yyyy.\n");
	            valid = 0;
	        } else {
	            books[index].publication.day = day;
	            books[index].publication.month = month;
	            books[index].publication.year = year;
	        }
	    }
	} while (!valid);

    printf("Book Updated successfully.\n");
 	saveBooksToFile();
  
    char choice;
    do {
        printf("Go back (b)? or Exit (0)?: ");
        scanf(" %c", &choice);
        if (choice == 'b') {
            return; 
        } else if (choice == '0') {
            printf("==========Thank You==========\n");
            printf("==========See You Soon==========\n\n");
            printf("--------------------------------------");
            exit(0); 
        } else {
            printf("Invalid choice. Please enter 'b' or '0'.\n");
        }
    } while (choice != 'b' && choice != '0');
}

//Tiet 3
void deleteBook() {
	printf("                         **** Delete A Book ****\n");
    char id[10];
    printf("Enter the Book ID to delete: ");
    scanf("%s", id);

    
    int index = -1;
    int i;
    for (i = 0; i < bookCount; i++) {
        if (strcmp(books[i].bookId, id) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Error: Book with ID '%s' not found.\n", id);
        return;
    }
    
    printf("One Book Found for ID: %s\n\n", books[index].bookId);
	printf("Book Information\n");
	printf("------------------------------\n");
	printf("%-15s: %s\n", "ID", books[index].bookId);
	printf("%-15s: %s\n", "Title", books[index].title);
	printf("%-15s: %s\n", "Author", books[index].author);
	printf("%-15s: %d\n", "Quantity", books[index].quantity);
	printf("%-15s: %d\n", "Price", books[index].price);
	printf("%-15s: %02d/%02d/%04d\n\n\n", "Publication Date", 
	       books[index].publication.day, 
	       books[index].publication.month, 
	       books[index].publication.year);

  
    printf("Are you sure you want to delete this book? (Y/N): ");
    char confirm;
    scanf(" %c", &confirm);
    if (confirm == 'Y' || confirm == 'y') {
       
        int j;
        for (j = index; j < bookCount - 1; j++) {
            books[j] = books[j + 1];
        }
        bookCount--;
        printf("Book Deleted Successfully.\n");
        
        saveBooksToFile();
    } else {
        printf("Book Deletion Cancelled.\n");
    }

    char choice;
    do {
        printf("Go back (b)? or Exit (0)?: ");
        scanf(" %c", &choice);
        if (choice == 'b') {
            return;
        } else if (choice == '0') {
            printf("==========Thank You==========\n");
            printf("==========See You Soon==========\n\n");
            printf("--------------------------------------");
            exit(0); 
        } else {
            printf("Invalid choice. Please enter 'b' or '0'.\n");
        }
    } while (choice != 'b' && choice != '0');
}

//Tiet 3
void sortBooksByPrice() {
    int choice;
    printf("Choose sorting order:\n");
    printf("[1] Ascending (Low to High)\n");
    printf("[2] Descending (High to Low)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

	int i;
    for (i = 0; i < bookCount - 1; i++) {
    	int j;
        for (j = i + 1; j < bookCount; j++) {
            if ((choice == 1 && books[i].price > books[j].price) ||
                (choice == 2 && books[i].price < books[j].price)) {
                struct Book temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }

    printf("Books sorted successfully.\n");
    displayBooks();
}

void toLowerCase(char* str) {
	int i;
    for (i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

//Tiet 4
void searchBookByTitle() {
    char keyword[30];
    char keywordLower[30];
    printf("Enter the title keyword to search: ");
    scanf(" %[^\n]%*c", keyword);
    
    strcpy(keywordLower, keyword);
    toLowerCase(keywordLower);
    
    int found = 0;
    printf("\nBooks matching '%s':\n", keyword);
     printf("|============|===========================|======================|============|============|=================|\n");
    printf("| %-10s | %-25s | %-20s | %-10s | %-10s | %-15s |\n", "ID", "Title", "Author", "Quantity", "Price", "Publication");
    printf("|============|===========================|======================|============|============|=================|\n");

	int i;
    for (i = 0; i < bookCount; i++) {
    	char titleLower[30];
        strcpy(titleLower, books[i].title); 
        toLowerCase(titleLower);
        
        if (strstr(titleLower, keywordLower) != NULL) { 
             printf("| %-10s | %-25s | %-20s | %-10d | %-10d | %02d/%02d/%04d      |\n", 
               books[i].bookId, 
               books[i].title, 
               books[i].author, 
               books[i].quantity, 
               books[i].price,
               books[i].publication.day,
               books[i].publication.month,
               books[i].publication.year);
      
        printf("|------------|---------------------------|----------------------|------------|------------|-----------------|\n");
            found = 1;
        }
    }

    if (!found) {
        printf("No books found with the keyword '%s'.\n", keyword);
    }
}


//Tiet 5
void ReadListBooksFromFile() {
    FILE *file = fopen("book.txt", "rb");
    
    if (file == NULL) {
        printf("Error: Could not open file for reading book.txt.\n");
        return;
    }
    
  
    while (fscanf(file, "%[^,], %[^,], %[^,], %d, %d, %d, %d, %d\n", 
                   books[bookCount].bookId,
                   books[bookCount].title,
                   books[bookCount].author,
                   &books[bookCount].quantity,
                   &books[bookCount].price,
                   &books[bookCount].publication.day,
                   &books[bookCount].publication.month,
                   &books[bookCount].publication.year) == 8) {
        bookCount++;
        
        if (bookCount >= MAX_BOOKS) {
            break;
        }
    }
    
    fclose(file);
    
    printf("Data loaded successfully from book.txt\n");
}


//Tiet 5
void saveBooksToFile() {
    FILE *file = fopen("book.txt", "w"); 
    if (file == NULL) {
        printf("Error: Could not open file for writing book.txt.\n");
        return;
    }
	int i;
    for (i = 0; i < bookCount; i++) {
        fprintf(file, "%s, %s, %s, %d, %d, %d, %d, %d\n", 
                books[i].bookId,
                books[i].title,
                books[i].author,
                books[i].quantity,
                books[i].price,
                books[i].publication.day,
                books[i].publication.month,
                books[i].publication.year);
    }

    fclose(file);
    printf("Data saved successfully to book.txt\n");
}




//Menu admin
void menuAmin() {
    printf("***Book Management System Using C***\n");
    printf("\n");
    printf("               CHOOSE YOUR ROLE                    \n");
    printf("      =======================\n");
    printf("      [1] Admin.\n");
    printf("      [0] Exit the Program.\n");
    printf("      ==========================\n");
    printf("Enter The Choice: ");
}



//Login admin
void loginAdmin() {
    printf("***Book Management System Using C***\n");
    printf("\n");
    printf("               LOGIN                    \n");
    printf("      =======================\n");
    int result = authenticate();
   
    printf("Enter The Choice: ");
}


//Xac thuc
int authenticate(){
	char username[MAX_ADMIN], password[MAX_ADMIN];
	char inputUser[MAX_ADMIN], inputPass[MAX_ADMIN];
	
	FILE *file = fopen("admin.txt", "r");
	if(file == NULL){
		printf("Error: Cannot open admin.txt file.\n");
		exit(1);
	}
	fscanf(file, "%[^,],%s", username, password);
	fclose(file);
	
	while(1){
		printf("Enter Username: ");
		scanf("%s", inputUser);
		printf("Enter Password: ");
		getPassword(inputPass);
		
	
        if (strcmp(username, inputUser) == 0 && strcmp(password, inputPass) == 0) {
        	printf("Login successful!\n");
        	printf("      ==========================\n");
            displayMenuManagement();
            return 1; 
        } else {
            printf("Invalid username or password. Please try again.\n");
        }
		
	}
}



void getPassword(char *password) {
    int i = 0;
    char ch;
    while ((ch = getch()) != '\r') {
        if (ch == '\b' && i > 0) {
            printf("\b \b");
            i--;
        } else if (ch != '\b') { 
            printf("*");
            password[i++] = ch;
        }
    }
    password[i] = '\0'; 
    printf("\n");
}

void menuManagement() {
    printf("***Book Management System Using C***\n");
    printf("\n");
    printf("               MENU                    \n");
    printf("      =======================\n");
    printf("      [1] Library management.\n");
    printf("      [2] Customer management.\n");
	printf("      [3] EXITS the Program.\n");
    printf("      ==========================\n");
    printf("Enter The Choice: ");
}


void displayMenuManagement(){
	int choice;
    do {
        menuManagement();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayMenuLibrary();
                break;
            case 0:
                printf("Exiting program. Thank you!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);
}



