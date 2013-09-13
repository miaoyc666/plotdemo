// ScrollingScopeDemoDlg.h : header file
//

#if !defined(AFX_SCROLLINGSCOPEDEMODLG_H__E316F71F_3CBA_40FC_B0CC_50186E521E18__INCLUDED_)
#define AFX_SCROLLINGSCOPEDEMODLG_H__E316F71F_3CBA_40FC_B0CC_50186E521E18__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <CSLScope.h>

/////////////////////////////////////////////////////////////////////////////
// CScrollingScopeDemoDlg dialog

class CScrollingScopeDemoDlg : public CDialog
{
// Construction
public:
	CScrollingScopeDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CScrollingScopeDemoDlg)
	enum { IDD = IDD_SCROLLINGSCOPEDEMO_DIALOG };
	CButton	m_Check0;
	CButton	m_Check1;
	CStatic	m_Scope;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScrollingScopeDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CTSLScope Scope;

protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CScrollingScopeDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnClose();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCROLLINGSCOPEDEMODLG_H__E316F71F_3CBA_40FC_B0CC_50186E521E18__INCLUDED_)
