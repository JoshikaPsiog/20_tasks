#include<iostream>
#include<fstream>
using namespace std;
 
string database="student.csv";
fstream fout;
int age;
string name,place,gender;
 
void Correspondent();
void Visa();
void TuitionFees();
void Accommodation();
void PersonalTutor();
 
void PersonalTutor() {
    cout<<"\nPERSONAL TUTOR PROCESS\n";
    cout<<"\nAssigning a personal tutor for the student\n";
    string credit;
    cout<<"\nDoes the student have extra credits? (yes/no): ";
    cin>>credit;
    if(credit == "yes") {
        cout<<"\nChoose the extra credit courses.\n";
    } else {
        cout<<"\nNo extra credits assigned.\n";
    }
    cout<<"\nStudent Admission Process Completed.\n";
}
void Accommodation() {
    cout<<"\nACCOMMODATION PROCESS\n";
 
    string need;
    cout<<"\nDo you need accommodation? (yes/no): ";
    cin>>need;
 
    if(need=="yes") {
        cout<<"\nAccommodation assigned successfully.\n";
    } else {
        cout<<"\nNo accommodation required.\n";
    }
 
    PersonalTutor();
}
void TuitionFees() {
    cout<<"\nTUITION FEES PROCESS\n";
 
    while (true) {
        string fee;
        cout<<"\nHave you paid the tuition fees? (yes/no): ";
        cin>>fee;
 
        if(fee == "yes") {
            cout<<"\nTuition fees paid successfully.\n";
            Accommodation();
            break;
        } else {
            cout<<"\nPlease pay the tuition fees to continue.\n";
        }
    }
}
void Visa() {
    cout<<"VISA PROCESS\n";
    string need,applied;
    cout<<"Do you need a visa? (yes/no):\n ";
    cin>>need;
    if(need == "yes") {
        cout<<"Informing student about visa requirements.\n";
        while(true) {
            cout<<"Have you applied for the visa? (yes/no): ";
            cin>>applied;
            if(applied == "yes") {
                cout<<"\nVisa application is in process.\n";
                TuitionFees();
                break;
            } else {
                cout<<"\nPlease apply for the visa.\n";
            }
        }
    } else {
        TuitionFees();
    }
}
void Correspondent() {
    cout<<"CORRESPONDENT PROCESS\n";
    cout<<"Enter Student Name: ";
    cin>>name;
    cout<<"Enter Age: ";
    cin>>age;
    cout<<"Enter Place: ";
    cin>>place;
    cout<<"Enter Gender: ";
    cin>>gender;
    fout.open(database, ios::out | ios::app);
    fout<<name<<","<<age<<","<<place<<","<<gender<<"\n";
    fout.close();
    cout<<"Data sent to correspondent successfully.\n";
    Visa();
}
int main() {
    cout<<"STUDENT ADMISSION PROCESS\n";
    Correspondent();
    cout<<"\nEND OF ADMISSION PROCESS\n";
}