# ATMegaSpin
## Goal of the game:
Stop the LED which precedes the last LED

## PCB Pictures:
### Front
![Front PCB view](https://github.com/MushuDG/ATMegaSpin/blob/main/Photo/ATMegaSpin_Front.png)
### Back
![Back PCB view](https://github.com/MushuDG/ATMegaSpin/blob/main/Photo/ATMegaSpin_Back.png)

## Electrical schematic:
![Electrical schematic](https://github.com/MushuDG/ATMegaSpin/blob/main/PDF/ATMegaSpin_Schematic.pdf)

## PCB schematic:
![PCB schematic](https://github.com/MushuDG/ATMegaSpin/blob/main/PDF/ATMegaSpin_PCB.pdf)

## Mechanical schematic:
![Mechanical schematic](https://github.com/MushuDG/ATMegaSpin/blob/main/PDF/EnsemblePCB.pdf)

## 3D Printed parts:
[3D Printed parts](https://www.printables.com/fr/model/649943-atmegaspin)

## PCB GERBER File:
![PCB GERBER File](https://github.com/MushuDG/ATMegaSpin/blob/main/KiCad/ATMegaSpin/ATMegaSpin-GERBER.zip)

## ATMega328P Pinout:
| Arduino Pinout | Electrical Part | ATMega328 Pinout | ATMega328 Pinout | Electrical Part | Arduino Pinout |
| -------------- | --------------- | ---------------- | ---------------- | --------------- | -------------- |
| Reset          | Not used        | 1                | 28               | Not used        | A5             |
| 0 RX           | Not used        | 2                | 27               | Not used        | A4             |
| 1 TX           | Not used        | 3                | 26               | Not used        | A3             |
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
