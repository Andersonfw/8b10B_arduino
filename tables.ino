void createYTable(void) {
  yTable[0] = 0xB;
  yTable[1] = 0x9;
  yTable[2] = 0x5;
  yTable[3] = 0xC;
  yTable[4] = 0xD;
  yTable[5] = 0xA;
  yTable[6] = 0x6;
  yTable[7] = 0xE;
  yTable[8] = 0x7;
}

void createXTable(void) {
  xTable[0] = 0x27;
  xTable[1] = 0x1D;
  xTable[2] = 0x2D;
  xTable[3] = 0x31;
  xTable[4] = 0x35;
  xTable[5] = 0x29;
  xTable[6] = 0x19;
  xTable[7] = 0x38;
  xTable[8] = 0x39;
  xTable[9] = 0x25;
  xTable[10] = 0x15;
  xTable[11] = 0x34;
  xTable[12] = 0xD;
  xTable[13] = 0x2C;
  xTable[14] = 0x1C;
  xTable[15] = 0x17;
  xTable[16] = 0x1B;
  xTable[17] = 0x23;
  xTable[18] = 0x13;
  xTable[19] = 0x32;
  xTable[20] = 0xB;
  xTable[21] = 0x2A;
  xTable[22] = 0x1A;
  xTable[23] = 0x3A;
  xTable[24] = 0x33;
  xTable[25] = 0x26;
  xTable[26] = 0x16;
  xTable[27] = 0x36;
  xTable[28] = 0xE;
  xTable[29] = 0x2E;
  xTable[30] = 0x1E;
  xTable[31] = 0x2B;
  
}void createDecYTable(void) {
//yTable[0] = 
  yTable[1] = 0x7
  yTable[2] = 0x4
  yTable[3] = 0x3
  yTable[4] = 0x0
  yTable[5] = 0x2
  yTable[6] = 0x6
  yTable[7] = 0x7
  yTable[8] = 0x7
  yTable[9] = 0x1
  yTable[10] = 0x5
  yTable[11] = 0x0
  yTable[12] = 0x3
  yTable[12] = 0x7
  yTable[13] = 0x4
}

void createDecXTable(void) {
	//yTable[0] = 
	//yTable[1] = 
	//yTable[2] = 
	//yTable[3] = 
	//yTable[4] = 
	xTable[5] = 0x17
	xTable[6] = 0x08
	xTable[7] = 0x07
	xTable[9] = 0x1B
	xTable[10] = 0x04
	xTable[11] = 0x14
	xTable[12] = 0x18
	xTable[13] = 0x0C
	xTable[14] = 0x1C
	xTable[17] = 0x1D
	xTable[18] = 0x02
	xTable[19] = 0x12
	xTable[20] = 0x1F
	xTable[21] = 0x0A
	xTable[22] = 0x1A
	xTable[23] = 0x0F
	xTable[24] = 0x00
	xTable[25] = 0x06
	xTable[26] = 0x16
	xTable[27] = 0x10
	xTable[28] = 0x0E
	xTable[29] = 0x01
	xTable[30] = 0x1E
	xTable[33] = 0x1E
	xTable[34] = 0x01
	xTable[35] = 0x11
	xTable[36] = 0x10
	xTable[37] = 0x09
	xTable[38] = 0x19
	xTable[39] = 0x00
	xTable[40] = 0x0F
	xTable[41] = 0x05
	xTable[42] = 0x15
	xTable[43] = 0x1F
	xTable[44] = 0x0D
	xTable[45] = 0x02
	xTable[46] = 0x1D
	xTable[49] = 0x03
	xTable[50] = 0x13
	xTable[51] = 0x18
	xTable[52] = 0x0B
	xTable[53] = 0x04
	xTable[54] = 0x1B
	xTable[56] = 0x07
	xTable[57] = 0x08
	xTable[58] = 0x17

}
void createEncodeTables(void) {
  createXTable();
  createYTable();
}

void createDecodeTables(void) {
  createDecXTable();
  createDecYTable();
}