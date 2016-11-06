/**
 * Blink
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 */
#include "Arduino.h"

//Пин подключен к ST_CP входу 74HC595
int latchPin = 8;
//Пин подключен к SH_CP входу 74HC595
int clockPin = 12;
//Пин подключен к DS входу 74HC595
int dataPin = 11;



void setup() {
 //устанавливаем режим OUTPUT
 pinMode(latchPin, OUTPUT);
 pinMode(clockPin, OUTPUT);
 pinMode(dataPin, OUTPUT);
}

void loop() {
 // отсчитываем от 0 до 255  и отображаем значение на светодиоде
 int row = 1;
 for (int i = 1; i < 9; i++) {
   // устанавливаем синхронизацию "защелки" на LOW
   digitalWrite(latchPin, LOW);

   shiftOut(dataPin, clockPin, MSBFIRST, row);
   shiftOut(dataPin, clockPin, MSBFIRST, 0);

   shiftOut(dataPin, clockPin, MSBFIRST, 255);
   shiftOut(dataPin, clockPin, MSBFIRST, 255);
   //"защелкиваем" регистр, тем самым устанавливая значения на выходах
   digitalWrite(latchPin, HIGH);
   row = row << i;
 }
}
