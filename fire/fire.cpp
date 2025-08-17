#include <iostream>
using namespace std;

void Function();
void Smoke();
void NoSmoke();

int main() {
    char inside;
    cout << "You see fire/smoke OR smoke detector triggers alarm.\n";
    cout << "Are you inside the building? (y/n): ";
    cin >> inside;
    if (inside == 'n' || inside == 'N') {
        cout << "Contact the fire department immediately.\n";
        return 0;
    } else {
        cout << "Push the fire alarm.\n";
        cout << "Bring keys, wallet, wet towels, and phone.\n";
        Function();
    }
    return 0;
}
void Function() {
    char choice;
    cout << "Is the door hot or smoke sweeping in? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        Smoke();
    } else {
        NoSmoke();
    }
}
void Smoke() {
    cout << "Seal all the cracks with wet towels.\n";
    cout << "Contact the fire department.\n";
    cout << "Wave at the windows to identify yourself.\n";
    cout << "Wait for rescue\n";
    cout << "Return to safety\n";
}
void NoSmoke() {
    char choice;
    cout << "Go downstairs until you leave the building.\n";
    cout << "Did you escape the building? (y/n): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        cout << "You are safe outside.\n";
        return; 
    } else {
        cout << "Do you see fire or strong smoke? (y/n): ";
        cin >> choice;
    if (choice == 'y' || choice == 'Y') {
            cout << "Go upstairs and head to balcony.\n";
                cout << "Reached balcony? (y/n): ";
            cin >> choice;
            if (choice == 'y' || choice == 'Y') {
                cout << "Wait for rescue.\n";
                return;
            } else {
                cout << "Do you still see fire/smoke? (y/n): ";
                cin >> choice;
        if (choice == 'y' || choice == 'Y') {
                    cout << "You are trapped. Wait for help.\n";
                    return;
        } else {
                    cout << "Find and enter a safe room.\n";
                    cout << "Wait for rescue.\n";
                    return;
                }
            }
} else {
            cout << "No fire/smoke seen, continue moving...\n";
            NoSmokeScenario(); 
        }
    }
}
