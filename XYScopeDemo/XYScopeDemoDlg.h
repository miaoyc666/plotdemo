// XYScopeDemoDlg.h : header file
//

#if !defined(AFX_XYSCOPEDEMODLG_H__1EF13564_AD8D_41A6_8EFA_C622BDBA98D7__INCLUDED_)
#define AFX_XYSCOPEDEMODLG_H__1EF13564_AD8D_41A6_8EFA_C622BDBA98D7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <CSLScope.h>

/////////////////////////////////////////////////////////////////////////////
// CXYScopeDemoDlg dialog

class CXYScopeDemoDlg : public CDialog
{
// Construction
public:
	CXYScopeDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CXYScopeDemoDlg)
	enum { IDD = IDD_XYSCOPEDEMO_DIALOG };
	CStatic	m_Scope;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CXYScopeDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CTSLScope Scope;
    double Angle1;
    double Angle2;
    double Angle3;

protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CXYScopeDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_XYSCOPEDEMODLG_H__1EF13564_AD8D_41A6_8EFA_C622BDBA98D7__INCLUDED_)
