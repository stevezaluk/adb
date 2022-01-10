#include <iostream>
#include <string>
#include <vector>

#include "../include/device.hpp"
#include <libusb-1.0/libusb.h>

using namespace std;

#ifndef USB_H
#define USB_H

class USBProtocol {
    protected:
        ssize_t deviceCount;
        libusb_context *context;
        libusb_device **rawDeviceList; // all connected usb devices (android or not)
    
    public:
        bool verbose;
        Device *currentDevice;
        vector<Device *> connectedDevices;
    
        USBProtocol(); 
        USBProtocol(libusb_context *context);
        ~USBProtocol();

        void findDevices();

        void setCurrentDevice(libusb_device *device);
        void setCurrentDevice(uint8_t serialNumber);
        void setCurrentDevice(string serialNumber);
};

#endif
