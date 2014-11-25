#include "stdafx.h"
#include "ReaderInterface.h"

long lRet;

ReaderInterface::ReaderInterface(){
	
	rd = gcnew ReaderDriver();
	strReaderList = gcnew array<String^>(MAX_READER);
	strResponseData = gcnew String("");
	strResponseSW = gcnew String("");
	nReaderCounter = 0;
	dwResponseLen = 0;

}

long ReaderInterface::GetReaderList(){

	int offset = 0;
	nReaderCounter = 0;

	lRet = rd->getReaderList();
	if(lRet != SCARD_S_SUCCESS){
		strResponseSW = ErrorDescription(lRet);
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
	if(lRet != SCARD_S_SUCCESS){
		strResponseSW = ErrorDescription(lRet);
		return lRet;
	}
	return lRet;
}


void ReaderInterface::GetResponseData(array<byte>^ response, int len){

	cli::pin_ptr<byte> pbyResponse = &(response[0]);
	for(int i = 0; i < len - 2; i ++){
		strResponseData += (rd->byResponseDate[i]).ToString("X2");
	}
}

long ReaderInterface::FetchNextData(byte length){

	int len = (int)length;

	byFetchNextData->SetValue(len, 4);

	lRet = rd->readerRW(byFetchNextData);
	if(lRet != SCARD_S_SUCCESS){
		strResponseSW = ErrorDescription(lRet);
		return lRet;
	}

	len = rd->dwResponseLen;
	GetResponseData(rd->byResponseDate, len);
	lRet = rd->byResponseDate[len - 2] * 256 + rd->byResponseDate[len - 1];
	return lRet;
}


long ReaderInterface::DateTransformer(array<byte>^ cmd){

	int len = 0;
	strResponseSW = "";
	strResponseData = "";

	lRet = rd->readerRW(cmd);
	if(lRet != SCARD_S_SUCCESS){
		strResponseSW = ErrorDescription(lRet);
		return lRet;
	}
	
	dwResponseLen = rd->dwResponseLen;
	lRet = rd->byResponseDate[dwResponseLen - 2] * 256 + rd->byResponseDate[dwResponseLen - 1];
	if(lRet != OPERATION_SUCCESS){
		if(rd->byResponseDate[dwResponseLen - 2] == FETCH_NEXT_DATA){
			do 
			{
				lRet = FetchNextData(rd->byResponseDate[dwResponseLen - 1]);
			} while (lRet != OPERATION_SUCCESS);
			
		}else{
			strResponseSW = ErrorDescription(lRet);
			return lRet;
		}
		
	}
	GetResponseData(rd->byResponseDate, dwResponseLen);
	return lRet;
}


long ReaderInterface::SelecteIDApplet(){

	lRet = DateTransformer(bySelecteIDApplet);
	if(lRet != SCARD_S_SUCCESS){
		strResponseSW = ErrorDescription(lRet);
	}
	return lRet;
}


long ReaderInterface::GetRandom(){

	lRet = DateTransformer(byGetRandom);
	if(lRet != OPERATION_SUCCESS){
		strResponseSW = ErrorDescription(lRet);
		return lRet;
	}
	return lRet;
}

long ReaderInterface::DisPlayOnCard(String^ line1, String^ line2){

	array<byte>^ cmd;

	if(line1->Equals(DIS_NOTHING_ON_LINE)){
		lRet = DateTransformer(byDisNothingFirstLine);
		if(lRet != OPERATION_SUCCESS){
			strResponseSW = ErrorDescription(lRet);
			return lRet;
		}
	}else{
		if(!line1->Equals(DIS_NOCHANGE)){
			cmd = GetDisDataArray(line1);
			cmd[LINE_INDEX_IN_ARRAY] = LINE1;
			lRet = DateTransformer(cmd);
			if(lRet != OPERATION_SUCCESS){
				strResponseSW = ErrorDescription(lRet);
				return lRet;
			}
		}
	}

	if(line2->Equals(DIS_NOTHING_ON_LINE)){
		lRet = DateTransformer(byDisNothingSecondLine);
		if(lRet != OPERATION_SUCCESS){
			strResponseSW = ErrorDescription(lRet);
			return lRet;
		}
	}else{
		if(!line2->Equals(DIS_NOCHANGE)){
			cmd = GetDisDataArray(line2);
			cmd[LINE_INDEX_IN_ARRAY] = LINE2;
			lRet = DateTransformer(cmd);
			if(lRet != OPERATION_SUCCESS){
				strResponseSW = ErrorDescription(lRet);
				return lRet;
			}
		}
	}

	lRet = DateTransformer(byDisplayOnCard);
	if(lRet != OPERATION_SUCCESS){
		strResponseSW = ErrorDescription(lRet);
		return lRet;
	}
	
	return lRet;
}


array<byte>^ ReaderInterface::GetDisDataArray(String^ data){

	array<byte>^ byRet = gcnew array<byte>(5 + data->Length);
	array<wchar_t>^ byData = data->ToCharArray();

	cli::interior_ptr<byte> pbyte = &bySetDisplayData[0];
	*(pbyte + 4) = data->Length;

	for(int i = 0; i < 5; i ++){
		byRet[i] = safe_cast<byte>(bySetDisplayData->GetValue(i));		
	}
	for(int i = 0; i < data->Length; i ++){
		byRet[5 + i] = cli::safe_cast<byte>(byData[i]);		
	}
	return byRet;
}

String^ ReaderInterface::ErrorDescription(long ret){

	 LPVOID lpMsgBuf = NULL;
	 DWORD retval = 0;
	 String^ ErrorDescription = gcnew String("");

	 retval = FormatMessage(
		 FORMAT_MESSAGE_ALLOCATE_BUFFER | 
		 FORMAT_MESSAGE_FROM_SYSTEM |
		 FORMAT_MESSAGE_IGNORE_INSERTS,
		 NULL,
		 (DWORD)ret,
		 MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		 (LPTSTR) &lpMsgBuf,
		 0, NULL );

	 if(!retval){
		 switch (ret){
			case 0x6A82: 
				ErrorDescription = (String^)OP_FAILED;
				break;
			default: 
				break;
		 }
	 }else{
		 ErrorDescription = String((LPTSTR)lpMsgBuf).ToString();
	 }

	 String^ str = String::Format("Error Code£º 0x{0, 8:X8}", ret);
	 str += ("\nError Reason£º " + ErrorDescription);
	 return str;

 }