/*
  SD card read/write
 
 This example shows how to read and write data to and from an SD card file 	
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
 
 ported for EasyMCU 9 July 2016
 by Morteza Zandi
 
 This example code is in the public domain.
 	 
 */


#include "headers.h"


File myFile;


int main()
{
    delay.s(8);
    cdc.print("Initializing SD card...");
    
    if (!SD.begin(P22, 1))
    {
        cdc.println("initialization failed!");
    }
    else
        cdc.println("initialization done.");
    
    // open the file. note that only one file can be open at a time,
    // so you have to close this one before opening another.
    myFile = SD.open("test.txt", FILE_WRITE);
    
    // if the file opened okay, write to it:
    if (myFile)
    {
        cdc.print("Writing to test.txt...");
        myFile.println("testing 1, 2, 3.");
        // close the file:
        myFile.close();
        cdc.println("done.");
    }
    else
    {
        // if the file didn't open, print an error:
        cdc.println("error opening test.txt");
    }
    
    // re-open the file for reading:
    myFile = SD.open("test.txt");
    if (myFile)
    {
        cdc.println("test.txt:");
        
        // read from the file until there's nothing else in it:
        while (myFile.available())
        {
            cdc.write(myFile.read());
        }
        // close the file:
        myFile.close();
    }
    else
    {
        // if the file didn't open, print an error:
        cdc.println("error opening test.txt");
    }

    while (1) 
    {/* Loop forever */
    
    } /* while */
} /* main */

