
// UserDefine_Conversion.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CUserDefine_ConversionApp:
// See UserDefine_Conversion.cpp for the implementation of this class
//

class CUserDefine_ConversionApp : public CWinApp
{
public:
	CUserDefine_ConversionApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CUserDefine_ConversionApp theApp;