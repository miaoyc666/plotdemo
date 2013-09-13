// MultiAxesScopeDemo.h : main header file for the MULTIAXESSCOPEDEMO application
//

#if !defined(AFX_MULTIAXESSCOPEDEMO_H__D67FAFB9_57E4_47D6_8B8B_6A92A048F436__INCLUDED_)
#define AFX_MULTIAXESSCOPEDEMO_H__D67FAFB9_57E4_47D6_8B8B_6A92A048F436__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMultiAxesScopeDemoApp:
// See MultiAxesScopeDemo.cpp for the implementation of this class
//

class CMultiAxesScopeDemoApp : public CWinApp
{
public:
	CMultiAxesScopeDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiAxesScopeDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMultiAxesScopeDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTIAXESSCOPEDEMO_H__D67FAFB9_57E4_47D6_8B8B_6A92A048F436__INCLUDED_)
