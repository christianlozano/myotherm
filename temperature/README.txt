depending on which sensor you use either the LM35 or LM335 you just use the code accordingly

LM35 Precision Centigrade Temperature Sensor
Calibrated Directly in Celsius (Centigrade)
• Linear + 10-mV/°C Scale Factor <-- SUPER IMPORTANT 
• 0.5°C Ensured Accuracy (at 25°C 77°F)
• Rated for Full −55°C (-67°F) to 150°C (302°F) Range
• Operates from 4 V to 30 V


the manual has a bunch of cool graphs descrbing the behavior of the sensor in different conditions which might be useful when answering questions in a slideshow (i.e. thermal response in still air, accuracy vs temperature, Noise Voltage)

manual: http://www.ti.com/lit/ds/symlink/lm35.pdf


amazon: https://www.amazon.com/s/ref=sr_pg_1?rh=i%3Aaps%2Ck%3Alm35&keywords=lm35&ie=UTF8&qid=1468435432

OR if you need it ASAP get it from microcenter in cambridge,
microcenter: http://www.microcenter.com/product/446165/OSEPP_LM35_Temperature_Sensor_Module_for_Arduino

idk if you've programmed an arduino but basically you just plug it in over usb and use the arduino IDE and when its connected you select the correct Board, Processor, and Port. you can copy and paste the code into an empty project it doesnt use any coding libraries so its super simple to use, good luck!


Future Recommendations:

Arduino Micro (4.8cm by 1.77cm)
The board can operate on an external supply of 6 to 20 volts. If supplied with less than 7V, however, the 5V pin may supply less than five volts and the board may become unstable. If using more than 12V, the voltage regulator may overheat and damage the board. The recommended range is 7 to 12 volts. Use VI pin to supply power to board instead of usb. 

More lm35 sensors
Using more sensors will let you get an averaged temperature reading and depending on what you want to get a temperature of you can put them closer or farther away from the surface.