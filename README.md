# SimpleArduinoLA
A simple Arduino LA as a workaround of missing a real powerfull one.

This is a simple Logic Analyzer, a tool which will help me debugging an electronic circuit for a University project. 
Luckily I don't need to run my circuit at high frecuencies and a custom Clock signal can be done with the builtin arduino one which really surprised me (Timer running doing PWM via tone() function).

## Requirements
* An Arduino Mega 2560
* The electronic circuit you want debug.

## SetUp
* Plug all your Pins you want analyze to all Analog Pins (Mega as 16, A0-A15)
* Connect the pin you want use as a data sample rate (PIN_CLK_MUESTREO), in my case is 2 (It allows ISR)
* (Optinal) If you haven't a waveform generator you can use a Timer to do a PWM. In this case use PIN_CLK (3) and connect directly to PIN_CLK_MUESTREO and to where the circuit have its clock signal inputs.
* Switch ON/OFF (GND/VCC) to decide print your recorded data to your fiendly arduino IDE (or whatever you have).

## Thanks to Copito
* My poor dog as he is still watching at me eating pizza while i'm programming this even if i said i won't give at him.
