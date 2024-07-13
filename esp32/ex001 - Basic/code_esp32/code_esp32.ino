#include <Arduino.h>
#include "variables.h"
#include "defines.h"


// ESP32 Setup
void setup() 
{
  // put your setup code here, to run once:
  initTimer();  // Timer Interrupt
  initIO();

  Serial.begin(9600);
}


// ESP32 MainLoop
void loop() 
{
  // put your main code here, to run repeatedly:

  Serial.println(val01);
  delay(100);
}



void task100u() 
{
  val01 = analogRead(sensor);
  // test_pwm_rise();
  // test_pwm_rise_fall();
}



void task1m() 
{
  test_Gpio();

}



void task1s() 
{
  blink();

}




