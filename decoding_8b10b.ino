#include <Wire.h>

#define I2C_DEV_ADDR 0x55

unsigned int* data = NULL;

void onReceive(int len){
  int length = Wire.available()/2;
  unsigned int dataPreDecode[length];

  for(int i = 0; i < length; i++){
    dataPreDecode[i] = Wire.read();
    dataPreDecode[i] =  dataPreDecode[i] << 8;
    dataPreDecode[i] =  dataPreDecode[i] | Wire.read();
  }

  for(int i = 0; i < length; i++){
    Serial.println(dataPreDecode[i], HEX);
  }
  Serial.println();
  
  char dataPostDecode[length];
  String message;
  
  for(int i = 0; i < length; i++){
    dataPostDecode[i] = decode8B10B(dataPreDecode[i]);
    Serial.println(dataPostDecode[i]);
    //message += (char)dataPostDecode[i];
  }

  //Serial.println(message);
}

void setup()
{
  setup8B10B_decode();
  Serial.begin(9600); 
  Wire.onReceive(onReceive);
  Wire.begin(I2C_DEV_ADDR);
}
