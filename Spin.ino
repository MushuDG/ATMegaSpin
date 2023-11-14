////////////////////////////////////////////////////////////////////////////////
// General informations
////////////////////////////////////////////////////////////////////////////////
// Author:             Mushu
// Project:            ATMegaSpin
// File:               Spin.ino
// Creation date:      14 novembre 2023
// Description:        Script managing the game
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
// CONST
////////////////////////////////////////////////////////////////////////////////
// Declaration of pin numbers
const int LED_PIN_0             =       2;                                      // LED 0
const int LED_PIN_1             =       3;                                      // LED 1
const int LED_PIN_2             =       4;                                      // LED 2
const int LED_PIN_3             =       5;                                      // LED 3
const int LED_PIN_4             =       6;                                      // LED 4
const int LED_PIN_5             =       7;                                      // LED 5
const int LED_PIN_6             =       8;                                      // LED 6
const int LED_PIN_7             =       9;                                      // LED 7
const int LED_PIN_8             =       10;                                     // LED 8
const int LED_PIN_9             =       11;                                     // LED 9
const int buttonPinPlay         =       13;                                     // BUTTON PLAY
const int buttonPinReset        =       12;                                     // BUTTON RESET
const int LED_NUMBER            =       10;                                     // TOTAL LED

// Create an array of the LED
byte LEDPinArray[LED_NUMBER]    =   {   LED_PIN_0,
                                        LED_PIN_1,
                                        LED_PIN_2,
                                        LED_PIN_3,
                                        LED_PIN_4,
                                        LED_PIN_5,
                                        LED_PIN_6,
                                        LED_PIN_7,
                                        LED_PIN_8,
                                        LED_PIN_9
                                    };

////////////////////////////////////////////////////////////////////////////////
// Var
////////////////////////////////////////////////////////////////////////////////
int buttonPlayState     =   0;                                                  // Var for reading the pushbutton play status
int buttonResetState    =   0;                                                  // Var for reading the pushbutton reset status
int ledState            =   0;                                                  // Var for reading the led status
int exitFlag            =   0;                                                  // Exit loop flag
int score               =   10;                                                 // Score

////////////////////////////////////////////////////////////////////////////////
// Setup
////////////////////////////////////////////////////////////////////////////////
void setup()
{
    // Set pinMode Output for all LED
    for (int i = 0; i < LED_NUMBER; i++) {
        pinMode(LEDPinArray[i], OUTPUT);
    }

    // Start Serial monitor
    Serial.begin(9600);

    //Set buttons as input
    pinMode(buttonPinPlay, INPUT);
    pinMode(buttonPinReset, INPUT);

    attachInterrupt(digitalPinToInterrupt(buttonPinPlay), blink, HIGH);
}

////////////////////////////////////////////////////////////////////////////////
// Loop
////////////////////////////////////////////////////////////////////////////////
void loop()
{
    Start_Waiting();

     for (int i = 0; i < LED_NUMBER; i++){
        digitalWrite(LEDPinArray[i], LOW);
     }
     delay(500);

     for (int i = 0; i < 3; i++){
        for (int i = 0; i < LED_NUMBER; i++){
            digitalWrite(LEDPinArray[i], HIGH);
        }
        delay(500);
        for (int i = 0; i < LED_NUMBER; i++){
            digitalWrite(LEDPinArray[i], LOW);
        }
        delay(500);
     }




     digitalWrite(LEDPinArray[9], HIGH);

     do{
        for (int i = 0; i < score; i++){
            digitalWrite(LEDPinArray[i],HIGH);
            buttonPlayState = digitalRead(buttonPinPlay);
            if( i==score-1 && buttonPlayState==HIGH){
                score--;
                break;
            }
            else if( i != score-1 && buttonPlayState==HIGH){
                exitFlag = 1;
            }
            else if( i == score-1){
                exitFlag = 1;
            }
            delay(300);
            digitalWrite(LEDPinArray[i],LOW);
        }
     } while (exitFlag==0);
  
  	digitalWrite(LEDPinArray[9], HIGH);

     do{
        for (int i = 0; i < LED_NUMBER+1; i++){
            buttonResetState=digitalRead(buttonPinReset);
            if (buttonResetState==HIGH){
                exitFlag=0;
                buttonPlayState=LOW;
                break;
            }
            if (i>=score){
                digitalWrite(LEDPinArray[i],HIGH);
            }
        }
        delay(1500);
        for (int i = 0; i < LED_NUMBER+1; i++){
            if (buttonResetState==HIGH){
                exitFlag=0;
                buttonPlayState=LOW;
                break;
            }

            if (i>=score){
                digitalWrite(LEDPinArray[i],LOW);
            }            
        }
       delay(1500);
     } while (exitFlag==1);

}

////////////////////////////////////////////////////////////////////////////////
// Start_Waiting
////////////////////////////////////////////////////////////////////////////////
void Start_Waiting(){

    // Set exitFlag to 0
    exitFlag=0;

    // Do while the start button isn't pressed
    do {

        // Foreach LED: Check status. If status is low then turn it on. Else, turn it off
        for (int i = 0; i < LED_NUMBER; i++){
            ledState = digitalRead(LEDPinArray[i]);
            if (ledState == LOW){
                digitalWrite(LEDPinArray[i], HIGH);
                delay(100);
            }
            else{
                digitalWrite(LEDPinArray[i], LOW);
                delay(100);
            }
        } // end for loop
     } while(exitFlag == 0); // end while loop
} // End Start_Waiting

void blink(){
    exitFlag=1;
    do {
        digitalWrite(LEDPinArray[0],HIGH);
        delay(1000);
        digitalWrite(LEDPinArray[0],LOW);
    } while (true);
}