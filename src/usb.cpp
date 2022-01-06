#include <iostream>
#include <string>


#include <libusb-1.0/libusb.h>
#include "../include/usb.hpp"

using namespace std;

USBProtocol::USBProtocol() {
    int init = libusb_init(&this->context);
    if(init == 0) {
        cout << "[libusb] Initialized" << endl;
    } else {
        cout << "[libusb] Error: Failed to initialize libusb" << endl;
        exit(0);
    }

    this->deviceList = nullptr;
}

USBProtocol::USBProtocol(libusb_context *context) {
    int init = libusb_init(&context);
    if(init == 0) {
        cout << "[libusb] Initialized" << endl;
    } else {
        cout << "[libusb] Error: Failed to initialize libusb" << endl;
        exit(0);
    }

    this->deviceList = nullptr;
}

USBProtocol::~USBProtocol() {
    libusb_free_device_list(this->deviceList, this->deviceCount);
    libusb_exit(this->context);
}