#include <iostream>
using namespace std;

// Function declarations
void start();
void organic();
void nonOrganic();

int main() {
    start();
    return 0;
}
void start() {
    char type;
    cout << "Enter waste type (O = Organic, N = Non-Organic): ";
    cin >> type;

    if (type == 'O' || type == 'o')
        organic();
    else if (type == 'N' || type == 'n')
        nonOrganic();
    else
        cout << "Invalid input!" << endl;
}
void organic() {
    char energy;
    cout << "Is it high energy? (y/n): ";
    cin >> energy;
    if (energy == 'y' || energy == 'Y')
        cout << "Use for bio-fuel" << endl;
    else
        cout << "Use for organic fertilizer" << endl;
}
void nonOrganic() {
    char reusable;
    cout << "Is it reusable? (y/n): ";
    cin >> reusable;
    if (reusable == 'y' || reusable == 'Y') {
        cout << "Reuse for other applications" << endl;
        return;
    }
    char recycle;
    cout << "Is it recyclable? (y/n): ";
    cin >> recycle;
    if (recycle == 'y' || recycle == 'Y')
        cout << "Recycle for other applications" << endl;
    else
        cout << "Send to landfill" << endl;
}
