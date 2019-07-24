
// Static_MemberDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Static_Member.h"
#include "Static_MemberDlg.h"
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


// CStatic_MemberDlg dialog



CStatic_MemberDlg::CStatic_MemberDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_STATIC_MEMBER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CStatic_MemberDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CStatic_MemberDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_STATIC_MEMBER_TEST, &CStatic_MemberDlg::OnBnClickedBtnStaticMemberTest)
	ON_BN_CLICKED(IDC_BTN_STATIC_VARIABLE, &CStatic_MemberDlg::OnBnClickedBtnStaticVariable)
END_MESSAGE_MAP()


// CStatic_MemberDlg message handlers

BOOL CStatic_MemberDlg::OnInitDialog()
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

void CStatic_MemberDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CStatic_MemberDlg::OnPaint()
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
HCURSOR CStatic_MemberDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//---------------------------------------------------------------------------
void CStatic_MemberDlg::OnBnClickedBtnStaticMemberTest()
{
	//------- Initial...
	TestA_CS    TestA_cs(1,2);
	double      Aera_d = 0;
	CString     Msg_cstr = _T("");
	const int   LocalCons_Value_con_i = 10;

	TestA_CS    B_cs(50, 20);
	TestA_CS    C_cs(50, 3);

	//-----------------------------------------------

	//LocalCons_Value_con_i = 12;  // compiler error(const的區域變數無法再修改)
	//TestA_cs.Test_d = 10;        // compiler error(物件內的const成員無法再修改)
	

	Aera_d = TestA_CS::Circle_Area_Fn(2.0);
	Msg_cstr.Format(_T("Circle >> radius:%.2f, area:%.2f"), 2.0, Aera_d);
	MessageBox(Msg_cstr);

	TestA_cs.Change_StaticValue_Fn(20);
	Aera_d = TestA_cs.Circle_Area_Fn(2.0);
	Msg_cstr.Format(_T("Circle(Change PI value) >> radius:%.2f, area:%.2f"), 2.0, Aera_d);
	MessageBox(Msg_cstr);

	switch (Compare_Fn(B_cs, C_cs))
	{
	case 1:  // B_cs is bigger
		MessageBox(_T("B_cs > C_cs"));
		break;
	case 0:  // equal case
		MessageBox(_T("B_cs == C_cs"));
		break;
	case 2:  // B_cs is smaller
		MessageBox(_T("B_cs < C_cs"));
		break;
	}
	
}
//---------------------------------------------------------------------------
void CStatic_MemberDlg::OnBnClickedBtnStaticVariable()
{
	//----- Initial...
	CString   Msg_cstr = _T("");

	//---------------------------------------

	// 當變數宣告為Static時，一旦變數生成，他就會一直存在記憶體之中，即使函式執行完畢，變數也不會消失
	// 雖然變數 Counter 是Counter_Fn()內的區域變數，由於是宣告成Static，所以函式結束後，變數仍然存在，
	// 他會 "直到程式執行結束後才消失" 。
	// 雖然變數一直存在，但由於他是被宣告在函式Counter_Fn()中，所以函式之外仍無法存取該Static變數

	// reference: https://openhome.cc/Gossip/CppGossip/Scope.html

	for (int i_i = 0; i_i < 10; i_i++)
	{
		Count_Fn();
	}
	//Counter_i++;   // compiler error, 無法存取別的Function內的變數(即使是宣告為static型態)
}
//---------------------------------------------------------------------------
void CStatic_MemberDlg::Count_Fn()
{
	//----- Initial ...
	static int Counter_i = 1;
	CString    Msg_cstr = _T("");

	//-------------------------------
	Msg_cstr.Format(_T("%d"), Counter_i);
	MessageBox(Msg_cstr);
	Counter_i++;
}
//---------------------------------------------------------------------------