
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
	//---- �Ѧ�(reference)���@���[��
	// 1. reference�@�w�n�Q�P���O�����󵹪�l��
	// 2. �@����l�ơA�L�k���s�j�w�ܥt�@�Ӫ���
	// 3. �����nreference to const�~��ѷӤ@��const����
	// reference: http://monkeycoding.com/?p=888

	//------ Initial...
	CString      Msg_cstr = _T("");

	//-------------------------------------

	int   VV1_i = 10;
	int   VV2_i = 20;
	int   &RR1_i = VV1_i;     // PASS (�P���O���i�H�Ѧ�)
	//&RR1_i = VV2_i;         // compiler error, �W��w�g��l�ƹLRR1_i�F�A�ҥH�L�k�b���s�j�w�ܥt�@�Ӽƭ�
	Msg_cstr.Format(_T("Original>>>>> (int)VV1_i:%d    (int &)RR1_i:%d"), VV1_i, RR1_i);
	MessageBox(Msg_cstr);
	RR1_i = VV2_i;
	Msg_cstr.Format(_T("After assign reference to others value>>>>> (int)VV1_i:%d    (int &)RR1_i:%d"), VV1_i, RR1_i);
	MessageBox(Msg_cstr);

	const int V1_i = 30;
	const int V2_i = 40;
	const int &R1_i = V1_i;   // PASS (�P���O���i�H�Ѧ�)
	//&R1_i = V2_i;           // compiler error, �W��w�g��l�ƹLR1_i�F�A�ҥH�L�k�b���s�j�w�ܥt�@�Ӽƭ�
	//int &R2_i = V2_i;       // compiler error, int���A��R2_i����ѦҦ�const int���A��V2_i;
							  // �i�H�z�Ѧ��]�� V2_i�O�ŧi��const int���A�A�N��o��V2_i���`���ܼ�(���i�ܰʼƭ�)
							  // �ҥH�Y�O R2_i�ŧi�� int���A�A���N�N���ܼƷ|���ܰʪ��i��ʡA�p���H��
							  // V2_i�`���ܼƪ��ت�
	Msg_cstr.Format(_T("(const int)V1_i:%d      (const int &)R1_i:%d"), V1_i, R1_i);
	MessageBox(Msg_cstr);

	int V3_i = 50;
	const int &R3_i = V3_i;   // PASS()
	Msg_cstr.Format(_T("(int)V3_i:%d       (const int &)R3_i:%d"), V3_i, R3_i);
	MessageBox(Msg_cstr);

}


void CPointer_ReferenceDlg::OnBnClickedBtnPointer()
{
	//---- ����(pointer)���@���[��
	// 1. �����npointer to const�~����V�@��const����C
	// 2. pointer to const�i�ᤩ�@��nonconst�������}�C
	// 3. const pointer������ܩҫ�����C
	// reference: http://monkeycoding.com/?p=888

	//----- Initial ...
	CString    Msg_cstr = _T("");

	//--------------------------------

	/////-----------------------------------------------------------/////
	///// <<< const int���Ы��V const int�ܼ� >>> /////
	/////-----------------------------------------------------------/////
	const int V1_const_i = 38;
	const int *P1_const_Val_i_pr = &V1_const_i;  // PASS
	//int *P2_i_pr = &V1_const_i;          // compiler error, int���A������P2_i_pr������Vconst int���A��V1_const_i
	//*P1_const_Val_i_pr = 100;            // compiler error, �]��P1_const_Val_i_pr�ŧi��const int���A�����СA
									       // �ҥH�L�k�ܧ��ҫ��V���ƭ�
	Msg_cstr.Format(_T("(const int *)P1_i_pr:%d     (const int)V1_i:%d"), *P1_const_Val_i_pr, V1_const_i);
	MessageBox(Msg_cstr);


	/////-----------------------------------------------------------/////
	///// <<< const int���Ы��V int�ܼ� >>> /////
	/////-----------------------------------------------------------/////
	int  V3_i = 30;
	const int *P3_const_Val_i_pr = &V3_i;  // PASS, ������z�LP3_const_Val_i_pr�h�ק�V3_i���ƭȡA�_�h�|�ɭP���~
	//*P3_const_Val_i_pr = 50;             // compiler error, �]��P3_const_Val_i_pr�ŧi��const int���A�����СA
										   // �ҥH�L�k�ܧ�ҫ��V���ƭ�
	Msg_cstr.Format(_T("(const int *)P3_const_Val_i_pr:%d      (int)V3_i:%d"), *P3_const_Val_i_pr, V3_i);
	MessageBox(Msg_cstr);


	/////-----------------------------------------------------------/////
	///// <<< int const���Ы��V int�ܼ� >>> /////
	/////-----------------------------------------------------------/////
	int  V4_i = 40;
	int  V5_i = 50;
	int *const P4_const_Addr_i_pr = &V4_i; // PASS
	//P4_const_Addr_i_pr = &V5_i;          // compiler error, �]��P4_const_Addr_i_pr�O�ŧi��const���A���СA
										   // ������ܦ�}
	//P4_const_Addr_i_pr++;                // compiler error�A��]�P�W

	Msg_cstr.Format(_T("Before assign pointer new value >>> (int *const)P4_const_Addr_i_pr:%d      (int)V4_i:%d"), *P4_const_Addr_i_pr, V4_i);
	MessageBox(Msg_cstr);
	*P4_const_Addr_i_pr = V5_i;
	Msg_cstr.Format(_T("After assign pointer new value >>> (int *const)P4_const_Addr_i_pr:%d      (int)V4_i:%d"), *P4_const_Addr_i_pr, V4_i);
	MessageBox(Msg_cstr);


	/////-----------------------------------------------------------/////
	///// <<< int ���Ы��V const int�ܼ� >>> /////
	/////-----------------------------------------------------------/////
	const int V6_const_i = 60;
	int *V6_i_pr = NULL;
	//V6_i_pr = &V6_const_i;               // compiler error, int���A�����еL�k���Vconst int���A���ܼ�
										   // �i�H�z�Ѭ��]��V6_const_i���`���ܼơA�]�N�O�L�k����ȡA�p�G��int���A�����Хh���V���A
										   // ���N�N��i�H�ǥ�V6_i_pr�h����ƭȡA�H�ϭ쥻�ŧi���`���ܼƪ���J

}
//-----------------------------------------------------------------------------------------------