#include <DallasTemperature.h>

  pinMode(3, OUTPUT);
  digitalWrite(3,HIGH);
  
// definicje
#define ONE_WIRE_BUS 2 // magistrala oneWire podłączona do pinu 2
#define TEMPERATURE_PRECISION 9 // rozdzielczość

// konfiguracja oneWire do komunikacji z dowolnym urządzeniem OneWire (nie tylko z układami temperaturowymi Maxim / Dallas)
OneWire oneWire(ONE_WIRE_BUS);

// przekazanie odniesienia oneWire do temperatury Dallas.
DallasTemperature sensors(&oneWire);


// tablica do przechowywania adresów urządzeń
DeviceAddress insideThermometer, outsideThermometer;

// Zmienne
int numberOfDevices; // liczba znalezionych czujników temperatury

int mVperAmp = 185; // dla modułu 20A - 100, dla modułu 30A - 66
int Wartosc_analogowa= 0; // 
int ACSoffset = 2472;
float  napiecie = 0;
double natezenie= 0;
double srednie_natezenie =0;
int srednia = 50;

void setup(void) 
{
 
    Serial.begin(9600); // uruchomienie portu szeregowego
    sensors.begin();// inicjalizacja biblioteki

      // przechwycenie liczby czujmików na magistrali oneWire
    numberOfDevices = sensors.getDeviceCount(); 

      // lokalizacja czujników na magistrali oneWire
  Serial.print("Lokalizowanie urządzeń...");
  Serial.print("Wykryto ");
  Serial.print(sensors.getDeviceCount(), DEC);
  Serial.println(" czujników.");

      // sprawdzanie mocy pasożytniczej
  Serial.print("Moc pasożytnicza: ");
  if (sensors.isParasitePowerMode()) Serial.println("WŁ");
  else Serial.println("WYŁ");
   
   

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

