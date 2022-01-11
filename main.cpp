#include <iostream>
#include <string.h>

#include "include/usb.hpp"
#include "include/colors.hpp"

using namespace std;

void usage() {
    cout << "adb - Android Debug Bridge" << endl << endl;
    cout << "Basics: " << endl;
    cout << "help : Print this page" << endl;
    cout << "devices : Scan and display connected devices" << endl;
}

int main(int argc, char **argv) {    
    if(argc == 1) {
        cout << "[adb] " << RED << "Error" << RESET << ": Invalid ammount of argument" << endl;
        usage();
        return 1;
    }

    if(strcmp(argv[1], "help") == 0) {
        usage();
    } else if(strcmp(argv[1], "devices") == 0) {
        USBProtocol *u = new USBProtocol();
        u->findDevices();
        delete u;
    } else {
        cout << "[adb] " << RED << "Error" << RESET << ": Invalid argument" << endl;
    }

    return 0;
}
