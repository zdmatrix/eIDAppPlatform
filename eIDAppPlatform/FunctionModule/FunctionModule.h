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

			return lRet;
		}
	};
}
