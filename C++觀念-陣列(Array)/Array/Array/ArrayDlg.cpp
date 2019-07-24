
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
	/////----- 紀錄一些陣列(Array)的基本觀念
	// 不管是 "靜態陣列" 或是 "動態陣列" 的宣告方式，其所分配到的記憶體空間都是連續的

	// 下面是 "靜態陣列" 的宣告方式，靜態陣列長度必須事先固定，不可以使用變數來事後決定陣列長度
	// reference: http://monkeycoding.com/?p=908 的 No.2

	// 定義於函式主體外的內建型別array元素會被初始化為0，定義於函式主體內的內建型別array元素不會被初始化
	// reference: http://monkeycoding.com/?p=908 的 No.4

	//----- Initial...
	CString     Msg_cstr = _T("");
	int         Array1_i_ay[5];                  // PASS
	const int   ArraySize_con_i = 10;
	int         Array2_i_ay[ArraySize_con_i];     // PASS(可以用常數變數來宣告陣列)
	int         Size_i = 10;
	//int         Array3_i_ay[Size_i];              // compiler error, 不可用一般變數來宣告陣列
	int         Array4_i_ay[Array_Size_i_de];     // PASS(可以用常數來宣告陣列)
	//--------------------------

	Msg_cstr.Format(_T("Function inside array --> Array1_i_ay: {%d,%d,%d,%d,%d}"), Array1_i_ay[0], Array1_i_ay[1], Array1_i_ay[2], Array1_i_ay[3], Array1_i_ay[4]);
	MessageBox(Msg_cstr);

	Msg_cstr.Format(_T("Function outside array --> OutArray_i_ay: {%d,%d,%d,%d,%d}"), OutArray_i_ay[0], OutArray_i_ay[1], OutArray_i_ay[2], OutArray_i_ay[3], OutArray_i_ay[4]);
	MessageBox(Msg_cstr);
}


void CArrayDlg::OnBnClickedBtnDynamicArrayDeclare()
{
	/////----- 紀錄一些陣列(Array)的基本觀念
	// 不管是 "靜態陣列" 或是 "動態陣列" 的宣告方式，其所分配到的記憶體空間都是連續的

	// 下面是 "動態陣列" 的宣告方式，以下兩種情況下，必須使用動態的方式來配置記憶體。
	// a. 必須到執行期，才能知道要分配多少空間給變數。
	// b. 需要很多記憶體(可能是大量要計算的資料)，由於靜態陣列的空間在stack上，因此無法分配過於大量的記憶體
	// 動態陣列使用new運算子，選擇型態以及所需要的空間，並傳回該空間的位址，程式結束前必須使用delete將空間
	// 釋放，否則會有記憶體洩漏的問題。
	// reference: http://monkeycoding.com/?p=908 的 "動態配置array"

	// 如果陣列內的元素為class物件時，會用default的建構式來初始化每個元素，如果是內建型別則元素不會初始化
	// reference: http://monkeycoding.com/?p=908 的 No.3

	//----- Initial...
	CString     Msg_cstr = _T("");
	int         *ptr = new int;     
	int         *ptr2 = new int[5];      //ptr2有5個int未初始化(不會等於0)
	CString     *psa = new CString[5];   //psa有5個CString的空字串

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
	
	///////------ 動態宣告二維陣列
	// 以下例子是先配置一維陣列，且每個元素是int *型態
	// 然後再把每個int *型態的元素指向一個動態宣告的一維陣列
	// reference: http://www.programmer-club.com.tw/ShowSameTitleN/c/33977.html

	Msg_cstr.Format(_T("(Static_int_Array): { {%d,%d,%d,%d,%d}, {%d,%d,%d,%d,%d}, {%d,%d,%d,%d,%d} }"),
		Static_2D_Array_i_ay[0][0], Static_2D_Array_i_ay[0][1], Static_2D_Array_i_ay[0][2], Static_2D_Array_i_ay[0][3], Static_2D_Array_i_ay[0][4],
		Static_2D_Array_i_ay[1][0], Static_2D_Array_i_ay[1][1], Static_2D_Array_i_ay[1][2], Static_2D_Array_i_ay[1][3], Static_2D_Array_i_ay[1][4],
		Static_2D_Array_i_ay[2][0], Static_2D_Array_i_ay[2][1], Static_2D_Array_i_ay[2][2], Static_2D_Array_i_ay[2][3], Static_2D_Array_i_ay[2][4]);
	MessageBox(Msg_cstr);

	/////--> 動態產生二維陣列(int型態)
	int     **Dync_2D_Array_i_ay_pr = new int*[Static_Array_Row_i]; //先動態配置一維陣列大小為Row_i且每個元素為pointer to int *
	for (int i_i = 0; i_i < Static_Array_Row_i; i_i++)
	{
		Dync_2D_Array_i_ay_pr[i_i] = new int[Static_Array_Col_i];   //再將每個pinter to int*元素指向一個一維陣列
		memset(Dync_2D_Array_i_ay_pr[i_i], 0, sizeof(int)*Static_Array_Col_i); // 將二維陣列的列向量(row)指向數值0
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

	/////--> 刪除動態產生的二維陣列(int型態)
	for (int i_i = 0; i_i < Static_Array_Row_i; i_i++)
		delete[] Dync_2D_Array_i_ay_pr[i_i];  // 先將每一個元素所指向一維陣列的刪除
	delete[] Dync_2D_Array_i_ay_pr;           // 再刪除全部的陣列


	///////////////////--------------------------------------------------
	///////////////////------------  CString型態的二維陣列
	///////////////////--------------------------------------------------


	/*LPTSTR*/CString     Static_2D_Array_cstr_ay[][3] = { { _T("John"), _T("Ken"), _T("Stephon") },{ _T("American"), _T("Chinese"), _T("Japan") } };
	Static_Array_Row_i = sizeof(Static_2D_Array_cstr_ay) / sizeof(Static_2D_Array_cstr_ay[0]);
	Static_Array_Col_i = sizeof(Static_2D_Array_cstr_ay[0]) / sizeof(Static_2D_Array_cstr_ay[0][0]);

	Msg_cstr.Format(_T("(Static_CString_Array): { {%s,%s,%s}, {%s,%s,%s} }"),
		Static_2D_Array_cstr_ay[0][0], Static_2D_Array_cstr_ay[0][1], Static_2D_Array_cstr_ay[0][2],
		Static_2D_Array_cstr_ay[1][0], Static_2D_Array_cstr_ay[1][1], Static_2D_Array_cstr_ay[1][2]);
	MessageBox(Msg_cstr);

	/////--> 動態產生二維陣列(CString型態)
	/*LPTSTR*/CString      **Dync_2D_Array_cstr_ay_pr = new /*LPTSTR*/CString*[Static_Array_Row_i]; //先動態配置一維陣列大小為Row_i且每個元素為pointer to CString*
	for (int i_i = 0; i_i < Static_Array_Row_i; i_i++)
	{
		Dync_2D_Array_cstr_ay_pr[i_i] = new /*LPTSTR*/CString[Static_Array_Col_i];                  //再將每個pinter to CString*元素指向一個一維陣列
		//memset(Dync_2D_Array_cstr_ay_pr[i_i], 0, sizeof(LPTSTR/*CString*/)*Static_Array_Col_i);  // 將二維陣列的列向量(row)指向數值0
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

	/////--> 刪除動態產生的二維陣列(CString型態)
	for (int i_i = 0; i_i < Static_Array_Row_i; i_i++)
		delete[] Dync_2D_Array_cstr_ay_pr[i_i];  // 先將每一個元素所指向一維陣列的刪除
	delete[] Dync_2D_Array_cstr_ay_pr;           // 再刪除全部的陣列
}
