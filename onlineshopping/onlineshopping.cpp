#include <iostream>
using namespace std;

void sellerConfirm() {
    cout << "Seller confirms customer received order.\n";
}
void customerCollects() {
    cout << "Customer collects goods.\n";
    sellerConfirm();
}
void warehouseFlow() {
    cout << "Packed with other orders in warehouse.\n";
    cout << "Send warehouse goods to customer.\n";
    customerCollects();
}
void sellerFlow() {
    cout << "Contact seller to ship good.\n";
    cout << "Seller sends good to customer.\n";
    customerCollects();
}
int main() {
    cout << "Order placed in online.\n";
    char choice;
    cout << "Are all items in warehouse? (y/n): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        warehouseFlow();
    } else {
        sellerFlow();
    }

    return 0;
}
