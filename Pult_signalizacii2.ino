#include "FastLED.h"

// How many leds in your strip?
#define NUM_LEDS 8

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
#define DATA_PIN 6
#define CLOCK_PIN 13

// Define the array of leds
CRGB leds[NUM_LEDS];

int line[33], old[]={LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW,};


// the setup function runs once when you press reset or power the board
void setup() {
  // инициализация линий управления адресами мультиплексора
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
 // инициализация линий сігналізацій
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);

  pinMode(8, OUTPUT);

FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);
 
    for (int i=0; i <= 32; i++){ leds[i] = CRGB::Green;}
    FastLED.show();
}

// the loop function runs over and over again forever
void loop() {
  // 000
  digitalWrite(1, LOW);   
  digitalWrite(2, LOW);   
  digitalWrite(3, LOW); 
  line[1] = digitalRead(4);
  line[2] = digitalRead(5);
  line[3] = digitalRead(6);
  line[4] = digitalRead(7);  
  
  // 001
  digitalWrite(3, HIGH); 
  line[5] = digitalRead(4);
  line[6] = digitalRead(5);
  line[7] = digitalRead(6);
  line[8] = digitalRead(7); 

  // 010
  digitalWrite(2, HIGH); 
  digitalWrite(3, LOW); 
  line[9] = digitalRead(4);
  line[10] = digitalRead(5);
  line[11] = digitalRead(6);
  line[12] = digitalRead(7); 

  // 011
  digitalWrite(3, HIGH); 
  line[13] = digitalRead(4);
  line[14] = digitalRead(5);
  line[15] = digitalRead(6);
  line[16] = digitalRead(7); 

  // 100
  digitalWrite(1, HIGH);   
  digitalWrite(2, LOW);   
  digitalWrite(3, LOW); 
  line[17] = digitalRead(4);
  line[18] = digitalRead(5);
  line[19] = digitalRead(6);
  line[20] = digitalRead(7);  


   // 101
  digitalWrite(3, HIGH); 
  line[21] = digitalRead(4);
  line[22] = digitalRead(5);
  line[23] = digitalRead(6);
  line[24] = digitalRead(7); 


  // 110
  digitalWrite(2, HIGH); 
  digitalWrite(3, LOW); 
  line[25] = digitalRead(4);
  line[26] = digitalRead(5);
  line[27] = digitalRead(6);
  line[28] = digitalRead(7); 

  // 111
  digitalWrite(3, HIGH); 
  line[29] = digitalRead(4);
  line[30] = digitalRead(5);
  line[31] = digitalRead(6);
  line[32] = digitalRead(7); 

  // проверка изменения статуса сигнализации
  for (int i=1; i <= 33; i++){ if (line[i]!= old[i]) leds[i] = CRGB::Red;}
  FastLED.show();

  
  }
  
