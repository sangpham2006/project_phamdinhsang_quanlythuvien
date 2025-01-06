#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int main() {
    int choice;

    do {
        menuAmin();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                loginAdmin();
                break;
            case 0:
                printf("Exiting program. Thank you!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

