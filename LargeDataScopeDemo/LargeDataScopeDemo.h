// LargeDataScopeDemo.h : main header file for the LARGEDATASCOPEDEMO application
//

#if !defined(AFX_LARGEDATASCOPEDEMO_H__AA8C88A9_4F02_41D2_B1E2_42C66C93536D__INCLUDED_)
#define AFX_LARGEDATASCOPEDEMO_H__AA8C88A9_4F02_41D2_B1E2_42C66C93536D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CLargeDataScopeDemoApp:
// See LargeDataScopeDemo.cpp for the implementation of this class
//

class CLargeDataScopeDemoApp : public CWinApp
{
public:
	CLargeDataScopeDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLargeDataScopeDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CLargeDataScopeDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LARGEDATASCOPEDEMO_H__AA8C88A9_4F02_41D2_B1E2_42C66C93536D__INCLUDED_)
