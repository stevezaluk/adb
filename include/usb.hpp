#include <iostream>
#include <string>
#include <vector>

#include "../include/device.hpp"
#include <libusb-1.0/libusb.h>

using namespace std;

#ifndef USB_H
#define USB_H

class USBProtocol {
    private:
        ssize_t deviceCount;
        libusb_context *context;
        libusb_device **deviceList;
        
        Device *currentDevice;
    
    public:
        USBProtocol();
        USBProtocol(libusb_context *context);
        ~USBProtocol();

        void findDevices();

        void setCurrentDevice(libusb_device *device);
        void setCurrentDevice(uint8_t serialNumber);
        void setCurrentDevice(string serialNumber);

        void writeData(void *data);
        void readData();
};

#endif