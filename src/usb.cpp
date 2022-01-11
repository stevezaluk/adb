#include <iostream>
#include <string>
#include <sstream>

#include <libusb-1.0/libusb.h>
#include "../include/usb.hpp"
#include "../include/colors.hpp"
#include "../include/utils.hpp"

using namespace std;

USBProtocol::USBProtocol() {
    const libusb_version *version = libusb_get_version();
    cout << "[libusb] Version: " << version->major << "." << version->minor << "." << version->micro << version->rc << endl;
    
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
    const libusb_version *version = libusb_get_version();
    cout << "[libusb] Version: " << version->major << "." << version->minor << "." << version->micro << version->rc << endl;

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

void USBProtocol::findDevices() {
    this->deviceCount = libusb_get_device_list(this->context, &this->rawDeviceList);
    if(this->deviceCount == 0) {
        cout << "[libusb] " << RED "Error" << RESET << ": No USB devices found" << endl;
        return;
    } else {
        cout << "[libusb] Obtained device list" << endl;
    }

    for(size_t i = 0; i < this->deviceCount; i++) {
        libusb_device *device = this->rawDeviceList[i];
        libusb_device_descriptor desc = {0};

        int ret = libusb_get_device_descriptor(device, &desc);
        if(ret != 0) {
            cout << "[libusb] " << RED "Error" << RESET << ": Failed to find device descriptor" << endl;
        }

        stringstream str;
        str << hex << desc.idVendor;
        string vendorStr = str.str();
        
        bool vendorCheck = checkForVendor(vendorStr);
        if(vendorCheck == true) {
            Device *d = new Device();
            d->setDevice(device);
            d->setDeviceDesc(desc);

            printf("[libusb] %sFound%s: Connected Device (0x%04x) [%04x]\n", GREEN, RESET, d->desc.idVendor, d->desc.iSerialNumber);
            this->connectedDevices.push_back(d);
            break;
        }
    }
    if(this->connectedDevices.size() == 0) {
        this->currentDevice = nullptr;
        cout << "[libusb] " << RED "Error" << RESET << ": No android devices found!" << endl;
    } else if(this->connectedDevices.size() == 1) {
        this->currentDevice = this->connectedDevices.at(0);
    } else {
        this->currentDevice = nullptr;
    }
}
    
USBProtocol::~USBProtocol() {
    libusb_free_device_list(this->rawDeviceList, this->deviceCount);
    libusb_exit(this->context);
}
