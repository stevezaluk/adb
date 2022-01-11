#include <iostream>
#include <fstream>
#include <sstream>

#include "../include/utils.hpp"

using namespace std;

string openVendorFile() {
    string contents = "";
    
    ifstream file("../vendor_list.txt");

    file >> contents;

    file.close();

    return contents;
}

bool checkForVendor(string vendorId) {
    ifstream file("/Users/szaluk/lab/projects/adb/vendor_list.txt");

    while(!file.eof()) {
        string line;
        string vendor;

        getline(file, line);

        vendor = line.substr(0, line.find(':'));
        if(vendor == vendorId) {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}