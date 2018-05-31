#include <Adafruit_SSD1306.h>

#include <Adafruit_GFX.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <gfxfont.h>







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

