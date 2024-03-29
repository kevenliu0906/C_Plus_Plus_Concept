
// Pointer_Array_StringDlg.h : header file
//

#pragma once


// CPointer_Array_StringDlg dialog
class CPointer_Array_StringDlg : public CDialogEx
{
// Construction
public:
	CPointer_Array_StringDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_POINTER_ARRAY_STRING_DIALOG };
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
	afx_msg void OnBnClickedBtnPointerArrayString();
	afx_msg void OnBnClickedBtnArrayWithPointer();
	afx_msg void OnBnClickedBtnChararrayDifferentCharpointerarray();
};
