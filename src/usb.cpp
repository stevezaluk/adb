#include <iostream>
#include <string>
#include <sstream>

#include <libusb-1.0/libusb.h>
#include "../include/usb.hpp"
#include "../include/colors.hpp"
#include "../include/utils.hpp"

using namespace std;

USBProtocol::USBProtocol() {
    int init = libusb_init(&this->context);
    if(init == 0) {
        cout << "[libusb] Initialized" << endl << endl;
    } else {
        cout << "[libusb] Error: Failed to initialize libusb" << endl;
        exit(0);
    }

    this->rawDeviceList = nullptr;
    this->verbose = false;
}

USBProtocol::USBProtocol(libusb_context *context) {
    int init = libusb_init(&context);
    if(init == 0) {
        cout << "[libusb] Initialized" << endl;
    } else {
        cout << "[libusb] Error: Failed to initialize libusb" << endl;
        exit(0);
    }

    this->rawDeviceList = nullptr;
    this->verbose = false;
}

USBProtocol::~USBProtocol() {
    libusb_free_device_list(this->rawDeviceList, this->deviceCount);
    libusb_exit(this->context);
}
