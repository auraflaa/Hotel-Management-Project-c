---

# Hotel Management System  

## **Overview**  
The **Hotel Management System** is a C-based application designed to simplify and automate hotel operations. It provides features for managing room reservations, handling billing, and ensuring data security with personal password protection.  

---

## **Features**  

### **Room Management**  
- **Add Room:** Administrators can add new rooms with unique attributes, such as room numbers, types (Single/Double), and availability status.  
- **Check Availability:** Display all available rooms filtered by type.  
- **Delete Room:** Remove specific rooms from the system database.  
- **Update Room:** Modify room details, such as availability or type.  

### **Reservation Management**  
- **Book Room:** Guests can book rooms by providing their guest ID, room number, reservation date, and a secure personal password.  
- **View Reservations:** Guests can view their reservations using their credentials (guest ID and password).  
- **Cancel Reservation:** Allows guests to cancel bookings securely using their ID, room number, and password.  
- **Admin Reservation View:** Administrators can view all reservations without requiring a password.  

### **Billing**  
- **Generate Bills:** Automatically calculate the total bill based on reservation details, confirm payment, and update room availability accordingly.  

### **Security**  
- **Password Protection:** Guests create personal passwords during booking, ensuring that their data is secured and accessible only to them.  

---

## **Project Structure**  

### **Source Code Files**  
- **`main.c`**: The entry point of the application.  
- **`guest.c`**: Functions to handle guest-specific features.  
- **`room.c`**: Operations for room management.  
- **`reservation.c`**: Handles reservation logic and functionality.  
- **`bill.c`**: Contains the logic for billing and payment processing.  
- **`admin.c`**: Includes functions reserved for administrative operations.  
- **`myfunctions.h`**: Header file containing function declarations.  
- **`mystructure.h`**: Header file defining the structures used in the system.  

### **Data Files**  
- **`reservation.txt`**: Stores all reservation data.  
- **`rooms.txt`**: Contains the current room database, including room types and availability.  

---

## **How to Use**  

### **Getting Started**  
1. **Clone the Repository:**  
   ```bash
   git clone https://github.com/your-username/hotel-management-system.git
   ```  

2. **Navigate to the Project Directory:**  
   ```bash
   cd hotel-management-system
   ```  

3. **Compile the Program:**  
   ```bash
   gcc main.c guest.c room.c reservation.c bill.c admin.c -o hotel_management
   ```  

4. **Run the Application:**  
   ```bash
   ./hotel_management
   ```  

### **Usage Steps**  
1. **Room Management:** Add, check, delete, or update rooms from the system.  
2. **Reservation Management:**  
   - Book rooms using guest credentials.  
   - View existing reservations.  
   - Cancel bookings.  
3. **Billing System:** Generate and confirm payment invoices for reservations.  

---

## **Key Benefits**  
- **Efficiency:** Simplifies day-to-day hotel operations with minimal manual intervention.  
- **Data Security:** Secures guest data through password-protected access.  
- **Modular Design:** Organized codebase makes maintenance and updates easier.  

---

## **Future Enhancements**  
This project can be further improved by implementing:  
- Integration with **database management systems (DBMS)** for better scalability.  
- A **graphical user interface (GUI)** for enhanced user experience.  
- **Online booking features** for real-time updates and convenience.  

---

## **Conclusion**  
The **Hotel Management System** is a comprehensive and efficient solution for hotel operations. Its modular design and robust security make it a reliable tool for managing reservations and billing processes.  

---
