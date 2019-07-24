
// ArrayDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Array.h"
#include "ArrayDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define     Array_Size_i_de           5

int    OutArray_i_ay[Array_Size_i_de];


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


// CArrayDlg dialog



CArrayDlg::CArrayDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ARRAY_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CArrayDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CArrayDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_STATIC_ARRAY_DECLARE, &CArrayDlg::OnBnClickedBtnStaticArrayDeclare)
	ON_BN_CLICKED(IDC_BTN_DYNAMIC_ARRAY_DECLARE, &CArrayDlg::OnBnClickedBtnDynamicArrayDeclare)
	ON_BN_CLICKED(IDC_BTN_DYNAMIC_2D_ARRAY_DECLARE, &CArrayDlg::OnBnClickedBtnDynamic2dArrayDeclare)
END_MESSAGE_MAP()


// CArrayDlg message handlers

BOOL CArrayDlg::OnInitDialog()
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

void CArrayDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CArrayDlg::OnPaint()
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
HCURSOR CArrayDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CArrayDlg::OnBnClickedBtnStaticArrayDeclare()
{
	/////----- �����@�ǰ}�C(Array)�����[��
	// ���ެO "�R�A�}�C" �άO "�ʺA�}�C" ���ŧi�覡�A��Ҥ��t�쪺�O����Ŷ����O�s��

	// �U���O "�R�A�}�C" ���ŧi�覡�A�R�A�}�C���ץ����ƥ��T�w�A���i�H�ϥ��ܼƨӨƫ�M�w�}�C����
	// reference: http://monkeycoding.com/?p=908 �� No.2

	// �w�q��禡�D��~�����ث��Oarray�����|�Q��l�Ƭ�0�A�w�q��禡�D�餺�����ث��Oarray�������|�Q��l��
	// reference: http://monkeycoding.com/?p=908 �� No.4

	//----- Initial...
	CString     Msg_cstr = _T("");
	int         Array1_i_ay[5];                  // PASS
	const int   ArraySize_con_i = 10;
	int         Array2_i_ay[ArraySize_con_i];     // PASS(�i�H�α`���ܼƨӫŧi�}�C)
	int         Size_i = 10;
	//int         Array3_i_ay[Size_i];              // compiler error, ���i�Τ@���ܼƨӫŧi�}�C
	int         Array4_i_ay[Array_Size_i_de];     // PASS(�i�H�α`�ƨӫŧi�}�C)
	//--------------------------

	Msg_cstr.Format(_T("Function inside array --> Array1_i_ay: {%d,%d,%d,%d,%d}"), Array1_i_ay[0], Array1_i_ay[1], Array1_i_ay[2], Array1_i_ay[3], Array1_i_ay[4]);
	MessageBox(Msg_cstr);

	Msg_cstr.Format(_T("Function outside array --> OutArray_i_ay: {%d,%d,%d,%d,%d}"), OutArray_i_ay[0], OutArray_i_ay[1], OutArray_i_ay[2], OutArray_i_ay[3], OutArray_i_ay[4]);
	MessageBox(Msg_cstr);
}


void CArrayDlg::OnBnClickedBtnDynamicArrayDeclare()
{
	/////----- �����@�ǰ}�C(Array)�����[��
	// ���ެO "�R�A�}�C" �άO "�ʺA�}�C" ���ŧi�覡�A��Ҥ��t�쪺�O����Ŷ����O�s��

	// �U���O "�ʺA�}�C" ���ŧi�覡�A�H�U��ر��p�U�A�����ϥΰʺA���覡�Ӱt�m�O����C
	// a. �����������A�~�ા�D�n���t�h�֪Ŷ����ܼơC
	// b. �ݭn�ܦh�O����(�i��O�j�q�n�p�⪺���)�A�ѩ��R�A�}�C���Ŷ��bstack�W�A�]���L�k���t�L��j�q���O����
	// �ʺA�}�C�ϥ�new�B��l�A��ܫ��A�H�Ωһݭn���Ŷ��A�öǦ^�ӪŶ�����}�A�{�������e�����ϥ�delete�N�Ŷ�
	// ����A�_�h�|���O���鬪�|�����D�C
	// reference: http://monkeycoding.com/?p=908 �� "�ʺA�t�marray"

	// �p�G�}�C����������class����ɡA�|��default���غc���Ӫ�l�ƨC�Ӥ����A�p�G�O���ث��O�h�������|��l��
	// reference: http://monkeycoding.com/?p=908 �� No.3

	//----- Initial...
	CString     Msg_cstr = _T("");
	int         *ptr = new int;     
	int         *ptr2 = new int[5];      //ptr2��5��int����l��(���|����0)
	CString     *psa = new CString[5];   //psa��5��CString���Ŧr��

	//--------------------------

	Msg_cstr.Format(_T("only declare int array ptr2: {%d,%d,%d,%d,%d}"), ptr2[0], ptr2[1], ptr2[2], ptr2[3], ptr2[4]);
	MessageBox(Msg_cstr);

	Msg_cstr.Format(_T("only declare CString array psa: {%s,%s,%s,%s,%s}"), psa[0], psa[1], psa[2], psa[3], psa[4]);
	MessageBox(Msg_cstr);

	delete (ptr);
	delete[] ptr2;
	delete[] psa;
}


void CArrayDlg::OnBnClickedBtnDynamic2dArrayDeclare()
{
	//----- Initial ...
	CString     Msg_cstr = _T("");
	int         Static_2D_Array_i_ay[][5] = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15} };
	int         Static_Array_Row_i = sizeof(Static_2D_Array_i_ay) / sizeof(Static_2D_Array_i_ay[0]);
	int         Static_Array_Col_i = sizeof(Static_2D_Array_i_ay[0]) / sizeof(Static_2D_Array_i_ay[0][0]);

	//---------------------------------------------
	
	///////------ �ʺA�ŧi�G���}�C
	// �H�U�Ҥl�O���t�m�@���}�C�A�B�C�Ӥ����Oint *���A
	// �M��A��C��int *���A���������V�@�ӰʺA�ŧi���@���}�C
	// reference: http://www.programmer-club.com.tw/ShowSameTitleN/c/33977.html

	Msg_cstr.Format(_T("(Static_int_Array): { {%d,%d,%d,%d,%d}, {%d,%d,%d,%d,%d}, {%d,%d,%d,%d,%d} }"),
		Static_2D_Array_i_ay[0][0], Static_2D_Array_i_ay[0][1], Static_2D_Array_i_ay[0][2], Static_2D_Array_i_ay[0][3], Static_2D_Array_i_ay[0][4],
		Static_2D_Array_i_ay[1][0], Static_2D_Array_i_ay[1][1], Static_2D_Array_i_ay[1][2], Static_2D_Array_i_ay[1][3], Static_2D_Array_i_ay[1][4],
		Static_2D_Array_i_ay[2][0], Static_2D_Array_i_ay[2][1], Static_2D_Array_i_ay[2][2], Static_2D_Array_i_ay[2][3], Static_2D_Array_i_ay[2][4]);
	MessageBox(Msg_cstr);

	/////--> �ʺA���ͤG���}�C(int���A)
	int     **Dync_2D_Array_i_ay_pr = new int*[Static_Array_Row_i]; //���ʺA�t�m�@���}�C�j�p��Row_i�B�C�Ӥ�����pointer to int *
	for (int i_i = 0; i_i < Static_Array_Row_i; i_i++)
	{
		Dync_2D_Array_i_ay_pr[i_i] = new int[Static_Array_Col_i];   //�A�N�C��pinter to int*�������V�@�Ӥ@���}�C
		memset(Dync_2D_Array_i_ay_pr[i_i], 0, sizeof(int)*Static_Array_Col_i); // �N�G���}�C���C�V�q(row)���V�ƭ�0
	}

	for (int i_i = 0; i_i < Static_Array_Row_i; i_i++)
	{
		for (int j_i = 0; j_i < Static_Array_Col_i; j_i++)
		{
			Dync_2D_Array_i_ay_pr[i_i][j_i] = Static_2D_Array_i_ay[i_i][j_i];
		}
	}
	Msg_cstr.Format(_T("(Dynamic_int_Array): { {%d,%d,%d,%d,%d}, {%d,%d,%d,%d,%d}, {%d,%d,%d,%d,%d} }"),
		Dync_2D_Array_i_ay_pr[0][0], Dync_2D_Array_i_ay_pr[0][1], Dync_2D_Array_i_ay_pr[0][2], Dync_2D_Array_i_ay_pr[0][3], Dync_2D_Array_i_ay_pr[0][4],
		Dync_2D_Array_i_ay_pr[1][0], Dync_2D_Array_i_ay_pr[1][1], Dync_2D_Array_i_ay_pr[1][2], Dync_2D_Array_i_ay_pr[1][3], Dync_2D_Array_i_ay_pr[1][4],
		Dync_2D_Array_i_ay_pr[2][0], Dync_2D_Array_i_ay_pr[2][1], Dync_2D_Array_i_ay_pr[2][2], Dync_2D_Array_i_ay_pr[2][3], Dync_2D_Array_i_ay_pr[2][4]);
	MessageBox(Msg_cstr);

	/////--> �R���ʺA���ͪ��G���}�C(int���A)
	for (int i_i = 0; i_i < Static_Array_Row_i; i_i++)
		delete[] Dync_2D_Array_i_ay_pr[i_i];  // ���N�C�@�Ӥ����ҫ��V�@���}�C���R��
	delete[] Dync_2D_Array_i_ay_pr;           // �A�R���������}�C


	///////////////////--------------------------------------------------
	///////////////////------------  CString���A���G���}�C
	///////////////////--------------------------------------------------


	/*LPTSTR*/CString     Static_2D_Array_cstr_ay[][3] = { { _T("John"), _T("Ken"), _T("Stephon") },{ _T("American"), _T("Chinese"), _T("Japan") } };
	Static_Array_Row_i = sizeof(Static_2D_Array_cstr_ay) / sizeof(Static_2D_Array_cstr_ay[0]);
	Static_Array_Col_i = sizeof(Static_2D_Array_cstr_ay[0]) / sizeof(Static_2D_Array_cstr_ay[0][0]);

	Msg_cstr.Format(_T("(Static_CString_Array): { {%s,%s,%s}, {%s,%s,%s} }"),
		Static_2D_Array_cstr_ay[0][0], Static_2D_Array_cstr_ay[0][1], Static_2D_Array_cstr_ay[0][2],
		Static_2D_Array_cstr_ay[1][0], Static_2D_Array_cstr_ay[1][1], Static_2D_Array_cstr_ay[1][2]);
	MessageBox(Msg_cstr);

	/////--> �ʺA���ͤG���}�C(CString���A)
	/*LPTSTR*/CString      **Dync_2D_Array_cstr_ay_pr = new /*LPTSTR*/CString*[Static_Array_Row_i]; //���ʺA�t�m�@���}�C�j�p��Row_i�B�C�Ӥ�����pointer to CString*
	for (int i_i = 0; i_i < Static_Array_Row_i; i_i++)
	{
		Dync_2D_Array_cstr_ay_pr[i_i] = new /*LPTSTR*/CString[Static_Array_Col_i];                  //�A�N�C��pinter to CString*�������V�@�Ӥ@���}�C
		//memset(Dync_2D_Array_cstr_ay_pr[i_i], 0, sizeof(LPTSTR/*CString*/)*Static_Array_Col_i);  // �N�G���}�C���C�V�q(row)���V�ƭ�0
	}

	for (int i_i = 0; i_i < Static_Array_Row_i; i_i++)
	{
		for (int j_i = 0; j_i < Static_Array_Col_i; j_i++)
		{
			Dync_2D_Array_cstr_ay_pr[i_i][j_i] = Static_2D_Array_cstr_ay[i_i][j_i];
		}
	}

	Msg_cstr.Format(_T("(Dynamic_CString_Array): { {%s,%s,%s}, {%s,%s,%s} }"),
		Dync_2D_Array_cstr_ay_pr[0][0], Dync_2D_Array_cstr_ay_pr[0][1], Dync_2D_Array_cstr_ay_pr[0][2],
		Dync_2D_Array_cstr_ay_pr[1][0], Dync_2D_Array_cstr_ay_pr[1][1], Dync_2D_Array_cstr_ay_pr[1][2]);
	MessageBox(Msg_cstr);

	/////--> �R���ʺA���ͪ��G���}�C(CString���A)
	for (int i_i = 0; i_i < Static_Array_Row_i; i_i++)
		delete[] Dync_2D_Array_cstr_ay_pr[i_i];  // ���N�C�@�Ӥ����ҫ��V�@���}�C���R��
	delete[] Dync_2D_Array_cstr_ay_pr;           // �A�R���������}�C
}
