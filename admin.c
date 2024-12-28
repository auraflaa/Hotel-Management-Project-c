#include "myfunctions.h"
#include "mystructure.h"
#include <stdio.h>
#include <string.h>

void adminMenu() {
  char username[20];
  char password[20];
  int attempts = 0;
  const char correctUsername[] = "admin";
  const char correctPassword[] = "123";

  while (attempts < 3) {
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    if (strcmp(username, correctUsername) == 0 &&
        strcmp(password, correctPassword) == 0) {
      printf("Access granted. Welcome to the admin menu.\n");
      admin();
      return;
    } else {
      printf("Invalid username or password. Please try again.\n");
      attempts++;
    }
  }

  printf("Too many failed attempts. Access denied.\n");
}

int admin() {
  int choice;

  do {
    printf("\nAdmin Menu:\n");
    printf("1. Manage Rooms\n");
    printf("2. Manage Reservations\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      roomManagementMenu();
      break;
    case 2:
      reservationManagementMenu();
      break;
    case 3:
      printf("Exiting Admin Menu.\n");
      break;
    default:
      printf("Invalid choice. Please try again.\n");
      break;
    }
  } while (choice != 3);
  return 0;
}
