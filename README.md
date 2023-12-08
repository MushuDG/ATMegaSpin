> [!WARNING]  
> Hey! This project is still a Work in Progress. Files, instructions, and other stuff might change!

# Table of contents
1. [Goal of the game](#goal-of-the-game)
2. [PCB Pictures](#pcb-pictures)
    1. [Front](#front)
    2. [Back](#back)
3. [Schematics](#schematics)
    1. [Electrical schematic](#electrical-schematic)
    2. [PCB schematic](#pcb-schematic)
    3. [Mechanical schematic](#mechanical-schematic)
    4. [ATMega328P Pinout](#atmega328p-pinout)
4. [GERBER - 3D printed Files - Other Hardware stuff](#gerber---3d-printed-files---other-hardware-stuff)
    1. [3D Printed parts](#3d-printed-parts)
    2. [PCB GERBER File](#pcb-gerber-file)
    3. [Electrical parts](#electrical-parts)
5. [Installation](#installation)
    1. [Burn bootloader](#burn-bootloader)
        1. [Needed tools](#needed-tools)
        2. [Circuit](#circuit)
        3. [Pinout](#pinout)
        4. [Upload ISP sketch](#upload-isp-sketch)
        5. [Burn bootloader](#burn-bootloader-1)
            1. [Installing Mini-core](#installing-mini-core)
            2. [Select your device, crystal and programmer and burn bootloader](#select-your-device-crystal-and-programmer-and-burn-bootloader)
    2. [Upload sketch from programmer](#upload-sketch-from-programmer)
6. [Contributions](#contributions)
7. [License](#license)



# ATMegaSpin
## Goal of the game:
A LED game where the player has to press a button at the right moment to reach a specific goal. The challenge of the game lies in the speed at which the LEDs blink, the reduction of this speed with each achieved goal, and the necessity to press the button at the right moment to advance in the game.

## PCB Pictures:
### Front
![Front PCB view](https://github.com/MushuDG/ATMegaSpin/blob/main/Pictures/ATMegaSpin_Front.png)
### Back
![Back PCB view](https://github.com/MushuDG/ATMegaSpin/blob/main/Pictures/ATMegaSpin_Back.png)

# Schematics
## Electrical schematic:
[Electrical schematic](https://github.com/MushuDG/ATMegaSpin/blob/main/PDF/ATMegaSpin_Schematic.pdf)

## PCB schematic:
[PCB schematic](https://github.com/MushuDG/ATMegaSpin/blob/main/PDF/ATMegaSpin_PCB.pdf)

## Mechanical schematic:
[Mechanical schematic](https://github.com/MushuDG/ATMegaSpin/blob/main/PDF/EnsemblePCB.pdf)

## ATMega328P Pinout:
| Arduino Pinout | Electrical Part | ATMega328 Pinout | ATMega328 Pinout | Electrical Part | Arduino Pinout |
| -------------- | --------------- | ---------------- | ---------------- | --------------- | -------------- |
| Reset          | Not used        | 1                | 28               | Not used        | A5             |
| D0 RX          | Not used        | 2                | 27               | Not used        | A4             |
| D1 TX          | Not used        | 3                | 26               | Not used        | A3             |
| D2             | LED 1           | 4                | 25               | Not used        | A2             |
| D3             | Button Pin 4    | 5                | 24               | Not used        | A1             |
| D4             | LED 2           | 6                | 23               | Not used        | A0             |
| VCC            | +5V             | 7                | 22               | GND             | GND            |
| GND            | GND             | 8                | 21               | Not used        | Aref           |
| Crystal        | Crystal         | 9                | 20               | Not used        | Avcc           |
| Crystal        | Crystal         | 10               | 19               | LED 10          | D13            |
| D5             | Not used        | 11               | 18               | LED 9           | D12            |
| D6             | LED 3           | 12               | 17               | LED 8           | D11            |
| D7             | LED 4           | 13               | 16               | LED 7           | D10            |
| D8             | LED 5           | 14               | 15               | LED 6           | D9             |


# GERBER - 3D printed Files - Other Hardware stuff
## 3D Printed parts:
[3D Printed parts](https://www.printables.com/fr/model/649943-atmegaspin)

## PCB GERBER File:
[PCB GERBER File](https://github.com/MushuDG/ATMegaSpin/blob/main/KiCad/ATMegaSpin/ATMegaSpin-GERBER.zip)

## Electrical parts:
| N° | PRODUCTS DETAILS                                                                                | SUPPLIER | QUANTITY | PRICE       | TOTAL        |
| -- | ----------------------------------------------------------------------------------------------- | -------- | -------- | ----------- | ------------ |
| 1  | ED3050-5-ND‎<br>ED281DT‎<br>CONN IC DIP SOCKET 28POS TIN                                        | Digikey  | 5        | Fr. 0.40000 | Fr. 2.00000  |
| 2  | ATMEGA328P-PU-ND‎‎<br>ATMEGA328P-PU‎<br>IC MCU 8BIT 32KB FLASH 28DIP                            | Digikey  | 5        | Fr. 2.60000 | Fr. 13.00000 |
| 3  | 2223-TS02-66-60-BK-160-SCR-D-ND‎<br>TS02-66-60-BK-160-SCR-D‎<br>6 X 6 MM, 6 MM ACTUATOR HEIGHT, | Digikey  | 5        | Fr. 0.09000 | Fr. 0.45000  |
| 4  | 50-ECS-160-18-4X-CKM-ND‎<br>ECS-160-18-4X-CKM‎<br>CRYSTAL 16.0000MHZ 18PF TH                    | Digikey  | 5        | Fr. 0.41000 | Fr. 2.05000  |
| 5  | BC1005CT-ND‎<br>‎K220J15C0GF5TL2‎<br>CAP CER 22PF 50V C0G/NP0 RADIAL                            | Digikey  | 10       | Fr. 0.15500 | Fr. 1.55000  |
| 6  | BS-7-ND‎<br>BS-7‎<br>BATT HLDR COIN 20MM 1 CEL PC PIN                                           | Digikey  | 10       | Fr. 0.84100 | Fr. 8.41000  |
| 7  | CF18JT200RCT-ND‎<br>‎CF18JT200R‎<br>RES 200 OHM 5% 1/8W AXIAL                                   | Digikey  | 50       | Fr. 0.02260 | Fr. 1.13000  |
| 8  | ‎516-1325-ND‎<br>‎HLMP-4700‎<br>LED RED DIFFUSED T-1 3/4 T/H                                    | Digikey  | 50       | Fr. 0.34600 | Fr. 17.30000 |
| 9  | MFS101D-6-Z                                                                                     | Digikey  | 5        | Fr. 1.52000 | Fr. 7.60000  |
| 10 | PCB JLCPCB                                                                                      | JLCPCB   | 5        | Fr. 1.84000 | Fr. 9.20000  |
|    |                                                                                                 |          |          |             |              |
|    | Aprox. Total                                                                                    |          |          |             | Fr. 62.69    |
|    | Aprox. Total/pcs                                                                                |          |          |             | Fr. 12.54    |

# Prototype
![Prototype](https://github.com/MushuDG/ATMegaSpin/blob/main/Pictures/README_Pictures/Prototype/prototype.png)

# Installation
Before you can connect the [ATMega328P](https://en.wikipedia.org/wiki/ATmega328) microcontroller to the circuit, it's necessary to burn the bootloader of the chip. Once the bootloader is burned, the program can be uploaded to it.

*"To program the bootloader and provide to the microcontroller the compatibility with the Arduino Software (IDE) you need to use an In-circuit Serial Programmer (ISP) that is the device that connects to a specific set of pins of the microcontroller to perform the programming of the whole flash memory of the microcontroller, bootloader included. The ISP programming procedure also includes the writing of fuses: a special set of bits that define how the microcontroller works under specific circumstances."*

![Memory Map](https://github.com/MushuDG/ATMegaSpin/blob/main/Pictures/README_Pictures/MemoryMap/MemoryMap.png)
The Memory Map of an ATmega328P

> [!IMPORTANT]  
> The preceding paragraph and illustration were taken from this documentation: [Arduino as ISP and Arduino Bootloaders](https://docs.arduino.cc/built-in-examples/arduino-isp/ArduinoISP) -  Accessed on 2023-11-22

## Burn bootloader
### Needed tools
To burn the bootloader on the microcontroller you need 2 arduino (In this case I use Arduino UNO) cards. The first will be used as an ISP programmer.

### Circuit
![Arduino ISP Programmer circuit](https://github.com/MushuDG/ATMegaSpin/blob/main/Pictures/README_Pictures/Arduin_ISP_Programmer/Arduino_ISP_Programmer.png)

### Pinout
| Arduino Programmer Pin | Arduino Target Pin |
| ---------------------- | ------------------ |
| +5 [V]                 | +5 [V]             |
| GND                    | GND                |
| D10                    | Reset              |
| 11                     | 11                 |
| 12                     | 12                 |
| 13                     | 13                 |

### Upload ISP sketch
Once the circuit is connected, follow the following instructions to apply the ISP programming sketch on the Arduino programmer:
1. Open the Arduino IDE and from the menu *File > Examples > 11.ArduinoISP > ArduinoISP*, load the sketch.
2. Select the proper board (I.E.: Arduino Uno) and upload the sketch

### Burn bootloader
#### Installing Mini-core
1. Open up the Arduino IDE and navigate to the preferences (or press ctrl+,). Copy the following URL into the empty field labelled *‘Additional Boards Manager URLs’*: [https://mcudude.github.io/MiniCore/package_MCUdude_MiniCore_index.json](https://mcudude.github.io/MiniCore/package_MCUdude_MiniCore_index.json)
2. Go to the boards manager, which can be found under *Tools > Board > Boards Manager*.
Type *‘minicore’* into the search bar and the relevant entry will appear. Select the latest version and click *‘install’*. Once the installation is complete, close the boards manager window.

#### Select your device, crystal and programmer and burn bootloader
1. Select the relevant device, crystal and programmer options under the *‘tools’* menu.
2. Under board, select *‘ATmega328’* (or whichever chip you’re using).
3. Under clock, select the frequency of your external clock. It should be written in block capitals on the top of the crystal’s casing.
4. Set your programmer as *‘Arduino as ISP’*
5. Burn the bootloader using the *‘Burn Bootloader’* option at the bottom of the Tools menu.

## Upload sketch from programmer
Once the bootloader is burned, open up the *[Spin.ino](https://github.com/MushuDG/ATMegaSpin/blob/main/Code/Spin/Spin.ino)* sketch. From the menu *Sketch* use the *Upload Using Programmer* tool to Upload the sketch to the ATMega328P Target.

Then, you can disconnect the MCU from the Arduino target and clip it to your circuit. 

## Contributions

Contributions to this project are welcome! If you have ideas for improvements or bug fixes, please follow the [contribution guidelines](CONTRIBUTING.md).

1. Fork the project.
2. Create your feature branch: `git checkout -b feature/AmazingFeature`.
3. Commit your changes: `git commit -m 'Add some amazing feature'`.
4. Push to the branch: `git push origin feature/AmazingFeature`.
5. Open a pull request.

## License

This project is licensed under the  AGPL-3.0 license - see the [LICENSE](LICENSE) file for details.
