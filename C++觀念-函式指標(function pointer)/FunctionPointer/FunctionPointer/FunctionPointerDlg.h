
// FunctionPointerDlg.h : header file
//

#pragma once


// CFunctionPointerDlg dialog
class CFunctionPointerDlg : public CDialogEx
{
// Construction
public:
	CFunctionPointerDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FUNCTIONPOINTER_DIALOG };
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

	afx_msg void OnBnClickedBtnFuncPtr();
	afx_msg void OnBnClickedBtnFuncptrArraysort();

	afx_msg void OnBnClickedBtnMemberFuncPtr();
	afx_msg void OnBnClickedBtnStaticMemberFuncPtr();
};
