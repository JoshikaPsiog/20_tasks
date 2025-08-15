#include <iostream>
using namespace std;

void coffee(bool flag);

int main() {
    cout<< "power ON"<<endl;
    bool flag = true;  
    // cout << flag<<endl; 
        coffee(flag); 
     
}

void coffee(bool flag){
 int choice ;
 bool off;
 cout << "Enter your choice (1 - mocha ,2 - latte  or 3 - Expresso): ";
    cin>> choice ;
    switch (choice) {
        case 1:
            cout << "Add chocolaate powered" << endl;
            
        case 2:
            cout << "Add frothed milk" << endl;
            
        case 3:
            cout << "Add hot coffee" << endl;
            break;
        default:
            cout << "Invalid choice! Please enter 1, 2, or 3." << endl;
            break;
    }
   cout<<"continue?"<<endl;
   cin>>off;
   if (off) coffee(off);
    // coffee();
    // cout<<"do u want to continue ?"<<endl;
    //     cin>> flag ;
    //     if(flag) 
    //       coffee();
    //     else
    //       cout<<"power off";

}