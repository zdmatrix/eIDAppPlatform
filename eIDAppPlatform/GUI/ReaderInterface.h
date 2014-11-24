#pragma once

#using <..\\debug\\FunctionModule.dll>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Threading;
using namespace FunctionModule;

public ref class ReaderInterface{

public:
	
	String^ strResponse;
	

public:

	static const int MAX_READER = 0x40;

	array<String^>^ strReaderList;
	int nReaderCounter;

	ReaderDriver^ rd;
	


public:
	ReaderInterface();
	long ReaderControl(String^ readername, bool status);
	long DateTransformer(array<byte>^ cmd);

	long GetReaderList();
	
};