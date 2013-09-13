// SimpleWaterfallDlg.h : header file
//

#if !defined(AFX_SIMPLEWATERFALLDLG_H__70BAE6AD_72EF_4FBF_85CB_430B48F2ED65__INCLUDED_)
#define AFX_SIMPLEWATERFALLDLG_H__70BAE6AD_72EF_4FBF_85CB_430B48F2ED65__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <CSLWaterfall.h>
#include <fstream>

/////////////////////////////////////////////////////////////////////////////
// CSimpleWaterfallDlg dialog

class CSimpleWaterfallDlg : public CDialog
{
// Construction
public:
	CSimpleWaterfallDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSimpleWaterfallDlg)
	enum { IDD = IDD_SIMPLEWATERFALL_DIALOG };
	CStatic	m_Waterfall;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSimpleWaterfallDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	std::ifstream binary_file;
	CTSLWaterfall Waterfall;

protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSimpleWaterfallDlg)
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

#endif // !defined(AFX_SIMPLEWATERFALLDLG_H__70BAE6AD_72EF_4FBF_85CB_430B48F2ED65__INCLUDED_)
