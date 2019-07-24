
// Static_Member.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CStatic_MemberApp:
// See Static_Member.cpp for the implementation of this class
//

class CStatic_MemberApp : public CWinApp
{
public:
	CStatic_MemberApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CStatic_MemberApp theApp;