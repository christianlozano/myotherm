 
float tempK=0, tempC=0, tempF=0;
 
void setup(){
 
Serial.begin(9600);    //Setup serial to 9600 bps
pinMode(13, OUTPUT);  // initialize digital pin 13 as an output.
}
 

void loop(){

temps();
// you can mess around with the variables here
serialout();

algorithm();


delay(100);    //Delay 1 second
}

void temps(){ 
  tempK = analogRead(0) * 0.004882812 * 100;    //Read temperature in Kelvins first
  // Why .004882812? We get that by dividing our 5v (Power Supply) by 1024 (10bits based off arduino analog)
   
  tempC = tempK - 273.15;    //Convert from Kelvin to Celsius
  // Kelvin we – 273.15 to get our Celsius
  
  tempF = ((tempK) * 9 / 5) - 459.67;    //Convert from Kelvin to Fahrenheit
  // To get our Fahrenheit we multiply our Kelvin value by 9/5 and then subtract 459.67.
  }

void serialout(){
  //Print all the values to Serial
  Serial.print("Kelvin: "); Serial.println(tempK);
  Serial.print("Celsius: "); Serial.println(tempC);
  Serial.print("Fahrenheit: "); Serial.println(tempF);
  Serial.println();    //Print Blank Line
 
  }

  void algorithm(){
//   if temperature is greater than 90 blink 
    if (tempF>90){
        digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
        delay(100);              // wait for a second
        digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
//        delay(100);    
      }else{ // if not greater than 90 turn off
        digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
//        delay(100);              // wait for a second
        }
    }