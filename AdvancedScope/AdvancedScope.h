// AdvancedScope.h : main header file for the ADVANCEDSCOPE application
//

#if !defined(AFX_ADVANCEDSCOPE_H__DEBA10EC_C709_4927_8E78_D5267174F451__INCLUDED_)
#define AFX_ADVANCEDSCOPE_H__DEBA10EC_C709_4927_8E78_D5267174F451__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CAdvancedScopeApp:
// See AdvancedScope.cpp for the implementation of this class
//

class CAdvancedScopeApp : public CWinApp
{
public:
	CAdvancedScopeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAdvancedScopeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CAdvancedScopeApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADVANCEDSCOPE_H__DEBA10EC_C709_4927_8E78_D5267174F451__INCLUDED_)
