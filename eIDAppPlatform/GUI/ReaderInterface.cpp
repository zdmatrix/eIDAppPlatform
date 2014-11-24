#include "stdafx.h"
#include "ReaderInterface.h"

long lRet;

ReaderInterface::ReaderInterface(){
	
	rd = gcnew ReaderDriver();
	strReaderList = gcnew array<String^>(MAX_READER);
	nReaderCounter = 0;

}

long ReaderInterface::GetReaderList(){

	int offset = 0;
	nReaderCounter = 0;

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

long ReaderInterface::ReaderControl(String^ readername, bool status){
	lRet = rd->readerControl(readername, status);
	return lRet;
}

long ReaderInterface::DateTransformer(array<byte>^ cmd){

	strResponse = gcnew String("");
	lRet = rd->readerRW(cmd);
	if(lRet != SCARD_S_SUCCESS){
		return lRet;
	}
	cli::pin_ptr<byte> pbyResponse = &(rd->byResponseDate[0]);
	for(int i = 0; i < rd->byResponseDate->Length; i ++){
		strResponse += Convert::ToString(rd->byResponseDate[i], 16)->ToString();
	}
	return lRet;
}
