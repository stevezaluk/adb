#include <iostream>

#include "include/usb.hpp"

using namespace std;

void usage() {
    cout << "adb - Android Debug Bridge" << endl << endl;
    cout << "Basics: " << endl;
    cout << "help : Print this page" << endl;
    cout << "devices : Scan and display connected devices" << endl;
    cout << "-s [serialNumber] : Use device with this serial number" << endl;
}

int main(int argc, char **argv) {
    return 0;
}
