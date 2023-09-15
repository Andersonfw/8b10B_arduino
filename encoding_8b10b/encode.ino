unsigned char xTable[32], yTable[9], xDecTable[58], yDecTable[14];
char rd;

struct flag3B {
  char inv, y7Neg, y7Pos;
};

char bitDisparity(unsigned int data, unsigned char bits) {

  unsigned char ones = 0, zeros = 0;
  unsigned int i;

  for (i = 0x1; bits > 0; i = i << 1, bits--) {
  
    if (data & i)
      ones++;
    else
      zeros++;
  }

  return (ones != zeros);
}

unsigned char encode3B4B(unsigned char data, struct flag3B flags) {

  unsigned char enc;
  
  if (data == 7 && flags.y7Neg && rd < 0)
    enc = yTable[8];
  else if (data == 7 && flags.y7Pos && rd > 0)
    enc = ~yTable[8] & 0xF;
  else {
    enc = yTable[data];
    if (flags.inv && (enc == 0xC || bitDisparity(enc, 4)))
      enc = ~enc & 0xF; // complemento de enc (4 bits -> 0xF = 0000 1111)
  }
 
  return enc;
}

unsigned char encode5B6B(unsigned char data, struct flag3B *flags) {
    
  unsigned char enc;
  char disparity;
  
  enc = xTable[data];
  disparity = bitDisparity(enc, 6);
  
  // Flags utilizados para codificação 3B4B
  flags->inv   = (disparity && rd < 0) || !(disparity || rd < 0); // (disparity) XOR (rd < 0)
  flags->y7Pos = (data == 11 || data == 13 || data == 14);        // casos especiais para y = 7 e rd > 0 caracteres especiais K
  flags->y7Neg = (data == 17 || data == 18 || data == 20);        // casos especiais para y = 7 e rd < 0 caracteres especiais K
  
  if (rd > 0 && (enc == 0x38 || disparity))
    enc = ~enc & 0x3F; // complemento de enc (6 bits -> 0x3F = 0011 1111)
  
  return enc;
}

unsigned int encode8B10B(unsigned char data) {
  
  unsigned int encoded;
  unsigned char data5B, enc6B, data3B, enc4B;
  struct flag3B flags;
  
  data5B = data & 0x1F; // 5 bits menos significativos (EDCBA; 0x1F = 0001 1111)
  data3B = data & 0xE0; // 3 bits mais significativos  (HGF;   0xE0 = 1110 0000)
  data3B = data3B >> 5;
  
  enc6B = encode5B6B(data5B, &flags); // (abcdei)
  enc4B = encode3B4B(data3B, flags);  // (fghj)
  
  encoded = (unsigned int) enc6B;
  encoded = encoded << 4;             // (abcdei0000)
  encoded = encoded | enc4B;          // (abcdeifghj)
  
  if (bitDisparity(encoded, 10))
    rd = -rd;
  
  return encoded;
}

void setup8B10B(void) {
  rd = -1; // rd deve sempre começar como -1
  createEncodeTables();
}

