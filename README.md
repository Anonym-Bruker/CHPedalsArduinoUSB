# CHPedalsArduinoUSB
Code for converting CH Pedals from using a Gameport to using USB as output

What you might need to change in the code:
-----------------------------------------
You should review, and probably change these values, to match up to what you get.
Check the values printed out in the Serial.print, and adjust the following values accordingly
- int X_AXIS_MIN = 20;
- int Y_AXIS_MIN = 20;
- int X_AXIS_CUTOFF = 250;
- int Y_AXIS_CUTOFF = 250;
- int X_AXIS_MAX = 900;
- int Y_AXIS_MAX = 900;

You might consider comment out the Serial.print lines when done debugging.

Hardware:
---------
I used an Arduino clone from Aliexpress:
https://vi.aliexpress.com/item/32840365436.html
("New" 3-5V USB-C type version ATMEGA32U4 - Emulates Arduino Leonardo)

I also ordered some female game ports:
https://vi.aliexpress.com/item/1005004701460364.html

Also used some resistors and wires I had from other projects and soldered it all together (I am terrible at soldering)

How I connected it all together:
--------------------------------
And I connected the wires to the game port according to this drawing:
https://i.iinfo.cz/urs/pc_48_03-123437180089569.jpg

- Axis 1 (Game port pin 3) and axis 2 (Game port pin 6) to A0 and A1 on my Arduino
- Game port pin 4 to ground and game port pin 1 to VCC on my Arduino
- Added approx 200kOhm resistance from each of the gameport pins 3 and 6 to ground. (Not sure of the exact resistance. I connected two types I had lying around in a series as per picture.) 

For pinout on the Arduino I used: 
https://gadgetau.com.au/storage/2023/06/Arduino-Pro-Micro-Pinout-Diagram-Gadget-AU.webp

This site is also a good guide:
https://littlebigtech.net/posts/diy-gameport-to-usb-adapter/
(I did it almost the same way, just without the dip-switch and with less axis and no buttons)

Pictures:
---------
Added some pictures showing the finished product inside a small plastic box.
(And yes, I know I suck at soldering... :) )
