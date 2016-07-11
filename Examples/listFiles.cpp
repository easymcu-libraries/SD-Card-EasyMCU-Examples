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


	File root;
	

	void printDirectory(File dir, int numTabs)
	{
		 while(true)
		 {			 
			 File entry =  dir.openNextFile();
			 if (! entry) {
				 // no more files
				 //Serial.println("**nomorefiles**");
				 break;
			 }
			 for (uint8_t i=0; i<numTabs; i++) {
				 Serial.print('\t');
			 }
			 Serial.print(entry.name());
			 if (entry.isDirectory()) {
				 Serial.println("/");
				 printDirectory(entry, numTabs+1);
			 } else {
				 // files have sizes, directories do not
				 Serial.print("\t\t");
				 Serial.println(entry.size(), DEC);
			 }
			 entry.close();
		 }
	}

  int main()
	{
		// Open serial communications and wait for port to open:
		Serial.init(9600);

		Serial.print("Initializing SD card...");

		if (!SD.begin(P22, 1)) {
			Serial.println("initialization failed!");
		}
		else
		{
			Serial.println("initialization done.");

			root = SD.open("/");
			
			printDirectory(root, 0);
			
			Serial.println("done!");
		}
		
		while (1) 
		{/* Loop forever */

		} /* while */
	} /* main */

