#include <cassert>
#include <cstdio>
#include <libusb-1.0/libusb.h>
//#include "usb.h"

int main() {
  libusb_context *context = NULL;
  libusb_device **list = NULL;
  int rc = 0;
  ssize_t count = 0;

  rc = libusb_init(&context);
  assert(rc == 0);

  count = libusb_get_device_list(context, &list);
  assert(count > 0);

  for (size_t idx = 0; idx < count; ++idx) {
    libusb_device *device = list[idx];
    libusb_device_descriptor desc = {0};

    rc = libusb_get_device_descriptor(device, &desc);
    assert(rc == 0);
    printf("Vendor:Device = %04x:%04x\n", desc.idVendor, desc.idProduct);
  }
  uint16_t vid = 0x03eb; uint16_t pid = 0x204f;
  printf("Open device...\n");
  libusb_device_handle *handle = libusb_open_device_with_vid_pid(NULL, vid, pid);
  printf("Get device...\n");
  libusb_device *avrdevice = libusb_get_device(handle);
  unsigned char data[4];
  int actual_length;
  int r = libusb_bulk_transfer(handle, LIBUSB_ENDPOINT_IN, data, sizeof(data), &actual_length, 0);
  if (r == 0 && actual_length == sizeof(data)) {
     // results of the transaction can now be found in the data buffer
     // parse them here and report button press
     printf("%02x %02x %02x %02x\n",data[0],data[1],data[2],data[3]);
   } else {
     printf("Error\n");
   }

  printf("Closing device...\n");
  libusb_close(handle);
}
