/***********************/
/* initialize.ino */ 
/***********************/

// Timer Function -----
void initTimer()
{
  timer = timerBegin(1000000);           // Set timer frequency to 1Mhz
  timerAttachInterrupt(timer, &onTimer); // Attach onTimer function to our timer.  
  timerAlarm(timer, s100usec, true, 0);  // onTimer function every second (value in usec). ISR period! basic 1000000 = 1sec 
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



void initIO()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(GpioIn_05, INPUT);
  pinMode(sensor, INPUT);


}





