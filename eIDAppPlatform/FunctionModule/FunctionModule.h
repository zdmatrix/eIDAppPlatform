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

		array<char>^ cReaderList;


	public:

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

		long readerControl(bool status){

			cli::pin_ptr<SCARDCONTEXT> lphContextHandle = &hContextHandle;
			cli::pin_ptr<SCARDHANDLE> lphCardHandle = &hCardHandle;
			cli::pin_ptr<char> pcReaderList = &cReaderList[0];
			cli::pin_ptr<DWORD> pdwActiveProtocal = &dwActiveProtocal;

			if(lphContextHandle != nullptr){
				lRet = SCardReleaseContext(*lphContextHandle);
				if(lRet != SCARD_S_SUCCESS){
					return lRet;
				}
			}

			lRet = SCardEstablishContext(SCARD_SCOPE_USER, NULL, NULL, lphContextHandle);
			if(lRet != SCARD_S_SUCCESS){
				return lRet;
			}

			if(status){
				lRet = SCardConnect(*lphContextHandle, pcReaderList, SCARD_SHARE_DIRECT, SCARD_PROTOCOL_T0, lphCardHandle, pdwActiveProtocal);
				if(lRet != SCARD_S_SUCCESS){
					return lRet;
				}

			}else{
				lRet = SCardDisconnect(*lphCardHandle, SCARD_LEAVE_CARD);
				if(lRet != SCARD_S_SUCCESS){
					return lRet;
				}
				lRet = SCardReleaseContext(*lphContextHandle);
				if(lRet != SCARD_S_SUCCESS){
					return lRet;
				}

			}

			return lRet;
		}
	};
}
