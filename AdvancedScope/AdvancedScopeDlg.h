// AdvancedScopeDlg.h : header file
//

#if !defined(AFX_ADVANCEDSCOPEDLG_H__86E0D38C_85EC_473D_BD32_A4F534B9B487__INCLUDED_)
#define AFX_ADVANCEDSCOPEDLG_H__86E0D38C_85EC_473D_BD32_A4F534B9B487__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <CSLScope.h>

/////////////////////////////////////////////////////////////////////////////
// CAdvancedScopeDlg dialog

class CAdvancedScopeDlg : public CDialog
{
// Construction
public:
	CAdvancedScopeDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CAdvancedScopeDlg)
	enum { IDD = IDD_ADVANCEDSCOPE_DIALOG };
	CButton	m_VerticalCheck;
	CButton	m_ReversedCheck;
	CButton	m_LogarithmicXCheck;
	CButton	m_LogarithmicYCheck;
	CButton	m_CustomStepYCheck;
	CButton	m_CustomStepXCheck;
	CButton	m_CustomLabelYCheck;
	CButton	m_CustomLabelXCheck;
	CButton	m_LinksLegendCheckBox;
	CButton	m_SelectionCheckBox;
	CButton	m_MeasurementCheckBox;
	CButton	m_CursorsLegendCheckBox;
	CButton	m_Channel1LinkCheckBox;
	CButton	m_Channel0LinkCheckBox;
	CButton	m_HCursorCheckBox;
	CButton	m_VCursorCheckBox;
	CButton	m_MarkersLegendCheckBox;
	CButton	m_MarkersCheckBox;
	CButton	m_ChannelsLegendCheckBox;
	CButton	m_Channel1CheckBox;
	CButton	m_Channel0CheckBox;
	CStatic	m_Scope;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAdvancedScopeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CTSLScope Scope;
	int       Counter;

protected: // Events
	void __stdcall OnChannel0Draw( void *Sender, int ChannelIndex, double *ChannelData, int DataSize, bool WasChanged );
	void __stdcall OnCustomXAxesLabel( void *Sender, double Value, CString & );
	void __stdcall OnCustomYAxesLabel( void *Sender, double Value, CString & );
    void __stdcall OnCustomXAxesStep(VCLHANDLE Sender, double SampleValue, double & Step, bool & Draw);
    void __stdcall OnCustomYAxesStep(VCLHANDLE Sender, double SampleValue, double & Step, bool & Draw);

protected: // Helper functions.
	void UpdateCnannelLinks();

protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CAdvancedScopeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnChannel0Check();
	afx_msg void OnChannel1Check();
	afx_msg void OnChannelsLegendCheck();
	afx_msg void OnMarkersCheck();
	afx_msg void OnMarkersLegendCheck();
	afx_msg void OnVCursorCheck();
	afx_msg void OnHCursorCheck();
	afx_msg void OnChannel0LinkCheck();
	afx_msg void OnChannel1LinkCheck();
	afx_msg void OnCursorsLegendCheck();
	afx_msg void OnMeasurementCheck();
	afx_msg void OnSelectionCheck();
	afx_msg void OnLinksLegendCheck();
	afx_msg void OnLogarithmicYCheck();
	afx_msg void OnLogarithmicXCheck();
	afx_msg void OnCustomLabelXCheck();
	afx_msg void OnCustomStepXCheck();
	afx_msg void OnCustomLabelYCheck();
	afx_msg void OnCustomStepYCheck();
	afx_msg void OnReversedCheck();
	afx_msg void OnVerticalCheck();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADVANCEDSCOPEDLG_H__86E0D38C_85EC_473D_BD32_A4F534B9B487__INCLUDED_)
