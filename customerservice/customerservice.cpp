#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

void logErrorToCSV(const string &errorType, const string &description) {
    ofstream file("error-database.csv", ios::app);
    if (!file) {
        cerr << "Error opening error-database.csv" << endl;
        return;
    }
    time_t now = time(0);
    string dt = ctime(&now);
    dt.pop_back();

    file << errorType << "," << description << "," << dt << "\n";
    file.close();
}

void answerQuestion() {
    cout << "Customer enquiry answered successfully.\n";
}

void redirectToSalesSupport() {
    cout << "Redirecting to sales support...\n";
    cout << "Sales report completed.\n";
}

bool contactTechnicalTeam() {
    cout << "Technical team contacted.\n";
    return true; 
}

bool testIssue() {
    cout << "Testing issue...\n";
    return false; 
}

void contactCustomerForInfo() {
    cout << "Contacting customer for more information...\n";
}

void confirmIssueFixed() {
    cout << "Issue confirmed fixed with customer.\n";
}

void getFeedback() {
    cout << "Feedback received from customer.\n";
}

void survey() {
    cout << "Survey completed.\n";
}

void errorReport() {
    cout << "Error report generated.\n";
    logErrorToCSV("Technical Error", "Unresolved issue during testing");
}

void errorAnalysis() {
    cout << "Error analysis completed.\n";
}

bool solveIssue() {
    cout << "Attempting to solve issue...\n";
    return true; 
}
int main() {
    cout << "Customer found an issue.\n";
    cout << "Customer contacted customer service.\n";

    int issueType;
    cout << "Enter issue type (1-Enquiry, 2-Sales, 3-Technical, 4-New Issue): ";
    cin >> issueType;

    switch(issueType) {
        case 1: 
            answerQuestion();
            getFeedback();
            survey();
            break;

        case 2: 
            redirectToSalesSupport();
            getFeedback();
            survey();
            break;

        case 3: 
            if (contactTechnicalTeam()) {
                confirmIssueFixed();
                getFeedback();
                survey();
            }
            break;

        case 4: { 
            bool resolved = false;
            do {
                if (testIssue()) {
                    confirmIssueFixed();
                    getFeedback();
                    survey();
                    resolved = true;
                } else {
                    contactCustomerForInfo();
                    errorReport();
                    errorAnalysis();
                    if (solveIssue()) {
                        confirmIssueFixed();
                        getFeedback();
                        survey();
                        resolved = true;
                    } else {
                        cout << "Issue unresolved, looping again...\n";
                    }
                }
            } while (!resolved);
            break;
        }
        default:
            cout << "Invalid input.\n";
    }
    return 0;
}
