unsigned char xDecTable[59], yDecTable[14];

unsigned char decode3B4B(unsigned char data) {
  unsigned char dec;
   dec = yDecTable[data];
  return dec;
}

unsigned char decode5B6B(unsigned char data) {
  unsigned char dec;
  dec = xDecTable[data];
  return dec;
}

unsigned char decode8B10B(unsigned int data) {
  
  unsigned int decoded;
  unsigned char data6B, dec5B, data4B, dec3B;
  
  data6B = data & 0x3F0; // 6 bits mais significativos  (abcdei0000; 0x3F0 = 11 1111 0000)
  data4B = data & 0x00F; // 4 bits menos significativos (000000fghj; 0x00F = 00 0000 1111)
  data6B = data6B >> 4;
  
  dec5B = decode5B6B(data6B);  // (abcdei)
  dec3B = decode3B4B(data4B);  // (fghj)
  
  decoded = (unsigned int) dec3B;
  decoded = decoded << 5;             // (HGF00000)
  decoded = decoded | dec5B;          // (HGFEDCBA)
   
  return decoded;
}

void setup8B10B_decode(void) {
  createDecodeTables();
}

