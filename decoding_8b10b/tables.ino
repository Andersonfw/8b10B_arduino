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
	yDecTable[1] = 0x7;
	yDecTable[2] = 0x4;
	yDecTable[3] = 0x3;
	yDecTable[4] = 0x0;
	yDecTable[5] = 0x2;
	yDecTable[6] = 0x6;
	yDecTable[7] = 0x7;
	yDecTable[8] = 0x7;
	yDecTable[9] = 0x1;
	yDecTable[10] = 0x5;
	yDecTable[11] = 0x0;
	yDecTable[12] = 0x3;
	yDecTable[13] = 0x4;
  yDecTable[14] = 0x7;
}

void createDecXTable(void) {
	//yTable[0] = 
	//yTable[1] = 
	//yTable[2] = 
	//yTable[3] = 
	//yTable[4] = 
	xDecTable[5] = 0x17;
	xDecTable[6] = 0x08;
	xDecTable[7] = 0x07;
	xDecTable[9] = 0x1B;
	xDecTable[10] = 0x04;
	xDecTable[11] = 0x14;
	xDecTable[12] = 0x18;
	xDecTable[13] = 0x0C;
	xDecTable[14] = 0x1C;
	xDecTable[17] = 0x1D;
	xDecTable[18] = 0x02;
	xDecTable[19] = 0x12;
	xDecTable[20] = 0x1F;
	xDecTable[21] = 0x0A;
	xDecTable[22] = 0x1A;
	xDecTable[23] = 0x0F;
	xDecTable[24] = 0x00;
	xDecTable[25] = 0x06;
	xDecTable[26] = 0x16;
	xDecTable[27] = 0x10;
	xDecTable[28] = 0x0E;
	xDecTable[29] = 0x01;
	xDecTable[30] = 0x1E;
	xDecTable[33] = 0x1E;
	xDecTable[34] = 0x01;
	xDecTable[35] = 0x11;
	xDecTable[36] = 0x10;
	xDecTable[37] = 0x09;
	xDecTable[38] = 0x19;
	xDecTable[39] = 0x00;
	xDecTable[40] = 0x0F;
	xDecTable[41] = 0x05;
	xDecTable[42] = 0x15;
	xDecTable[43] = 0x1F;
	xDecTable[44] = 0x0D;
	xDecTable[45] = 0x02;
	xDecTable[46] = 0x1D;
	xDecTable[49] = 0x03;
	xDecTable[50] = 0x13;
	xDecTable[51] = 0x18;
	xDecTable[52] = 0x0B;
	xDecTable[53] = 0x04;
	xDecTable[54] = 0x1B;
	xDecTable[56] = 0x07;
	xDecTable[57] = 0x08;
	xDecTable[58] = 0x17;

}
void createEncodeTables(void) {
  createXTable();
  createYTable();
}

void createDecodeTables(void) {
  createDecXTable();
  createDecYTable();
}