#pragma once

#using <J:\work\Code\c++\project\eIDAppPlatform\eIDAppPlatform\debug\FunctionModule.dll>

using namespace System;
using namespace FunctionModule;

public ref class ReaderInterface{
public:
	static const int MAX_READER = 0x40;
	array<String^>^ strReaderList;
	int nReaderCounter;
public:
	long GetReaderList();
};