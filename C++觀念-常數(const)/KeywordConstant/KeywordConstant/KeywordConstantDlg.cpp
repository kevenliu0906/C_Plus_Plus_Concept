
// KeywordConstantDlg.cpp : implementation file
//

#include "stdafx.h"
#include "KeywordConstant.h"
#include "KeywordConstantDlg.h"
#include "afxdialogex.h"
#include "DataDefine.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CKeywordConstantDlg dialog



CKeywordConstantDlg::CKeywordConstantDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_KEYWORDCONSTANT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CKeywordConstantDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CKeywordConstantDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_FUNC_CONST_PARAMETER, &CKeywordConstantDlg::OnBnClickedBtnFuncConstParameter)
	ON_BN_CLICKED(IDC_BTN_CLASS_CONST_FUNC, &CKeywordConstantDlg::OnBnClickedBtnClassConstFunc)
	ON_BN_CLICKED(IDC_BTN_FUNC_CONST_RETURN, &CKeywordConstantDlg::OnBnClickedBtnFuncConstReturn)
END_MESSAGE_MAP()


// CKeywordConstantDlg message handlers

BOOL CKeywordConstantDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CKeywordConstantDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CKeywordConstantDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CKeywordConstantDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
//-------------------------------------------------------------------------------------
void CKeywordConstantDlg::OnBnClickedBtnFuncConstParameter()
{
	//----- Initial ...
	TestA_CS   TestA_cs;
	CString    Msg_cstr = _T("");
	int        ArrayNum_i_ay[] = { 1,2,3,4,5,6};
	int        FindNum_i = 5;
	int        ArraySize_i = 0;
	bool       FindResult_fg = false;

	//------------------------------------

	ArraySize_i = sizeof(ArrayNum_i_ay) / sizeof(ArrayNum_i_ay[0]);
	FindResult_fg = TestA_cs.FindNum_Fn(ArrayNum_i_ay, FindNum_i, sizeof(ArrayNum_i_ay) / sizeof(int));
	if (FindResult_fg)
	{
		Msg_cstr.Format(_T("ArrayNum:{%d,%d,%d,%d,%d,%d}; << MATCH >> FindNum:%d"), ArrayNum_i_ay[0], ArrayNum_i_ay[1], ArrayNum_i_ay[2], ArrayNum_i_ay[3], ArrayNum_i_ay[4], ArrayNum_i_ay[5], FindNum_i);
	}
	else
	{
		Msg_cstr.Format(_T("ArrayNum:{%d,%d,%d,%d,%d,%d}; << NOT MATCH >> FindNum:%d"), ArrayNum_i_ay[0], ArrayNum_i_ay[1], ArrayNum_i_ay[2], ArrayNum_i_ay[3], ArrayNum_i_ay[4], ArrayNum_i_ay[5], FindNum_i);
	}
	MessageBox(Msg_cstr);
}
//-------------------------------------------------------------------------------------
void CKeywordConstantDlg::OnBnClickedBtnClassConstFunc()
{
	//------ Initial ...
	TestA_CS   TestA_cs;
	CString    Msg_cstr = _T("");
	int        Set_X_Value_i = 28;

	//--------------------------------------------------

	Msg_cstr.Format(_T("Original >>>>> TestA_cs:: X_i:%d"), TestA_cs.Get_X_Value_Fn());
	MessageBox(Msg_cstr);
	TestA_cs.Set_X_Value_Fn(Set_X_Value_i);
	Msg_cstr.Format(_T("After Set X value(%d) >>>>> TestA_cs:: X_i:%d"), Set_X_Value_i, TestA_cs.Get_X_Value_Fn());
	MessageBox(Msg_cstr);
	/*const */int Z_Value_i = TestA_cs.Get_Z_Value_Fn();
	Msg_cstr.Format(_T("After Get Z value(%d) >>>>> TestA_cs:: Z_i:%d"), Z_Value_i, TestA_cs.Get_Z_Value_Fn());
	MessageBox(Msg_cstr);
}
//-------------------------------------------------------------------------------------
void CKeywordConstantDlg::OnBnClickedBtnFuncConstReturn()
{
	//------- Initial ...
	CString    Msg_cstr = _T("");
	TestA_CS   TestA_cs;

	//----------------------------------------

	int  Y_Value_i = TestA_cs.Get_Y_Const_Value_Fn();
	Msg_cstr.Format(_T("(After get_const_y_value) TestA_cs:: Y_Value_i:%d"), Y_Value_i);
	MessageBox(Msg_cstr);
	const int Const_X_Value_i = TestA_cs.Get_X_Value_Fn();
	Msg_cstr.Format(_T("(After get_x_value) TestA_cs:: Const_x_i:%d"), Const_X_Value_i);
	MessageBox(Msg_cstr);
}
//-------------------------------------------------------------------------------------