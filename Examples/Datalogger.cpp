/*
  SD card datalogger
 
 This example shows how to log data from three analog sensors 
 to an SD card using the SD library.
 	
 The circuit:
 * analog sensors on analog ins 0, 1, and 2
 * SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4
 
 created  24 Nov 2010
 modified 9 Apr 2012
 by Tom Igoe
  
 Ported for EasyMCU 9 July 2016
 by Morteza Zandi
 
 This example code is in the public domain.
 	 
 */

#include "headers.h"



int main()
{
 // Open serial communications and wait for port to open:
  Serial.init(9600);


  Serial.print("Initializing SD card...");
  // make sure that the default chip select pin is set to
  // output, even if you don't use it:
  
  // see if the card is present and can be initialized:
  if (!SD.begin(P22)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
  }
  Serial.println("card initialized.");

	while(1)
	{
		// make a string for assembling the data to log:
		String dataString = "";

		// read three sensors and append to the string:
		for (int analogPin = 0; analogPin < 3; analogPin++) {
			int sensor = analogRead(analogPin);
			dataString += String(sensor);
			if (analogPin < 2) {
				dataString += ","; 
			}
		}

		// open the file. note that only one file can be open at a time,
		// so you have to close this one before opening another.
		File dataFile = SD.open("datalog.txt", FILE_WRITE);

		// if the file is available, write to it:
		if (dataFile) {
			dataFile.println(dataString);
			dataFile.close();
			// print to the serial port too:
			Serial.println(dataString);
		}  
		// if the file isn't open, pop up an error:
		else {
			Serial.println("error opening datalog.txt");
		} 
	}
}

