# Test run Dumping USB content using libusb

CC           = g++
LD_FLAGS     = `pkg-config --libs libusb-1.0`
TARGET       = libusbtest
SRC          = $(TARGET).cpp

# Default target
all:
	$(CC) $(SRC) $(LD_FLAGS) -o $(TARGET)

