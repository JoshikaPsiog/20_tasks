#include <iostream>
#include <string>
#include <limits>
#include <fstream>
using namespace std;

struct Student {
    string name;
    string program;
    bool verified = false;
    bool needsVisa = false;
    bool visaApplied = false;
    bool feePaid = false;
    bool wantsAccommodation = false;
    string accommodation;
    string tutor;
    bool hasExtraCredits = false;
    string extraCourse;
};
void clearLine() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
bool askYesNo(const string& prompt) {
    char c;
    while (true) {
        cout << prompt << " (y/n): ";
        if (!(cin >> c)) { clearLine(); continue; }
        c = tolower(c);
        if (c == 'y') return true;
        if (c == 'n') return false;
        cout << "Enter y or n only!\n";
    }
}
string askLine(const string& prompt) {
    cout << prompt;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string s;
    getline(cin, s);
    return s;
}
void Registration(Student& s) {
    s.name    = askLine("Enter student name: ");
    s.program = askLine("Enter Department: ");
    cout << "Form completed and sent to department.\n";
    cout << "Student info stored in DB.\n";
}
void AdmissionOffice(Student& s) {
    do {
        s.verified = askYesNo("Are details verified?");
        if (!s.verified) {
            cout << "Form returned for correction.\n";
            if (askYesNo("Edit name?"))    s.name    = askLine("New name: ");
            if (askYesNo("Edit program?")) s.program = askLine("New program: ");
        }
    } while (!s.verified);
    cout << "Details verified.\n";
}
void Visa(Student& s) {
    s.needsVisa = askYesNo("Need visa?");
    if (s.needsVisa) {
        cout << "Inform student for visa application.\n";
        while (!s.visaApplied) {
            s.visaApplied = askYesNo("Has visa been applied?");
            if (!s.visaApplied) cout << "Waiting until visa applied...\n";
        }
        cout << "Visa process done.\n";
    }
}
void Fee(Student& s) {
    while (!s.feePaid) {
        s.feePaid = askYesNo("Fee paid?");
        if (!s.feePaid) cout << "Waiting for payment...\n";
    }
    cout << "Fee payment confirmed.\n";
}
void Accommodation(Student& s) {
    s.wantsAccommodation = askYesNo("Need accommodation?");
    if (s.wantsAccommodation) {
        s.accommodation = askLine("Assign accommodation (room/hostel): ");
        cout << "Accommodation assigned: " << s.accommodation << "\n";
    } else {
        cout << "No accommodation requested.\n";
    }
}
void Tutor(Student& s) {
    s.tutor = askLine("Assign tutor name: ");
    cout << "Student meets tutor " << s.tutor << "\n";
}
void ExtraCourse(Student& s) {
    s.hasExtraCredits = askYesNo("Has extra credits?");
    if (s.hasExtraCredits) {
        s.extraCourse = askLine("Choose extra course: ");
        cout << "Extra course chosen: " << s.extraCourse << "\n";
    }
}
void FullyRegistered(Student& s) {
    cout << s.name << " (" << s.program << ") registration complete.\n";
    cout << "Summary:\n";
    cout << "Verified: " << (s.verified ? "Yes" : "No") << "\n";
    cout << "Visa: " << (s.needsVisa ? (s.visaApplied ? "Applied" : "Required") : "Not required") << "\n";
    cout << "Fee: " << (s.feePaid ? "Paid" : "Not Paid") << "\n";
    cout << "Accommodation: " << (s.wantsAccommodation ? s.accommodation : "Not requested") << "\n";
    cout << "Tutor: " << (s.tutor.empty() ? "Not assigned" : s.tutor) << "\n";
    cout << "Extra Course: " << (s.hasExtraCredits ? s.extraCourse : "None") << "\n";
    cout << "End of process.\n";
}
void SaveDB(Student& s) {
    ofstream db("students.csv", ios::app);
    if (db.tellp() == 0) {
        db << "Name,Department,Verified,Visa,Fee,Accommodation,Tutor,ExtraCourse\n";
    }
    db << s.name << "," << s.program << ","
       << (s.verified ? "Yes" : "No") << ","
       << (s.needsVisa ? (s.visaApplied ? "Applied" : "Required") : "Not required") << ","
       << (s.feePaid ? "Yes" : "No") << ","
       << (s.wantsAccommodation ? s.accommodation : "None") << ","
       << (s.tutor.empty() ? "None" : s.tutor) << ","
       << (s.hasExtraCredits ? s.extraCourse : "None") << "\n";
    db.close();
    cout << "Data saved to students.csv\n";
}
int main() {
    Student s;
    Registration(s);
    AdmissionOffice(s);
    Visa(s);
    Fee(s);
    Accommodation(s);
    Tutor(s);
    ExtraCourse(s);
    FullyRegistered(s);
    SaveDB(s);
    return 0;
}
