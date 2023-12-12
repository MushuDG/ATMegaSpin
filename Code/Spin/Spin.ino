////////////////////////////////////////////////////////////////////////////////
// General informations
////////////////////////////////////////////////////////////////////////////////
// Author:             Mushu
// Project:            ATMegaSpin
// File:               Spin.ino
// Creation date:      14 novembre 2023
// Description:        Program managing the game
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
// Pin Declaration
////////////////////////////////////////////////////////////////////////////////
// Declaration of pin numbers
#define LED_PIN_0                       2                                       // LED 0
#define LED_PIN_1                       4                                       // LED 1
#define LED_PIN_2                       6                                       // LED 2
#define LED_PIN_3                       7                                       // LED 3
#define LED_PIN_4                       8                                       // LED 4
#define LED_PIN_5                       9                                       // LED 5
#define LED_PIN_6                       10                                      // LED 6
#define LED_PIN_7                       11                                      // LED 7
#define LED_PIN_8                       12                                      // LED 8
#define LED_PIN_9                       13                                      // LED 9
#define BUTTON_PIN_PLAY                   3                                       // BUTTON PLAY
//#define buttonPinReset                5                                       // BUTTON RESET

////////////////////////////////////////////////////////////////////////////////
// Constants
////////////////////////////////////////////////////////////////////////////////
const int LED_NUMBER PROGMEM    =       10;                                     // TOTAL LED count
const int MAX_SPEED PROGMEM     =       1500;                                   // Define max speed game
const int MIN_SPEED PROGMEM     =       500;                                    // Define min speed game

////////////////////////////////////////////////////////////////////////////////
// Array of LED Pins
////////////////////////////////////////////////////////////////////////////////
const byte LEDPinArray[LED_NUMBER]  =   {   LED_PIN_0,
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
// Variables
////////////////////////////////////////////////////////////////////////////////
int buttonPlayState             =       0;                                      // Var for reading the pushbutton play status
//int buttonResetState          =       0;                                      // Var for reading the pushbutton reset status
int ledState                    =       0;                                      // Var for reading the led status
int score                       =       0;                                      // Score
int goal                        =       10;                                     // Goal to reached
float delaySpeed                =       0;                                      // Define the speed game
float subtractValue             =       0;                                      // Define the subtract speed value
bool exitFlag                   =       false;                                  // Exit loop flag

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes
////////////////////////////////////////////////////////////////////////////////
void setup();
void loop();
void Start_Waiting();
void Starting_Blink();
void Game();
void Game_Over();
float Get_Speed_Game(int minSpeed, int maxSpeed);
void Interrupt_Stop_Button();

////////////////////////////////////////////////////////////////////////////////
// Setup
////////////////////////////////////////////////////////////////////////////////
void setup()
 {
    // Set pinMode Output for all LED
    for (int i = 0; i < LED_NUMBER; i++) {
        pinMode(LEDPinArray[i], OUTPUT);
    } // End For loop

    // Start Serial monitor
    //Serial.begin(9600);

    // Set buttons as input
    pinMode(BUTTON_PIN_PLAY, INPUT);
    //pinMode(buttonPinReset, INPUT);

    // Create and attach interrupt function (Interrupt_Stop_Button) to BUTTON_PIN_PLAY when pin Rising
    attachInterrupt(digitalPinToInterrupt(BUTTON_PIN_PLAY), Interrupt_Stop_Button, RISING);
}

////////////////////////////////////////////////////////////////////////////////
// Loop
////////////////////////////////////////////////////////////////////////////////
void loop()
 {
    // Total on board LED
    goal = 10;

    // Setup random speed game
    delaySpeed = Get_Speed_Game(MIN_SPEED, MAX_SPEED);

    // Get the 10% initial speed to subtract each goal reached\ {
    subtractValue = delaySpeed * 0.1;

    // Start waiting display
    Start_Waiting();

    // Display starting light
    Starting_Blink();

    // Start the game
    Game();

    // Display Game Over
    Game_Over();    
} // End loop

////////////////////////////////////////////////////////////////////////////////
// Start_Waiting
////////////////////////////////////////////////////////////////////////////////
void Start_Waiting() {

    // Set exitFlag to 0
    exitFlag                    =   false;
    unsigned long currentMillis =   0;
    unsigned long ledMillis     =   0;

    // Do while the start button isn't pressed
    do {
        currentMillis = millis();

        // Foreach LED: Check status. If status is low then turn it on. Else, turn it off
        for (int i = 0; i < LED_NUMBER; i++) {
            ledState = digitalRead(LEDPinArray[i]);
            if (ledState == LOW) {
                digitalWrite(LEDPinArray[i], HIGH);
            } else {
                digitalWrite(LEDPinArray[i], LOW);
            }
            // Delay after each LED (keep if necessary)
            while (millis() - ledMillis < 100) {
                // Wait
            }
            ledMillis = millis();
        } // end for loop
    } while(exitFlag == false); // end while loop
} // End Start_Waiting

////////////////////////////////////////////////////////////////////////////////
// Starting_Blink
////////////////////////////////////////////////////////////////////////////////
void Starting_Blink() {

    // Reset all LED statement
    for (int i = 0; i < LED_NUMBER; i++) {
        digitalWrite(LEDPinArray[i], LOW);
    } // End For loop

    // Pause
    delay(500);

    // Blink all LED 3 times
    for (int i = 0; i < 3; i++) {

        // Turn on LEDs
        for (int i = 0; i < LED_NUMBER; i++) {
            digitalWrite(LEDPinArray[i], HIGH);
        } // End For loop

        // Pause
        delay(500);

        // Turn off LEDs
        for (int i = 0; i < LED_NUMBER; i++) {
            digitalWrite(LEDPinArray[i], LOW);
        } // End For loop

        // Pause
        delay(500);
     } // End For loop
} // End Starting_Blink

////////////////////////////////////////////////////////////////////////////////
// Game
////////////////////////////////////////////////////////////////////////////////
void Game() {
    
    // Set exitFlag to 0
    exitFlag = false;

    // Set score to 0
    score = 0;

    // Turn on last LED
    digitalWrite(LEDPinArray[9], HIGH);

    // Start game
    do {

        // Foreach led under the goal
        for (int i = 0; i < goal; i++) {
            
            // If score is reached, exit for loop and do while loop
            if( score == LED_NUMBER - 1 ) {
                exitFlag = true;
                break;
            } // End if

            // if the stop button was pressed at good time:
            // - Highlight the goal -1 led.
            // - Then, set the flag to 0
            // - Then, decrease the goal
            // - Then increase the score
            // - Then break the for loop
            if( i == goal - 1 && exitFlag == true) {
                digitalWrite(LEDPinArray[i - 1], HIGH);
                exitFlag = false;
                goal--;
                score++;
                break;
            } // End if

            // Else if the button was pressed but the goal is not reached, 
            // or if the button wasn't pressed but the goal is reached,
            // break the for loop and go to the Gameover "screen"
            else if( (i != goal - 1 && exitFlag == true) || (i == goal - 1)) {
                exitFlag = true;
                break;
            } // End Else if

            // Blink the current LED
            digitalWrite(LEDPinArray[i], HIGH);

            // Delay using millis
            unsigned long currentMillis = millis();
            while (millis() - currentMillis < delaySpeed) {
                // Wait
            }    

            digitalWrite(LEDPinArray[i],LOW);
        } // End For loop

        delaySpeed= delaySpeed - subtractValue;
     } while (exitFlag == false); // End do while loop
} // End Game


////////////////////////////////////////////////////////////////////////////////
// Game_Over
////////////////////////////////////////////////////////////////////////////////
void Game_Over() {
    exitFlag = false;

    // Reset all LED statement
    for (int i = 0; i < LED_NUMBER; i++) {
        digitalWrite(LEDPinArray[i], LOW);
    } // End For loop

    // Delay
    unsigned long currentMillis = millis();
    while (millis() - currentMillis < 500) {
        // Wait
    }

    do {

        // Turn on LEDs
        for (int i = (LED_NUMBER - score - 1); i < LED_NUMBER; i++) {
            digitalWrite(LEDPinArray[i], HIGH);
        } // End For loop

        // Delay
        while (millis() - currentMillis < 500) {
            // Wait
        }
        currentMillis = millis();

        // Turn off LEDs
        for (int i = (LED_NUMBER - score - 1); i < LED_NUMBER; i++) {
            digitalWrite(LEDPinArray[i], LOW);
        } // End For loop

        // Delay
        while (millis() - currentMillis < 500) {
            // Wait
        }
        currentMillis = millis();
    } while (exitFlag == false);
} // End Game_Over

////////////////////////////////////////////////////////////////////////////////
// Get_Speed_Game
// Param:   int minSpeed    :   Minimal speed delay for the game
//          int maxSpeed    :   Maximal speed delay for the game
// Return:  random          :   Random value between minSpeed and maxSpeed
////////////////////////////////////////////////////////////////////////////////
float Get_Speed_Game(int minSpeed, int maxSpeed) {
    return random(minSpeed, maxSpeed); 
} // End Get_Speed_Game

////////////////////////////////////////////////////////////////////////////////
// Interrupt_Stop_Button
////////////////////////////////////////////////////////////////////////////////
void Interrupt_Stop_Button() {

    //Disable temporary interruption
    detachInterrupt(digitalPinToInterrupt(BUTTON_PIN_PLAY)); 
    exitFlag = true;
    unsigned long buttonReleaseTime = millis();
    
    // Wait until the button is released to avoid repeated triggers
    while(digitalRead(BUTTON_PIN_PLAY) == HIGH && millis() - buttonReleaseTime < 1000) {
        // Wait until the button is released or one second has passed
    }

    // Reactivate the interrupt
    attachInterrupt(digitalPinToInterrupt(BUTTON_PIN_PLAY), Interrupt_Stop_Button, RISING); 
} // End Interrupt_Stop_Button