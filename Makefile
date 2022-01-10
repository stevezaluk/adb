cc=g++
targets=main.cpp src/*.cpp
libusbflags=`pkg-config --libs --cflags libusb-1.0`
debugflags=-Wall -Werror -pedantic
output=adb

debug:
	$(cc) $(targets) $(debugflags) $(libusbflags) -o a.out

all:
	$(cc) $(targets) $(libusbflags) -o $(output)
