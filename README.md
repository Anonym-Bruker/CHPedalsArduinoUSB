# CHPedalsArduinoUSB
Code for converting CH Pedals from using a Gameport to using USB as output

You should review, and probably change these values, to match up to what you get.
(Check the values printed out in the Serial.print, and adjust accordingly)
int X_AXIS_MIN = 20;
int Y_AXIS_MIN = 20;
int X_AXIS_CUTOFF = 250;
int Y_AXIS_CUTOFF = 250;
int X_AXIS_MAX = 900;
int Y_AXIS_MAX = 900;

You might consider comment out the Serial.print lines when done debugging.
