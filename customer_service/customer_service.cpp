#include<iostream>
#include <cstring>
#include <fstream>
using namespace std;

void log(const string& issue){
    ofstream file("issues_db.csv",ios::app);
    time_t now= time(0);
    char* dt=ctime(&now);
    dt[strlen(dt)-1] = '\0'; 
    file << issue << "," << dt << "\n";
    file.close();
}
void feedback(){
    cout<<"please give us your feedback";
}
void questions(){
    char input;
    cout<<"is it a sales issue(y/n)?";
    cin>>input;
    if(input=='Y'||input=='y'){
        cout<<"redirect to sales report";
        feedback();
    }
    else{
        cout<<"is it a technical issue(y/n)?";
        cin>>input;
    if(input=='Y'||input=='y'){
        cout<<"redirect to sales report";
        feedback();
    }
    else{
        cout<<"it is a new issue?(y/n)";
        cin>>input;
        if(input=='Y'||input=='y'){
        cout<<"resolve new issue\n";
        cout<<"simulate issue\n";
        if(input=='Y'||input=='y'){
        log("new_issue,resolved");
    }
    else{
        cout<<"contact customer for more information\n";
    }
    }
    else{
         cout<<"test issue\n";
         cout<<"simulate issue\n";
        if(input=='Y'||input=='y'){
        log("new_issue,simulated,but not solved");
    }
    else{
        cout<<"contact customer for more information\n";
    }
    }
    }
    }
}
int main(){
    char input;
   cout<<"customer found issue\n";
   cout<<"customer contact customer service\n";
   cout<<"Do you have any enquiries?\n";
   cin>>input;
   if(input=='Y'||input=='y'){
        cout<<"your quiries will be answered shortly\n";
        cout<<"please give us ur feedback\n";
        feedback();
   }
else if(input=='n'||input=='N'){
    questions();
   }
}