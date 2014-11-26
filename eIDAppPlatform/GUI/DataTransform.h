#pragma once

using namespace System;

public ref class DataTransform{

public:

	static const int IMAGE_BLOCK_SIZE = 470;

	array<BYTE>^ g_byNUM0;
	array<BYTE>^ g_byNUM1;
	array<BYTE>^ g_byNUM2;
	array<BYTE>^ g_byNUM3;
	array<BYTE>^ g_byNUM4;
	array<BYTE>^ g_byNUM5;
	array<BYTE>^ g_byNUM6;
	array<BYTE>^ g_byNUM7;
	array<BYTE>^ g_byNUM8;
	array<BYTE>^ g_byNUM9;
	array<cli::array<BYTE>^>^ g_byNUM09;

	array<BYTE>^ g_byORG0;
	array<BYTE>^ g_byORG1;
	array<BYTE>^ g_byORG2;
	array<BYTE>^ g_byORG3;
	array<BYTE>^ g_byORG4;
	array<BYTE>^ g_byORG5;
	array<cli::array<BYTE>^>^ g_byORG;

	array<BYTE>^ g_byKEY;
	array<BYTE>^ g_byIPTable;
	array<BYTE>^ g_byPC1Table;
	array<BYTE>^ g_byloopTable;
	array<BYTE>^ g_byPC2Table;
	array<BYTE>^ g_byETable;
	array<BYTE>^ g_byPTable;
	array<BYTE>^ g_byIPRTable;

	array<cli::array<cli::array<BYTE>^>^>^ g_bySBoxTable;
	array<cli::array<BYTE>^>^ S1;
	array<cli::array<BYTE>^>^ S2;
	array<cli::array<BYTE>^>^ S3;
	array<cli::array<BYTE>^>^ S4;
	array<cli::array<BYTE>^>^ S5;
	array<cli::array<BYTE>^>^ S6;
	array<cli::array<BYTE>^>^ S7;
	array<cli::array<BYTE>^>^ S8;

	array<BYTE>^ S10;
	array<BYTE>^ S11;
	array<BYTE>^ S12;
	array<BYTE>^ S13;

	array<BYTE>^ S20;
	array<BYTE>^ S21;
	array<BYTE>^ S22;
	array<BYTE>^ S23;

	array<BYTE>^ S30;
	array<BYTE>^ S31;
	array<BYTE>^ S32;
	array<BYTE>^ S33;

	array<BYTE>^ S40;
	array<BYTE>^ S41;
	array<BYTE>^ S42;
	array<BYTE>^ S43;

	array<BYTE>^ S50;
	array<BYTE>^ S51;
	array<BYTE>^ S52;
	array<BYTE>^ S53;

	array<BYTE>^ S60;
	array<BYTE>^ S61;
	array<BYTE>^ S62;
	array<BYTE>^ S63;

	array<BYTE>^ S70;
	array<BYTE>^ S71;
	array<BYTE>^ S72;
	array<BYTE>^ S73;

	array<BYTE>^ S80;
	array<BYTE>^ S81;
	array<BYTE>^ S82;
	array<BYTE>^ S83;

public:

	DataTransform();
	Byte* getImageData(String^ strData);
	void display7Seg (int nx, int ny, array<BYTE>^ g_byNUM09, LPBYTE lpbyBmpData);
	void drawLine(BYTE x0, BYTE y0, BYTE x1, BYTE y1, BYTE color, LPBYTE lpbyBmpData);
	void setPixel(int x, int y, int color, LPBYTE lpbyBmpData);

/*
	String^ strDES3Encrypt(array<BYTE>^ randomdata, array<BYTE>^ key, int enorde);
	array<BYTE>^ byDESGo(array<BYTE>^ in, array<BYTE>^ key, int enorde);
	array<BYTE>^ byBytes2Bits(array<BYTE>^ input, int length);
	array<BYTE>^ byTableChange (array<BYTE>^ input, array<BYTE>^ table, int outLen );
	array<cli::array<BYTE>^>^ bySetSubKey(array<BYTE>^ key);
	array<BYTE>^ byF(array<BYTE>^ in, array<BYTE>^ ki);
	array<BYTE>^ byXorArray(array<BYTE>^ a, array<BYTE>^ b, int len);
	array<BYTE>^ byBits2Bytes (array<BYTE>^ in, int bitLen );
	array<BYTE>^ byArrayLeftRotate(array<BYTE>^ input, int len, int loop);
	array<BYTE>^ bySBox (array<BYTE>^ in );
*/	
};