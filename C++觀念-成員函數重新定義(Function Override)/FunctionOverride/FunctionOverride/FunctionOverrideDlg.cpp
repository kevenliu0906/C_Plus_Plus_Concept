
// FunctionOverrideDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FunctionOverride.h"
#include "FunctionOverrideDlg.h"
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


// CFunctionOverrideDlg dialog



CFunctionOverrideDlg::CFunctionOverrideDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_FUNCTIONOVERRIDE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFunctionOverrideDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CFunctionOverrideDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_FUNC_OVERRIDE, &CFunctionOverrideDlg::OnBnClickedBtnFuncOverride)
END_MESSAGE_MAP()


// CFunctionOverrideDlg message handlers

BOOL CFunctionOverrideDlg::OnInitDialog()
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

void CFunctionOverrideDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFunctionOverrideDlg::OnPaint()
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
HCURSOR CFunctionOverrideDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CFunctionOverrideDlg::OnBnClickedBtnFuncOverride()
{
	//----- Initial...
	CString    Msg_cstr = _T("");
	TestA_CS   A_cs;
	TestAA_CS  AA_cs;
	TestA_CS   *Test_A_cs_ptr = NULL;

	//------------------------------------

	//-- �����禡�����s�w�q(function override)
	// ����: �p�G�����O���w�q�F�@�Ө禡�A��A�~�ӤF�����O����A�A�i�H "���s�w�q(override)" �o�Ө禡�A
	//       �H�����A�Ω�l�����O�C
	//       ��@�Ӧ����禡�b�l�����O���Q���s�w�q�A�ϥΦ��l�����O�ҥͦ�������өI�s�Ө禡�A�Ұ��檺�|�O
	//       �l�����O���ҩw�q���禡�A�Ӱ����O�����P�W�禡�ä����v�T�C

	// �i�H�o�ˤl�z�� >> �b�եΤ@�����������禡���ɭԡA�sĶ���|�u�������~����v�Ū��V�W�d��禡���w�q�A�p�G
	//                  ���F����N����d��F�A�ҥH�p�G�@�ӭl�����O�M�����O�����P�W���禡�A�ӽsĶ���̲�
	//                  ��ܤF�b�l�����O�����禡�A����ڭ̴N���o�ӭl�����O�������禡 "����" �F�����O����
	//                  ���禡�A�]�N�O��������F�sĶ���~��V�W�d���ƪ��w�q�C

	// reference: https://openhome.cc/Gossip/CppGossip/OverrideMemberFunction.html
	// reference: https://www.geeksforgeeks.org/function-overloading-vs-function-overriding-in-cpp/
	// reference: http://www.cppblog.com/zgysx/archive/2007/03/12/19662.html

	MessageBox(_T("object call function"));
	A_cs.Show_Fn();    // ����TestA_CS����Show_Fn()
	AA_cs.Show_Fn();   // ����TestAA_CS����Show_Fn()

	MessageBox(_T("base class ptr call function"));
	Test_A_cs_ptr = &A_cs;
	Test_A_cs_ptr->Show_Fn();
	Test_A_cs_ptr = &AA_cs;
	Test_A_cs_ptr->Show_Fn();
}
