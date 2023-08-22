# arduino-dmx-midi
Takes a DMX input and outputs midi notes with different velocitys, depending on the input  
useful if you want to use an old DMX desk as a midi controller for your PC

based on USBMIDI.h and DMXSerial.h (both obtainable using the library manager)  
if you're using this and the COM port in windows creates issues, you want to turn off CDC:  
locate your arduino15 folder and find USBDesc.h and uncomment #define CDC_DISABLED.  
also, change the product version (0x100) in USBCore.cpp to any other hex number.  Example files are provided in this repo.
On windows, you'll need to choose a different driver as well: open device manager, update driver, choose from list and then audio device  
Warning: to upload you'll now have to press the reset button, also usb serial doesn't work anymore (revert the changes to use it again)
