
// PolymorphismDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Polymorphism.h"
#include "PolymorphismDlg.h"
#include "afxdialogex.h"
#include "DataDefine.h"
#include "PersonalOther.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
/////====================================================================================/////
/////======================== Global Function ===========================================/////
/////====================================================================================/////
//void ShowByRef_Fn(A_CS &tempA_cs)
//{
//	tempA_cs.Show_Fn();
//}
////-------------------------------------------------------------------------------------------------
//void ShowByPtr_Fn(A_CS *tempA_cs_pr)
//{
//	tempA_cs_pr->Show_Fn();
//}
///////====================================================================================/////


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


// CPolymorphismDlg dialog



CPolymorphismDlg::CPolymorphismDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_POLYMORPHISM_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPolymorphismDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CPolymorphismDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_POLYMORPHISM, &CPolymorphismDlg::OnBnClickedBtnPolymorphism)
END_MESSAGE_MAP()


// CPolymorphismDlg message handlers

BOOL CPolymorphismDlg::OnInitDialog()
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


	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CPolymorphismDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPolymorphismDlg::OnPaint()
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
HCURSOR CPolymorphismDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPolymorphismDlg::OnBnClickedBtnPolymorphism()
{
	//--> test the C++ 多形概念
	// (如果把TestA_Class.h內的A_CS的Show_Fn()函數前方virtual拿掉，就會有不一樣的輸出)
	// <<多型只有在使用 "指標"或是"參考" 才得以發揮作用>>， "多型是動態鍵結" 的概念
	// 需要在基底類別把要多型的函式前加上關鍵字virtual，表示這函式是虛擬函式，並且在衍生類別中重新定義虛擬函式，
	// 表示此成員函式的操作延遲至 "執行時期" 再決定。
	// reference: http://monkeycoding.com/?p=936
	// reference: http://puremonkey2010.blogspot.com/2014/08/c-gossip-virtual-function.html
	// reference: https://www.itread01.com/content/1544437518.html

	A_CS    Test_A_cs;
	AA_CS   Test_AA_cs;
	A_CS    *Test_A_cs_pr = NULL;
	
	MessageBox(_T("====== TestByRef (dynamic binding test) ======"));
	ShowByRef_Fn(Test_A_cs);
	ShowByRef_Fn(Test_AA_cs);
	
	MessageBox(_T("====== TestByPtr (dynamic binding test) ======"));
	ShowByPtr_Fn(&Test_A_cs);
	ShowByPtr_Fn(&Test_AA_cs);

	Test_A_cs_pr = &Test_A_cs;
	Test_A_cs_pr->Show_Fn();
	Test_A_cs_pr = &Test_AA_cs;
	Test_A_cs_pr->Show_Fn();

	MessageBox(_T("====== Each object call member function (static binding test) ======"));
	Test_A_cs.Show_Fn();
	Test_AA_cs.Show_Fn();

	MessageBox(_T("====== Pointer to basic class and call function (dynamic binding test) ======"));
	Test_A_cs_pr = &Test_A_cs;
	Test_A_cs_pr->ShowParam_Test_Fn(0);
	Test_A_cs_pr->Test_Fn();

	Test_A_cs_pr = &Test_AA_cs;
	Test_A_cs_pr->ShowParam_Test_Fn(0);
	Test_A_cs_pr->Test_Fn();  // 即使子類別(AA_CS)有宣告Test_Fn()，但是由於父類別(A_CS)的Test_Fn()沒有宣告成virtual
							  // 所以這個function只會會進入到父類別(A_CS)的Test_Fn()內
}
