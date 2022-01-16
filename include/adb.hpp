#include <iostream>

#include "usb.hpp"

using namespace std;

#ifndef ADB_H
#define ADB_H

class ADBProtocol: public USBProtocol {
    public:
        ADBProtocol();
        ~ADBProtocol();
};

#endif