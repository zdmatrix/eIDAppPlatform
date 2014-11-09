#include "stdafx.h"
#include "ReaderInterface.h"

long lRet;

long ReaderInterface::GetReaderList(){
	
	ReaderDriver^ rd = gcnew ReaderDriver;

	nReaderCounter = 0;
	
	lRet = rd->getReaderList();
	if(lRet != SCARD_S_SUCCESS){
		return lRet;
	}

	cli::pin_ptr<char> pch = &(rd->cReaderList[0]);
	strReaderList = gcnew array<String^>(MAX_READER);
	for(int i = 0; i < MAX_READER && *pch != '\0'; i ++){
		strReaderList[i] = String(pch).ToString();
		pch += (strReaderList[i]->Length + 1);
		nReaderCounter ++;
	}
	
	return lRet;
}