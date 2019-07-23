
// OverloadingDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Overloading.h"
#include "OverloadingDlg.h"
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


// COverloadingDlg dialog



COverloadingDlg::COverloadingDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_OVERLOADING_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COverloadingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(COverloadingDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_OVERLOADING, &COverloadingDlg::OnBnClickedBtnOverloading)
END_MESSAGE_MAP()


// COverloadingDlg message handlers

BOOL COverloadingDlg::OnInitDialog()
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

void COverloadingDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void COverloadingDlg::OnPaint()
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
HCURSOR COverloadingDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
//------------------------------------------------------------------
void COverloadingDlg::OnBnClickedBtnOverloading()
{
	//-------- Initial .....
	TestA_CS   A_cs;
	double     Result_d = 0;
	double     tempA_d = 1;
	double     tempB_d = 2;
	double     tempC_d = 3;
	int        Result_i = 0;
	int        tempA_i = 10;
	int        tempB_i = 20;
	CString    Msg_cstr = _T("");

	//----------------------------------------
	
  //--> 更(overloading)阀├
	// ㄧΑ更(overloading)沮ㄧΑ "把计把计戈篈" 沮 "把计计" ┪琌 "ㄢ挡"
	// 璶猔種琌"篈" ぃノ耞ㄧΑ更(overloading)ㄌ沮
	// reference: https://openhome.cc/Gossip/CppGossip/OverloadedFunction.html

	Result_d = A_cs.Add_Fn(tempA_d, tempB_d);
	Msg_cstr.Format(_T("<double type with Add_Fn()> A:%f + B:%f = %f"), tempA_d, tempB_d, Result_d);
	MessageBox(Msg_cstr);
	Result_d = A_cs.Add_Fn(tempA_d, tempB_d, tempC_d);
	Msg_cstr.Format(_T("<double type with Add_Fn()> A:%f + B:%f + C:%f = %f"), tempA_d, tempB_d, tempC_d, Result_d);
	MessageBox(Msg_cstr);
	Result_i = A_cs.Add_Fn(tempA_i, tempB_i);
	Msg_cstr.Format(_T("<int type with Add_Fn()> A:%d + B:%d = %d"), tempA_i, tempB_i, Result_i);
	MessageBox(Msg_cstr);
}
//------------------------------------------------------------------