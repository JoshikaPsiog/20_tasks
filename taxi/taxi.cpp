#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <thread>
#include <chrono> 
using namespace std;

struct Order {
    int id;
    string name;
    int pickupTime; 
    string location;
};
struct Taxi {
    int id;
    bool available;
    int distance; 
};
void waitOneMinute() {
    cout << "Waiting 1 minute...\n";
    this_thread::sleep_for(chrono::seconds(1)); 
}
bool checkPickupTime(Order o) {
    if (o.pickupTime > 30) {
        cout << "Pickup time > 30 mins.\n";
        waitOneMinute();
        return false;
    }
    return true;
}
bool checkTaxi(Taxi t) {
    if (!t.available) {
        cout << "No taxis available.\n";
        waitOneMinute();
        return false;
    }
    if (t.distance > 10) {
        cout << "Taxi too far (>10 km).\n";
        waitOneMinute();
        return false;
    }
    return true;
}
void assignPassenger(Order o, Taxi t) {
cout << "Passenger " << o.name << " assigned to driver (Taxi " << t.id << ")\n";
    cout << "Taxi ride started from " << o.location << "\n";

    ofstream history("orderHistory.csv", ios::app);
    history << o.id << "," << o.name << "," << o.location << ",Taxi" << t.id << ",Completed\n";
    history.close();

    cout << "Ride complete. Added to order history.\n";
}
Order getOrder(string orderID) {
    ifstream file("orders.csv");
    string line;
    getline(file, line); 
    Order o = {0, "", 0, ""};
    while (getline(file, line)) {
        stringstream ss(line);
        string id, name, time, loc;
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, time, ',');
        getline(ss, loc, ',');
        if (id == orderID) {
            o.id = stoi(id);
            o.name = name;
            o.pickupTime = stoi(time);
            o.location = loc;
            break;
        }
    }
    file.close();
    return o;
}
Taxi findTaxi() {
    ifstream file("taxis.csv");
    string line;
    getline(file, line); 
    Taxi t = {0, false, 0};
    while (getline(file, line)) {
        stringstream ss(line);
        string id, available, dist;
        getline(ss, id, ',');
        getline(ss, available, ',');
        getline(ss, dist, ',');
        int avail = stoi(available);
        int d = stoi(dist);
        if (avail == 1) {
            t.id = stoi(id);
            t.available = true;
            t.distance = d;
            break;
        }
    }
file.close();
    return t;
}
int main() {
    string orderID;
    cout << "Enter Order ID to process: ";
    cin >> orderID;
    Order o = getOrder(orderID);
    if (o.id == 0) {
        cout << "Order not found in DB.\n";
        return 0;
    }
    cout << "Incoming order from " << o.name << " at " << o.location << "\n";
    Taxi t = findTaxi();
    if (t.id == 0) {
        cout << "No taxis found in DB.\n";
        return 0;
    }
    while (!checkPickupTime(o)); 
    while (!checkTaxi(t));       
    assignPassenger(o, t);
    return 0;
}
