
// Inherit_ConstructDestruct.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CInherit_ConstructDestructApp:
// See Inherit_ConstructDestruct.cpp for the implementation of this class
//

class CInherit_ConstructDestructApp : public CWinApp
{
public:
	CInherit_ConstructDestructApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CInherit_ConstructDestructApp theApp;