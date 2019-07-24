
// NameSpaceDlg.cpp : implementation file
//

#include "stdafx.h"
#include "NameSpace.h"
#include "NameSpaceDlg.h"
#include "afxdialogex.h"
#include "DataDefine.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//using namespace BigToSmall;
//using namespace SmallToBig;


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


// CNameSpaceDlg dialog



CNameSpaceDlg::CNameSpaceDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_NAMESPACE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNameSpaceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CNameSpaceDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_NAMESPACE, &CNameSpaceDlg::OnBnClickedBtnNamespace)
END_MESSAGE_MAP()


// CNameSpaceDlg message handlers

BOOL CNameSpaceDlg::OnInitDialog()
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

void CNameSpaceDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CNameSpaceDlg::OnPaint()
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
HCURSOR CNameSpaceDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CNameSpaceDlg::OnBnClickedBtnNamespace()
{
	//----- 命名空間(namespace)的概念
	// 當有兩個檔案中有相同的類別定義或宣告，就需要透過 命名空間(namespace) 來將類別區隔開來
	// C++提供名稱空間的概念，他就像是一個名稱管理容器，雖然不同的命名空間內有定義相同的類別，
	// 但由於屬於不同的名稱空間，所以這兩個名稱並不會衝突。
	//
	// C++使用namespace關鍵字來定義一個名稱空間，名稱空間中的成員，可以直接使用當中所宣告成員，
	// 但如果要在名稱空間之外使用這些成員，則要指定名稱空間。
	//
	// reference: http://monkeycoding.com/?p=944

	//------ Initial ...
	CString    Msg_cstr = _T("");
	int        Array_i_ay[5] = { 20,50,40,10,30 };
	//-----------------------------------
	
	BigToSmall::Sort_CS    Sort_BigToSmall_cs; //或是使用 using name BigToSmall; 在開頭部分
	SmallToBig::Sort_CS    Sort_SmallToBig_cs; //或是使用 using name SmallToBig; 在開頭部分

	Msg_cstr.Format(_T("(Original) Array_i_ay[%d]:{%d,%d,%d,%d,%d}"), sizeof(Array_i_ay) / sizeof(Array_i_ay[0]), Array_i_ay[0], Array_i_ay[1], Array_i_ay[2], Array_i_ay[3], Array_i_ay[4]);
	MessageBox(Msg_cstr);

	Sort_BigToSmall_cs.SortNum_Fn(Array_i_ay, sizeof(Array_i_ay) / sizeof(Array_i_ay[0]));
	Msg_cstr.Format(_T("(Big->Small) Array_i_ay[%d]:{%d,%d,%d,%d,%d}"), sizeof(Array_i_ay) / sizeof(Array_i_ay[0]), Array_i_ay[0], Array_i_ay[1], Array_i_ay[2], Array_i_ay[3], Array_i_ay[4]);
	MessageBox(Msg_cstr);

	Sort_SmallToBig_cs.SortNum_Fn(Array_i_ay, sizeof(Array_i_ay) / sizeof(Array_i_ay[0]));
	Msg_cstr.Format(_T("(Small->Big) Array_i_ay[%d]:{%d,%d,%d,%d,%d}"), sizeof(Array_i_ay) / sizeof(Array_i_ay[0]), Array_i_ay[0], Array_i_ay[1], Array_i_ay[2], Array_i_ay[3], Array_i_ay[4]);
	MessageBox(Msg_cstr);
}
