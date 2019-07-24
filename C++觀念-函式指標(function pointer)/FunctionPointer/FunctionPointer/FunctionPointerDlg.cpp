
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
	// <<函式指標(Pointer to function)的概念>>
	// 函式本身在記憶體中也佔有一個空間，而函式名稱本身也就是 "指向該空間位址的參考名稱" ，
	// 當 "呼叫函式名稱時，程式就會去執行該函式名稱所指向的記憶體空間中之指令" 。
	// 一個函式型態由傳回值型態與參數列決定，不包括函式名稱，
	// 一個 "函式指標可指向" 具有相同型態的函式，也就是具有 "相同傳回值型態和參數列" 的函式。
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
	// 函式指標(function pointer)應用在矩陣排列上
	// 函式名稱本身也就是 "指向該空間位址的參考名稱" ，
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

	//-- 成員函式指標(Point to class member function)的觀念
	// 說明: 要宣告一個成員函式指標與單純的宣告函式指標是類似的，所不同的是你要指定哪一個類別的函式，
	//       為了取得一個成員函式的位址值，你可以使用 & 取址運算子並指名是哪個類別的哪個成員函式
	//       成員函式在記憶體中只會存在一份，再調用成員函式時，具體要配合實際的物件地址，
	//       物件地址會是this指標指向的位址，所以 "透過物件" 調用成員函式

	// reference: https://openhome.cc/Gossip/CppGossip/MemberFunctionPtr.html
	// reference: https://ppt.cc/f8kjNx

	Math_CS   Math_cs;
	int(Math_CS::*MULTIPLY_FN_ptr)(int, int);

	MULTIPLY_FN_ptr = &Math_CS::Multiply_Fn;  //類別的成員函式指標(等號右邊一定要加上&)
	Result_fn3_ptr_i = (Math_cs.*MULTIPLY_FN_ptr)(TempA_i, TempB_i); //一定要透過物件來取用成員函式指標
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

	//-- 靜態類別成員指標(Pointer to class static member)的觀念
	// 說明: 成員函式指標不可以用來存取靜態類別成員函式，對於靜態類別成員，其指標宣告方式與一般指標宣告方式是類似的，

	// refernce: https://openhome.cc/Gossip/CppGossip/PointerToStaticMember.html

	double    *PI_d_ptr = NULL;
	double(*GET_PI_VALUE_FN)() = 0; // 宣告靜態成員函式指標(注意寫法，和一般函式指標一樣，但前方不用加寫類別名稱::)

	PI_d_ptr = &Math_CS::PI;
	GET_PI_VALUE_FN = &Math_CS::Get_PI_Value_Fn;
	Result_d = GET_PI_VALUE_FN();   // 呼叫類別靜態成員函式指標，與一般函式指標用法相同

	Msg_cstr.Format(_T("Math::PI=%f, Math::Get_PI_Value_Fn(%x):%f"), *PI_d_ptr, GET_PI_VALUE_FN, Result_d);
	MessageBox(Msg_cstr);
}
//-------------------------------------------------------------------------------