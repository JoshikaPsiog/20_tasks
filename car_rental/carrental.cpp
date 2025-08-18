#include <iostream>
#include <map>
#include <cstring>
#include <ctime>
#include<fstream>
#include <sstream>

using namespace std;
string adminPassword = "admin123";

void lookForCar(){
    char input;
    cout<<"cars assigned\n";
    cout<<"did you make payment(y/n)\n";
    cin>>input;
    if(input=='y'||input=='Y'){
        cout<<"thank you for riding";
    }
    else{
        lookForCar();
    }
    
}
void  enquiries(){
    char input;
    cout<<"is there any quiries need to be solved?(y/n)";
    cin>>input;
    if(input=='y'||input=='Y'){
        cout<<"contact customer care team , to sortout the issues\n";
    }
    else{
        cout<<"no isses need to be solved\n";
    }
}
void updatelibrary(){
    cout<<"library updated";

}
void adminLogin(){
    string pwd;
    int out;
    cout << "Enter Admin Password: ";
    cin >> pwd;
    if (pwd == adminPassword) {
        cout << "Admin login successful.\n";
        cout<<"choose the application\n";
        cout<<"1.update car library \n2.answer customer enquiries \n3.logout\n";
        cin>> out;
        if(out==1){
            updatelibrary();
        }
        else if(out==2){
            enquiries();
        }
        else{
            cout<<"logging out\nclosing\n";
            return;
        }
    }
}
map<string, string> users;
void loadUsersFromCSV() {
    ifstream file("user_data.csv");
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string username, password, action, timestamp;
        getline(ss, username, ',\n');
        getline(ss, password, ',');
        getline(ss, action, ',');
        getline(ss, timestamp, ',');
        if (action == "Registered" || action == "Password Reset") {
            users[username] = password;
        }
    }
    file.close();
}
void logToCSV(const string& username, const string& password, const string& action) {
    ofstream file("user_data.csv", ios::app);
    time_t now = time(0);
    char* dt = ctime(&now);
    dt[strlen(dt)-1] = '\0'; 
    file << username << "," << password << "," << action << "," << dt << "\n";
    file.close();
}
void userLogin() {
    loadUsersFromCSV();
    int choice;
    cout << "\n1. Register\n2. Login\nChoice: ";
    cin >> choice;

    string u, p;
    if (choice == 1) {
        cout << "Enter new username: ";
        cin >> u;
        cout << "Enter new password: ";
        cin >> p;
        users[u] = p;
        logToCSV(u, p, "Registered");
        cout << "User registered successfully!\n";
    } else if (choice == 2) {
        cout << "Enter username: ";
        cin >> u;
        cout << "Enter password: ";
        cin >> p;

        if (users.count(u) && users[u] == p) {
            logToCSV(u, p, "Login");
            cout << "Login successful!\n";
             lookForCar(); 
        } else {
            cout << "Invalid login. Forgot password? (y/n): ";
            char ans;
            cin >> ans;
            if (ans == 'y') {
                cout << "Enter new password: ";
                cin >> p;
                users[u] = p;
                logToCSV(u, p, "Password Reset");
                cout << "Password reset successful.\n";
            }
            else{
                userLogin(); 
            }
        }
    }
}


int main(){
    int role;
  cout << "1. Admin Login\n2. User Login\n3. Exit\nChoice: ";
        cin >> role;
        if (role == 1) adminLogin();
        else if (role == 2) userLogin();
        else if (role == 3) cout << "Exiting system...\n";

}