
// FunctionDlg.h : header file
//

#pragma once


// CFunctionDlg dialog
class CFunctionDlg : public CDialogEx
{
// Construction
public:
	CFunctionDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FUNCTION_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnFunction();

	void   PrintArray_Fn(const int *A_i_ay_pr, int SizeofArray_i);
	void   PrintArray_Fn(int A_i_ay[]);
	void   PrintArray_WithReference_Fn(int(&arr)[5]);
	void   PrintArray_WithPointer_Fn(int (*arr)[5]);
};
