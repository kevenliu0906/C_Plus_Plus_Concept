
// Pass2DArrayDlg.h : header file
//

#pragma once


// CPass2DArrayDlg dialog
class CPass2DArrayDlg : public CDialogEx
{
// Construction
public:
	CPass2DArrayDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PASS2DARRAY_DIALOG };
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
	afx_msg void OnBnClickedBtnPass2dArray();
	afx_msg void OnBnClickedBtnPtrError();
	afx_msg void OnBnClickedBtnPtrConstantString();
	afx_msg void OnBnClickedBtnStrcatError();
	afx_msg void OnBnClickedBtnPassPointerArray();
	afx_msg void OnBnClickedBtnPass2dPtrArray();
	afx_msg void OnBnClickedBtnPass1dArray();
};
