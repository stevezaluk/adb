#include <iostream>
#include <libusb-1.0/libusb.h>
#include "../include/device.hpp"

using namespace std;

Device::Device() {
    
}

Device::Device(libusb_device *device) {
    Device::device = device;

}

libusb_device* Device::getDevice() {
    return Device::device;
}

libusb_device_descriptor Device::getDeviceDesc() {
    return this->desc;
}

libusb_device_handle* Device::getDeviceHandle() {
    return Device::handle;
}

void Device::setDevice(libusb_device *device) {
    Device::device = device;
}

void Device::setDeviceDesc(libusb_device_descriptor desc) {
    this->desc = desc;
}

void Device::setDeviceHandle(libusb_device_handle *handle) {
    Device::handle = handle;
}