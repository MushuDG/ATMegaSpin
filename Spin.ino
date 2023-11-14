////////////////////////////////////////////////////////////////////////////////
// General informations
////////////////////////////////////////////////////////////////////////////////
// Author:             Mushu
// Project:            ATMegaSpin
// File:               Spin.ino
// Creation date:      14 novembre 2023
// Description:        Script managing the game
////////////////////////////////////////////////////////////////////////////////

const int LED_PIN_0             =       2;
const int LED_PIN_1             =       3;
const int LED_PIN_2             =       4;
const int LED_PIN_3             =       5;
const int LED_PIN_4             =       6;
const int LED_PIN_5             =       7;
const int LED_PIN_6             =       8;
const int LED_PIN_7             =       9;
const int LED_PIN_8             =       10;
const int LED_PIN_9             =       11;
const int buttonPinPlay         =       13;
const int buttonPinReset        =       12;
const int LED_NUMBER            =       10;

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

// variables will change:
int buttonPlayState     =   0;  // variable for reading the pushbutton status
int buttonResetState    =   0;
int ledState            =   0;
int exitFlag            =   0;
int score               =   10;

void setup()
{
  for (int i = 0; i < LED_NUMBER; i++) {
    pinMode(LEDPinArray[i], OUTPUT);
  }
  Serial.begin(9600);
  pinMode(buttonPinPlay, INPUT);
}

void loop()
{
    do {
        if (buttonPlayState == LOW){
            for (int i = 0; i < LED_NUMBER; i++){
                ledState = digitalRead(LEDPinArray[i]);
                if (ledState == LOW){
                    digitalWrite(LEDPinArray[i], HIGH);
                    buttonPlayState = digitalRead(buttonPinPlay);
                    if (buttonPlayState==HIGH){
                        Serial.write("break \n");
                        break;
                    }
                    delay(100);
                }
                else{
                    digitalWrite(LEDPinArray[i], LOW);
                    buttonPlayState = digitalRead(buttonPinPlay);
                    if (buttonPlayState==HIGH){
                        Serial.write("break \n");
                        break;                    
                    }
                    delay(100);
                }
            }
        }
     } while(buttonPlayState == LOW);




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