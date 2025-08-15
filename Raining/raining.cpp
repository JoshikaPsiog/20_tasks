#include <iostream>
using namespace std;

void umbrella() {
bool found = false;
int attempt = 0;
    while (attempt < 2) {
        attempt++;
        cout << "Searching...attempt " << attempt << endl;
        cout << "Found umbrella? yes=1, no=0: ";
        cin >> found;
        if (found) {
            cout << "Bring umbrella" << endl;
            return; 
        }
    }
    cout << "Buy umbrella" << endl;
    cout << "Bring umbrella" << endl;
}

int main() {
    bool rain;
    cout << "Is it raining? yes=1, no=0: ";
    cin >> rain;
    if (rain) {
        bool found;
        cout << "Find umbrella" << endl;
        cout << "Found umbrella? yes=1, no=0: ";
        cin >> found;
        if (found) {
            cout << "Bring umbrella" << endl;
        } else {
            umbrella();
        }
    } else {
        cout << "Don't bring umbrella" << endl;
    }
    return 0;
}
