
/*            Throttle script with filtering
 *  This script takes three axis, and filters the signal for an output 
 *  at 50 Hz. The clock is used to exactly time the polling, 
 *  to avoid sampling bias. A crude bandpass filter throws 
 *  away spikes that are impossible(!) to result from user 
 *  input. This will convert spikes on the control axis into 
 *  a mere stutter. Then a Kalman filter is applied to the 
 *  20 Hz signal to remove remaining gaussian noise. 
 *  All axes each get their own one dimensional Kalman 
 *  because there is no correlation that is relevant for the 
 *  filter. The constants in this script are configured for 
 *  the Saitek Pro throttle quadrant.
 *  
 *  BN: Arduino Leonardo VID: 2341 PID: 8036
*/

#include "Joystick.h"

int X_AXIS_MIN = 20;
int Y_AXIS_MIN = 20;
int X_AXIS_CUTOFF = 250;
int Y_AXIS_CUTOFF = 250;
int X_AXIS_MAX = 900;
int Y_AXIS_MAX = 900;

int XAxisPosition = 0;
int YAxisPosition = 0;


// output configuration
Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, 
  JOYSTICK_TYPE_JOYSTICK, 0, 0,
  true, true, false, false, false, false,
  false, false, false, false, false);


//Eksempel for å teste joystick
// Støtter tre akser og fire knapper
// NB! Kjøres på en nano med old bootloader: VID: 1A86 PID: 7523

void setup() {
  // Initialize Joystick Library

  // Initialize Button Pins
  //pinMode(9, INPUT_PULLUP);
  //pinMode(10, INPUT_PULLUP);
  //pinMode(11, INPUT_PULLUP);
  //pinMode(12, INPUT_PULLUP);

  pinMode(A0, INPUT); //configure inputs for potentiometers
  pinMode(A1, INPUT); //configure inputs for potentiometers
  pinMode(A2, INPUT); //configure inputs for potentiometers
  pinMode(A3, INPUT); //configure inputs for potentiometers

  Joystick.begin();
  Joystick.setXAxisRange(X_AXIS_MIN, X_AXIS_CUTOFF);
  Joystick.setYAxisRange(Y_AXIS_MIN, Y_AXIS_CUTOFF);

  Serial.begin( 9600 ); //remove comment for debugging on the serial monitor/plotter
}

// Constant that maps the phyical pin to the joystick button.
const int pinToButtonMap = 9;

// Last state of the button
int lastButtonState[4] = {0,0,0,0};

void loop() {
  int potX = analogRead(A0); //X axis
  Serial.print("potX: ");
  Serial.print(potX);
  int potY = analogRead(A1); //Y axis
  Serial.print("potY: ");
  Serial.print(potY);
  int potZ = analogRead(A2); //Z axis
  Serial.print("potZ: ");
  Serial.print(potZ);
  int potX1 = analogRead(A3); //X1 axis
  Serial.print("potX1: ");
  Serial.print(potX1);
  Serial.println("");

  if(potX > X_AXIS_CUTOFF){
    XAxisPosition= X_AXIS_CUTOFF;
  } else {
    XAxisPosition = potX; 
  }

  if(potY > Y_AXIS_CUTOFF){
    YAxisPosition= Y_AXIS_CUTOFF;
  } else {
    YAxisPosition = potY; 
  }

  Joystick.setXAxis(XAxisPosition);
  Joystick.setYAxis(YAxisPosition); 

  if(potX > X_AXIS_MAX && potY > Y_AXIS_MAX){
    Serial.println("BRAKING!!!");
    Joystick.setButton(4, HIGH);
    //Joystick.setXAxis(X_AXIS_MIN);
    //Joystick.setYAxis(Y_AXIS_MIN);
  } else {
    Joystick.setButton(4, LOW);    
  }
    

  // Read pin values
  for (int index = 0; index < 4; index++)
  {
    int currentButtonState = !digitalRead(index + pinToButtonMap);
    if (currentButtonState != lastButtonState[index])
    {
      Serial.print("Button: ");
      Serial.print(index);
      Serial.print("State: ");
      Serial.print(currentButtonState);
      lastButtonState[index] = currentButtonState;
      Joystick.setButton(index, lastButtonState[index]);
    }
  }


  delay(50);
}
