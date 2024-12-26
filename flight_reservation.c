#include <string.h>
#include <stdio.h>
#include <stdlib.h>
static int n = 0; 
static int m = 0; 
int seat_id = 0;  
// Flight structure
struct flight {
    char fl_no[10];//flight number
    char flt_name[20];//flight name
    char source[20];//source of flight
    char destn[20];//flight destination
    int no_passengers;//number of passengers
} f[20];
// Ticket structure
struct FlightTicket {
    int seat_id;   //seat id
    char src[20];//flight source name
    char des[20];//flight destination name
    char pn_name[20];//passenger name
    int age;//passenger age
    long mobile;  //passenger mobile number
    char flt_no[10];//flight number
    int status;  //flight status
} FT[100];
// Create a flight
void create() {
    if (n >= 20) {//flight capacity
        printf("Flight capacity reached. Cannot add more flights.\n");
        return; }
    printf("Enter the flight details:\n");
    printf("Enter flight number: ");
    scanf("%s", f[n].fl_no);//enter flight number
    printf("Enter flight name: ");
    scanf("%s", f[n].flt_name);//enter flight name
    printf("Enter flight source: ");
    scanf("%s", f[n].source);//enter flight source
    printf("Enter the flight destination: ");
    scanf("%s", f[n].destn);//enter flight destination
    printf("Enter the capacity of the flight: ");
    scanf("%d", &f[n].no_passengers);//enter capacity of flight
    n++;
}
// Display all flights
void display() {
    if (n == 0) {
        printf("No flights available.\n");
        return;
    }
    printf("Available flights:\n");
    for (int i = 0; i < n; i++) {
        printf("\nFlight Number: %s\nFlight Name: %s\nSource: %s\nDestination: %s\nCapacity: %d\n",
               f[i].fl_no, f[i].flt_name, f[i].source, f[i].destn, f[i].no_passengers);
    }//flight details 
}
// Update flight details
void update() {
    char name[20];
    printf("Enter the flight name to update: ");
    scanf("%s", name);
    for (int i = 0; i < n; i++) {
        if (strcmp(f[i].flt_name, name) == 0) {
            printf("Enter new source: ");
            scanf("%s", f[i].source);//enter new flight source
            printf("Enter new destination: ");
            scanf("%s", f[i].destn);//enter new flight destination
            printf("Enter new capacity: ");
            scanf("%d", &f[i].no_passengers);//enter no of passengers
            printf("Flight updated successfully.\n");
            return;
        }
    }
    printf("Flight not found.\n");
}
// Book tickets
void book_tkt() {
    char fl_no[10];//flight number
    int num_seats;//number of seats
    printf("Enter the flight number to book tickets: ");
    scanf("%s", fl_no);

    for (int i = 0; i < n; i++) {
        if (strcmp(f[i].fl_no, fl_no) == 0) {
            printf("Enter the number of seats to book: ");
            scanf("%d", &num_seats);//enter the number of seats to book

            if (num_seats > f[i].no_passengers) {
                printf("Not enough seats available. Only %d left.\n", f[i].no_passengers);//if number of sets are more than no of passengers
                return;}
            for (int j = 0; j < num_seats; j++) {//strcpy for source , destination anf flight number
                FT[m].seat_id = ++seat_id;
                strcpy(FT[m].src, f[i].source);
                strcpy(FT[m].des, f[i].destn);
                strcpy(FT[m].flt_no, f[i].fl_no);
                printf("Enter passenger %d's name: ", j + 1);
                scanf("%s", FT[m].pn_name);//passenger name
                printf("Enter passenger %d's age: ", j + 1);
                scanf("%d", &FT[m].age);//passenger age
                printf("Enter passenger %d's mobile number: ", j + 1);
                scanf("%ld", &FT[m].mobile);//passenger mobile number
                FT[m].status = 0; // Active ticket
                m++;}
            f[i].no_passengers -= num_seats;
            printf("Tickets booked successfully. Seat IDs: ");
            for (int j = m - num_seats; j < m; j++) {
                printf("%d ", FT[j].seat_id);//when tickets are booked it shows seat id
            }
            printf("\n");
            return;
        }
    }
    printf("Flight not found.\n");
}
// Display tickets
void tkt_dis() {
    char fl_no[10];
    printf("Enter flight number to display tickets: ");
    scanf("%s", fl_no);//enter flight number
    int found = 0;
    printf("Tickets for Flight %s:\n", fl_no);
    for (int i = 0; i < m; i++) {//details of passenger shown on display of tickets
        if (FT[i].status == 0 && strcmp(FT[i].flt_no, fl_no) == 0) {
            printf("Seat ID: %d\nName: %s\nAge: %d\nMobile: %ld\n\n",
                   FT[i].seat_id, FT[i].pn_name, FT[i].age, FT[i].mobile);
            found = 1;
        }
    }
    if (!found) {
        printf("No tickets found for this flight.\n");
    }
}
// Cancel a ticket
void cancel_tkt() {
    int seat_id_to_cancel;//seat id for cancelation
    char fl_no[10];
    printf("Enter flight number for the ticket: ");
    scanf("%s", fl_no);//enter flight number
    printf("Enter Seat ID to cancel: ");
    scanf("%d", &seat_id_to_cancel);//enter seat id
    for (int i = 0; i < m; i++) {
        if (FT[i].seat_id == seat_id_to_cancel && FT[i].status == 0 && strcmp(FT[i].flt_no, fl_no) == 0) {
            FT[i].status = 1;  
            printf("Ticket with Seat ID %d canceled successfully.\n", seat_id_to_cancel);
            return;
        }
    }
    printf("Seat ID not found or already canceled.\n");
}
// Update passenger details
void update_psng() {
    int seat_id_to_update, option;//seat id to update the ticket
    char fl_no[10];//flight number to update the ticket
    printf("Enter flight number for the ticket: ");
    scanf("%s", fl_no);
    printf("Enter Seat ID to update passenger details: ");
    scanf("%d", &seat_id_to_update);
    for (int i = 0; i < m; i++) {
        if (FT[i].seat_id == seat_id_to_update && FT[i].status == 0 && strcmp(FT[i].flt_no, fl_no) == 0) {
            printf("Choose detail to update:\n1. Name\n2. Age\n3. Mobile\n");
            scanf("%d", &option);
//when want to change any of our details among name ,age,moblie number
            switch (option) {
                case 1:
                    printf("Enter new name: ");
                    scanf("%s", FT[i].pn_name);
                    printf("Name updated successfully.\n");
                    break;
                case 2:
                    printf("Enter new age: ");
                    scanf("%d", &FT[i].age);
                    printf("Age updated successfully.\n");
                    break;
                case 3:
                    printf("Enter new mobile number: ");
                    scanf("%ld", &FT[i].mobile);
                    printf("Mobile number updated successfully.\n");
                    break;
                default:
                    printf("Invalid option.\n");
            }
            return;
        }
    }
    printf("Seat ID not found or ticket canceled.\n");
}
// Main menu
int main() {
    int choice;
    while (1) {
        printf("\n*** Welcome to Flight Reservation System ***\n");//diplays menu for our selection
        printf("1. Create Flight\n");
        printf("2. Display Flights\n");
        printf("3. Update Flight\n");
        printf("4. Book Tickets\n");
        printf("5. Display Tickets\n");
        printf("6. Update Passenger Details\n");
        printf("7. Cancel Ticket\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: update(); break;
            case 4: book_tkt(); break;
            case 5: tkt_dis(); break;
            case 6: update_psng(); break;
            case 7: cancel_tkt(); break;
            case 8: exit(0);
            default: printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}