
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
	TCHAR    *Constant_tc_ptr = _T("abcde");  // Constant_tc_ptr�{�b���V�@�Ӧr��`��
	TCHAR    Const_tc_ay[] = _T("xyz");
	CString  Msg_cstr = _T("");

	//---------------------------------

	//----- ���n�չϥΫ��Хh���@�Ӧr��`��
	// ����: �r��`�ƪ����e�O "��Ū" ���A���ϥ��v���S����諸�v�Q�A
	//       �Y�Ʊ�ϥΥi�H��諸�r��A���N���b�X�k�Ŷ�
	// reference: https://mikepmpliu80.pixnet.net/blog/category/1348531 �� No.2 item


	/////--> <<���ЯS��>>
	Msg_cstr.Format(_T("pointer to string(before): %s"), Constant_tc_ptr);
	MessageBox(Msg_cstr);

	//*Constant_tc_ptr = 'j';      // execute error, pointer�S���v�O�h��� "�r��`��"
	Constant_tc_ptr = _T("123");   // PASS, pointer was changed to point other const string

	Msg_cstr.Format(_T("pointer to string(after point to other const string): %s"), Constant_tc_ptr);
	MessageBox(Msg_cstr);

	/////////
	///////// �p�G�n���A�Х� "�}�C�ܼ�" ���N "�����ܼ�" �Ӱ�����Ȫ�����
	/////////

	/////--> <<�}�C�S��>>
	Msg_cstr.Format(_T("array to string(before): %s"), Const_tc_ay);
	MessageBox(Msg_cstr);

	//Const_tc_ay = _T("123");   // compiler error, "�}�C�W��" �L�k�������V��L�r��`��
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

	// �ŧi���а}�C�A�i�H���K���B�z�r��}�C
	// ArrayWithPointer_tc_ptr_ay�����C�Ӥ������O�r�����СA�]�U�۫��V�@�Ӧr��`�ơC
	// �i�@�B�X�R�o�ӷ����A�N�i�H�ϥΤG���H�W���r��}�C�A�Ҧp StudentInfo_tc_ptr_ay
	// reference: https://openhome.cc/Gossip/CppGossip/PointerAndString.html

	/////--> �@�����r�����а}�C
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


	/////--> �G�����r�����а}�C
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

	// �W�C��ӫŧi���@�����M�����A�����N�q���P�C
	
	// str1�O���а}�C�A�C�@�Ӥ������O���СA���V�@�Ӧr��`�ơA
	// �u�n�t�~���w�r��`�Ƶ��Y�������A�Ӥ������V���O�����}�N���P�F

	// str2�O�ŧi3*10���r���}�C�Ŷ��A�s��t�m30�ӰO����Ŷ��A�r��O�����x�s�b�o�ӪŶ��A
	// �C�Ӧr�ꪺ��}�O�T�w���A�ӨϥΪ��Ŷ��]�O�T�w��(�]�N�O�t�Ŧr���|�O10�Ӧr��)

	// reference: https://openhome.cc/Gossip/CppGossip/PointerAndString.html


	//////--> ���а}�C���d�ҡA�t�~���w�r��`�Ƶ��䤤�@�Ӥ�����A��O���骺��}�N���P�F
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
		str1[0] = _T("good-student");  // execute pass, �ѩ�O�ŧi�����а}�C���x�s�r��A�ҥH���|�����ת�����
		for (int i_i = 0; i_i < Size_i; i_i++)
		{
			Data_cstr.Format(_T("%s(%x),"), str1[i_i], str1[i_i]);
			Msg_cstr = Msg_cstr + Data_cstr;
		}
		MessageBox(Msg_cstr);
	}

	//////--> �G���r���}�C���d�ҡA�t�~���w�r��`�Ƶ��䤤�@�ӦC��A��O���骺��}���M�ۦP
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
		//_tcscpy_s(str2[0], _T("good-student")); // execute error, �ҥH�r����׶W�L�ŧi�r���}�C�����׼ƭ�(�W�L10�Ӧr����)
		_tcscpy_s(str2[0], _T("student"));
		for (int i_i = 0; i_i < Size_i; i_i++)
		{
			Data_cstr.Format(_T("%s(%x),"), str2[i_i], str2[i_i]);
			Msg_cstr = Msg_cstr + Data_cstr;
		}
		MessageBox(Msg_cstr);
	}
}
