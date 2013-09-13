// LargeDataScopeDemoDlg.h : header file
//

#if !defined(AFX_LARGEDATASCOPEDEMODLG_H__2D0CF8F3_C906_4210_84D1_233D2E208431__INCLUDED_)
#define AFX_LARGEDATASCOPEDEMODLG_H__2D0CF8F3_C906_4210_84D1_233D2E208431__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <CSLScope.h>

/////////////////////////////////////////////////////////////////////////////
// CLargeDataScopeDemoDlg dialog

class CLargeDataScopeDemoDlg : public CDialog
{
// Construction
public:
	CLargeDataScopeDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CLargeDataScopeDemoDlg)
	enum { IDD = IDD_LARGEDATASCOPEDEMO_DIALOG };
	CStatic	m_Scope;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLargeDataScopeDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CTSLScope Scope;

protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CLargeDataScopeDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LARGEDATASCOPEDEMODLG_H__2D0CF8F3_C906_4210_84D1_233D2E208431__INCLUDED_)
