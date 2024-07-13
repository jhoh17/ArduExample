/***********************/
/* process.ino */ 
/***********************/




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





