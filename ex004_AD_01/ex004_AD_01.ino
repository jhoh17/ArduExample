#include <Arduino.h>

#define LED_BUILTIN  2
int red = 13; 
int green = 14; 
int yellow = 12;
int GpioIn_05 = 5; 
int button = 0; 
int sensor = 36; 


// Timer Function -----
#define s100usec 100
hw_timer_t *timer = NULL;



// User Defined Functions 
void task100u();
void task1m(); 
void task1s();
void blink(); 
void test_Gpio(); 



// ESP32 Setup 
void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600); 
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(GpioIn_05, INPUT);
  pinMode(sensor, INPUT);


  // Timer Function -----
  timer = timerBegin(1000000);    // Set timer frequency to 1Mhz
  timerAttachInterrupt(timer, &onTimer);  // Attach onTimer function to our timer.
  // Set alarm to call onTimer function every second (value in microseconds).
  timerAlarm(timer, s100usec, true, 0);  // Change this value for ISR period! basic 1000000 = 1sec 
  // Timer Function -----  

}



// ESP32 MainLoop 
void loop() 
{
  // put your main code here, to run repeatedly:
  int val = analogRead(sensor); 
  
  Serial.println(val); 
  delay(100); 
}



// Timer Function -----
void ARDUINO_ISR_ATTR onTimer() 
{
  static int countN_1sec = 0, countN_1msec = 0; 
  
  // task 100usec
  task100u();


  // task 1m sec
  if(countN_1msec > 10) 
  {
    task1m();
    countN_1msec = 0; 
  }
  else
  {

  }
  countN_1msec++; 


  // task 1 sec
  if(countN_1sec > 10000) 
  {
    task1s(); 
    countN_1sec = 0; 
  }
  else
  {

  }
  countN_1sec++; 

}
// Timer Function -----



void task100u()
{
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



void blink()
{
  static int i = 1;   
  digitalWrite(LED_BUILTIN, i);  // Turn the RGB LED white
  i ^= 1; 
}



void test_Gpio()
{
  button = digitalRead(GpioIn_05); 

  if(button == 1)
  {
    digitalWrite(red, HIGH); 
  }
  else
  {
    digitalWrite(red, LOW); 
  }
}



