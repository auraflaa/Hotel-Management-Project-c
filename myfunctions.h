#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// Guest Management Functions
void addGuest();
void viewGuests();
void deleteGuest();
void updateGuest();

// Room Management Functions
void addRoom();
void checkAvailability();
void deleteRoom();
void updateRoom();

// Reservation Management Functions
void bookRoom();
void viewReservations();
void cancelReservation();

// Billing Functions
void genbill();
void pastbill();

// Admin Functions
void adminlog();
void adminacc();
void sysstat();

// Data Persistence Functions
void savedata();
void loaddata();
void exitfunc();

#endif
