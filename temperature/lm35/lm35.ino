// the manual has a bunch of cool graphs descrbing the behavior of 
// the sensor in different conditions which might be useful when answering
// questions in a slideshow (i.e. thermal response in still air, accuracy vs temperature, 
// Noise Voltage)
// 
// manual: http://www.ti.com/lit/ds/symlink/lm35.pdf
// LM35 Precision Centigrade Temperature Sensor
// Calibrated Directly in Celsius (Centigrade)
//   - Linear + 10-mV/°C Scale Factor <-- SUPER IMPORTANT 
//   - 0.5°C Ensured Accuracy (at 25°C 77°F)
//   - Rated for Full −55°C (-67°F) to 150°C (302°F) Range
//   - Operates from 4 V to 30 V

#define TEMP1  A0  // Analog input pin that the first LM35 is attached to
#define TEMP2  A1  // Analog input pin that the second LM35 is attached to

float sensorValue1 = 0;        // raw value read from analog
float sensorValue2 = 0;        // raw value read from analog
float voltage = 0; //converted voltage value from raw value
float tempC1=0; //value in celsius converted from sensorvalue1
float tempF1=0; //value in fahrenheit converted from celsius
float tempC2=0; //value in celsius converted from sensorvalue2
float tempF2=0; //value in fahrenheit converted from celsius

int count=50;

float avg=0;    //running average done by adding (F1+F2)/2;

void setup() {
  Serial.begin(9600);// initialize serial communications at 9600 bps
  pinMode(TEMP1,INPUT); // configures the specified pin to behave as an input
  pinMode(TEMP2,INPUT); // configures the specified pin to behave as an input
}

void loop() {
    
  sensorValue1 = analogRead(TEMP1); // read the analog in value:
  // sensorValue2 = analogRead(TEMP2); // read the analog in value:
  
  voltage = sensorValue1 * 5.0; // for using the 5v to power the sensor
  voltage /= 1024.0;
    
  tempC1 = (voltage-0.5) * 100; // converts analoge value to mV and scale to temperature in centigrade
  tempF1 = tempC1*1.8+32; //converts from celcius to farenheit

  count++;
  if (count>=60){
    count/=60;
  }

  // tempC2 =(float)(sensorValue2/1023*5000)/10; // converts analoge value to mV and scale to temperature in centigrade
  // tempF2 = tempC2*1.8+32; //converts from celcius to farenheit

  // avg=(tempF1+tempF2)/2; // average

  serialout(); // send data over serial

delay(1000); // wait 1 second before running again
}

void serialout(){

  Serial.print(tempF1);Serial.print(","); Serial.print(count); // print the data in csv format
  Serial.print("tempF 1 = ");  Serial.println(tempF1); // print tempF results to the serial monitor:
  Serial.print("count  = ");  Serial.print(count); Serial.println("s");    // print the  time to the serial monitor:
  Serial.print("serlVal1 = ");  Serial.println(sensorValue1); // print out the serial value
  Serial.print("voltage  = ");  Serial.println(voltage); // print out the voltage
  Serial.println("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");    // print line out
}