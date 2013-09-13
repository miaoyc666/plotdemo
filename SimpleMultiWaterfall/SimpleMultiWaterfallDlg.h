// SimpleMultiWaterfallDlg.h : header file
//

#if !defined(AFX_SIMPLEMULTIWATERFALLDLG_H__E2A6AB91_39FD_4BF3_BD57_CB8F7AFF3450__INCLUDED_)
#define AFX_SIMPLEMULTIWATERFALLDLG_H__E2A6AB91_39FD_4BF3_BD57_CB8F7AFF3450__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <CPLMultiWaterfall.h>
#include <fstream>

/////////////////////////////////////////////////////////////////////////////
// CSimpleMultiWaterfallDlg dialog

class CSimpleMultiWaterfallDlg : public CDialog
{
// Construction
public:
	CSimpleMultiWaterfallDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSimpleMultiWaterfallDlg)
	enum { IDD = IDD_SIMPLEMULTIWATERFALL_DIALOG };
	CStatic	m_MultiWaterfall;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSimpleMultiWaterfallDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

protected:
	std::ifstream binary_file_red;
	std::ifstream binary_file_green;
	std::ifstream binary_file_blue;
	CTPLMultiWaterfall MultiWaterfall;

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSimpleMultiWaterfallDlg)
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

#endif // !defined(AFX_SIMPLEMULTIWATERFALLDLG_H__E2A6AB91_39FD_4BF3_BD57_CB8F7AFF3450__INCLUDED_)
