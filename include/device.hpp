#include <iostream>
#include <string>
#include <libusb-1.0/libusb.h>

#ifndef DEV_H
#define DEV_H

using namespace std;

class Device {
    public:
        string state;

        libusb_device *device;
        libusb_device_descriptor desc;

        Device(libusb_device *device);
        ~Device();
        
        void upload(string filename);
        void download(string filename);
        void install(string apk);
        void uninstall(string appName);

        void command(string command);
        void shell();

        void reboot(string mode);
        void info();

        void wipeUserData();
};

#endif DEV_H