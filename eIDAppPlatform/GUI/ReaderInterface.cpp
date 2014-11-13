#include "stdafx.h"
#include "ReaderInterface.h"

long lRet;

ReaderInterface::ReaderInterface(){
	rd = gcnew ReaderDriver;
}

long ReaderInterface::GetReaderList(){

	int offset = 0;
	nReaderCounter = 0;
	strReaderList = gcnew array<String^>(MAX_READER);
//	ReaderDriver^ rd = gcnew ReaderDriver;
	lRet = rd->getReaderList();
	if(lRet != SCARD_S_SUCCESS){
		return lRet;
	}
	cli::pin_ptr<char> pchReaderList = &(rd->cReaderList[0]);
	for(int i = 0; pchReaderList[offset] != '\0'; i ++){
		strReaderList[i] = String(pchReaderList + offset).ToString();
		offset += (strReaderList[i]->Length + 1);
		nReaderCounter ++;
	}
	return lRet;
}

long ReaderInterface::ReaderControl(bool status){
	lRet = rd->readerControl(status);
	return lRet;
}