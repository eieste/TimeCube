#include <Arduino.h>
#include <Wire.h>


byte TxByte = 0xAA;
 
void I2C_TxHandler(void)
{
  Wire.write(TxByte);
  Serial.println("fooBar");
}

void setup(){
    Serial.begin(9600);
    Wire.begin(0x55); // Initialize I2C (Slave Mode: address=0x55 )
    Wire.onRequest(I2C_TxHandler);
}

void loop(){



}