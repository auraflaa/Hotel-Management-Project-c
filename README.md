

# Hotel Management System

A robust and efficient C-based application designed to streamline hotel operations by managing room reservations, billing, and cancellations with secure password protection.

---

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Project Structure](#project-structure)
- [Prerequisites](#prerequisites)
- [Installation and Setup](#installation-and-setup)
- [Usage](#usage)
- [Key Benefits](#key-benefits)
- [Future Enhancements](#future-enhancements)
- [Troubleshooting & Known Issues](#troubleshooting--known-issues)
- [License](#license)
- [About](#about)

---

## Overview

The Hotel Management System is a command-line application written in C. It simplifies daily hotel operations by providing an interface to manage room inventory, process reservations, handle billing, and enforce data security through personal passwords.

---

## Features

### Room Management
- **Add Room:** Allows administrators to add new rooms with unique attributes (room number, type, and availability).
- **Check Availability:** Displays all available rooms, with the option to filter by type (e.g., Single/Double).
- **Delete Room:** Removes a room from the system.
- **Update Room:** Modifies room details, such as type and availability status.

### Reservation Management
- **Book Room:** Enables guests to reserve rooms by providing a guest ID, room number, reservation date, and a secure password.
- **View Reservations:** Guests can view their current reservations using their credentials.
- **Cancel Reservation:** Permits secure cancellation of bookings by verifying guest details.
- **Administrative View:** Administrators can view all reservations without password restrictions.

### Billing
- **Generate Bills:** Automatically calculates the total bill based on reservation details, confirms payment, and updates room availability post-payment.

### Security
- **Password Protection:** Ensures that guest and reservation data remains secure through personal password mechanisms.

---

## Project Structure

The repository is organized as follows:

- **Source Code Files:**
  - `main.c` – Entry point of the application.
  - `guest.c` – Guest-related functionalities.
  - `room.c` – Room management operations.
  - `reservation.c` – Reservation handling and logic.
  - `bill.c` – Billing and payment processing.
  - `admin.c` – Administrative functions.
  - `myfunctions.h` – Function declarations.
  - `mystructure.c` – Data structure definitions (ensure corresponding header file exists, e.g., `mystructure.h`).

- **Data Files:**
  - `reservations.txt` – Stores reservation data.
  - `rooms.txt` – Contains room details, including types and availability.

---

## Prerequisites

Before compiling and running the application, ensure you have:

- A C compiler (e.g., GCC).  
- Basic command-line interface knowledge.
- Familiarity with terminal operations on your operating system.

---

## Installation and Setup

1. **Clone the Repository:**

   ```bash
   git clone https://github.com/auraflaa/Hotel-Management-Project-c.git
   ```

2. **Navigate to the Project Directory:**

   ```bash
   cd Hotel-Management-Project-c
   ```

3. **Compile the Application:**

   ```bash
   gcc main.c guest.c room.c reservation.c bill.c admin.c -o hotel_management
   ```

4. **Run the Application:**

   ```bash
   ./hotel_management
   ```

---

## Usage

1. **Room Management:**  
   - Use the provided menu options to add, view, update, or delete room details.

2. **Reservation Management:**  
   - Follow the prompts to book a room by entering your guest ID, room number, and password.
   - To view or cancel a reservation, use the appropriate menu options and provide your credentials.

3. **Billing:**  
   - Generate bills for reservations. The system will calculate the total amount based on the duration of stay and room rate, update the room’s availability, and confirm payment.

---

## Key Benefits

- **Efficiency:** Automates routine hotel management tasks to reduce manual workload.
- **Security:** Incorporates personal password protection to safeguard guest information.
- **Modular Design:** Clean and organized code structure facilitates easier maintenance and future enhancements.

---

## Future Enhancements

- **Database Integration:** Migrate from flat files to a relational or NoSQL database for enhanced scalability.
- **Graphical User Interface (GUI):** Develop a GUI to improve user experience and accessibility.
- **Online Booking:** Incorporate web-based booking capabilities for real-time reservations and updates.
- **Enhanced Reporting:** Add modules for generating detailed reports and analytics on hotel operations.
- **Mobile Compatibility:** Develop mobile applications for both guests and administrators.

---

## Troubleshooting & Known Issues

- **Compilation Errors:** Ensure that all source files are present and that your compiler is updated.
- **File Permissions:** Verify that `reservations.txt` and `rooms.txt` have appropriate read/write permissions.
- **Data Consistency:** Regularly backup data files to prevent data loss in case of unexpected shutdowns.

---

## License

*If applicable, include license details here. For example:*

This project is licensed under the MIT License – see the [LICENSE](LICENSE) file for details.

---

## About

The Hotel Management System was developed to provide an efficient, secure, and user-friendly solution for managing hotel operations. Its modular design and reliance on the C programming language ensure high performance and reliability. Contributions and suggestions for improvements are welcome.

---

