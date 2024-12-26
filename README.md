# Fight-Reservation-System
The main key features to access the reservation system is:
1)	Create the flight 
2)	 Book flight
3)	display flight 
4)	book flight ticket
5)	Display the flight ticket
6)	Update the flight ticket
7)	Cancel the flight ticket
8)	Exit   


FLIGHT RESERVATION SYSTEM 
The project "Flight Reservation System" is developed in c language which assists in creating, updating and maintaining Flights information and Ticket Booking. The application is built using a menu driven approach where user can select an option to perform following operations.
Create a Flight
Update Flight details
Display Flight details
Book a Ticket
Update passenger details
Cancel Ticket 
Display Passengers in a flight.




Implementation 
The project is implemented using structures and functions.
The structure Flight stores data about flight like flight number, flight name, source, destination and number of passengers it can accommodate.
The Ticket Booking structure is used to store details of booking like booking id  passenger name, age, mobile and number of seats he want to book.
The functions implemented are
1. Create()- This function will read flights details and store them.
2. Update()- Thus function will change details of an existing flight.
3. Display()- This function lists all the available flights and their details.
4. Book_ticket()- This function proceeds by asking user to input flight number in which he wants to book ticket. Once input is given and seats are available  the user will be asked to input the passenger details like name, age, mobile number and number of seats. Once the ticket is booked the user gets a confirmation message and number of seats available for respective flight will be reduced. Each ticket booking is given a auto unique number called booking id which can be used for further operations.
5. Update_passenger()- This function assists user who booked ticket to modify his details with help of booking id. The new input from user will be updated in the database.
6. Cancel_ticket()- This method will help user to cancel a booked ticket. The user initially gives the booking id for reference and the ticket is cancelled and user gets a confirmation message. Once ticket is cancelled for a flight the number of available seats will be incremented accordingly.
7.Display_flight()- This method is implemented to display Passengers booked tickets for a flight. Once the user gives input a flight number he can view the passe gers traveling in flight.
8. Exit()- The user can opt this option  if he wants to exit from application.
The key point of this code is here the code is post defined code all inputs are given by the users.




Conclusion:
The project "Flight Reservation System" is developed to assist passengers book a ticket and cancel it. The project can be further extended to manage partial cancelation of ticket and manage the ticket booking with halts.











