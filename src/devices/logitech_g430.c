#include "../device.h"

#include <string.h>

static struct device device_g430;

static const uint16_t PRODUCT_ID = 0x0a4d;

static int g430_send_sidetone(hid_device* device_handle, uint8_t num);

void g430_init(struct device** device)
{
    device_g430.idVendor = VENDOR_LOGITECH;
    device_g430.idProductsSupported = &PRODUCT_ID;
    device_g430.numIdProducts = 1;

    strcpy(device_g430.device_name, "Logitech G430");

    device_g430.capabilities = /*CAP_SIDETONE*/ 0;
    device_g430.send_sidetone = &g430_send_sidetone;

    *device = &device_g430;
}

static int g430_send_sidetone(hid_device* device_handle, uint8_t num)
{
    // This used to work on mac via libusb
    // Needs to be redone for hid lib

    // Values for volumes 0 - 100 were taken from a USB data capture. Values for 101-128 were invented, but they work :)
    /*uint16_t volumes[129] = {
        0x00F2, 0x9EF9, 0x9CFD, 0x5500, 0x6702, 0x1304, 0x7A05, 0xAE06, 0xBD07, 0xAF08, 0x8909, 0x4F0A, 0x050B, 0xAE0B,
        0x4A0C, 0xDD0C, 0x660D, 0xE70D, 0x610E, 0xD50E, 0x430F, 0xAC0F, 0x1010, 0x7010, 0xCB10, 0x2411, 0x7911, 0xCA11,
        0x1912, 0x6512, 0xAF12, 0xF612, 0x3B13, 0x7E13, 0xBF13, 0xFE13, 0x3C14, 0x7714, 0xB214, 0xEA14, 0x2215, 0x5715,
        0x8C15, 0xC015, 0xF215, 0x2316, 0x5316, 0x8216, 0xB016, 0xDE16, 0x0A17, 0x3517, 0x6017, 0x6017, 0xB317, 0xDB17,
        0x0318, 0x2918, 0x5018, 0x5018, 0x9A18, 0xBE18, 0xE218, 0x0519, 0x2819, 0x4A19, 0x6C19, 0x8D19, 0xAD19, 0xCD19,
        0xED19, 0x0C1A, 0x2B1A, 0x4A1A, 0x671A, 0x851A, 0xA21A, 0xBF1A, 0xDB1A, 0xF81A, 0x131B, 0x2F1B, 0x4A1B, 0x641B,
        0x7F1B, 0x991B, 0xB31B, 0xCC1B, 0xE51B, 0xFE1B, 0x171C, 0x2F1C, 0x471C, 0x5F1C, 0x771C, 0x8E1C, 0xA51C, 0xBC1C,
        0xD31C, 0xE91C, 0x001D, 0x161D, 0x2C1D, 0x421D, 0x581D, 0x6E1D, 0x841D, 0x9A1D, 0xB01D, 0xC61D, 0xDC1D, 0xF21D,
        0x081E, 0x1E1E, 0x341E, 0x4A1E, 0x601E, 0x761E, 0x8C1E, 0xA21E, 0xB81E, 0xCE1E, 0xE41E, 0xFA1E, 0x101F, 0x261F,
        0x3C1F, 0x521F, 0x681F };*/

    //unsigned char data[2] = { volumes[num] >> 8, volumes[num] & 0xFF };

    //int size = libusb_control_transfer(device_handle, LIBUSB_DT_HID, LIBUSB_REQUEST_CLEAR_FEATURE, 0x0201, 0x0600, data, 0x2, 1000);

    // unused parameter
    (void)(device_handle);
    (void)(num);
    printf("G430 not supported in this build, see README\n");

    return HSC_ERROR;
}
