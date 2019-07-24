
// ReWriteDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ReWrite.h"
#include "ReWriteDlg.h"
#include "afxdialogex.h"
#include "DataDefine.h"
#include "PersonalOther.h"

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


// CReWriteDlg dialog



CReWriteDlg::CReWriteDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_REWRITE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CReWriteDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CReWriteDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_RE_WRITE, &CReWriteDlg::OnBnClickedBtnReWrite)
	ON_BN_CLICKED(IDC_BTN_OPERATOR, &CReWriteDlg::OnBnClickedBtnOperator)
	ON_BN_CLICKED(IDC_BTN_FRIEND_OPERATOR, &CReWriteDlg::OnBnClickedBtnFriendOperator)
END_MESSAGE_MAP()


// CReWriteDlg message handlers

BOOL CReWriteDlg::OnInitDialog()
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

void CReWriteDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CReWriteDlg::OnPaint()
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
HCURSOR CReWriteDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CReWriteDlg::OnBnClickedBtnReWrite()
{
	//------ Initial ......
	TestA_CS  A_cs(1, 2);
	TestA_CS  B_cs(3, 4);
	CString   Msg_cstr = _T("");

	//------------------------------------------

	//--> 將運算子重載的觀念
	// 在C++中，預設除了基本資料型態可以使用運算子進行運算，例如int、double、char等，如果您要將兩個物件相加，預設上是不行
	// 然而在很多情形下，您會想要將兩個物件的某些屬性值相加，並傳回運算後的結果，例如座標相加，
	// 在C++中，這可以透過重載運算子來達到目的
	// reference: http://monkeycoding.com/?p=930
	// reference: https://openhome.cc/Gossip/CppGossip/OverloadOperator.html

	Msg_cstr.Format(_T("A_cs(%d,%d), B_cs(%d,%d)"), A_cs.Get_X_Value_Fn(), A_cs.Get_Y_Value_Fn(),
													B_cs.Get_X_Value_Fn(), B_cs.Get_Y_Value_Fn());
	MessageBox(Msg_cstr);
	if (A_cs == B_cs)
	{
		Msg_cstr.Format(_T("(Before operator =) A_cs(%d,%d) is Equal B_cs(%d,%d)"), A_cs.Get_X_Value_Fn(), A_cs.Get_Y_Value_Fn(),
																					B_cs.Get_X_Value_Fn(), B_cs.Get_Y_Value_Fn());
		MessageBox(Msg_cstr);
	}
	else
	{
		Msg_cstr.Format(_T("(Before operator =) A_cs(%d,%d) is NOT Equal B_cs(%d,%d)"), A_cs.Get_X_Value_Fn(), A_cs.Get_Y_Value_Fn(),
																						B_cs.Get_X_Value_Fn(), B_cs.Get_Y_Value_Fn());
		MessageBox(Msg_cstr);
	}

	A_cs = B_cs;
	if (A_cs == B_cs)
	{
		Msg_cstr.Format(_T("(After operator =) A_cs(%d,%d) is Equal B_cs(%d,%d)"), A_cs.Get_X_Value_Fn(), A_cs.Get_Y_Value_Fn(),
																				   B_cs.Get_X_Value_Fn(), B_cs.Get_Y_Value_Fn());
		MessageBox(Msg_cstr);
	}
	else
	{
		Msg_cstr.Format(_T("(After operator =) A_cs(%d,%d) is NOT Equal B_cs(%d,%d)"), A_cs.Get_X_Value_Fn(), A_cs.Get_Y_Value_Fn(),
																					   B_cs.Get_X_Value_Fn(), B_cs.Get_Y_Value_Fn());
		MessageBox(Msg_cstr);
	}

	TestA_CS   C_cs;

	C_cs = A_cs + B_cs;
	Msg_cstr.Format(_T("C_cs(%d,%d) = A_cs(%d,%d) + B_cs(%d,%d)"), C_cs.Get_X_Value_Fn(), C_cs.Get_Y_Value_Fn(),
																   A_cs.Get_X_Value_Fn(), A_cs.Get_Y_Value_Fn(),
																   B_cs.Get_X_Value_Fn(), B_cs.Get_Y_Value_Fn());
	MessageBox(Msg_cstr);
}
//-------------------------------------------------------------------------------------------
void CReWriteDlg::OnBnClickedBtnOperator()
{
	//----- Initial...
	CString    Msg_cstr = _T("");
	TestA_CS   A_cs(1,2);
	TestA_CS   TestC_cs;

	//--------------------------------
	
	//-- 將運算子重載的觀念
	//  如果要重載++或是--運算子，必須要注意到前置或是後置的問題，例如一個變數x，前置(++x)和後置(x++)實際意義並不同。
	//  在重載時為了要區別前置或後置，C++中使用一個int參數來做區別，
	// <<例如>>:
	//  傳回值型態  operator++();      //前置，例如++x
	//  傳回值型態  operator++(int);   //後置，例如x++
	// 
	//  在後置中會傳入一個0，但實質上沒有作用，只是作為識別前置與後置之用。 

	TestC_cs = A_cs;
	Msg_cstr.Format(_T("(Original) TestC_cs = A_cs,\n TestC_cs(%d,%d), A_cs(%d,%d)"), TestC_cs.Get_X_Value_Fn(), TestC_cs.Get_Y_Value_Fn(),
																					  A_cs.Get_X_Value_Fn(), A_cs.Get_Y_Value_Fn());
	MessageBox(Msg_cstr);

	//////------------- 重載 ++運算子 -----------------//////
	TestC_cs = ++A_cs;
	Msg_cstr.Format(_T("After assign TestC_cs = ++A_cs,\n TestC_cs(%d,%d), A_cs(%d,%d)"), TestC_cs.Get_X_Value_Fn(), TestC_cs.Get_Y_Value_Fn(),
																						  A_cs.Get_X_Value_Fn(), A_cs.Get_Y_Value_Fn());
	MessageBox(Msg_cstr);

	TestC_cs = A_cs++;
	Msg_cstr.Format(_T("After assign TestC_cs = A_cs++,\n TestC_cs(%d,%d), A_cs(%d,%d)"), TestC_cs.Get_X_Value_Fn(), TestC_cs.Get_Y_Value_Fn(),
																						  A_cs.Get_X_Value_Fn(), A_cs.Get_Y_Value_Fn());
	MessageBox(Msg_cstr);

	//////------------- 重載 --運算子 -----------------//////
	TestC_cs = --A_cs;
	Msg_cstr.Format(_T("After assign TestC_cs = --A_cs,\n TestC_cs(%d,%d), A_cs(%d,%d)"), TestC_cs.Get_X_Value_Fn(), TestC_cs.Get_Y_Value_Fn(),
																						  A_cs.Get_X_Value_Fn(), A_cs.Get_Y_Value_Fn());
	MessageBox(Msg_cstr);

	TestC_cs = A_cs--;
	Msg_cstr.Format(_T("After assign TestC_cs = A_cs--,\n TestC_cs(%d,%d), A_cs(%d,%d)"), TestC_cs.Get_X_Value_Fn(), TestC_cs.Get_Y_Value_Fn(),
																						  A_cs.Get_X_Value_Fn(), A_cs.Get_Y_Value_Fn());
	MessageBox(Msg_cstr);
}
//-------------------------------------------------------------------------------------------
void CReWriteDlg::OnBnClickedBtnFriendOperator()
{
	//------ Initial...
	CString      Msg_cstr = _T("");
	TestA_CS     A_cs(5,6);
	TestA_CS     Sum_cs;
	TestA_CS     Sum2_cs;

	//-----------------------------------
	// <<使用friend函式來重載運算子>>
	// 使用類別成員來重載二元運算子，會有一個限制，就是運算子的左邊一定要是原物件
	// 如果使用類別成員重載，你就無法讓運算子重載的左邊是常數
	// reference: https://openhome.cc/Gossip/CppGossip/friendOverLoadOperator.html

	// 使用friend函式重載二元運算子時，你要指定兩個參數型態，分別表示運算子的左右邊的運算元型態。
	// reference: http://hungming.ct.ntust.edu.tw/2018fall/ct5707/classnotes/chap09.pdf 的8.3節

	Sum_cs = A_cs + 10;
	Msg_cstr.Format(_T("Sum_cs(%d,%d) = A_cs(%d,%d) + 10"), Sum_cs.Get_X_Value_Fn(), Sum_cs.Get_Y_Value_Fn(),
															A_cs.Get_X_Value_Fn(), A_cs.Get_Y_Value_Fn());
	MessageBox(Msg_cstr);

	Sum2_cs = 20 + A_cs;
	Msg_cstr.Format(_T("Sum2_cs(%d,%d) = 20 + A_cs(%d,%d)"), Sum2_cs.Get_X_Value_Fn(), Sum2_cs.Get_Y_Value_Fn(),
															 A_cs.Get_X_Value_Fn(), A_cs.Get_Y_Value_Fn());
	MessageBox(Msg_cstr);
}
//-------------------------------------------------------------------------------------------