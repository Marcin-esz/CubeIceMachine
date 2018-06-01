#include <DallasTemperature.h>
#include <OneWire.h>



// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS 2
#define TEMPERATURE_PRECISION 9

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);

// arrays to hold device addresses
DeviceAddress insideThermometer, outsideThermometer;

// Zmienne
int mVperAmp = 185; // dla moduĹ‚u 20A - 100, dla moduĹ‚u 30A - 66
int Wartosc_analogowa= 0; // 
int ACSoffset = 2472;
float  napiecie = 0;
double natezenie= 0;
double srednie_natezenie =0;
int srednia = 50;

void setup() 
{

// Start up the library
   sensors.begin();

// locate devices on the bus
  Serial.print("Locating devices...");
  Serial.print("Found ");
  Serial.print(sensors.getDeviceCount(), DEC);
  Serial.println(" devices.");

// report parasite power requirements
  Serial.print("Parasite power is: ");
  if (sensors.isParasitePowerMode()) Serial.println("ON");
  else Serial.println("OFF");
   
   pinMode(3, OUTPUT);
   digitalWrite(3,HIGH);

}


void loop() {

  srednie_natezenie = 0;
  for(int i=0;i<=srednia;i++)
  {
     Wartosc_analogowa = analogRead(A0);
     napiecie = (Wartosc_analogowa / 1024.0) * 5000; // napiÄ™cie w mV
     natezenie = ((napiecie - ACSoffset) / mVperAmp)*1000; // natÄ™ĹĽenie w mA

     srednie_natezenie =  srednie_natezenie+ natezenie;

     delay(1);
  }
  
  srednie_natezenie= srednie_natezenie/srednia;
  Serial.println(srednie_natezenie);


  if (srednie_natezenie >800)
  {
      digitalWrite(3,LOW);
  }
    
  
}

