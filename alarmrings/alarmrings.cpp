#include <iostream>
using namespace std;
void prgm();

int main(){
    
   cout<<"alarm is ringing"<<endl;
   prgm();
  
}

void prgm(){
     cout<<"Are you ready to wake up?"<<endl;
     char input;
    cin>> input;
   if(input=='y'||input=='Y'){
    cout<<"leave bed"<<endl;
    cout<<"did you leave bed?"<<endl;
    cin>> input;
    if(input=='y'||input=='Y'){
        cout<<"turning off the alarm"<<endl;
    }
    else{
        prgm();
    }
}
   else{
    cout<<"wil you be late?"<<endl;
    cin>>input;
    if(input=='y'||input=='Y'){
        cout<<"leave bed"<<endl;
    cout<<"did you leave bed?"<<endl;
    cin>> input;
    if(input=='y'||input=='Y'){
        cout<<"turning off the alarm"<<endl;
    }
    else{
        prgm();
    }
    }
    else{
        cout<<"snooze the alarm"<<endl;
        prgm();
    }
   }
}