
// FunctionDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Function.h"
#include "FunctionDlg.h"
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


// CFunctionDlg dialog



CFunctionDlg::CFunctionDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_FUNCTION_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFunctionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CFunctionDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_FUNCTION, &CFunctionDlg::OnBnClickedBtnFunction)
END_MESSAGE_MAP()


// CFunctionDlg message handlers

BOOL CFunctionDlg::OnInitDialog()
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

void CFunctionDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFunctionDlg::OnPaint()
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
HCURSOR CFunctionDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CFunctionDlg::OnBnClickedBtnFunction()
{
	//---- ㄧΑ(function)ㄇ芠├
	// ㄧΑ璶肚蝴皚 
	

	//------ Initial...
	CString   Msg_cstr = _T("");

	//------------------------------------

	int    Array_i_ay[5] = { 1,2,3,4,5 };
	int    ArraySize_i = 5;
	int    *Crray_i_ay_pr = new int[ArraySize_i];
	int    Brray_i_ay[6] = { 6,7,8,9,10,11 };
	int    Array2D_i_ay[][5] = { {10,20,30,40,50},{100,200,300,400,500} };


	Msg_cstr.Format(_T("(Origianl Array) Array_i_ay[%d]={%d,%d,%d,%d,%d}"), sizeof(Array_i_ay) / sizeof(Array_i_ay[0]), Array_i_ay[0], Array_i_ay[1], Array_i_ay[2], Array_i_ay[3], Array_i_ay[4]);
	MessageBox(Msg_cstr);
	PrintArray_Fn(Array_i_ay, sizeof(Array_i_ay) / sizeof(Array_i_ay[0]));
	PrintArray_Fn(Brray_i_ay);
	for (int i_i = 0; i_i < ArraySize_i; i_i++)
	{
		Crray_i_ay_pr[i_i] = i_i;
	}
	PrintArray_Fn(Crray_i_ay_pr, ArraySize_i);
	PrintArray_WithReference_Fn(Array_i_ay);
	//PrintArray_WithReference_Fn(Crray_i_ay_pr);  // compiler error, PrintArray_WithReference_Fn()把计﹚竡int皚皚5
	                                               // 琌Crray_i_ay_pr琌int篈夹
	PrintArray_WithPointer_Fn(Array2D_i_ay);
	delete[] Crray_i_ay_pr;
}
//-----------------------------------------------------------------------------------------------
void CFunctionDlg::PrintArray_Fn(const int *A_i_ay_pr, int SizeofArray_i)
{
	//------ Initial ...
	CString    Msg_cstr = _T("");
	CString    Data_cstr = _T("");
	CString    tempData_cstr = _T("");

	//--------------------------------------

	for (int i_i = 0; i_i < SizeofArray_i; i_i++)
	{
		if (i_i == SizeofArray_i - 1)
			tempData_cstr.Format(_T("%d"), A_i_ay_pr[i_i]);
		else
			tempData_cstr.Format(_T("%d,"), A_i_ay_pr[i_i]);
		Data_cstr = Data_cstr + tempData_cstr;
	}

	Msg_cstr.Format(_T("PrintArray_Fn(pointer, size) --> A_i_ay_pr[%d]={%s}"), SizeofArray_i, Data_cstr);
	MessageBox(Msg_cstr);
}
//-----------------------------------------------------------------------------------------------
void CFunctionDlg::PrintArray_Fn(int A_i_ay[])
{
	//------ Initial ...
	CString    Msg_cstr = _T("");

	//------------------------------

	Msg_cstr.Format(_T("PrintArray_Fn(pointer) --> A_i_ay[%d]={%d(%x),%d(%x),%d(%x),%d(%x),%d(%x)}"), sizeof(A_i_ay) / sizeof(A_i_ay[0]), A_i_ay[0], (A_i_ay), A_i_ay[1], (A_i_ay + 1), A_i_ay[2], (A_i_ay + 2), A_i_ay[3], (A_i_ay + 3), A_i_ay[4], (A_i_ay + 4));
	MessageBox(Msg_cstr);
}
//-----------------------------------------------------------------------------------------------
void CFunctionDlg::PrintArray_WithReference_Fn(int(&arr)[5])
{
	//----- ㄧΑず把计﹚竡5int篈arrayarr琌把σ肚跑计
	// ノ把σ皚よΑㄓ笷浪琩┮盿皚へ琌5

	// reference http://monkeycoding.com/?p=893  No.4
	//------ Initial ...
	CString    Msg_cstr = _T("");
	int        Array_Size_i = 0;
	CString    Data_cstr = _T("");
	CString    tempData_cstr = _T("");

	//------------------------------

	Array_Size_i = sizeof(arr) / sizeof(arr[0]);
	for (int i_i = 0; i_i < Array_Size_i; i_i++)
	{
		if (i_i == Array_Size_i - 1)
			tempData_cstr.Format(_T("%d(%x)"), arr[i_i], arr + i_i);
		else
			tempData_cstr.Format(_T("%d(%x),"), arr[i_i], arr + i_i);
		Data_cstr = Data_cstr + tempData_cstr;
	}
	Msg_cstr.Format(_T("PrintArray_Fn(reference array with size 5) --> arr[%d]={%s}"), Array_Size_i, Data_cstr);
	MessageBox(Msg_cstr);
}
//-----------------------------------------------------------------------------------------------
void CFunctionDlg::PrintArray_WithPointer_Fn(int(*arr)[5])
{
	//------ Initial ...
	CString    Msg_cstr = _T("");
	int        arr_RowSize_i = 0;
	int        arr_ColSize_i = 0;

	//------------------------------
	arr_RowSize_i = sizeof(arr) / sizeof(arr[0]);
	arr_ColSize_i = sizeof(arr[0]) / sizeof(arr[0][0]);
	Msg_cstr.Format(_T("PrintArray_Fn(pointer array with size 5) --> arr[%d][%d]={{%d(%x),%d(%x),%d(%x),%d(%x),%d(%x)},{%d(%x),%d(%x),%d(%x),%d(%x),%d(%x)}}"), arr_RowSize_i, arr_ColSize_i,
		arr[0][0], (arr[0]), arr[0][1], (arr[0] + 1), arr[0][2], (arr[0] + 2), arr[0][3], (arr[0] + 3), arr[0][4], (arr[0] + 4),
		arr[1][0], (arr[1]), arr[1][1], (arr[1] + 1), arr[1][2], (arr[1] + 2), arr[1][3], (arr[1] + 3), arr[1][4], (arr[1] + 4));
	MessageBox(Msg_cstr);
}
//-----------------------------------------------------------------------------------------------