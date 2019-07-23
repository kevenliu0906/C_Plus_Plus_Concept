
// UserDefine_ConversionDlg.cpp : implementation file
//

#include "stdafx.h"
#include "UserDefine_Conversion.h"
#include "UserDefine_ConversionDlg.h"
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


// CUserDefine_ConversionDlg dialog



CUserDefine_ConversionDlg::CUserDefine_ConversionDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_USERDEFINE_CONVERSION_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CUserDefine_ConversionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CUserDefine_ConversionDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_USER_DEFINE_CONV, &CUserDefine_ConversionDlg::OnBnClickedBtnUserDefineConv)
END_MESSAGE_MAP()


// CUserDefine_ConversionDlg message handlers

BOOL CUserDefine_ConversionDlg::OnInitDialog()
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

void CUserDefine_ConversionDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CUserDefine_ConversionDlg::OnPaint()
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
HCURSOR CUserDefine_ConversionDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//-----------------------------------------------------------------
void CUserDefine_ConversionDlg::OnBnClickedBtnUserDefineConv()
{
	//------ Initial...
	CString      Msg_cstr = _T("");
	Integer_CS   Integer1_cs(10);
	Integer_CS   Integer2_cs(20);
	int          Result_i = 0;
	int          Result2_i = 0;

	//-------------------------------------
	if (Integer1_cs == Integer2_cs)
		Msg_cstr.Format(_T("(Origianl) >> Integer1_cs:%d, Integer2_cs:%d, Integer1_cs=Integer2_cs"), Integer1_cs.GetValue_Fn(), Integer2_cs.GetValue_Fn());
	else
		Msg_cstr.Format(_T("(Original) >> Integer1_cs:%d, Integer2_cs:%d, Integer1_cs!=Integer2_cs"), Integer1_cs.GetValue_Fn(), Integer2_cs.GetValue_Fn());
	MessageBox(Msg_cstr);

	Integer1_cs = Integer2_cs;

	if (Integer1_cs == Integer2_cs)
		Msg_cstr.Format(_T("(After =) >> Integer1_cs:%d, Integer2_cs:%d, Integer1_cs=Integer2_cs"), Integer1_cs.GetValue_Fn(), Integer2_cs.GetValue_Fn());
	else
		Msg_cstr.Format(_T("(After =) >> Integer1_cs:%d, Integer2_cs:%d, Integer1_cs!=Integer2_cs"), Integer1_cs.GetValue_Fn(), Integer2_cs.GetValue_Fn());
	MessageBox(Msg_cstr);

	//-- C++���ϥΪ̦۩w���A�ഫ(User-Defined Conversions)
	// ����: �b�ϥ�friend�禡�����B��l���A�A�i�H�ϥ�friend�禡�ѨM�򥻫��A�P�ۭq���A�ۥ[�B��B����D�C
	//       �]�N�O�� 10+Object�B Object-15 �o�����B��i�z�Lfriend�禡�ӭ����۹������B��l�C
	//       �M�ӷQ�Q�b��h���B��ݨD���A�A�i���+�B-�B*�B/�B%�������B��l���Q���ۭq���A�B�⪺�ݨD�A���C�@�ӻݨD
	//       �������۹������B��l���G�O���X�G�Ĳv���C
	// �Ѫk: ���Ӵ��Ѫ��O�@�Ӧ۰ʫ��A�ഫ�A�b�ݭn���ɭԡA�sĶ���|�ھڧA���ۭq���A�ഫ�A�۰ʱN�A���ۭq���A�ഫ��
	//       �A���w�����A�C

	Result_i = Integer1_cs + 25;
	Result2_i = 15 + Integer1_cs;

	Msg_cstr.Format(_T("Integer1_CS:%d,  Integer2_CS:%d,  Integer1_cs+25=%d,  15+Integer1_cs=%d"), Integer1_cs.GetValue_Fn(), Integer2_cs.GetValue_Fn(), Result_i, Result2_i);
	MessageBox(Msg_cstr);

}
//-----------------------------------------------------------------