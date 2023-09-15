#include <Wire.h>

#define I2C_DEV_ADDR 0x55

unsigned int* data = NULL;

void onReceive(){
  int length = Wire.available()/2;
  unsigned int dataPreDecode[length];

  for(int i = 0; i < length; i++){
    dataPreDecode[i] = Wire.read();
    dataPreDecode[i] =  dataPreDecode[i] << 8;
    dataPreDecode[i] =  dataPreDecode[i] | Wire.read();
  }

  Serial.println("--------------------------------------------------------------------------------------------------------------");
 Serial.print("tamanho da Mensagem recebida:  ");
 Serial.println(length);
 Serial.println("Dado codificado recebido: ");

  for(int i = 0; i < length; i++){
    Serial.print(dataPreDecode[i], HEX);
    Serial.print(" -- ");
  }
  Serial.println();
  
  unsigned char dataPostDecode[length];
  char message[length];
  
    Serial.println("DadoDecodificado: ");
  for(int i = 0; i < length; i++){
    dataPostDecode[i] = decode8B10B(dataPreDecode[i]);
    Serial.print(dataPostDecode[i]);
    Serial.print(" ");
    Serial.print(dataPostDecode[i], DEC);
    Serial.print("(");
    char t = dataPostDecode[i];
    Serial.print(t);
    Serial.print(")");
    Serial.print(" -- ");
    message[i] = t;
    //message += (char)dataPostDecode[i];
  }
Serial.println("");
Serial.println("Mensagem recebida:");
for(int i = 0; i < length; i++){
Serial.print(message[i]);
}
      Serial.println("");
      Serial.println("--------------------------------------------------------------------------------------------------------------");
}

void setup()
{
  setup8B10B_decode();
  Serial.begin(9600); 
  Wire.onReceive(onReceive);
  Wire.begin(I2C_DEV_ADDR);
  Serial.print("INICIO do DECODER");
}

void loop() {
      if ( Wire.available() > 0){
          // turn on or off depending on Serial.read()
          onReceive();
    }

}
