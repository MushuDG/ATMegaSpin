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
#define buttonPinPlay                   3                                       // BUTTON PLAY
#define buttonPinReset                  5                                       // BUTTON RESET

////////////////////////////////////////////////////////////////////////////////
// CONST
////////////////////////////////////////////////////////////////////////////////
const int LED_NUMBER            =       10;                                     // TOTAL LED
const int maxSpeed              =       1500;                                   // Define max speed game
const int minSpeed              =       500;                                    // Define min speed game

// Create an array of the LED
const byte LEDPinArray[LED_NUMBER]    = {   LED_PIN_0,
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
int buttonPlayState             =       0;                                      // Var for reading the pushbutton play status
int buttonResetState            =       0;                                      // Var for reading the pushbutton reset status
int ledState                    =       0;                                      // Var for reading the led status
int exitFlag                    =       0;                                      // Exit loop flag
int score                       =       0;                                      // Score
int goal                        =       10;                                     // Goal to reached
float delaySpeed                =       0;                                      // Define the speed game
float soustractValue            =       0;                                      // Define the soustract speed value

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
    Serial.begin(9600);

    // Set buttons as input
    pinMode(buttonPinPlay, INPUT);
    pinMode(buttonPinReset, INPUT);

    // Create and attach interrupt function (Interrupt_Stop_Button) to buttonPinPlay when pin Rising
    attachInterrupt(digitalPinToInterrupt(buttonPinPlay), Interrupt_Stop_Button, RISING);
}

////////////////////////////////////////////////////////////////////////////////
// Loop
////////////////////////////////////////////////////////////////////////////////
void loop()
{
    goal = 10;
    delaySpeed = Get_Speed_Game(minSpeed, maxSpeed);
    soustractValue = delaySpeed * 0.1;
    Start_Waiting();
    Starting_Blink();
    Game();
    Game_Over();    
} // End loop

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

////////////////////////////////////////////////////////////////////////////////
// Starting_Blink
////////////////////////////////////////////////////////////////////////////////
void Starting_Blink(){

    // Reset all LED statement
    for (int i = 0; i < LED_NUMBER; i++){
        digitalWrite(LEDPinArray[i], LOW);
    } // End For loop

    // Pause
    delay(500);

    // Blink all LED 3 times
    for (int i = 0; i < 3; i++){

        // Turn on LEDs
        for (int i = 0; i < LED_NUMBER; i++){
            digitalWrite(LEDPinArray[i], HIGH);
        } // End For loop

        // Pause
        delay(500);

        // Turn off LEDs
        for (int i = 0; i < LED_NUMBER; i++){
            digitalWrite(LEDPinArray[i], LOW);
        } // End For loop

        // Pause
        delay(500);
     } // End For loop
} // End Starting_Blink

////////////////////////////////////////////////////////////////////////////////
// Game
////////////////////////////////////////////////////////////////////////////////
void Game(){
    
    // Set exitFlag to 0
    exitFlag = 0;

    // Set score to 0
    score = 0;

    // Turn on last LED
    digitalWrite(LEDPinArray[9], HIGH);

    // Start game
    do{

        // Foreach led under the goal
        for (int i = 0; i < goal; i++){

            // if the stop button was pressed at good time:
            // - Highlight the goal -1 led.
            // - Then, set the flag to 0
            // - Then, decrease the goal
            // - Then increase the score
            // - Then break the for loop
            if( i==goal-1 && exitFlag==1){
                digitalWrite(LEDPinArray[i-1],HIGH);
                exitFlag=0;
                goal--;
                score++;
                break;
            } // End if

            // Else if the button was pressed but the goal is not reached, 
            // or if the button wasn't pressed but the goal is reached,
            // break the for loop and go to the Gameover "screen"
            else if( (i != goal-1 && exitFlag==1) || (i == goal-1)){
                exitFlag = 1;
                break;
            } // End Else if

            // Blink the current LED
            digitalWrite(LEDPinArray[i],HIGH);
            delay(delaySpeed);            
            digitalWrite(LEDPinArray[i],LOW);
        } // End For loop

        delaySpeed=delaySpeed-soustractValue;
     } while (exitFlag==0); // End do while loop
} // End Game


////////////////////////////////////////////////////////////////////////////////
// Game_Over
////////////////////////////////////////////////////////////////////////////////
void Game_Over(){
    exitFlag = 0;

    // Reset all LED statement
    for (int i = 0; i < LED_NUMBER; i++){
        digitalWrite(LEDPinArray[i], LOW);
    } // End For loop

    // Pause
    delay(500);

    do{
        // Turn on LEDs
        for (int i = (LED_NUMBER-score-1); i < LED_NUMBER; i++){
            digitalWrite(LEDPinArray[i], HIGH);
        } // End For loop

        // Pause
        delay(500);

        // Turn off LEDs
        for (int i = (LED_NUMBER-score-1); i < LED_NUMBER; i++){
            digitalWrite(LEDPinArray[i], LOW);
        } // End For loop

        // Pause
        delay(500);
    } while (exitFlag==0);
} // End Game_Over

////////////////////////////////////////////////////////////////////////////////
// Get_Speed_Game
// Param:   int minSpeed    :   Minimal speed delay for the game
//          int maxSpeed    :   Maximal speed delay for the game
// Return:  random          :   Random value between minSpeed and maxSpeed
////////////////////////////////////////////////////////////////////////////////
float Get_Speed_Game(int minSpeed, int maxSpeed){
    return random(minSpeed, maxSpeed); 
} // End Get_Speed_Game

////////////////////////////////////////////////////////////////////////////////
// Interrupt_Stop_Button
////////////////////////////////////////////////////////////////////////////////
void Interrupt_Stop_Button(){
    exitFlag = 1;
} // End Interrupt_Stop_Button
