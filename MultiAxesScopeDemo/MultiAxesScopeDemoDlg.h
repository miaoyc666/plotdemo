// MultiAxesScopeDemoDlg.h : header file
//

#if !defined(AFX_MULTIAXESSCOPEDEMODLG_H__CE2D72F4_5A65_4329_A9C9_4017EB39BD8C__INCLUDED_)
#define AFX_MULTIAXESSCOPEDEMODLG_H__CE2D72F4_5A65_4329_A9C9_4017EB39BD8C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <CSLScope.h>

/////////////////////////////////////////////////////////////////////////////
// CMultiAxesScopeDemoDlg dialog

class CMultiAxesScopeDemoDlg : public CDialog
{
// Construction
public:
	CMultiAxesScopeDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMultiAxesScopeDemoDlg)
	enum { IDD = IDD_MULTIAXESSCOPEDEMO_DIALOG };
	CStatic	m_Scope;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiAxesScopeDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CTSLScope Scope;
	int       Counter;

protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMultiAxesScopeDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTIAXESSCOPEDEMODLG_H__CE2D72F4_5A65_4329_A9C9_4017EB39BD8C__INCLUDED_)
