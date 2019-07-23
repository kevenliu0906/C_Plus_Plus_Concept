
// Pass2DArray.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CPass2DArrayApp:
// See Pass2DArray.cpp for the implementation of this class
//

class CPass2DArrayApp : public CWinApp
{
public:
	CPass2DArrayApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CPass2DArrayApp theApp;