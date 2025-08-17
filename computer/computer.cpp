#include <iostream>
using namespace std;

void Power() {
    char input;
cout << "Is the power light on? (y/n): ";
  cin>>input;
    if (input == 'y' || input == 'Y') {
        cout << "Find a specialist.\n";
}
else{
  cout << "Is the power plugged into the wall? (y/n): ";
    cin >> input;
    if (input == 'y' || input == 'Y') {
        cout << "Find a specialist.\n";
}
else{
cout << "Plug power to the wall.\n";
        Power(); 
}
}       
}
void diagnosis() {
    char input;
    cout << "Is the computer ON? (y/n): ";
    cin >> input;

    if (input == 'y' || input == 'Y') {
        cout << "Is there any error message? (y/n): ";
        cin >> input;

        if (input == 'y' || input == 'Y') {
            cout << "perform diagnosis\n";
            diagnosis();

        } else {
            cout << "Computer in good condition.\n";
        }
    } else {
        Power(); 
    }
}

int main() {
    diagnosis();
    return 0;
}

