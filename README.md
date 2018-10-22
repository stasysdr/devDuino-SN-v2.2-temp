# devDuino-SN-v2.2-temp
ArduinoIDE library to read temperature from devDuino Sensor Node v2.2 and print it via serial.

To upload:
1. setup Arduino as ISP (follow instructions on https://www.arduino.cc/en/Tutorial/ArduinoISP)
2. connect Arduino wires as described here: https://blog.squix.org/2014/07/devduino-sensor-node-part-1-programming.html (ICSP pins on arduino match ISP pins on devDuino SN (looking at pits with button on the top)
3. on Arduino IDE Tools\Programmer select "Arduino as ISP"
4. select Tools\Board - Arduino Nano and set Processor to ATmega (old bootloader).
5. upload sketch via Sketch\Upload Using Programmer
