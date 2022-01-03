cc=g++
targets=main.cpp
libusbflags=`pkg-config --libs --cflags libusb-1.0`
debugflags=-Wall -Werror -pedantic
output=adb

all:
	$(cc) $(targets) $(debugflags) $(libusbflags) -o $(output)