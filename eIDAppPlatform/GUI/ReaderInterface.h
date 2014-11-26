#pragma once

#using <..\\debug\\FunctionModule.dll>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Threading;
using namespace FunctionModule;

public ref class ReaderInterface{

public:

	static const int MAX_READER = 0x40;
	static const int LINE1 = 0x01;
	static const int LINE2 = 0x02;
	static const int LINE_INDEX_IN_ARRAY = 0x03;
	static const int DISDATA_LENGTH_IN_ARRAY = 0x04;

	static const Int64 OPERATION_SUCCESS = 0x9000;
	static const Int64 FETCH_NEXT_DATA = 0x61;
	

	static array<byte>^ byGetRandom = gcnew array<byte>{0x00, (byte)0x84, 0x00, 0x00, 0x08};

	static array<byte>^ bySelecteIDApplet = gcnew array<byte>{0x00, (byte)0xA4, 0x00, 0x00, 0x08, (byte)0xA0, 
		0x00, 0x00, 0x00, 0x03, 0x45, 0x49, 0x44};

	static array<byte>^ byFetchNextData = gcnew array<byte>{0x00, (byte)0xc0, 0x00, 0x00, 0x00};

	static array<byte>^ byDisNothingFirstLine = gcnew array<byte>{(byte)0x80, (byte)0xBF, 0x01, 0x01, 0x09, 
		(byte)0x20, (byte)0x20, (byte)0x20, (byte)0x20, (byte)0x20, (byte)0x20, (byte)0x20, (byte)0x20, (byte)0x20};

	static array<byte>^ byDisNothingSecondLine = gcnew array<byte>{(byte)0x80, (byte)0xBF, 0x01, 0x02, 0x09, 
		(byte)0x20, (byte)0x20, (byte)0x20, (byte)0x20, (byte)0x20, (byte)0x20, (byte)0x20, (byte)0x20, (byte)0x20};

	static array<byte>^ bySetDisplayData = gcnew array<byte>{(byte)0x80, (byte)0xBF, 0x01, 0x00, 0x00};

	static array<byte>^ byDisplayOnCard = gcnew array<byte>{(byte)0x80, (byte)0xBF, 0x01, 0x03, 0x00};
	static array<byte>^ bySelectBinFile = gcnew array<byte>{0x00, (byte)0xa4, 0x00, 0x00, 0x02, 0x55, 0x55};
	static array<byte>^ byUpdateBinFile = gcnew array<byte>{0x00, (byte)0xd6, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00};
	static array<byte>^ byReadBinFile = gcnew array<byte>{0x00, (byte)0xb0, 0x00, 0x00, 0x04};
	static array<byte>^ byEnableCardButtonPushed = gcnew array<byte>{(byte)0x80, (byte)0xbf, 0x06, 0x00, 0x00};

	static String^ OP_FAILED = gcnew String("Operation Failed£¡");
	static String^ DIS_NOTHING_ON_LINE = gcnew String("DIS_NOTHING");
	static String^ DIS_NOCHANGE = gcnew String("DIS_NOCHANGE");

	String^ strResponseSW;
	String^ strResponseData;

	array<String^>^ strReaderList;

	int nReaderCounter;

	DWORD dwResponseLen;

	ReaderDriver^ rd;
	


public:
	ReaderInterface();
	long GetReaderList();
	long ReaderControl(String^ readername, bool status);
	long DateCommunication(array<byte>^ cmd);

	long SelecteIDApplet();
	long GetRandom();
	long DisPlayOnCard(String^ line1, String^ line2);
	long GetBanlance();
	long UpdateBinFile(String^ data);
	long WaitCardButtonPushed();

	String^ ErrorDescription(long ret);

private:
	long FetchNextData(byte length);
	void GetResponseData(array<byte>^ response, int len);
	array<byte>^ GetDisDataArray(String^ data);
	
};