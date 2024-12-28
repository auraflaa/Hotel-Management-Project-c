#include "myfunctions.h"
#include "mystructure.h"
#include <stdio.h>
#include <string.h>

// Add a new guest
void addGuest() {
  Guest g;
  FILE *fp = fopen("guests.txt", "a"); // Append mode
  if (!fp) {
    printf("Error opening file.\n");
    return;
  }

  // Collect guest details
  printf("Enter Guest ID: ");
  scanf("%s", g.id);
  printf("Enter Guest Name: ");
  scanf(" %[^\n]", g.name); // Read string with spaces
  printf("Enter Phone: ");
  scanf("%s", g.phone);
  printf("Enter Email: ");
  scanf("%s", g.email);

  // Save to file
  fprintf(fp, "%s %s %s %s\n", g.id, g.name, g.phone, g.email);
  fclose(fp);
  printf("Guest added successfully.\n");
}

// View all guests
void viewGuests() {
  Guest g;
  FILE *fp = fopen("guests.txt", "r"); // Read mode
  if (!fp) {
    printf("No guest records found.\n");
    return;
  }

  printf("\nGuest List:\n");
  printf("ID\tName\t\tPhone\t\tEmail\n");
  printf("--------------------------------------------------\n");
  while (fscanf(fp, "%s %s %s %s", g.id, g.name, g.phone, g.email) != EOF) {
    printf("%s\t%s\t%s\t%s\n", g.id, g.name, g.phone, g.email);
  }
  fclose(fp);
}

// Delete a guest
void deleteGuest() {
  char id[10];
  Guest g;
  FILE *fp = fopen("guests.txt", "r");
  FILE *temp = fopen("temp.txt", "w"); // Temporary file
  int found = 0;

  if (!fp || !temp) {
    printf("Error opening file.\n");
    return;
  }

  printf("Enter Guest ID to delete: ");
  scanf("%s", id);

  // Copy all records except the one to delete
  while (fscanf(fp, "%s %s %s %s", g.id, g.name, g.phone, g.email) != EOF) {
    if (strcmp(g.id, id) == 0) {
      found = 1;
      continue; // Skip the record to delete
    }
    fprintf(temp, "%s %s %s %s\n", g.id, g.name, g.phone, g.email);
  }
  fclose(fp);
  fclose(temp);

  remove("guests.txt");
  rename("temp.txt", "guests.txt");

  if (found) {
    printf("Guest deleted successfully.\n");
  } else {
    printf("Guest ID not found.\n");
  }
}

// Update guest details
void updateGuest() {
  char id[10];
  Guest g;
  FILE *fp = fopen("guests.txt", "r");
  FILE *temp = fopen("temp.txt", "w"); // Temporary file
  int found = 0;

  if (!fp || !temp) {
    printf("Error opening file.\n");
    return;
  }

  printf("Enter Guest ID to update: ");
  scanf("%s", id);

  // Update record
  while (fscanf(fp, "%s %s %s %s", g.id, g.name, g.phone, g.email) != EOF) {
    if (strcmp(g.id, id) == 0) {
      found = 1;
      printf("Enter New Name: ");
      scanf(" %[^\n]", g.name);
      printf("Enter New Phone: ");
      scanf("%s", g.phone);
      printf("Enter New Email: ");
      scanf("%s", g.email);
    }
    fprintf(temp, "%s %s %s %s\n", g.id, g.name, g.phone, g.email);
  }
  fclose(fp);
  fclose(temp);

  remove("guests.txt");
  rename("temp.txt", "guests.txt");

  if (found) {
    printf("Guest updated successfully.\n");
  } else {
    printf("Guest ID not found.\n");
  }
}

// Guest management menu
void guestManagementMenu() {
  int choice;
  printf("\n");
  do {
    printf("\n--- Guest Management ---\n");
    printf("1. Add Guest\n");
    printf("2. View Guests\n");
    printf("3. Delete Guest\n");
    printf("4. Update Guest\n");
    printf("5. Back to Main Menu\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      addGuest();
      break;
    case 2:
      viewGuests();
      break;
    case 3:
      deleteGuest();
      break;
    case 4:
      updateGuest();
      break;
    case 5:
      printf("Returning to Main Menu...\n");
      break;
    default:
      printf("Invalid choice! Try again.\n");
    }
  } while (choice != 5);
}
