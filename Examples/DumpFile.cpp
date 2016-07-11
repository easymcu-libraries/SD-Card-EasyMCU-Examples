/*
  SD card file dump
 
 This example shows how to read a file from the SD card using the
 SD library and send it over the serial port.
 	
 The circuit:
 * SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4
 
 created  22 December 2010
 by Limor Fried
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
		
		// see if the card is present and can be initialized:
		if (!SD.begin(P22, 1)) {
			Serial.println("Card failed, or not present");
		}
		else
			Serial.println("card initialized.");
		
		// open the file. note that only one file can be open at a time,
		// so you have to close this one before opening another.
		File dataFile = SD.open("datalog.txt");

		// if the file is available, write to it:
		if (dataFile) {
			while (dataFile.available()) {
				Serial.write(dataFile.read());
			}
			dataFile.close();
		}  
		// if the file isn't open, pop up an error:
		else {
			Serial.println("error opening datalog.txt");
		} 
		
		
		while (1) 
		{/* Loop forever */
			io.toggle(LED1);
			delay(200);
		} /* while */
	} /* main */

