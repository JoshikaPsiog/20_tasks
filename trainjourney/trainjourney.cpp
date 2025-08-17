#include <iostream>
using namespace std;

void Ticket() {
    char input;
    cout << "Collect ticket (y/n): ";
    cin >> input;
    if (input == 'y' || input == 'Y') {
        cout << "Check letter box in 3 days or collect from machine.\n";
        cout << "Board train.\n";
    } else {
        cout << "Ticket not collected. Returning to Ticket step...\n";
        Ticket(); 
    }
}
void Reservation() {
    char input;
    cout << "Do you want a reservation? (y/n): ";
    cin >> input;
    if (input == 'y' || input == 'Y') {
        cout << "Select seat.\n";
        Ticket();
    } else {
        cout << "Need seat reservation! Returning to Reservation step...\n";
        Reservation(); 
    }
}
void Assigned() {
    char input;
    cout << "Do you have a reservation? (y/n): ";
    cin >> input;
    if (input == 'y' || input == 'Y') {
        cout << "Look for the assigned seat.\n";
    } else {
        cout << "Look for any unassigned seat.\n";
    }
    cout << "Ticket checked by inspector.\n";
}

void Discount() {
    char input;
    while (true) {
        cout << "Do you have a discounted ticket? (y/n): ";
        cin >> input;

        if (input == 'y' || input == 'Y') {
            cout << "Show valid documentation (y/n): ";
            cin >> input;

            if (input == 'y' || input == 'Y') {
                cout << "Discount approved.\n";
                break; // exit loop
            } else {
                cout << "Documentation invalid. Please try again.\n";
            }
        } else {
            cout << "No discounted ticket.\n";
            break; 
        }
    }
}
void Destination() {
    char input;
    cout << "Arrive at destination? (y/n): ";
    cin >> input;
    if (input == 'y' || input == 'Y') {
        cout << "Leave train.\n";
    } else {
        cout << "Not yet arrived. Returning to Destination step...\n";
        Destination(); 
    }
}

int main() {
 cout << "Buy tickets.\n";
    Reservation();
    Assigned();
    Discount();
    Destination();
    return 0;
}
