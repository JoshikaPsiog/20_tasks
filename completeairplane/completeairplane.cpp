#include <iostream>
using namespace std;

void Checking() {
    char input;
    cout << "Metal detected in screening? (y/n): ";
    cin >> input;
    if (input == 'y' || input == 'Y') {
        cout << "Perform hand search.\n";
    }
    else{
        cout<<"immigration\n";
    }
    cout << "Carrying dangerous goods? (y/n): ";
    cin >> input;
    if (input == 'y' || input == 'Y') {
        cout << "Give up dangerous goods.\n";
    }
     else{
        cout<<"immigration\n";
    }
    cout << "Articles above permitted areas? (y/n): ";
    cin >> input;
    if (input == 'y' || input == 'Y') {
        cout << "Give up articles above permitted areas.\n";
    }
     else{
        cout<<"immigration\n";
    }
}
void Process() {
    char input;
        cout << "Permit to enter country? (y/n): ";
        cin >> input;
        if (input == 'y' || input == 'Y') {
            cout << "Permit granted.\n";
            cout << "Claim baggage.\n";
        } else {
            cout << "Send to originating country.\n";
        }
    
}
int main() {
    cout << "Check in.\n";
    cout << "Baggage drop.\n";
    cout << "Security screening.\n";
    Checking();  
    cout << "Board flights.\n";
    cout << "Flight departs.\n";
    cout << "Flight lands.\n";
    char input;
    cout << "Connection flight? (y/n): ";
    cin >> input;
    if (input == 'y' || input == 'Y') {
        Process();
    }
    cout << "Claim baggage.\n";
    cout << "Leave flight.\n";
    return 0;
}
