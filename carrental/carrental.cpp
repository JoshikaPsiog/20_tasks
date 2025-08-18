#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, string> users; 
map<string, bool> cars;      
string adminPassword = "admin123";

void updateCarLibrary() {
    int choice;
    cout << "1. Add Car\n2. Remove Car\n3. Show Cars\nChoice: ";
    cin >> choice;
    if (choice == 1) {
        string car;
        cout << "Enter car name to add: ";
        cin >> car;
        cars[car] = true;
        cout << car << " added successfully.\n";
    } else if (choice == 2) {
        string car;
        cout << "Enter car name to remove: ";
        cin >> car;
        if (cars.erase(car))
            cout << car << " removed successfully.\n";
        else
            cout << "Car not found.\n";
    } else if (choice == 3) {
        cout << "\nAvailable Cars:\n";
        for (auto &c : cars)
            cout << c.first << (c.second ? " (Available)" : " (Booked)") << endl;
    }
}
void answerEnquiries() {
    cout << "Example: How many cars available?\n";
    cout << "Currently available cars:\n";
    for (auto &c : cars)
        if (c.second) cout << c.first << endl;
}
void makePayment() {
    cout << "Payment successful\n";
}
void lookForCar() {
    for (auto &c : cars)
        if (c.second) cout << c.first << endl;

    string choice;
    cout << "Enter car to book: ";
    cin >> choice;

    if (cars.find(choice) != cars.end() && cars[choice]) {
        cars[choice] = false;
        cout << choice << " booked successfully!\n";
        makePayment();
    } else {
        cout << "Car not available.\n";
    }
}
void userLogin() {
    int choice;
    cout << "\n1. Register\n2. Login\nChoice: ";
    cin >> choice;

    if (choice == 1) {
        string u, p;
        cout << "Enter new username: "; cin >> u;
        cout << "Enter new password: "; cin >> p;
        users[u] = p;
        cout << "User registered successfully!\n";
    } else if (choice == 2) {
        string u, p;
        cout << "Enter username: "; cin >> u;
        cout << "Enter password: "; cin >> p;

        if (users.count(u) && users[u] == p) {
            cout << "Login successful!\n";
            lookForCar();
        } else {
            cout << "Invalid login. Forgot password? (y/n): ";
            char ans; cin >> ans;
            if (ans == 'y') {
                cout << "Enter new password: "; cin >> p;
                users[u] = p;
                cout << "Password reset successful.\n";
            }
        }
    }
}

void adminLogin() {
    string pwd;
    cout << "Enter Admin Password: ";
    cin >> pwd;

    if (pwd == adminPassword) {
        cout << "Admin login successful.\n";
        int choice;
        do {
            cout << "\n--- Admin Menu ---\n";
            cout << "1. Update Car Library\n2. Answer Customer Enquiries\n3. Logout\nChoice: ";
            cin >> choice;
            switch (choice) {
                case 1: updateCarLibrary(); break;
                case 2: answerEnquiries(); break;
                case 3: cout << "Logging out...\n"; break;
                default: cout << "Invalid choice.\n";
            }
        } while (choice != 3);
    } else {
        cout << "Invalid Admin password!\n";
    }
}

int main() {
    cars["BMW"] = true;
    cars["Audi"] = true;
    cars["Tesla"] = true;

    int role;
    do {
        cout << "1. Admin Login\n2. User Login\n3. Exit\nChoice: ";
        cin >> role;
        if (role == 1) adminLogin();
        else if (role == 2) userLogin();
        else if (role == 3) cout << "Exiting system...\n";
        else cout << "Invalid choice.\n";
    } while (role != 3);
    return 0;
}
