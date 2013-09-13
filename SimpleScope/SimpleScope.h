// SimpleScope.h : main header file for the SIMPLESCOPE application
//

#if !defined(AFX_SIMPLESCOPE_H__509D8A36_C794_4CAB_9222_E83D181C3A85__INCLUDED_)
#define AFX_SIMPLESCOPE_H__509D8A36_C794_4CAB_9222_E83D181C3A85__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSimpleScopeApp:
// See SimpleScope.cpp for the implementation of this class
//

class CSimpleScopeApp : public CWinApp
{
public:
	CSimpleScopeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSimpleScopeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSimpleScopeApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SIMPLESCOPE_H__509D8A36_C794_4CAB_9222_E83D181C3A85__INCLUDED_)
