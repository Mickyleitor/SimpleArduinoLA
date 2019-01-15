# Simple Arduino Logic Analyzer
A simple Arduino LA as a workaround of missing a real powerful one.

This is a simple Logic Analyzer, a tool which help me debugging an electronic circuit logic functions.
Luckily we don't need to run our circuit at high frecuencies. So a custom clock signal can be generated though a pin switching the edges once we get the last sample.

## Requirements
* An Arduino Mega 2560
* The electronic circuit you want debug.

## Set Up
* Plug all your Pins you want analyze to the Analogical Pins (Mega has 16, A0-A15)
* Use the PIN_CLK as a CLK signal for your circuit, we want see the logic function of our circuit rather than pushing our circuit to the time-limits!!
* Switch ON/OFF (GND/VCC) the PIN_READ to print your recorded data to your fiendly arduino IDE (or whatever you have).

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
* My poor dog as he is still watching at me eating pizza while i'm programming this even if i said that i won't give him a piece of pizza.

Michele La Malva Moreno - [LinkedIn](https://www.linkedin.com/in/michele-la-malva-moreno/) | [Blogspot](https://mickysim.blogspot.com/) | [Github](https://github.com/Mickyleitor)
