#include "myfunctions.h"
#include "mystructure.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

#define SINGLE_ROOM_RATE 1000 // Rate for a single room per day
#define DOUBLE_ROOM_RATE 1500 // Rate for a double room per day

int calculateDays(const char *startDate, const char *endDate);
void billing();

// Function to calculate the number of days between two dates
int calculateDays(const char *startDate, const char *endDate) {
    int d1, m1, y1, d2, m2, y2;
    sscanf(startDate, "%d/%d/%d", &d1, &m1, &y1);
    sscanf(endDate, "%d/%d/%d", &d2, &m2, &y2);

    struct tm a = {0, 0, 0, d1, m1 - 1, y1 - 1900};
    struct tm b = {0, 0, 0, d2, m2 - 1, y2 - 1900};

    time_t x = mktime(&a);
    time_t y = mktime(&b);

    double difference = difftime(y, x) / (60 * 60 * 24);
    return (int)difference + 1; // Add 1 to include the start date
}

// Billing function
void billing() {
    char guestID[10];
    char endDate[20], currentDate[20];
    int roomNumber, roomRate, totalDays;
    double totalAmount;
    Reservation res;
    Room r;
    FILE *fpRes = fopen("reservations.txt", "r");
    FILE *fpRooms = fopen("rooms.txt", "r");
    FILE *tempRooms = fopen("tempRooms.txt", "w");
    FILE *tempRes = fopen("tempRes.txt", "w");

    if (!fpRes || !fpRooms || !tempRooms || !tempRes) {
        printf("Error opening file.\n");
        return;
    }

    // Get the current date
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(currentDate, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

    printf("Enter Guest ID: ");
    scanf("%s", guestID);
    printf("Enter Room Number: ");
    scanf("%d", &roomNumber);

    int found = 0;
    while (fscanf(fpRes, "%s %d %s", res.guestID, &res.roomNumber, res.date) != EOF) {
        if (strcmp(res.guestID, guestID) == 0 && res.roomNumber == roomNumber) {
            found = 1;
            strcpy(endDate, currentDate);
            break;
        } else {
            fprintf(tempRes, "%s %d %s\n", res.guestID, res.roomNumber, res.date);
        }
    }

    if (!found) {
        printf("Reservation not found.\n");
        fclose(fpRes);
        fclose(fpRooms);
        fclose(tempRooms);
        fclose(tempRes);
        return;
    }

    totalDays = calculateDays(res.date, endDate);

    while (fscanf(fpRooms, "%d %s %d", &r.roomNumber, r.type, &r.isAvailable) != EOF) {
        if (r.roomNumber == roomNumber) {
            if (strcmp(r.type, "Single") == 0) {
                roomRate = SINGLE_ROOM_RATE;
            } else if (strcmp(r.type, "Double") == 0) {
                roomRate = DOUBLE_ROOM_RATE;
            } else {
                printf("Invalid room type.\n");
                fclose(fpRes);
                fclose(fpRooms);
                fclose(tempRooms);
                fclose(tempRes);
                return;
            }
            break;
        }
    }

    totalAmount = (double)totalDays * roomRate;
    printf("Total amount to be paid by Guest ID %s for Room Number %d is: Rs.%.2lf/-\n", guestID, roomNumber, totalAmount);

    char paymentConfirmation[10];
    printf("Has the payment been made? (yes/no): ");
    scanf("%s", paymentConfirmation);

    if (strcmp(paymentConfirmation, "yes") == 0) {
        // Mark the room as available
        rewind(fpRooms);
        while (fscanf(fpRooms, "%d %s %d", &r.roomNumber, r.type, &r.isAvailable) != EOF) {
            if (r.roomNumber == roomNumber) {
                r.isAvailable = 1;
            }
            fprintf(tempRooms, "%d %s %d\n", r.roomNumber, r.type, r.isAvailable);
        }
        fclose(fpRooms);
        fclose(tempRooms);
        remove("rooms.txt");
        rename("tempRooms.txt", "rooms.txt");

        // Remove the reservation
        while (fscanf(fpRes, "%s %d %s", res.guestID, &res.roomNumber, res.date) != EOF) {
            if (!(strcmp(res.guestID, guestID) == 0 && res.roomNumber == roomNumber)) {
                fprintf(tempRes, "%s %d %s\n", res.guestID, res.roomNumber, res.date);
            }
        }
        fclose(fpRes);
        fclose(tempRes);
        remove("reservations.txt");
        rename("tempRes.txt", "reservations.txt");

        printf("\nThank you for choosing us. We look forward to welcoming you back!\n");
    } else {
        fclose(fpRooms);
        fclose(tempRooms);
        fclose(fpRes);
        fclose(tempRes);
        printf("\nPayment not confirmed. Please make the payment at the Reception.\n");
    }
}
