#include<iostream>
#include<cstring>
#include <fstream>
using namespace std;
void logStep(const string& step, char input) {
    ofstream file("payment_verification_log.csv", ios::app);
    time_t now = time(0);
    char* dt = ctime(&now);
    dt[strlen(dt)-1] = '\0'; 
    file << step << "," << input << "," << dt << "\n";
    file.close();
}

void transaction() {
    cout << "Transaction completed successfully.\n";
    logStep("Transaction", 'y');
}

void checking(){
    char input;
    cout<< "is your payment verified by client? (y/n)";
    cin>>input;
    if(input=='y'||input=='Y'){
        cout<<"is the card valid?(y/n)";
        cin>>input;
        if(input=='y'||input=='Y'){
        cout<<"is funds available?(y/n)";
        cin>>input;
        if(input=='y'||input=='Y'){
        cout<<"payment verified by bank";
        cout<<"is your account valid?";
        cin>>input;
        if(input=='y'||input=='Y'){
            transaction();
            
logStep("Payment verified by client", input);

        }
        else{
            checking();
        }
        
    
    }
    else{
        checking();
    }
    }
    else{
        checking();
    }
    }
    else{
        checking();
    }
}

int main(){
    cout<<"order placed by client\n";
    checking();

}