
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

	//--- �~�ӫ᪺�غc�禡�M�Ѻc�禡����
	// �����غc >> �Y�A�~�ӤF�Y�����O����A��A�b�ͦ��l�����O������ɭY�����w�ѼơA�L�Ѽƪ��w�]�غc�l�|�Q����A
	//            �Ӱ�¦���O���L�Ѽƹw�]�غc�l�]�|�Q����C
	//            �p�G�A�ϥέl�����O�ͦ�����A�h�غc�禡�����涶�Ƿ|�q "�����O���غc�禡�}�l����_" �A�]�������O
	//			  �O�l�����O����¦�A�@�ǰ�¦���ѼƩΪ�l���A�����������A "�A�Ӱ���l�����O���غc�禡" �C

	// �����Ѻc >> �b����Q�����ɡA�Ѻc�禡�����涶�ǫh���n�ۤϡA�O�q "�l�����O���Ѻc�禡�}�l����" �A�A�Ӥ~�O��¦���O
	//            ���Ѻc�禡�A�]���Y�����O���Ѻc�禡�p�G������A�h�l�����O�̩ۨ�����O���@�Ǫ��A�]�|�Q�Ѻc(�Ҧp����)
	//            �h���ɦA��l�����O���Ѻc�禡�A�N�|�s�b�̰۬ۨ��D�ӳy�����~�C

	// reference: https://openhome.cc/Gossip/CppGossip/ConDesAfterInheritance.html

	//MessageBox(_T("Point2D object create"));
	//Point2D_CS    Point2D_A_cs;

	MessageBox(_T("Point3D-non parameter object create"));
	Point3D_CS    Point3D_A_cs;

	MessageBox(_T("Point3D-use parameter object create"));
	Point3D_CS    Point3D_B_cs(1, 2, 3);
}
