/*
 * Arduino GPS shield v1.1
 * Shield: http://imall.iteadstudio.com/im120417017.html
 * Arduino: UNO
 * 
 * Receives GPS data from SoftSerial
 * Sends data throw USB from Serial 
 */
#include <SD.h>
#include <SoftwareSerial.h>

const int CHIP_SELECT = 10;
void setup()
{
  Serial.begin(9600);
  
  pinMode(CHIP_SELECT, OUTPUT);
  if (!SD.begin(CHIP_SELECT)) {
   
    return;
  }
 
}

void loop()
{
  // make a string for assembling the data to log:
  char index = 0;
  char temp = 0;
  String dataString = "";
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  /*
    while(Serial.available())
    {
      File dataFile = SD.open("datalog.txt", FILE_WRITE);
      if(dataFile)
      {
        temp = Serial.read();
        dataString += String(temp);
        dataFile.print(dataString);
        dataString = "";
        dataFile.close();
      }
    }
  */  
File dataFile = SD.open("datalog.txt", FILE_WRITE);
 if(dataFile)
 {
   while(Serial.available())
   {
     temp = Serial.read();
     dataString += String(temp);
     index++;
     if(index>200)
       break;
   }
   dataFile.print(dataString);
   dataFile.close();
 }
} 

