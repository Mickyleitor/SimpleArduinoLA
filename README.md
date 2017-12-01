# SimpleArduinoLA
A simple Arduino LA as a workaround of missing a real powerfull one.

This is a simple Logic Analyzer, a tool which will help me debugging an electronic circuit.
Luckily I don't need to run my circuit at high frecuencies and a custom Clock signal can be done <del>with the builtin arduino one which really surprised me (Timer running doing PWM via tone() function).</del> manually generating it via Digital Output.

## Requirements
* An Arduino Mega 2560
* The electronic circuit you want debug.

## SetUp
* Plug all your Pins you want analyze to all Analog Pins (Mega has 16, A0-A15)
* Use the PIN_CLK as a CLK signal for your circuit, we want see the logic function of our circuit rather than pushing our circuit to the time-limits!!
* Switch ON/OFF (GND/VCC) the PIN_READ to decide print your recorded data to your fiendly arduino IDE (or whatever you have).

## Examples
We will test the following circuit in order to see the results via Serial Plotter.
![](https://github.com/Mickyleitor/SimpleArduinoLA/blob/master/TestCircuit.JPG)
As you can see, there is 4 modes M(1:0).
* 0 - Parallel Loading
* 1 - Right shift loading (With SR signal used for the shift)
* 2 - Output data complement
* 3 - Incremental count of output data

Naming the signals from up to down as 
* CLK,M0,M1,SR - A(15:12)
* D(3:0) - A(11:8)
* S(3:0) - A(7:4)
* DX(3:0) - A(3:0)

The Serial plotter will visualize our circuit like this (this is a real test one):
![](https://github.com/Mickyleitor/SimpleArduinoLA/blob/master/LogicAnalyzer.JPG)

## Thanks to Copito
* My poor dog as he is still watching at me eating pizza while i'm programming this even if i said i won't give at him.
