# Test run Dumping USB content using libusb

CC           = gcc
LD_FLAGS     = `pkg-config --libs libusb-1.0`
TARGET       = libusbtest
SRC          = $(TARGET).cpp

TARGET_HID   = generic_hid
SRC_HID      = $(TARGET_HID).cpp

# Default target
all:
	$(CC) $(SRC) $(LD_FLAGS) -o $(TARGET)
	$(CC) $(SRC_HID) $(LD_FLAGS) -o $(TARGET_HID)

clean:
	rm $(TARGET) $(TARGET_HID)
