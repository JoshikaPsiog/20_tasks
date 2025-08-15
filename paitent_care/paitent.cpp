#include <iostream>
using namespace std;
void assign();
void nurse();
void doctor();
int loop(); 

int main() {
    cout<<"are u in emergency?(yes=1 / no=0 )"<<endl;
    bool emergency;
    cin >> emergency; 
    if (emergency) {
        assign();    
    }
    else {
        int input = loop(); 
        if (input) {
            nurse();
            // doctor();
            assign();
        }
        else {
            cout << "register paitent" << endl;
            loop();
        }
    }
}

int loop() {
    bool inputs;
    cout << "is patient name registerd? yes(1) or no(0)" << endl;
    cin >> inputs;
    return inputs;
}

void assign(){
    cout<<"assigning doctor for you"<<endl;
    cout<<"do you need to followup? (y/n)"<<endl;
    char follow;
    cin>>follow;
    if(follow=='y'|| follow=='Y'){
    cout<<"appoinment will be arranged"<<endl;
    if(follow='y'||'Y'){
        cout<<"Give Patient Prescription"<<endl;
    }
    }
    cout<<"do you medication? (y/n)"<<endl;
    cin>>follow; 
    if(follow=='y'||follow=='Y'){
        cout<<"Give Patient Prescription"<<endl;
    }
    cout<<"paitent leaves"<<endl;
}
    void nurse(){
        cout<<"is any nurse available or not? (y/n)"<<endl;
        char input;
        cin>>input;
        if(input=='n'||input=='N'){
            cout<<"wait till nurse available"<<endl;
            nurse();
        }
        else{
             cout << "yor health condition is recorded" << endl;
            doctor();
        }
    }
    void doctor(){
        cout<<"is any doctor available or not? (y/n)"<<endl;
        char input;
        cin>>input;
        if(input=='n'||input=='N'){
            cout<<"wait till doctor available"<<endl;
            doctor();
        }
        else{
            assign();
        }
    }
