
// FunctionPointerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FunctionPointer.h"
#include "FunctionPointerDlg.h"
#include "afxdialogex.h"
#include "DataDefine.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


int(*ADD_FN_Ptr)(int, int);
int(*ADD_FN2_Ptr)(int, int, int);
bool(*SORT_BIG_FN)(int, int);
bool(*SORT_SMALL_FN)(int, int);


int Add_Fn(int A_i, int B_i)
{
	return (A_i + B_i);
}

int Add_Fn(int A_i, int B_i, int C_i)
{
	return (A_i + B_i + C_i);
}

bool Sort_Big_Fn(int A_i, int B_i)
{
	return (A_i > B_i);
}

bool Sort_Small_Fn(int A_i, int B_i)
{
	return (A_i < B_i);
}

void Swap_Fn(int &A_i, int &B_i)
{
	int   Temp_i = 0;
	
	Temp_i = A_i;
	A_i = B_i;
	B_i = Temp_i;
}

void Swap_ArrayNum_Fn(int *TempArray_i_ay_pr, int ArrayNum_i, bool(*SORT_METHOD_FN_PTR)(int, int));


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


// CFunctionPointerDlg dialog



CFunctionPointerDlg::CFunctionPointerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_FUNCTIONPOINTER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFunctionPointerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CFunctionPointerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_FUNC_PTR, &CFunctionPointerDlg::OnBnClickedBtnFuncPtr)
	ON_BN_CLICKED(IDC_BTN_FUNCPTR_ARRAYSORT, &CFunctionPointerDlg::OnBnClickedBtnFuncptrArraysort)
	ON_BN_CLICKED(IDC_BTN_MEMBER_FUNC_PTR, &CFunctionPointerDlg::OnBnClickedBtnMemberFuncPtr)
	ON_BN_CLICKED(IDC_BTN_STATIC_MEMBER_FUNC_PTR, &CFunctionPointerDlg::OnBnClickedBtnStaticMemberFuncPtr)
END_MESSAGE_MAP()


// CFunctionPointerDlg message handlers

BOOL CFunctionPointerDlg::OnInitDialog()
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

void CFunctionPointerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFunctionPointerDlg::OnPaint()
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
HCURSOR CFunctionPointerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
//-------------------------------------------------------------------------------
void CFunctionPointerDlg::OnBnClickedBtnFuncPtr()
{
	//----- Initial...
	CString    Msg_cstr = _T("");
	int        TempA_i = 10;
	int        TempB_i = 20;
	int        TempC_i = 30;
	int        Result_i = 0;
	int        Result_fn_ptr_i = 0;
	int        Result_fn2_ptr_i = 0;
	int        Result_fn3_ptr_i = 0;

	//--------------------------------------
	// <<�禡����(Pointer to function)������>>
	// �禡�����b�O���餤�]�����@�ӪŶ��A�Ө禡�W�٥����]�N�O "���V�ӪŶ���}���ѦҦW��" �A
	// �� "�I�s�禡�W�ٮɡA�{���N�|�h����Ө禡�W�٩ҫ��V���O����Ŷ��������O" �C
	// �@�Ө禡���A�ѶǦ^�ȫ��A�P�ѼƦC�M�w�A���]�A�禡�W�١A
	// �@�� "�禡���Хi���V" �㦳�ۦP���A���禡�A�]�N�O�㦳 "�ۦP�Ǧ^�ȫ��A�M�ѼƦC" ���禡�C
	// 
	// reference: https://openhome.cc/Gossip/CppGossip/FunctionPointer.html

	Result_i = Add_Fn(TempA_i, TempB_i);

	ADD_FN_Ptr = Add_Fn;
	Result_fn_ptr_i = ADD_FN_Ptr(TempA_i, TempB_i);

	ADD_FN2_Ptr = Add_Fn;
	Result_fn2_ptr_i = ADD_FN2_Ptr(TempA_i, TempB_i, TempC_i);

	//Msg_cstr.Format(_T("Add_Fn >>> (addr):%x;   %d+%d=%d"), Add_Fn, TempA_i, TempB_i, Result_i);
	//MessageBox(Msg_cstr);

	Msg_cstr.Format(_T("ADD_FN_ptr >>> (addr):%x;   %d+%d=%d"), ADD_FN_Ptr, TempA_i, TempB_i, Result_fn_ptr_i);
	MessageBox(Msg_cstr);

	Msg_cstr.Format(_T("ADD_FN2_ptr >>> (addr):%x;   %d+%d+%d=%d"), ADD_FN2_Ptr, TempA_i, TempB_i, TempC_i, Result_fn2_ptr_i);
	MessageBox(Msg_cstr);

}
//-------------------------------------------------------------------------------
void CFunctionPointerDlg::OnBnClickedBtnFuncptrArraysort()
{
	//----- Initial...
	CString    Msg_cstr = _T("");
	int        Array_i_ay[] = { 3,1,5,2,4 };

	//--------------------------------------
	// �禡����(function pointer)���Φb�x�}�ƦC�W
	// �禡�W�٥����]�N�O "���V�ӪŶ���}���ѦҦW��" �A
	//
	// reference: https://openhome.cc/Gossip/CppGossip/FunctionPointer.html

	SORT_BIG_FN = Sort_Big_Fn;
	SORT_SMALL_FN = Sort_Small_Fn;

	Msg_cstr.Format(_T("Original array: A[]={%d,%d,%d,%d,%d}"), Array_i_ay[0], Array_i_ay[1], Array_i_ay[2], Array_i_ay[3], Array_i_ay[4]);
	MessageBox(Msg_cstr);

	/////--> Sort array num (big->small)
	Swap_ArrayNum_Fn(Array_i_ay, sizeof(Array_i_ay) / sizeof(Array_i_ay[0]), SORT_SMALL_FN);
	Msg_cstr.Format(_T("Sorting array(big->small): A[]={%d,%d,%d,%d,%d}"), Array_i_ay[0], Array_i_ay[1], Array_i_ay[2], Array_i_ay[3], Array_i_ay[4]);
	MessageBox(Msg_cstr);


	/////--> Sort array num (small->big)
	Swap_ArrayNum_Fn(Array_i_ay, sizeof(Array_i_ay) / sizeof(Array_i_ay[0]), /*SORT_BIG_FN*/Sort_Big_Fn);
	Msg_cstr.Format(_T("Sorting array(small->big): A[]={%d,%d,%d,%d,%d}"), Array_i_ay[0], Array_i_ay[1], Array_i_ay[2], Array_i_ay[3], Array_i_ay[4]);
	MessageBox(Msg_cstr);
}
//-------------------------------------------------------------------------------
void Swap_ArrayNum_Fn(int *TempArray_i_ay_pr, int ArrayNum_i, bool(*SORT_METHOD_FN_PTR)(int, int))
{
	//------ Initial...
	//-----------------------------

	for (int i_i = 0; i_i < ArrayNum_i; i_i++)
	{
		for (int j_i = i_i + 1; j_i < ArrayNum_i; j_i++)
		{
			if (SORT_METHOD_FN_PTR(TempArray_i_ay_pr[i_i], TempArray_i_ay_pr[j_i]))
			{
				Swap_Fn(TempArray_i_ay_pr[i_i], TempArray_i_ay_pr[j_i]);
			}
		}
	}
}
//-------------------------------------------------------------------------------
void CFunctionPointerDlg::OnBnClickedBtnMemberFuncPtr()
{
	//----- Initial...
	int    TempA_i = 10;
	int    TempB_i = 20;
	int    Result_fn3_ptr_i = 0;
	CString Msg_cstr = _T("");
	//---------------------------

	//-- �����禡����(Point to class member function)���[��
	// ����: �n�ŧi�@�Ӧ����禡���лP��ª��ŧi�禡���ЬO�������A�Ҥ��P���O�A�n���w���@�����O���禡�A
	//       ���F���o�@�Ӧ����禡����}�ȡA�A�i�H�ϥ� & ���}�B��l�ë��W�O�������O�����Ӧ����禡
	//       �����禡�b�O���餤�u�|�s�b�@���A�A�եΦ����禡�ɡA����n�t�X��ڪ�����a�}�A
	//       ����a�}�|�Othis���Ы��V����}�A�ҥH "�z�L����" �եΦ����禡

	// reference: https://openhome.cc/Gossip/CppGossip/MemberFunctionPtr.html
	// reference: https://ppt.cc/f8kjNx

	Math_CS   Math_cs;
	int(Math_CS::*MULTIPLY_FN_ptr)(int, int);

	MULTIPLY_FN_ptr = &Math_CS::Multiply_Fn;  //���O�������禡����(�����k��@�w�n�[�W&)
	Result_fn3_ptr_i = (Math_cs.*MULTIPLY_FN_ptr)(TempA_i, TempB_i); //�@�w�n�z�L����Ө��Φ����禡����
	Msg_cstr.Format(_T("MULTIPLY_FN_ptr >>> (addr):%x;   %d*%d=%d"), MULTIPLY_FN_ptr, TempA_i, TempB_i, Result_fn3_ptr_i);
	MessageBox(Msg_cstr);
}
//-------------------------------------------------------------------------------
void CFunctionPointerDlg::OnBnClickedBtnStaticMemberFuncPtr()
{
	//----- Initial...
	CString   Msg_cstr = _T("");
	double    Result_d = 0;

	//-------------------------------------

	//-- �R�A���O��������(Pointer to class static member)���[��
	// ����: �����禡���Ф��i�H�ΨӦs���R�A���O�����禡�A����R�A���O�����A����Ыŧi�覡�P�@����Ыŧi�覡�O�������A

	// refernce: https://openhome.cc/Gossip/CppGossip/PointerToStaticMember.html

	double    *PI_d_ptr = NULL;
	double(*GET_PI_VALUE_FN)() = 0; // �ŧi�R�A�����禡����(�`�N�g�k�A�M�@��禡���Ф@�ˡA���e�褣�Υ[�g���O�W��::)

	PI_d_ptr = &Math_CS::PI;
	GET_PI_VALUE_FN = &Math_CS::Get_PI_Value_Fn;
	Result_d = GET_PI_VALUE_FN();   // �I�s���O�R�A�����禡���СA�P�@��禡���ХΪk�ۦP

	Msg_cstr.Format(_T("Math::PI=%f, Math::Get_PI_Value_Fn(%x):%f"), *PI_d_ptr, GET_PI_VALUE_FN, Result_d);
	MessageBox(Msg_cstr);
}
//-------------------------------------------------------------------------------