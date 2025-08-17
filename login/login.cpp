#include <iostream>
#include <string>
using namespace std;

void LoginProcess() {
    string correctUser = "admin";
    string correctPass = "1234";
    string user, pass;
    int attempts = 5;
    while (attempts > 0) {
        cout << "\nEnter username: ";
        cin >> user;
        cout << "Enter password: ";
        cin >> pass;
if (user == correctUser && pass == correctPass) {
            cout << "Authorisation successful.\n";
            cout << "Access granted.\n";
            return; 
    } else {
            attempts--;
            cout << "Invalid login attempt. ";
if (attempts > 0) {
                cout << attempts << "attempts left.\n";
                cout << "Alerting user\n";
            } else {
                cout << "\nNo attempts left!\n";
                cout << "Account locked\n";
                return; 
            }
     } }
}
int main() {
    LoginProcess();
    return 0;
}
