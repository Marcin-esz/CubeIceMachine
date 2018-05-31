/*
 * main.c    ATmega328P    F_CPU = 16000000 Hz
 *
 * Created on: 31.05.2018
 *     Author: Marcin Szewczyk
*/
// dołączanie systemowych plików nagłówkowych
#include <avr/io.h>
#include <util/delay.h>
#include <avr/pgmspace.h>
#include "mk_build.h"

// miejsce na dołączanie własnych plików    
#include <Adafruit_GFX_Library/Adafruit_GFX.h>
#include <Adafruit_GFX_Library/Adafruit_SPITFT.h>  
#include <Adafruit_GFX_Library/Adafruit_SPITFT_Macros.h>                                                  
#include <Adafruit_GFX_Library/gfxfont.h>     
#include <Adafruit_SSD1306/Adafruit_SSD1306.h>   
           
#define OLED_RESET 4     
Adafruit_SSD1306 display(OLED_RESET);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2 

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

                         
         
// główna funkcja programu - main()
int main( void ) {
                      
// sekcja inicjalizacji peryferiów
                                    
// główna pętla programu
    while ( 1 ) {

    }                          

}                                    