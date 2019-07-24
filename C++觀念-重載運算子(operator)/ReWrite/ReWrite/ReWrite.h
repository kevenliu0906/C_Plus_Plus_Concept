
// ReWrite.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CReWriteApp:
// See ReWrite.cpp for the implementation of this class
//

class CReWriteApp : public CWinApp
{
public:
	CReWriteApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CReWriteApp theApp;