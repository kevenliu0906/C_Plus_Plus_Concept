
// Inherit_ConstructDestructDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Inherit_ConstructDestruct.h"
#include "Inherit_ConstructDestructDlg.h"
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


// CInherit_ConstructDestructDlg dialog



CInherit_ConstructDestructDlg::CInherit_ConstructDestructDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_INHERIT_CONSTRUCTDESTRUCT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CInherit_ConstructDestructDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CInherit_ConstructDestructDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_INHERIT_CONSTRUCT_DECONSTRUCT, &CInherit_ConstructDestructDlg::OnBnClickedBtnInheritConstructDeconstruct)
END_MESSAGE_MAP()


// CInherit_ConstructDestructDlg message handlers

BOOL CInherit_ConstructDestructDlg::OnInitDialog()
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

void CInherit_ConstructDestructDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CInherit_ConstructDestructDlg::OnPaint()
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
HCURSOR CInherit_ConstructDestructDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CInherit_ConstructDestructDlg::OnBnClickedBtnInheritConstructDeconstruct()
{
	//--- Initial...
	CString       Msg_cstr = _T("");
		
	//------------------------------

	//--- 繼承後的建構函式和解構函式概念
	// 說明建構 >> 若你繼承了某個類別之後，當你在生成衍生類別的物件時若不指定參數，無參數的預設建構子會被執行，
	//            而基礎類別的無參數預設建構子也會被執行。
	//            如果你使用衍生類別生成物件，則建構函式的執行順序會從 "基底類別的建構函式開始執行起" ，因為基底類別
	//			  是衍生類別的基礎，一些基礎的參數或初始狀態必須先完成， "再來執行衍生類別的建構函式" 。

	// 說明解構 >> 在物件被消滅時，解構函式的執行順序則正好相反，是從 "衍生類別的解構函式開始執行" ，再來才是基礎類別
	//            的解構函式，因為若基底類別的解構函式如果先執行，則衍生類別相依於基底類別的一些狀態也會被解構(例如指標)
	//            則此時再行衍生類別的解構函式，將會存在著相依問題而造成錯誤。

	// reference: https://openhome.cc/Gossip/CppGossip/ConDesAfterInheritance.html

	//MessageBox(_T("Point2D object create"));
	//Point2D_CS    Point2D_A_cs;

	MessageBox(_T("Point3D-non parameter object create"));
	Point3D_CS    Point3D_A_cs;

	MessageBox(_T("Point3D-use parameter object create"));
	Point3D_CS    Point3D_B_cs(1, 2, 3);
}
