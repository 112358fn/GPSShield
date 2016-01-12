/*
 * Arduino GPS shield v1.1
 * Shield: http://imall.iteadstudio.com/im120417017.html
 * Arduino: UNO
 * 
 * Receives GPS data from SoftSerial
 * Sends data throw USB from Serial 
 * 
 * The circuit:
 * RX is digital pin 2 (connect to TX of other device)
 * TX is digital pin 3 (connect to RX of other device)
 * On the shield:
 * Select pins 2 and 3 as Tx and Rx over the UART multiplexer
 * 
 * modified 11 Dec 2015
 * by Alvaro Alonso
 * 
 */
#include <SPI.h>
#include <SD.h>
#include <SoftwareSerial.h>

/*
 * Constants
 */
const byte RX_PIN = 2;
const byte TX_PIN = 3;
const byte CHIP_SELECT = 10;
const char LOG_FILE[] = "datalog.txt";

// Soft Serial Constructor
SoftwareSerial softSerial (RX_PIN, TX_PIN);

void setup()
{
  // Open Hardware Serial
  Serial.begin(9600);
  while (!Serial) {}
  Serial.println("Conected to Arduino UNO.\nStarting system ...");
  // Open Soft Serial
  softSerial.begin(38400);
  // Open SD 
  /*
  pinMode(CHIP_SELECT, OUTPUT);
  if (!SD.begin(CHIP_SELECT)) {
    return;
  }
 */
 return;
}

void loop()
{
  String data = readGPS( );
  //saveToSd(data);
  Serial.println();
  delay(2000);
} 

void saveToSd(String data) {
 File dataFile = SD.open(LOG_FILE, FILE_WRITE);
 if(dataFile)
 {
   dataFile.print(data);
   dataFile.close();
 }
}

String readGPS() {
  char index = 0;
  byte temp = 0;
  String dataString = "";
  while(softSerial.available())
  {
     temp = softSerial.read();
     Serial.write(temp);
     //dataString += String(temp);
  }
  return dataString;
}

