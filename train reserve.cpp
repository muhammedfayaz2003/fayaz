#include <stdio.h>
#include <stdbool.h>

#define NUM_SEATS 30

// Function to display the available seats
void displaySeats(bool seats[], int numSeats) {
    printf("Available seats:\n");
    for (int i = 0; i < numSeats; i++) {
        if (!seats[i]) {
            printf("Seat %d\n", i + 1);
        }
    }
}

int main() {
    bool seats[NUM_SEATS] = {false};  // Initialize all seats as available

    while (1) {
        int choice;
        printf("\nTrain Ticket Reservation System\n");
        printf("1. Reserve a seat\n");
        printf("2. Display available seats\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                displaySeats(seats, NUM_SEATS);

                int seatNumber;
                printf("Enter the seat number you want to reserve: ");
                scanf("%d", &seatNumber);

                if (seatNumber >= 1 && seatNumber <= NUM_SEATS) {
                    if (!seats[seatNumber - 1]) {
                        seats[seatNumber - 1] = true;
                        printf("Seat %d reserved successfully.\n", seatNumber);
                    } else {
                        printf("Seat %d is already reserved.\n", seatNumber);
                    }
                } else {
                    printf("Invalid seat number.\n");
                }

                break;
            }
            case 2: {
                displaySeats(seats, NUM_SEATS);
                break;
            }
            case 3: {
                printf("Exiting the program.\n");
                return 0;
            }
            default: {
                printf("Invalid choice. Please select a valid option.\n");
                break;
            }
        }
    }

    return 0;
}
