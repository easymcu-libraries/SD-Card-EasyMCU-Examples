SD-Card-EasyMCU-Examples
EasyMCU examples for SD card

These examples are ported from Arduino for EasyMCU

Some examples use Serial (UART unit) and some ones use cdc (USB CDC). Copy content of .cpp example files and paste to your new main.cpp project. also Enable USB CDC or UART Unit corresponding to the examples requirement, compile -> progrom and have fun ...

you need USB to Serial convertor when UART unit is in use. if you don't have one or you want to use USB CDC ... Replace Serial by cdc and remove Serial.begin() at very beginning of main function. So simple ...!

Check EasyMCU for our tutorial and wiring.
