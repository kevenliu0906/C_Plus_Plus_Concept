
// Pass2DArrayDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Pass2DArray.h"
#include "Pass2DArrayDlg.h"
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


// CPass2DArrayDlg dialog



CPass2DArrayDlg::CPass2DArrayDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PASS2DARRAY_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPass2DArrayDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CPass2DArrayDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_PASS_2D_ARRAY, &CPass2DArrayDlg::OnBnClickedBtnPass2dArray)
	ON_BN_CLICKED(IDC_BTN_PTR_ERROR, &CPass2DArrayDlg::OnBnClickedBtnPtrError)
	ON_BN_CLICKED(IDC_BTN_PTR_CONSTANT_STRING, &CPass2DArrayDlg::OnBnClickedBtnPtrConstantString)
	ON_BN_CLICKED(IDC_BTN_STRCAT_ERROR, &CPass2DArrayDlg::OnBnClickedBtnStrcatError)
	ON_BN_CLICKED(IDC_BTN_PASS_POINTER_ARRAY, &CPass2DArrayDlg::OnBnClickedBtnPassPointerArray)
	ON_BN_CLICKED(IDC_BTN_PASS2D_PTR_ARRAY, &CPass2DArrayDlg::OnBnClickedBtnPass2dPtrArray)
	ON_BN_CLICKED(IDC_BTN_PASS_1D_ARRAY, &CPass2DArrayDlg::OnBnClickedBtnPass1dArray)
END_MESSAGE_MAP()


// CPass2DArrayDlg message handlers

BOOL CPass2DArrayDlg::OnInitDialog()
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

void CPass2DArrayDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPass2DArrayDlg::OnPaint()
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
HCURSOR CPass2DArrayDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
//----------------------------------------------------------------------------------------
void CPass2DArrayDlg::OnBnClickedBtnPass2dArray()
{
	//----- Initial ...
	CString     Msg_cstr = _T("");
	int Array_i_ay[2][3] = { {1,2,3},{4,5,6} };
	int RowCount_i = 0;
	int ColCount_i = 0;
	TestA_CS    TestA_cs;
	//----------------------------------

	//------ ���n�q�Q�G���}�C�i�H�� pointer to pointer �Ӷǻ�
	//-- reference: https://mikepmpliu80.pixnet.net/blog/category/1348531 �� No.7 item

	//-- �w�g���T�ŧi�FArray_i_ay�ܼƬO�@��2*3���G��int�}�C
	//-- �ҥH�i�H������X���h�֭�Row�MCol
	RowCount_i = sizeof(Array_i_ay) / sizeof(Array_i_ay[0]);
	ColCount_i = sizeof(Array_i_ay[0]) / sizeof(Array_i_ay[0][0]);

	Msg_cstr.Format(_T("(Original) Array_i_ay[%d][%d]={%d,%d,%d,%d,%d,%d}"), RowCount_i, ColCount_i, Array_i_ay[0][0], Array_i_ay[0][1], Array_i_ay[0][2], Array_i_ay[1][0], Array_i_ay[1][1], Array_i_ay[1][2]);
	MessageBox(Msg_cstr);

	//TestA_cs.Pass2DArray_Fn(Array_i_ay);       // compiler error,�ǤJ�G���}�C����γo�Ө禡�ŧi�覡
	TestA_cs.Pass2DArray_Correct_Fn(Array_i_ay); // compiler pass, �ǤJ�G���}�C���T����ܫŧi�覡

}
//----------------------------------------------------------------------------------------
void CPass2DArrayDlg::OnBnClickedBtnPtrError()
{
	//------ Initial...
	//char *P1_c_ptr;    //�|������l�ȡA�������V���
	char      *P2_c_ptr = NULL;
	char      Var_c = 'c';
	CString   Msg_cstr = _T("");

	//----------------------------------------

	//------ ���i�H�����������V��誺����
	// ����: �����ܼƥ��������V�Y�ӥi�H�X�k�ާ@���Ŷ��A�~��i��ާ@
	// reference: https://mikepmpliu80.pixnet.net/blog/category/1348531 �� No.1 item

	//*P1_c_ptr = 'a';    // compiler error, �N'a'�g�줣�����
	//*P2_c_ptr = 'c';    // execute error, �N'c'�g��"��}0"
	P2_c_ptr = &Var_c;
	Msg_cstr.Format(_T("Original >>>>> P2_c_ptr=%x , *P2_c_ptr = %c , Var_c:%c(%x)"), P2_c_ptr, *P2_c_ptr, Var_c, &Var_c);
	MessageBox(Msg_cstr);
	*P2_c_ptr = 'd';      // �NVar_c�����e�ܬ�'d'
	Msg_cstr.Format(_T("After changed by pointer >>>>> P1_c_ptr=%x , *P2_c_ptr = %c , Var_c:%c(%x)"), P2_c_ptr, *P2_c_ptr, Var_c, &Var_c);
	MessageBox(Msg_cstr);
}
//----------------------------------------------------------------------------------------
void CPass2DArrayDlg::OnBnClickedBtnPtrConstantString()
{
	//------- Initial...
	TCHAR    *Constant_tc_ptr = _T("abcde");  // Constant_tc_ptr�{�b���V�@�Ӧr��`��
	TCHAR    Const_tc_ay[] = _T("xyz");
	CString  Msg_cstr = _T("");

	//---------------------------------

	//----- ���n�չϥΫ��Хh���@�Ӧr��`��
	// ����: "�r��`��" �����e�O "��Ū" ���A���ϥ��v���S����諸�v�Q�A
	//       �Y�Ʊ�ϥΥi�H��諸�r��A���N���b�X�k�Ŷ�
	// reference: https://mikepmpliu80.pixnet.net/blog/category/1348531 �� No.2 item


	/////--> <<���ЯS��>>
	Msg_cstr.Format(_T("pointer to string(before): %s"), Constant_tc_ptr);
	MessageBox(Msg_cstr);
	
	//*Constant_tc_ptr = 'j';      // execute error, pointer�S���v�O�h���r��`��
	Constant_tc_ptr = _T("123");   // PASS, pointer was changed to point other const string
	
	Msg_cstr.Format(_T("pointer to string(after point to other const string): %s"), Constant_tc_ptr);
	MessageBox(Msg_cstr);


	///////// �p�G�n���A�Х� "�}�C�ܼ�" ���N "�����ܼ�" �Ӱ�����Ȫ�����

	/////--> <<�}�C�S��>>
	Msg_cstr.Format(_T("array to string(before): %s"), Const_tc_ay);
	MessageBox(Msg_cstr);
	
	//Const_tc_ay = _T("123");   // compiler error, can not assign the const string to array
	Const_tc_ay[1] = 'j';          // PASS, change the array value
	Msg_cstr.Format(_T("array to string(after assign value to change the array): %s"), Const_tc_ay);
	MessageBox(Msg_cstr);
	_tcscpy_s(Const_tc_ay, _T("12"));
	Msg_cstr.Format(_T("array to string(after copy string to change the array): %s"), Const_tc_ay);
	MessageBox(Msg_cstr);
	
}
//----------------------------------------------------------------------------------------
void CPass2DArrayDlg::OnBnClickedBtnStrcatError()
{
	//------ Initial ...
	char  *string1_c_ptr = "abc";
	char  *string2_c_ptr = "12345";

	char  string3_c_ay[50] = "abc";
	char  *string4_c_ptr = "12345";
	CString Msg_cstr = _T("");
	CString temp3_cstr(string3_c_ay);
	CString temp4_cstr(string4_c_ptr);
	
	//--------------------------------------------
	//--- strcat()���|�t�~�t�m�O����Ŷ��A�u�N��ƪ��[��s1�ҫ���Ū�r�ꪺ�᭱�A�|�g�J��{���L�v�IĲ���O����Ŷ�
	// reference: https://mikepmpliu80.pixnet.net/blog/category/1348531 �� No.2 item

	//strcat_s(string1_c_ptr, string2_c_ptr); // execute error, strcat()���|�t�~�t�m�O����Ŷ�
	strcat_s(string3_c_ay, string4_c_ptr);
	CString NewString_cstr(string3_c_ay);

	Msg_cstr.Format(_T("string3:%s, string4:%s"), temp3_cstr, temp4_cstr);
	MessageBox(Msg_cstr);

	Msg_cstr.Format(_T("After strcat >>>>>  %s"), NewString_cstr);
	MessageBox(Msg_cstr);

}
//----------------------------------------------------------------------------------------
void CPass2DArrayDlg::OnBnClickedBtnPassPointerArray()
{
	//----- �ǻ�pointer array��t�@��function
	//

	//----- Initial ...
	CString     Msg_cstr = _T("");
	TestA_CS    TestA_cs;
	int         ArraySize_i = 0;

	//---------------------------------------

	int    Value_A_i = 10;
	int    Value_B_i = 20;
	int    Value_C_i = 30;

	int   *A_i_pr = /*&Value_A_i*/new int(10);
	int   *B_i_pr = /*&Value_B_i*/new int(20);
	int   *C_i_pr = /*&Value_C_i*/new int(30);

	int   *Array_i_pr_ay[3] = { A_i_pr, B_i_pr, C_i_pr };
	ArraySize_i = sizeof(Array_i_pr_ay)/sizeof(Array_i_pr_ay[0]);

	Msg_cstr.Format(_T("(Original) tempArray_i_pr_ay[%d]={(%x):%d, (%x):%d, (%x):%d}"), ArraySize_i, Array_i_pr_ay[0], *Array_i_pr_ay[0],
																									 Array_i_pr_ay[1], *Array_i_pr_ay[1],
																									 Array_i_pr_ay[2], *Array_i_pr_ay[2]);
	MessageBox(Msg_cstr);

	TestA_cs.PassArrayWithPointer_ByPtr_Fn(Array_i_pr_ay);

	TestA_cs.PassArrayWithPointer_ByRef_Fn(Array_i_pr_ay);

	TestA_cs.PassArrayWithPointer_Fn(Array_i_pr_ay);

	delete A_i_pr;
	delete B_i_pr;
	delete C_i_pr;
}
//----------------------------------------------------------------------------------------
void CPass2DArrayDlg::OnBnClickedBtnPass2dPtrArray()
{
	//------ Initial...
	CString    Msg_cstr = _T("");
	int        Array_i_ay[][3] = { {1,2,3}, {4,5,6} };
	int        *Array_i_ptr_ay[2][3] = { NULL , NULL };
	int        Row_i = sizeof(Array_i_ay) / sizeof(Array_i_ay[0]);
	int        Col_i = sizeof(Array_i_ay[0]) / sizeof(Array_i_ay[0][0]);
	TestA_CS   TestA_cs;

	//--------------------------------
	for (int i_i = 0; i_i < Row_i; i_i++)
	{
		for (int j_i = 0; j_i < Col_i; j_i++)
		{
			Array_i_ptr_ay[i_i][j_i] = &Array_i_ay[i_i][j_i];
		}
	}

	Msg_cstr.Format(_T("(Original) Array_i_ptr_ay[%d][%d]={%x(%d),%x(%d),%x(%d),%x(%d),%x(%d),%x(%d)}"), Row_i, Col_i, 
		Array_i_ptr_ay[0][0], *Array_i_ptr_ay[0][0], Array_i_ptr_ay[0][1], *Array_i_ptr_ay[0][1], Array_i_ptr_ay[0][2], *Array_i_ptr_ay[0][2],
		Array_i_ptr_ay[1][0], *Array_i_ptr_ay[1][0], Array_i_ptr_ay[1][1], *Array_i_ptr_ay[1][1], Array_i_ptr_ay[1][2], *Array_i_ptr_ay[1][2]);
	MessageBox(Msg_cstr);

	TestA_cs.Pass2DIntPtrArray_Fn(Array_i_ptr_ay);

}
//----------------------------------------------------------------------------------------
void CPass2DArrayDlg::OnBnClickedBtnPass1dArray()
{
	//----- Initial...
	int       Array_i_ay[] = { 1,2,3,4,5 };
	CString   Msg_cstr = _T("");
	TestA_CS  TestA_cs;
	int       ArraySize_i = 0;
	//---------------------------------------

	ArraySize_i = sizeof(Array_i_ay) / sizeof(Array_i_ay[0]);
	Msg_cstr.Format(_T("(Original) Array_i_ay[%d]={%d,%d,%d,%d,%d}"), ArraySize_i, Array_i_ay[0], Array_i_ay[1], Array_i_ay[2], Array_i_ay[3], Array_i_ay[4]);
	MessageBox(Msg_cstr);
	
	TestA_cs.Pass1DArray_ByPtr_Fn(Array_i_ay);

	TestA_cs.Pass1DArray_ByRef_Fn(Array_i_ay);

	TestA_cs.Pass1DArray_Fn(Array_i_ay);
}
//----------------------------------------------------------------------------------------