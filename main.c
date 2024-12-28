#include "myfunctions.h"
#include <stdio.h>

int main() {
  int choice;
  do {
    printf("\n--- Hotel Management System ---\n");
    printf("1. Reservations\n");
    printf("2. Billing\n");
    printf("3. Admin\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    printf("\n");
    switch (choice) {
    case 1:
      reservationManagementMenu();
      break;
    case 2:
      billing();
      break;
    case 3:
      adminMenu();
      break;
    case 4:
      printf("Exiting...\n\nThank You for using our services!\n");
      break;
    default:
      printf("Invalid choice! Try again.\n");
    }
  } while (choice != 4);

  return 0;
}
