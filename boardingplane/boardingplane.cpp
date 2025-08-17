#include <iostream>
#include <thread>  
#include <chrono>   
using namespace std;

void waitFiveMinutes() {
    cout << "\nTime(t): 5 minutes before plane..." << endl;
    for (int i = 5; i > 0; --i) {   
        cout << " Announcement in " << i << " sec...\r" << flush;
        this_thread::sleep_for(chrono::seconds(1));
    }
    cout << endl;
cout << "Announcement: 5 minutes before departure!" << endl;
}
void firstHalfBoarding() {
    char input;
cout << "Did first half of first-class passengers board? (y/n): ";
    cin >> input;

    if (input == 'y' || input == 'Y') {
        cout << "First half boarded successfully." << endl;
    } else {
        cout << "First half not boarded, retrying..." << endl;
        firstHalfBoarding();
    }
}
void secondHalfBoarding() {
  char input;
cout << "Did remaining first-class passengers board? (y/n): ";
cin >> input;
    if (input == 'y' || input == 'Y') {
        cout << "Remaining first-class boarded successfully." << endl;
    } else {
        cout << "Remaining passengers not boarded, retrying..." << endl;
        secondHalfBoarding(); 
    }
}
int main() {
char planeArrived;
cout << "Has the plane arrived at gate? (y/n): ";
cin >> planeArrived;
    if (planeArrived == 'y' || planeArrived == 'Y') {
        cout << "\nBoarding (B) started." << endl;
        cout << "Start priority boarding..." << endl;
        firstHalfBoarding();
        secondHalfBoarding();
        cout << "First-class boarding complete." << endl;
        char allBoarded = 'n';
        while (allBoarded == 'n' || allBoarded == 'N') {
            waitFiveMinutes();
            cout << "Have all general passengers boarded? (y/n): ";
            cin >> allBoarded;
        }
        cout << "\nAll passengers have boarded the plane." << endl;
        cout << "Closing gate..." << endl;
        cout << "End of process." << endl;
    } else {
        cout << "Plane not yet arrived. Process cannot start." << endl;
    }
    return 0;
}
