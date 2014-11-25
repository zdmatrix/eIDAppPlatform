// FunctionModule.h

#pragma once

#include "winscard.h"

using namespace System;

namespace FunctionModule {

	public ref class ReaderDriver
	{
		// TODO: 在此处添加此类的方法。
	public:

		long lRet;

		SCARDCONTEXT hContextHandle;
		SCARDHANDLE hCardHandle;
		
		DWORD dwReaderLength;
		DWORD dwActiveProtocal;
		DWORD dwResponseLen;

		array<char>^ cReaderList;
		array<byte>^ byResponseDate;

		const static int Lc = 4;
		const static int APDU_LEN = 5;
		const static int MAX_RESPONSE_ONETIME = 2048;

	public:

		ReaderDriver(){
			lRet = 0;
			hContextHandle = 0;
			hCardHandle = 0;

			dwReaderLength = 0;
			dwActiveProtocal = 0;
			dwResponseLen = 0;
			cReaderList = nullptr;
			byResponseDate = gcnew array<byte>(MAX_RESPONSE_ONETIME);
		}

		long getReaderList(){

			dwReaderLength = 0;

			cli::pin_ptr<SCARDCONTEXT> lphContextHandle = &hContextHandle;
			cli::pin_ptr<DWORD> lpdwReaderLength = &dwReaderLength; 
			

			lRet = SCardEstablishContext(SCARD_SCOPE_USER, NULL, NULL, lphContextHandle);
			if(lRet != SCARD_S_SUCCESS){
				return lRet;
			}

			lRet = SCardListReaders(hContextHandle, SCARD_ALL_READERS, NULL, lpdwReaderLength);
			if(lRet != SCARD_S_SUCCESS){
				return lRet;
			}

			cReaderList = gcnew array<char>(dwReaderLength);
			cli::pin_ptr<char> pcReaderList = &cReaderList[0];
			lRet = SCardListReaders(hContextHandle, SCARD_ALL_READERS, (LPTSTR)pcReaderList, lpdwReaderLength);
			if(lRet != SCARD_S_SUCCESS){
				return lRet;
			}

			return lRet;
		}

		long readerControl(String^ readername, bool status){

			cli::pin_ptr<SCARDCONTEXT> lphContextHandle = &hContextHandle;
			cli::pin_ptr<SCARDHANDLE> lphCardHandle = &hCardHandle;
			char* pReadername = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(readername);
			cli::pin_ptr<DWORD> lpdwActiveProtocal = &dwActiveProtocal;
			cli::pin_ptr<DWORD> lpdwReaderLength = &dwReaderLength; 

			if(status){

				lRet = getReaderList();
				if(lRet != SCARD_S_SUCCESS){
					return lRet;
				}
				lRet = SCardConnect(hContextHandle, pReadername, SCARD_SHARE_SHARED, SCARD_PROTOCOL_T0 | SCARD_PROTOCOL_T1, lphCardHandle, lpdwActiveProtocal);
				if(lRet != SCARD_S_SUCCESS){
					return lRet;
				}

			}else{
				
				lRet = SCardDisconnect(hCardHandle, SCARD_RESET_CARD);
				if(lRet != SCARD_S_SUCCESS){
					return lRet;
				}

				lRet = SCardReleaseContext(hContextHandle);
				if(lRet != SCARD_S_SUCCESS){
					return lRet;
				}
			}

			return lRet;
		}

		long readerRW(array<byte>^ cmd){

			SCARD_IO_REQUEST hIO_Request;
			hIO_Request.dwProtocol = dwActiveProtocal;
			hIO_Request.cbPciLength = (DWORD)sizeof(SCARD_IO_REQUEST);

			dwResponseLen = MAX_RESPONSE_ONETIME;

			cli::pin_ptr<SCARD_IO_REQUEST> lphIoRequest = &hIO_Request;
			cli::pin_ptr<byte> lpbyResponseDate = &byResponseDate[0];
			cli::pin_ptr<byte> lpcmd = &cmd[0];
			cli::pin_ptr<DWORD> lpdwResponseLen = &dwResponseLen;

			lRet = SCardTransmit(hCardHandle, lphIoRequest, lpcmd, cmd->Length, NULL, (LPBYTE)lpbyResponseDate, lpdwResponseLen);
			return lRet;

		}
	};
}
