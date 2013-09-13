// SimpleWaterfall.h : main header file for the SIMPLEWATERFALL application
//

#if !defined(AFX_SIMPLEWATERFALL_H__C406DFCA_803A_4585_B3FA_0CA50F74998C__INCLUDED_)
#define AFX_SIMPLEWATERFALL_H__C406DFCA_803A_4585_B3FA_0CA50F74998C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSimpleWaterfallApp:
// See SimpleWaterfall.cpp for the implementation of this class
//

class CSimpleWaterfallApp : public CWinApp
{
public:
	CSimpleWaterfallApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSimpleWaterfallApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSimpleWaterfallApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SIMPLEWATERFALL_H__C406DFCA_803A_4585_B3FA_0CA50F74998C__INCLUDED_)
