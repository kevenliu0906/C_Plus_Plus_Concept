
// Pointer_ReferenceDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Pointer_Reference.h"
#include "Pointer_ReferenceDlg.h"
#include "afxdialogex.h"


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


// CPointer_ReferenceDlg dialog



CPointer_ReferenceDlg::CPointer_ReferenceDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_POINTER_REFERENCE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPointer_ReferenceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CPointer_ReferenceDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_REFERENCE, &CPointer_ReferenceDlg::OnBnClickedBtnReference)
	ON_BN_CLICKED(IDC_BTN_POINTER, &CPointer_ReferenceDlg::OnBnClickedBtnPointer)
END_MESSAGE_MAP()


// CPointer_ReferenceDlg message handlers

BOOL CPointer_ReferenceDlg::OnInitDialog()
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

void CPointer_ReferenceDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPointer_ReferenceDlg::OnPaint()
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
HCURSOR CPointer_ReferenceDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPointer_ReferenceDlg::OnBnClickedBtnReference()
{
	//---- 參考(reference)的一些觀念
	// 1. reference一定要被同型別的物件給初始化
	// 2. 一旦初始化，無法重新綁定至另一個物件
	// 3. 必須要reference to const才能參照一個const物件
	// reference: http://monkeycoding.com/?p=888

	//------ Initial...
	CString      Msg_cstr = _T("");

	//-------------------------------------

	int   VV1_i = 10;
	int   VV2_i = 20;
	int   &RR1_i = VV1_i;     // PASS (同型別的可以參考)
	//&RR1_i = VV2_i;         // compiler error, 上行已經初始化過RR1_i了，所以無法在重新綁定至另一個數值
	Msg_cstr.Format(_T("Original>>>>> (int)VV1_i:%d    (int &)RR1_i:%d"), VV1_i, RR1_i);
	MessageBox(Msg_cstr);
	RR1_i = VV2_i;
	Msg_cstr.Format(_T("After assign reference to others value>>>>> (int)VV1_i:%d    (int &)RR1_i:%d"), VV1_i, RR1_i);
	MessageBox(Msg_cstr);

	const int V1_i = 30;
	const int V2_i = 40;
	const int &R1_i = V1_i;   // PASS (同型別的可以參考)
	//&R1_i = V2_i;           // compiler error, 上行已經初始化過R1_i了，所以無法在重新綁定至另一個數值
	//int &R2_i = V2_i;       // compiler error, int型態的R2_i不能參考至const int型態的V2_i;
							  // 可以理解成因為 V2_i是宣告成const int型態，代表這個V2_i為常數變數(不可變動數值)
							  // 所以若是 R2_i宣告成 int型態，不就代表此變數會有變動的可能性，如此違反
							  // V2_i常數變數的目的
	Msg_cstr.Format(_T("(const int)V1_i:%d      (const int &)R1_i:%d"), V1_i, R1_i);
	MessageBox(Msg_cstr);

	int V3_i = 50;
	const int &R3_i = V3_i;   // PASS()
	Msg_cstr.Format(_T("(int)V3_i:%d       (const int &)R3_i:%d"), V3_i, R3_i);
	MessageBox(Msg_cstr);

}


void CPointer_ReferenceDlg::OnBnClickedBtnPointer()
{
	//---- 指標(pointer)的一些觀念
	// 1. 必須要pointer to const才能指向一個const物件。
	// 2. pointer to const可賦予一個nonconst的物件位址。
	// 3. const pointer不能改變所指物件。
	// reference: http://monkeycoding.com/?p=888

	//----- Initial ...
	CString    Msg_cstr = _T("");

	//--------------------------------

	/////-----------------------------------------------------------/////
	///// <<< const int指標指向 const int變數 >>> /////
	/////-----------------------------------------------------------/////
	const int V1_const_i = 38;
	const int *P1_const_Val_i_pr = &V1_const_i;  // PASS
	//int *P2_i_pr = &V1_const_i;          // compiler error, int型態的指標P2_i_pr不能指向const int型態的V1_const_i
	//*P1_const_Val_i_pr = 100;            // compiler error, 因為P1_const_Val_i_pr宣告成const int型態的指標，
									       // 所以無法變更其所指向的數值
	Msg_cstr.Format(_T("(const int *)P1_i_pr:%d     (const int)V1_i:%d"), *P1_const_Val_i_pr, V1_const_i);
	MessageBox(Msg_cstr);


	/////-----------------------------------------------------------/////
	///// <<< const int指標指向 int變數 >>> /////
	/////-----------------------------------------------------------/////
	int  V3_i = 30;
	const int *P3_const_Val_i_pr = &V3_i;  // PASS, 但不能透過P3_const_Val_i_pr去修改V3_i的數值，否則會導致錯誤
	//*P3_const_Val_i_pr = 50;             // compiler error, 因為P3_const_Val_i_pr宣告成const int型態的指標，
										   // 所以無法變更所指向的數值
	Msg_cstr.Format(_T("(const int *)P3_const_Val_i_pr:%d      (int)V3_i:%d"), *P3_const_Val_i_pr, V3_i);
	MessageBox(Msg_cstr);


	/////-----------------------------------------------------------/////
	///// <<< int const指標指向 int變數 >>> /////
	/////-----------------------------------------------------------/////
	int  V4_i = 40;
	int  V5_i = 50;
	int *const P4_const_Addr_i_pr = &V4_i; // PASS
	//P4_const_Addr_i_pr = &V5_i;          // compiler error, 因為P4_const_Addr_i_pr是宣告成const型態指標，
										   // 不能改變位址
	//P4_const_Addr_i_pr++;                // compiler error，原因同上

	Msg_cstr.Format(_T("Before assign pointer new value >>> (int *const)P4_const_Addr_i_pr:%d      (int)V4_i:%d"), *P4_const_Addr_i_pr, V4_i);
	MessageBox(Msg_cstr);
	*P4_const_Addr_i_pr = V5_i;
	Msg_cstr.Format(_T("After assign pointer new value >>> (int *const)P4_const_Addr_i_pr:%d      (int)V4_i:%d"), *P4_const_Addr_i_pr, V4_i);
	MessageBox(Msg_cstr);


	/////-----------------------------------------------------------/////
	///// <<< int 指標指向 const int變數 >>> /////
	/////-----------------------------------------------------------/////
	const int V6_const_i = 60;
	int *V6_i_pr = NULL;
	//V6_i_pr = &V6_const_i;               // compiler error, int型態的指標無法指向const int型態的變數
										   // 可以理解為因為V6_const_i的常數變數，也就是無法更改其值，如果用int型態的指標去指向它，
										   // 不就代表可以藉由V6_i_pr去更改其數值，違反原本宣告成常數變數的初衷

}
//-----------------------------------------------------------------------------------------------