
// Pointer_Reference.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CPointer_ReferenceApp:
// See Pointer_Reference.cpp for the implementation of this class
//

class CPointer_ReferenceApp : public CWinApp
{
public:
	CPointer_ReferenceApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CPointer_ReferenceApp theApp;