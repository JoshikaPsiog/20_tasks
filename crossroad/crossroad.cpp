#include <iostream>
#include <string>
using namespace std;

void starting();
void process();
void carapproach(); 

int main() {
    starting();
}

void starting() {
    char input;
    while (true) {
        cout << "Did you find foot bridge (y/n)? ";
        cin >> input;
        if (input == 'y' || input == 'Y') {
            cout << "Use the foot bridge" << endl;
            break;
        }

        cout << "Did you find tunnel (y/n)? ";
        cin >> input;
        if (input == 'y' || input == 'Y') {
            cout << "Use the tunnel" << endl;
            break;
        }

        cout << "Did you find crossing (y/n)? ";
        cin >> input;
        if (input == 'y' || input == 'Y') {
            cout << "Walk away" << endl;
            starting();
            break;
        } else {
            process();
        }
    }
}

void process() {
    string color;
    cout << "Did you see Traffic Light? ";
    cin >> color;
    for (char &c : color) {
        c = tolower(c);
    }
    if (color == "green") {
        cout << "Color is green  go" << endl;
        process();
    } else {
        cout << "Color is red " << endl;
        
        // Break;
       carapproach();
        return;
    }
}
void carapproach(){
    char input;
    cout<<"look right"<<endl;
    cout<<"is any car approacing?"<<endl;
    cin>>input;
    if(input=='y'||input=='Y'){
        carapproach();
    }
    else{
        cout<<"cross the traffic"<<endl;
        exit(0);
    }
}
