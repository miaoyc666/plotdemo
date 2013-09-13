// SimpleMultiWaterfall.h : main header file for the SIMPLEMULTIWATERFALL application
//

#if !defined(AFX_SIMPLEMULTIWATERFALL_H__E8BD1D18_1866_43B5_A789_023D0AF74A54__INCLUDED_)
#define AFX_SIMPLEMULTIWATERFALL_H__E8BD1D18_1866_43B5_A789_023D0AF74A54__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSimpleMultiWaterfallApp:
// See SimpleMultiWaterfall.cpp for the implementation of this class
//

class CSimpleMultiWaterfallApp : public CWinApp
{
public:
	CSimpleMultiWaterfallApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSimpleMultiWaterfallApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSimpleMultiWaterfallApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SIMPLEMULTIWATERFALL_H__E8BD1D18_1866_43B5_A789_023D0AF74A54__INCLUDED_)
