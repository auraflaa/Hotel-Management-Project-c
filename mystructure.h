#ifndef MYSTRUCTURE_H
#define MYSTRUCTURE_H


// Structure to store room details
typedef struct {
    int roomNumber;
    char type[20];
    int isAvailable;
} Room;

// Structure to store reservation details
typedef struct {
    char guestID[10];
    int roomNumber;
    char date[20];
} Reservation;

// Structure to store guest details
typedef struct {
    char id[10];
    char name[50];
    char phone[15];
    char email[50];
} Guest;

#endif
