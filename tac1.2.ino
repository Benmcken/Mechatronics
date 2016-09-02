////////////LCD///////////////
#include <LiquidCrystal.h>
char ch;
int Contrast=15;
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

///////////////////////////

//tachometer sketch using smaller ir optopcoupler
int encoder_pin = 7 ; 
unsigned int rpm; 
volatile byte pulses;
unsigned long timeold; 
unsigned int pulsesperturn = 20;     // how many slots on disc  

 void counter()
 {

  //update count
          pulses++;
 }

void setup() 
{
  
    Serial.begin(9600);
pinMode(encoder_pin, INPUT);

attachInterrupt(0, counter, FALLING);

   pulses = 0; 
   rpm = 0;
   timeold = 0;




///////////////////////////////////////////////////////////////////////

    pinMode(13,OUTPUT);
  //analogWrite(6,Contrast);
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("lcd"
);
/////////////////////////////////////////////////////////////////////









}

void loop() 
{
//////////////////////////////////////
  

  ////////////////////////////////////////////
if (millis() - timeold >= 1000){

 detachInterrupt(0);
  rpm = (60 * 1000 / pulsesperturn )/ (millis() - timeold )* pulses ; 
  timeold = millis();
  pulses = 0;
  //write to serial port 

  Serial.println("RPM = ");
  Serial.println(rpm,DEC);
  attachInterrupt(0, counter, FALLING);


  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
   lcd.print(rpm);
}

  
}
