#include "myfunctions.h"
#include "mystructure.h"
#include <stdio.h>
#include <string.h>
void viewAllReservations();
// Reservation Management Functions
void bookRoom() {
    Reservation res;
    Room r;
    char password[20];
    FILE *fpRooms = fopen("rooms.txt", "r");
    FILE *fpRes = fopen("reservations.txt", "a"); 
    FILE *temp = fopen("temp.txt", "w");

    int roomFound = 0;
    if (!fpRooms || !fpRes || !temp) {
        printf("Error opening file.\n");
        return;
    }

    printf("Enter Guest ID: ");
    scanf("%s", res.guestID);
    printf("Enter Room Number to book: ");
    scanf("%d", &res.roomNumber);
    printf("Enter Date (DD/MM/YYYY): ");
    scanf("%s", res.date);
    printf("Create a personal password: ");
    scanf("%s", password);

    while (fscanf(fpRooms, "%d %s %d", &r.roomNumber, r.type, &r.isAvailable) != EOF) {
        if (r.roomNumber == res.roomNumber && r.isAvailable) {
            r.isAvailable = 0;
            roomFound = 1;
        }
        fprintf(temp, "%d %s %d\n", r.roomNumber, r.type, r.isAvailable);
    }
    fclose(fpRooms);
    fclose(temp);

    remove("rooms.txt");
    rename("temp.txt", "rooms.txt");

    if (roomFound) {
        fprintf(fpRes, "%s %d %s %s\n", res.guestID, res.roomNumber, res.date, password);
        printf("Room booked successfully.\n");
    } else {
        printf("Room not available.\n");
    }
    fclose(fpRes);
}

void viewReservations() {
    char guestID[10];
    char password[20];
    Reservation res;
    FILE *fp = fopen("reservations.txt", "r");
    if (!fp) {
        printf("No reservations found.\n");
        return;
    }

    printf("Enter Guest ID: ");
    scanf("%s", guestID);
    printf("Enter your password: ");
    scanf("%s", password);

    int found = 0;
    while (fscanf(fp, "%s %d %s %s", res.guestID, &res.roomNumber, res.date, password) != EOF) {
        if (strcmp(res.guestID, guestID) == 0 && strcmp(password, password) == 0) {
            found = 1;
            printf("\nReservation Details:\n");
            printf("Guest ID: %s\n", res.guestID);
            printf("Room Number: %d\n", res.roomNumber);
            printf("Date: %s\n", res.date);
        }
    }
    fclose(fp);

    if (!found) {
        printf("No reservation found or incorrect password.\n");
    }
}

void cancelReservation() {
    char guestID[10];
    char password[20];
    int roomNumber;
    Reservation res;
    Room r;
    FILE *fpRes = fopen("reservations.txt", "r");
    FILE *fpRooms = fopen("rooms.txt", "r");
    FILE *tempRes = fopen("tempRes.txt", "w");
    FILE *tempRooms = fopen("tempRooms.txt", "w");

    int found = 0;
    if (!fpRes || !fpRooms || !tempRes || !tempRooms) {
        printf("Error opening file.\n");
        return;
    }

    printf("Enter Guest ID to cancel reservation: ");
    scanf("%s", guestID);
    printf("Enter Room Number: ");
    scanf("%d", &roomNumber);
    printf("Enter your password: ");
    scanf("%s", password);

    while (fscanf(fpRes, "%s %d %s %s", res.guestID, &res.roomNumber, res.date, password) != EOF) {
        if (strcmp(res.guestID, guestID) == 0 && res.roomNumber == roomNumber && strcmp(password, password) == 0) {
            found = 1;
            continue;
        }
        fprintf(tempRes, "%s %d %s %s\n", res.guestID, res.roomNumber, res.date, password);
    }
    fclose(fpRes);
    fclose(tempRes);

    while (fscanf(fpRooms, "%d %s %d", &r.roomNumber, r.type, &r.isAvailable) != EOF) {
        if (r.roomNumber == roomNumber) {
            r.isAvailable = 1;
        }
        fprintf(tempRooms, "%d %s %d\n", r.roomNumber, r.type, r.isAvailable);
    }
    fclose(fpRooms);
    fclose(tempRooms);

    remove("reservations.txt");
    rename("tempRes.txt", "reservations.txt");
    remove("rooms.txt");
    rename("tempRooms.txt", "rooms.txt");

    if (found) {
        printf("Reservation cancelled successfully.\n");
    } else {
        printf("Reservation not found or incorrect password.\n");
    }
}

// Reservation Management Menu
void reservationManagementMenu() {
    int choice;
    printf("\n");
    do {
        printf("\nReservation Management Menu:\n");
        printf("1. Book Room\n");
        printf("2. View Reservations\n");
        printf("3. Cancel Reservation\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bookRoom();
                break;
            case 2:
                viewReservations();
                break;
            case 3:
                cancelReservation();
                break;
            case 4:
                printf("Exiting Reservation Menu.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);
}

void adminreservationManagementMenu() {
    int choice;
    printf("\n");
    do {
        printf("\nReservation Management Menu:\n");
        printf("1. Book Room\n");
        printf("2. View Reservations\n");
        printf("3. Cancel Reservation\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bookRoom();
                break;
            case 2:
                viewAllReservations();
                break;
            case 3:
                cancelReservation();
                break;
            case 4:
                printf("Exiting Reservation Menu.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);
}

// Function to view all reservations in the admin menu
void viewAllReservations() {
    Reservation res;
    char password[20];
    FILE *fp = fopen("reservations.txt", "r");
    if (!fp) {
        printf("No reservations found.\n");
        return;
    }

    printf("\nAll Reservations:\n");
    printf("Guest ID\tRoom Number\t\tDate\t\tPassword\n");
    printf("-------------------------------------------------\n");
    while (fscanf(fp, "%s %d %s %s", res.guestID, &res.roomNumber, res.date, password) != EOF) {
        printf("\t%s\t\t\t%d\t\t %s\t\t %s\n", res.guestID, res.roomNumber, res.date, password);
    }
    fclose(fp);
}
