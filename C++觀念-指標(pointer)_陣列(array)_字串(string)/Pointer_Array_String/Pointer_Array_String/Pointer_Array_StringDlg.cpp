
// Pointer_Array_StringDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Pointer_Array_String.h"
#include "Pointer_Array_StringDlg.h"
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


// CPointer_Array_StringDlg dialog



CPointer_Array_StringDlg::CPointer_Array_StringDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_POINTER_ARRAY_STRING_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPointer_Array_StringDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CPointer_Array_StringDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_POINTER_ARRAY_STRING, &CPointer_Array_StringDlg::OnBnClickedBtnPointerArrayString)
	ON_BN_CLICKED(IDC_BTN_ARRAY_WITH_POINTER, &CPointer_Array_StringDlg::OnBnClickedBtnArrayWithPointer)
	ON_BN_CLICKED(IDC_BTN_CHARARRAY_DIFFERENT_CHARPOINTERARRAY, &CPointer_Array_StringDlg::OnBnClickedBtnChararrayDifferentCharpointerarray)
END_MESSAGE_MAP()


// CPointer_Array_StringDlg message handlers

BOOL CPointer_Array_StringDlg::OnInitDialog()
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

void CPointer_Array_StringDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPointer_Array_StringDlg::OnPaint()
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
HCURSOR CPointer_Array_StringDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPointer_Array_StringDlg::OnBnClickedBtnPointerArrayString()
{
	//------- Initial...
	TCHAR    *Constant_tc_ptr = _T("abcde");  // Constant_tc_ptr現在指向一個字串常數
	TCHAR    Const_tc_ay[] = _T("xyz");
	CString  Msg_cstr = _T("");

	//---------------------------------

	//----- 不要試圖用指標去更改一個字串常數
	// 說明: 字串常數的內容是 "唯讀" 的，有使用權但沒有更改的權利，
	//       若希望使用可以更改的字串，須將其放在合法空間
	// reference: https://mikepmpliu80.pixnet.net/blog/category/1348531 的 No.2 item


	/////--> <<指標特性>>
	Msg_cstr.Format(_T("pointer to string(before): %s"), Constant_tc_ptr);
	MessageBox(Msg_cstr);

	//*Constant_tc_ptr = 'j';      // execute error, pointer沒有權力去更改 "字串常數"
	Constant_tc_ptr = _T("123");   // PASS, pointer was changed to point other const string

	Msg_cstr.Format(_T("pointer to string(after point to other const string): %s"), Constant_tc_ptr);
	MessageBox(Msg_cstr);

	/////////
	///////// 如果要更改，請用 "陣列變數" 取代 "指標變數" 來做更改其值的部分
	/////////

	/////--> <<陣列特性>>
	Msg_cstr.Format(_T("array to string(before): %s"), Const_tc_ay);
	MessageBox(Msg_cstr);

	//Const_tc_ay = _T("123");   // compiler error, "陣列名稱" 無法直接指向其他字串常數
	*Const_tc_ay = 'j';          // PASS, change the array value
	Msg_cstr.Format(_T("array to string(after change the array value): %s"), Const_tc_ay);
	MessageBox(Msg_cstr);
}


void CPointer_Array_StringDlg::OnBnClickedBtnArrayWithPointer()
{
	//------ Initial...
	CString    Msg_cstr = _T("");
	CString    Data_cstr = _T("");
	CString    TempData_cstr = _T("");
	TCHAR      *ArrayWithPointer_tc_ptr_ay[] = { _T("Teacher"), _T("Student"), _T("Dog"), _T("Professor"), _T("School") };
	TCHAR      *StudentInfo_tc_ptr_ay[][2] = { {_T("Student: "), _T("Jerry")}, {_T("Major: "), _T("Science")}, {_T("ID: "), _T("9001210001")} };
	int        ArraySize_i = 0;
	int        Array_Info_Count_i = 0;
	int        Array_Student_Count_i = 0;

	//--------------------------------

	// 宣告指標陣列，可以更方便的處理字串陣列
	// ArrayWithPointer_tc_ptr_ay中的每個元素都是字元指標，也各自指向一個字串常數。
	// 進一步擴充這個概念，就可以使用二維以上的字串陣列，例如 StudentInfo_tc_ptr_ay
	// reference: https://openhome.cc/Gossip/CppGossip/PointerAndString.html

	/////--> 一維的字元指標陣列
	ArraySize_i = sizeof(ArrayWithPointer_tc_ptr_ay) / sizeof(ArrayWithPointer_tc_ptr_ay[0]);
	Msg_cstr = _T("The ArrayWithPointer are:");
	
	for (int i_i = 0; i_i < ArraySize_i; i_i++)
	{
		if (i_i != ArraySize_i - 1)
			Data_cstr.Format(_T("%s,"), ArrayWithPointer_tc_ptr_ay[i_i]);
		else
			Data_cstr.Format(_T("%s"), ArrayWithPointer_tc_ptr_ay[i_i]);
		Msg_cstr = Msg_cstr + Data_cstr;
	}

	MessageBox(Msg_cstr);


	/////--> 二維的字元指標陣列
	Array_Info_Count_i = sizeof(StudentInfo_tc_ptr_ay) / sizeof(StudentInfo_tc_ptr_ay[0]);
	Array_Student_Count_i = sizeof(StudentInfo_tc_ptr_ay[0]) / sizeof(StudentInfo_tc_ptr_ay[0][0]);
	Msg_cstr = _T("");
	Data_cstr = _T("");


	for (int i_i = 0; i_i < Array_Info_Count_i; i_i++)
	{
		Data_cstr = _T("");
		for (int j_i = 0; j_i < Array_Student_Count_i; j_i++)
		{
			if (j_i == 0)
				TempData_cstr.Format(_T("%-12s"), StudentInfo_tc_ptr_ay[i_i][j_i]);
			else if (j_i == Array_Student_Count_i - 1)
				TempData_cstr.Format(_T("%s;"), StudentInfo_tc_ptr_ay[i_i][j_i]);
			else
				TempData_cstr.Format(_T("%s"), StudentInfo_tc_ptr_ay[i_i][j_i]);

			/*if (j_i != Array_Student_Count_i - 1)
				TempData_cstr.Format(_T("%s"), StudentInfo_tc_ptr_ay[i_i][j_i]);
			else
				TempData_cstr.Format(_T("%s;"), StudentInfo_tc_ptr_ay[i_i][j_i]);*/

			Data_cstr = Data_cstr + TempData_cstr;
		}

		Msg_cstr = Msg_cstr + Data_cstr;
		if (i_i != Array_Info_Count_i - 1)
			Msg_cstr = Msg_cstr + _T("\n");
	}
	MessageBox(Msg_cstr);
}


void CPointer_Array_StringDlg::OnBnClickedBtnChararrayDifferentCharpointerarray()
{
	//------ Initial...
	CString    Msg_cstr = _T("");
	CString    Data_cstr = _T("");
	TCHAR      *str1[] = { _T("professor"), _T("Justin"), _T("etc.") };
	TCHAR      str2[3][10] = { _T("professor"), _T("Justin"), _T("etc.") };
	int        Size_i = 0;
	//-----------------------------------------

	// 上列兩個宣告的作用雖然類似，但其實意義不同。
	
	// str1是指標陣列，每一個元素都是指標，指向一個字串常數，
	// 只要另外指定字串常數給某給元素，該元素指向的記憶體位址就不同了

	// str2是宣告3*10的字元陣列空間，連續配置30個記憶體空間，字串是直接儲存在這個空間，
	// 每個字串的位址是固定的，而使用的空間也是固定的(也就是含空字元會是10個字元)

	// reference: https://openhome.cc/Gossip/CppGossip/PointerAndString.html


	//////--> 指標陣列的範例，另外指定字串常數給其中一個元素後，其記憶體的位址就不同了
	{
		Size_i = sizeof(str1) / sizeof(str1[0]);
		Msg_cstr = _T("Before re-sign the constant string to element(char* 1D-array)\n");
		for (int i_i = 0; i_i < Size_i; i_i++)
		{
			Data_cstr.Format(_T("%s(%x),"), str1[i_i], str1[i_i]);
			Msg_cstr = Msg_cstr + Data_cstr;
		}
		MessageBox(Msg_cstr);

		Msg_cstr = _T("After re-sign the constant string to element(char* 1D-array)\n");
		str1[0] = _T("good-student");  // execute pass, 由於是宣告成指標陣列來儲存字串，所以不會有長度的限制
		for (int i_i = 0; i_i < Size_i; i_i++)
		{
			Data_cstr.Format(_T("%s(%x),"), str1[i_i], str1[i_i]);
			Msg_cstr = Msg_cstr + Data_cstr;
		}
		MessageBox(Msg_cstr);
	}

	//////--> 二維字元陣列的範例，另外指定字串常數給其中一個列後，其記憶體的位址仍然相同
	{
		int CharCount_i = 0;
		Size_i = sizeof(str2) / sizeof(str2[0]);
		CharCount_i = sizeof(str2[0]) / sizeof(str2[0][0]);

		Msg_cstr = _T("Before re-sign the constant string to row(char 2D-array)\n");
		for (int i_i = 0; i_i < Size_i; i_i++)
		{
			Data_cstr.Format(_T("%s(%x),"), str2[i_i], str2[i_i]);
			Msg_cstr = Msg_cstr + Data_cstr;
		}
		MessageBox(Msg_cstr);

		Msg_cstr = _T("After re-sign the constant string to row(char 2D-array)\n");
		//_tcscpy_s(str2[0], _T("good-student")); // execute error, 所以字串長度超過宣告字元陣列的長度數值(超過10個字元數)
		_tcscpy_s(str2[0], _T("student"));
		for (int i_i = 0; i_i < Size_i; i_i++)
		{
			Data_cstr.Format(_T("%s(%x),"), str2[i_i], str2[i_i]);
			Msg_cstr = Msg_cstr + Data_cstr;
		}
		MessageBox(Msg_cstr);
	}
}
