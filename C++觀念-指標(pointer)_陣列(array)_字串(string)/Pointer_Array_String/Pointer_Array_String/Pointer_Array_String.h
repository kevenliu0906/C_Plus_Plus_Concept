
// Pointer_Array_String.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CPointer_Array_StringApp:
// See Pointer_Array_String.cpp for the implementation of this class
//

class CPointer_Array_StringApp : public CWinApp
{
public:
	CPointer_Array_StringApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CPointer_Array_StringApp theApp;