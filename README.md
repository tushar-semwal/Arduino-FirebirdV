# Arduino-FirebirdV (AtMega 2560)
Extending Arduino IDE for FirebirdV robot by Nex-Robotics.

`Note1: Current instructions are for Windows OS. Will be adding later for linux but others are free to try. Will not be that different from Windows.`. 
`Note2: Currently, this Arduino extension can only be used for creating the hex files. Directly uploading to FirebirdV is NOT implemented.`
## 1. Initial environment setup
1. Install AVR-GCC from [here](https://sourceforge.net/projects/winavr/files/).
2. Install latest Arduino IDE from [here](https://www.arduino.cc/en/Main/Software).

## 2. Setting up the Arduino IDE
1. Open the Arduino IDE and go to Tools->Boards. You will see a board for AtMega 2560. However, this board is set at F_CPU (cpu frequency) of 16MHz but the frequency of mega chip on Firebird robot is set to 14.7456MHz. Thus we need to create a new board configuration for the required frequencey.
2. The new board configuration is required to be appended to **boards.text** file which can found here (by default): `C:\Program Files (x86)\Arduino\hardware\arduino\avr\` or `<INSTALLED_FOLDER>\Arduino\hardware\arduino\avr\`.
3. Open the **boards.txt** file in **Admin** mode using your favourite text editor and add this to the file. Save it then.:
```
firebird.name=Firebird V Mega 2560 Robot

firebird.vid.0=0x2341
firebird.pid.0=0x0010
firebird.vid.1=0x2341
firebird.pid.1=0x0042
firebird.vid.2=0x2A03
firebird.pid.2=0x0010
firebird.vid.3=0x2A03
firebird.pid.3=0x0042
firebird.vid.4=0x2341
firebird.pid.4=0x0210
firebird.vid.5=0x2341
firebird.pid.5=0x0242

firebird.upload.tool=avrdude
firebird.upload.maximum_data_size=8192

firebird.bootloader.tool=avrdude
firebird.bootloader.low_fuses=0xFF
firebird.bootloader.unlock_bits=0x3F
firebird.bootloader.lock_bits=0x0F

firebird.build.f_cpu=14745600L

firebird.build.core=arduino
firebird.build.variant=mega
# default board may be overridden by the cpu menu
firebird.build.board=AVR_MEGA2560

## Arduino/Genuino Mega w/ ATmega2560
## -------------------------
firebird.menu.cpu.atmega2560=ATmega2560 (Mega 2560)

firebird.menu.cpu.atmega2560.upload.protocol=wiring
firebird.menu.cpu.atmega2560.upload.maximum_size=253952
firebird.menu.cpu.atmega2560.upload.speed=115200

firebird.menu.cpu.atmega2560.bootloader.high_fuses=0xD8
firebird.menu.cpu.atmega2560.bootloader.extended_fuses=0xFD
firebird.menu.cpu.atmega2560.bootloader.file=stk500v2/stk500boot_v2_mega2560.hex

firebird.menu.cpu.atmega2560.build.mcu=atmega2560
firebird.menu.cpu.atmega2560.build.board=AVR_MEGA2560
```
4. That's it! Close the IDE and open it again. You will be able to select your new board with name as Firebird V Mega 2560 Robot. You will be able to see the same as shown below:
![sample_ide](https://github.com/tushar-semwal/Arduino-FirebirdV/blob/master/images/sample.png)

## 3. Custom Arduino Libraries for Firebird V
1. Put the folder FirebirdV/* [found here](https://github.com/tushar-semwal/Arduino-FirebirdV/tree/master/Library) into your `C:\Users\<UNAME>\Documents\Arduino\libraries\` folder. Close the IDE and open it again to see the examples under FirebirdV. 
![example](https://github.com/tushar-semwal/Arduino-FirebirdV/blob/master/images/examples_arduino_FB.png)

## 4. Using the Arduino IDE Serial terminal. 
* Connect the USB cable to Firebird V robot and PC.
* Check the Tools->Port and check when the appropriate port occurs. 
* Since the USB port of Firebird is connected to the UART2 of AtMega chip, use Serial2.begin and other functions for communication. For better understanding, see the examples.
