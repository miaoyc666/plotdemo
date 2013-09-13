// XYScopeDemo.h : main header file for the XYSCOPEDEMO application
//

#if !defined(AFX_XYSCOPEDEMO_H__37F6AC73_5B26_433D_BE0C_ECDE1F0B36BB__INCLUDED_)
#define AFX_XYSCOPEDEMO_H__37F6AC73_5B26_433D_BE0C_ECDE1F0B36BB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CXYScopeDemoApp:
// See XYScopeDemo.cpp for the implementation of this class
//

class CXYScopeDemoApp : public CWinApp
{
public:
	CXYScopeDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CXYScopeDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CXYScopeDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_XYSCOPEDEMO_H__37F6AC73_5B26_433D_BE0C_ECDE1F0B36BB__INCLUDED_)
