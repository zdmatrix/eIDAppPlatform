#pragma once

#using <J:\work\Code\c++\project\eIDAppPlatform\eIDAppPlatform\debug\FunctionModule.dll>

using namespace System;
using namespace FunctionModule;

public ref class ReaderInterface{
public:
	const static int MAX_READER = 64;
	int nReaderCounter;

	array<String^>^ strReaderList;
public:
	long GetReaderList();

};
