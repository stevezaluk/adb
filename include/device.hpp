#include <iostream>
#include <string>
#include <libusb-1.0/libusb.h>

#ifndef DEV_H
#define DEV_H

using namespace std;

class Device {
    protected:
        libusb_device *device;
        libusb_device_descriptor desc;
        libusb_device_handle *handle;

    public:
        string state;
        string manufacturer;

        Device();
        Device(libusb_device *device);
        ~Device();

        libusb_device *getDevice();
        libusb_device_descriptor getDeviceDesc();
        libusb_device_handle *getDeviceHandle();

        void setDevice(libusb_device *device);
        void setDeviceDesc(libusb_device_descriptor desc);
        void setDeviceHandle(libusb_device_handle *handle);
        
        void upload(string filename);
        void download(string filename);
        void install(string apk);
        void uninstall(string appName);

        void command(string command);
        void shell();

        void reboot(string mode);
        void info();

        void wipeUserData();
        
        void openHandle();
        void writeData(void *data);
        void readData();
};

#endif
