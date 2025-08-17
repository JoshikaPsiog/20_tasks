#include <iostream>
using namespace std;

void grade(int marks) {
    const int A = 1, B = 2, C = 3, F = 4;
    int gradeType;

    if (marks >= 80 && marks <= 100) gradeType = A;
    else if (marks >= 60 && marks < 80) gradeType = B;
    else if (marks >= 50 && marks < 60) gradeType = C;
    else gradeType = F;

    switch (gradeType) {
        case A:
            cout << "A Grade" << endl;
            break;
        case B:
            cout << "B Grade" << endl;
            break;
        case C:
            cout << "C Grade" << endl;
            break;
        case F:
            cout << "Fail" << endl;
            break;
    }
}

int check() {
    int marks;
    cout << "Enter the score: ";
    cin >> marks;

    if (marks >= 0 && marks <= 100) {
        grade(marks);
    } else {
        cout << "Invalid score! Try again." << endl;
        check();
    }
    return marks;
}

int main() {
    char input;
    check();
    cout<<"do you have any corrections?(y/n)"<<endl;
    cin>>input;
    if(input=='y'||input=='Y'){
        check();
    }

}
