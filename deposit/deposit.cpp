#include <iostream>
#include <string>
using namespace std;

void MoneyProcess() {
    char input;
    cout << "cheque requires 7 days for clearance (y/n).\n";
    cin>>input;
    if(input=='Y'||input=='Y'){
         cout << "money transfer successful! Amount credited to receiver account.\n";
    }
else{
 cout << "did the sender review the transaction? (y/n): ";
    cin >> input;
    if (input == 'y' || input== 'Y') {
        cout << "Did the sender authorize the transaction? (y/n): ";
        cin >> input;
        if (input == 'y' || input == 'Y') {
            cout << "Money transfer successful! Amount credited to receiver account.\n";
        } else {
            cout << "Invalid transaction (authorization denied).\n";
            cout << "Returning...\n";
        }
    } else {
        cout << "Invalid transaction (not reviewed).\n";
        cout << "Returning...\n";
        MoneyProcess();
    }
}
}
int main() {
    string senderAcc, receiverAcc;
    double value;
    char card, cheque;
    cout << "Insert bank card to machine (y/n): ";
    cin >> card;
    if (card == 'n' || card == 'N') {
        cout << "Transaction cancelled. Card not inserted.\n";
        return 0;
    }
    cout << "enter receiver bank account number: ";
    cin >> receiverAcc;
    cout << "insert cheque into machine (y/n): ";
    cin >> cheque;
    if (cheque == 'n' || cheque == 'N') {
        cout << "transaction cancelled. cheque not inserted.\n";
        return 0;
    }
    cout << "enter sender account number: ";
    cin >> senderAcc;
    cout << "enter value: ";
    cin >> value;
    cout << "processing deposit...\n";
    MoneyProcess();
    return 0;
}
