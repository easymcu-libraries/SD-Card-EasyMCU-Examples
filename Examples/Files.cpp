/*
  SD card basic file example
 
 This example shows how to create and destroy an SD card file 	
 The circuit:
 * SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4
 
 created   Nov 2010
 by David A. Mellis
 modified 9 Apr 2012
 by Tom Igoe
 
 Ported for EasyMCU 9 July 2016
 by Morteza Zandi
 
 This example code is in the public domain.
 	 
 */

#include "headers.h"


	File myFile;

  int main()
	{
	 // Open serial communications and wait for port to open:
		Serial.init(9600);

		Serial.print("Initializing SD card...");

		if (!SD.begin(P22, 1)) {
			Serial.println("initialization failed!");
		}
		else
			Serial.println("initialization done.");

		if (SD.exists("example.txt")) {
			Serial.println("example.txt exists.");
		}
		else {
			Serial.println("example.txt doesn't exist.");
		}

		// open a new file and immediately close it:
		Serial.println("Creating example.txt...");
		myFile = SD.open("example.txt", FILE_WRITE);
		myFile.close();

		// Check to see if the file exists: 
		if (SD.exists("example.txt")) {
			Serial.println("example.txt exists.");
		}
		else {
			Serial.println("example.txt doesn't exist.");  
		}

		// delete the file:
		Serial.println("Removing example.txt...");
		SD.remove("example.txt");

		if (SD.exists("example.txt")){ 
			Serial.println("example.txt exists.");
		}
		else {
			Serial.println("example.txt doesn't exist.");  
		}

		while (1) 
		{/* Loop forever */

		} /* while */
	} /* main */



