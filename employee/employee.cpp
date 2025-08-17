#include <iostream>
using namespace std;

void Hiring() {
    char input;
    cout << "Arrange candidate meeting.\n";
    cout << "Conduct pre-interview.\n";
    cout << "Setup interview questions.\n";
    cout << "Conduct interview.\n";
    cout << "Good reference? (y/n): ";
    cin >> input;
    if (input == 'n' || input == 'N') {
        cout << "Candidate not hired.\n";
        return; 
    }
    cout << "Select candidate.\n";
    cout << "Evaluate pay rate.\n";
    cout << "Send employment offer letter.\n";

    cout << "Candidate accepts offer? (y/n): ";
    cin >> input;
    if (input == 'y' || input == 'Y') {
        cout << "Hire candidate.\n";
    } else {
        cout << "Candidate not hired.\n";
    }
}
void Reviewing() {
    char input;
    cout << "Review resumes on file.\n";
    cout << "Suitable candidate found? (y/n): ";
    cin >> input;
    if (input == 'y' || input == 'Y') {
        Hiring();  
    } else {
         char input;
    cout << "Develop recruitment plan.\n";
    cout << "Place advertisements.\n";
    cout << "Collect applications.\n";
    cout << "Qualified resume found? (y/n): ";
    cin >> input;
    if (input == 'y' || input == 'Y') {
        Hiring(); 
    } else {
        cout << "Candidate not hired.\n";
    }
    }
}
void RegularHiring() {
    char input;
    cout << "Post job internally.\n";
    cout << "Suitable candidate available? (y/n): ";
    cin >> input;
    if (input == 'y' || input == 'Y') {
        Reviewing();
    } else {
        cout << "Candidate not hired.\n";
    }
}

int main() {
    cout << "Define job description.\n";
    cout << "Send crew request to HR.\n";
    char input;
    cout << "Is it regular hiring process? (y/n): ";
    cin >> input;
    if (input == 'y' || input == 'Y') {
        RegularHiring();
    } else {
         cout << "special hiring\n";
    }

    return 0;
}
