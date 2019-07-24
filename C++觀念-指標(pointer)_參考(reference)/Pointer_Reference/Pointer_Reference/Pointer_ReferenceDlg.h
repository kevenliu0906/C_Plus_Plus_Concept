
// Pointer_ReferenceDlg.h : header file
//

#pragma once


// CPointer_ReferenceDlg dialog
class CPointer_ReferenceDlg : public CDialogEx
{
// Construction
public:
	CPointer_ReferenceDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_POINTER_REFERENCE_DIALOG };
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
	afx_msg void OnBnClickedBtnReference();
	afx_msg void OnBnClickedBtnPointer();

};
