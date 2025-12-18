//Adding Libraries
#include <SPI.h>                  /* to handle the communication interface with the modem*/
#include <nRF24L01.h>             /* to handle this particular modem driver*/
#include <RF24.h>                 /* the library which helps us to control the radio modem*/
#include <QMC5883LCompass.h>      // QMC5883L Compass Library
#include <Adafruit_GPS.h>
#include <SoftwareSerial.h>

QMC5883LCompass compass;

// Connect the GPS Power pin to 5V
// Connect the GPS Ground pin to ground
// Connect the GPS TX (transmit) pin to Digital 2
// Connect the GPS RX (receive) pin to Digital 3
SoftwareSerial mySerial(3, 2);
Adafruit_GPS GPS(&mySerial);

char c;

RF24 radio(8, 7);                   /* Creating instance 'radio'  ( CE , CSN )   CE -> D7 | CSN -> D8 */
const byte Address[6] = "00009" ;     /* Address to which data to be transmitted*/

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(5000);

  GPS.begin(9600);
  GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA);
  GPS.sendCommand(PMTK_SET_NMEA_UPDATE_5HZ);
  delay(1000);

  radio.begin ();                 /* Activate the modem*/
  radio.openWritingPipe (Address); /* Sets the address oftransmitter to which program will send the data */

  compass.init(); // Initialize the Compass.
  compass.setSmoothing(5,true);
}

void loop() {

  clearGPS();

  while (!GPS.newNMEAreceived()) {
    c = GPS.read();
  }

  GPS.parse(GPS.lastNMEA());

  if (GPS.fix) {
    //Serial.print("Google Maps location: ");
    //Serial.print(GPS.latitudeDegrees, 6);
    //Serial.print(", ");
    //Serial.println(GPS.longitudeDegrees, 6);
  }
  Serial.println("-------------------------------------");

// -------------------------------------GPS-------------------------------------
  String gpsLatitude = String(GPS.latitudeDegrees, 6);
  gpsLatitude = gpsLatitude.substring(6);
  char gpsLa[gpsLatitude.length() + 1]; //determine size of the array
  gpsLatitude.toCharArray(gpsLa, sizeof(gpsLa)); //put readStringinto an array
  float gpsLatdata = atof(gpsLa); //convert the array into a float
//  Serial.println(gpsLatdata);
  
  String gpsLongitude = String(GPS.longitudeDegrees, 6);
  gpsLongitude = gpsLongitude.substring(6);
  char gpsLo[gpsLongitude.length() + 1]; //determine size of the array
  gpsLongitude.toCharArray(gpsLo, sizeof(gpsLo)); //put readStringinto an array
  float gpsLondata = atof(gpsLo); //convert the array into a float

// -------------------------------------KOMPASS-------------------------------------
  int x, y;
  float rotacija; // rotacija
  compass.read(); // nolasa komposu
  x = compass.getX();
  y = compass.getY();
  rotacija = atan2(y, x);
  rotacija = (rotacija < 0 ? rotacija + 2 * PI : rotacija) * 180 / PI;
//  Serial.println(rotacija);

// -------------------------------------DATU SUTISANA-------------------------------------
  float  tx_rot[3];  // dati, kas tiek sutiti
  tx_rot[0] = rotacija;
  tx_rot[1] = gpsLatdata;
  tx_rot[2] = gpsLondata;
  
  // put your main code here, to run repeatedly:
  radio.stopListening ();          /* Setting modem in transmission mode*/
  radio.write(&tx_rot, sizeof(tx_rot));            /* Sending data over NRF 24L01*/
}

void clearGPS() {
  while (!GPS.newNMEAreceived()) {
    c = GPS.read();
  }
  GPS.parse(GPS.lastNMEA());

  while (!GPS.newNMEAreceived()) {
    c = GPS.read();
  }
  GPS.parse(GPS.lastNMEA());
}
