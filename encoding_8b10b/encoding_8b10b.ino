#include <Wire.h>

#define I2C_DEV_ADDR 0x55

unsigned int inX, inY;

void serialEvent() {
  String message = Serial.readString();
  int length = message.length() +1;
  int total_Lenght = length;
  int leght_remaining = length;
  Serial.println("--------------------------------------------------------------------------------------------------------------");


  Serial.print("Mensagem a ser enviada:");
  Serial.print(message);
  Serial.println("Tamanho: ");
  Serial.println(length);



  unsigned char dataPreEncode[length]; 
  for(int i = 0; i < length; i++){
  dataPreEncode[i] = message[i];
 }
  // strcpy((char*)dataPreEncode, message.c_str());

  unsigned int dataPostEncode[length];
  
  Serial.println("Dado bufferizado antes do encode:");
  for(int i = 0; i < length; i++){
    Serial.print(dataPreEncode[i]);
    Serial.print("(");
    char t = dataPreEncode[i];
    Serial.print(t);
    Serial.print(")");
    Serial.print(" -- ");
  }
  Serial.println("");

 Serial.println("Dado codificado para ser enviado:");
  for(int i = 0; i < length; i++){
    dataPostEncode[i] = encode8B10B(dataPreEncode[i]);
    Serial.print(dataPostEncode[i], HEX);
    Serial.print(" -- ");
  }
  
    Serial.println("");
  Wire.beginTransmission(I2C_DEV_ADDR);
  for(int i = 0; i < length; i++){
    Wire.write(highByte(dataPostEncode[i]));
    Wire.write(lowByte(dataPostEncode[i]));
  }
  Wire.endTransmission();

  Serial.println("--------------------------------------------------------------------------------------------------------------");
}


void setup() {

  setup8B10B();
  inX = inY = 0;
  Serial.begin(9600);
  Serial.print("    \t Y \t  X  \tCURRENT RD- \tCURRENT RD+ \t  \n");
  Serial.print("DX.Y\tHGF\tEDCBA\tabcdei\tfghj\tabcdei\tfghj\tRD-\tRD+\n");

  Wire.begin();
}

void loop() {

  // unsigned int input, output;
  // unsigned int a, f;
  // char r;

  // char datachar = 'S'; // Dado a ser transmitido
  // input = int(datachar);
  // Serial.print("Dado a ser codificado:");
  // Serial.print(datachar);
  // Serial.print("  -----  ");
  // Serial.print(input, BIN);
  // Serial.print("  -----  ");
  // Serial.println(input);

  // Serial.print('D');
  // Serial.print(inX, DEC);
  // Serial.print('.');
  // Serial.print(inY, DEC);
  // Serial.print('\t');
  // Serial.print(inY, BIN);
  // Serial.print('\t');
  // Serial.print(inX, BIN);
  // Serial.print('\t');

  // rd = -1;
  // input = (inY << 5) | inX;
  // output = encode8B10B(input);

  // Serial.print("output: ");
  // Serial.println(output, BIN);
  // a = (output & 0x3F0) >> 4;
  // f = output & 0xF;

  // Serial.print(a, BIN);
  // Serial.print('\t');
  // Serial.print(f, BIN);
  // Serial.print('\t');

  /*r = rd = 1;
  output = encode8B10B(input);
  Serial.print("RD :");
  Serial.println(rd,DEC);
  Serial.print("saida:  ");
  Serial.println(output, BIN);


  datachar = 'A'; // Dado a ser transmitido
  input = int(datachar);
  Serial.print("Dado a ser codificado:");
  Serial.print(datachar);
  Serial.print("  -----  ");
  Serial.print(input, BIN);
  Serial.print("  -----  ");
  Serial.println(input);

  output = encode8B10B(input);
  Serial.print("RD :");
  Serial.println(rd,DEC);
  Serial.print("saida:  ");
  Serial.println(output, BIN);*/
  // a = (output & 0x3F0) >> 4;
  // f = output & 0xF;

  // Serial.print(a, BIN);
  // Serial.print('\t');
  // Serial.print(f, BIN);
  // Serial.print('\t');

  // if (r == rd)
  //   Serial.print("same\n");
  // else
  //   Serial.print("flip\n");

  // if (++inY == 8) {
  //   inY = 0;
  //   inX++;
  // }

  // if (inX >= 32)
  //   while (1)
  //     ;

    if (Serial.available() > 0){
          // turn on or off depending on Serial.read()
          serialEvent();
    }

}
