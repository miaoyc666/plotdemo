// SimpleScopeDlg.h : header file
//

#if !defined(AFX_SIMPLESCOPEDLG_H__080FD11D_82B0_4BE6_A126_674342BB9360__INCLUDED_)
#define AFX_SIMPLESCOPEDLG_H__080FD11D_82B0_4BE6_A126_674342BB9360__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <CSLScope.h>

/////////////////////////////////////////////////////////////////////////////
// CSimpleScopeDlg dialog

class CSimpleScopeDlg : public CDialog
{
// Construction
public:
	CSimpleScopeDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSimpleScopeDlg)
	enum { IDD = IDD_SIMPLESCOPE_DIALOG };
	CStatic	m_Scope;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSimpleScopeDlg)
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
	//{{AFX_MSG(CSimpleScopeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnPlotDataButton();
	afx_msg void OnClearButton();
	afx_msg void OnLinesButton();
	afx_msg void OnBarsButton();
	afx_msg void OnPointsButton();
	afx_msg void OnPlusButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SIMPLESCOPEDLG_H__080FD11D_82B0_4BE6_A126_674342BB9360__INCLUDED_)
