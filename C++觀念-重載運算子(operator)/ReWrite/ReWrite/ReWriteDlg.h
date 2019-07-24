
// ReWriteDlg.h : header file
//

#pragma once


// CReWriteDlg dialog
class CReWriteDlg : public CDialogEx
{
// Construction
public:
	CReWriteDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_REWRITE_DIALOG };
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
	afx_msg void OnBnClickedBtnReWrite();
	afx_msg void OnBnClickedBtnOperator();
	afx_msg void OnBnClickedBtnFriendOperator();
};
