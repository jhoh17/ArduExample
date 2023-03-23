#include <SoftwareSerial.h>


#define BT1_TX  7
#define BT1_RX  8


SoftwareSerial bluetooth(BT1_RX, BT1_TX); 

void setup() 
{
  // put your setup code here, to run once:
  // Serial Starts
  Serial.begin(9600);
  bluetooth.begin(9600); 
  
}

void BT(); 




void loop() 
{
  // put your main code here, to run repeatedly:
  if(1)
  {
    BT(); 
  }    
}


void BT()
{
  if(bluetooth.available())
  {
    Serial.write(bluetooth.read()); 
  }

  if(Serial.available())
  {
    bluetooth.write(Serial.read()); 
  }  
}





// 
