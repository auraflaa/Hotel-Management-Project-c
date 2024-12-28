#include "myfunctions.h"
#include "mystructure.h"
#include <stdio.h>
#include <string.h>

// Room Management Functions
void addRoom() {
  Room r;
  FILE *fp = fopen("rooms.txt", "a"); // Append mode
  if (!fp) {
    printf("Error opening file.\n");
    return;
  }

  printf("Enter Room Number: ");
  scanf("%d", &r.roomNumber);
  printf("Enter Room Type (Single/Double): ");
  scanf("%s", r.type);
  r.isAvailable = 1; // Room is available by default

  fprintf(fp, "%d %s %d\n", r.roomNumber, r.type, r.isAvailable);
  fclose(fp);
  printf("Room added successfully.\n");
}

void checkAvailability() {
  Room r;
  FILE *fp = fopen("rooms.txt", "r"); // Read mode
  if (!fp) {
    printf("No room records found.\n");
    return;
  }

  printf("\nAvailable Rooms:\n");
  printf("Room Number\tType\n");
  printf("------------------------\n");
  while (fscanf(fp, "%d %s %d", &r.roomNumber, r.type, &r.isAvailable) != EOF) {
    if (r.isAvailable) {
      printf("%d\t\t%s\n", r.roomNumber, r.type);
    }
  }
  fclose(fp);
}

void deleteRoom() {
  int roomNumber;
  Room r;
  FILE *fp = fopen("rooms.txt", "r");
  FILE *temp = fopen("temp.txt", "w"); // Temporary file
  int found = 0;

  if (!fp || !temp) {
    printf("Error opening file.\n");
    return;
  }

  printf("Enter Room Number to delete: ");
  scanf("%d", &roomNumber);

  while (fscanf(fp, "%d %s %d", &r.roomNumber, r.type, &r.isAvailable) != EOF) {
    if (r.roomNumber == roomNumber) {
      found = 1;
      continue;
    }
    fprintf(temp, "%d %s %d\n", r.roomNumber, r.type, r.isAvailable);
  }
  fclose(fp);
  fclose(temp);

  remove("rooms.txt");
  rename("temp.txt", "rooms.txt");

  if (found) {
    printf("Room deleted successfully.\n");
  } else {
    printf("Room Number not found.\n");
  }
}

void updateRoom() {
  int roomNumber;
  Room r;
  FILE *fp = fopen("rooms.txt", "r");
  FILE *temp = fopen("temp.txt", "w"); // Temporary file
  int found = 0;

  if (!fp || !temp) {
    printf("Error opening file.\n");
    return;
  }

  printf("Enter Room Number to update: ");
  scanf("%d", &roomNumber);

  while (fscanf(fp, "%d %s %d", &r.roomNumber, r.type, &r.isAvailable) != EOF) {
    if (r.roomNumber == roomNumber) {
      found = 1;
      printf("Enter New Room Type (Single/Double): ");
      scanf("%s", r.type);
      printf("Is Room Available? (1 for Yes, 0 for No): ");
      scanf("%d", &r.isAvailable);
    }
    fprintf(temp, "%d %s %d\n", r.roomNumber, r.type, r.isAvailable);
  }
  fclose(fp);
  fclose(temp);

  remove("rooms.txt");
  rename("temp.txt", "rooms.txt");

  if (found) {
    printf("Room updated successfully.\n");
  } else {
    printf("Room Number not found.\n");
  }
}

// Room Management Menu
void roomManagementMenu() {
  int choice;
  printf("\n");
  do {
    printf("\nRoom Management Menu:\n");
    printf("1. Add Room\n");
    printf("2. Check Availability\n");
    printf("3. Delete Room\n");
    printf("4. Update Room\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      addRoom();
      break;
    case 2:
      checkAvailability();
      break;
    case 3:
      deleteRoom();
      break;
    case 4:
      updateRoom();
      break;
    case 5:
      printf("Exiting Room Management Menu.\n");
      break;
    default:
      printf("Invalid choice. Please try again.\n");
      break;
    }
  } while (choice != 5);
}
