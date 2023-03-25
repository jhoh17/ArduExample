#include "uTimerLib.h"


int Tsamp = 100; // 100usec sampling time 
float Tsamp0 = (float)Tsamp*0.000001; 

volatile boolean status = 0;
int LED_1 = 13; 
int LED_2 = 12; 



void setup() 
{
  // put your setup code here, to run once:
  TimerLib.setInterval_us(timed_function, Tsamp); // 100usec, 10kHz Sampling    

  pinMode(LED_1, OUTPUT); 
  pinMode(LED_2, OUTPUT); 
  
}


void loop() 
{
  // put your main code here, to run repeatedly:
    blink();  
}


/*** Main Loop ***/ 
void timed_function() 
{  
  //  statusTsamp(); 
  //  
  //  AD_Reading();
  //  
  //  Wind_Run(); 
  // Led_Run();  
  // iPV_Run();   
}



/****************************************/ 
void blink()
{    
    status = !status;      
    digitalWrite(LED_1, status);
    digitalWrite(LED_2, status);
    delay(500); 
}
