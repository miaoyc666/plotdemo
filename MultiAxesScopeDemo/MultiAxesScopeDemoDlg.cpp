// MultiAxesScopeDemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MultiAxesScopeDemo.h"
#include "MultiAxesScopeDemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMultiAxesScopeDemoDlg dialog

CMultiAxesScopeDemoDlg::CMultiAxesScopeDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMultiAxesScopeDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMultiAxesScopeDemoDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMultiAxesScopeDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMultiAxesScopeDemoDlg)
	DDX_Control(pDX, ID_VCSCOPE, m_Scope);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMultiAxesScopeDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CMultiAxesScopeDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMultiAxesScopeDemoDlg message handlers

BOOL CMultiAxesScopeDemoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	Scope.Open( m_Scope.m_hWnd );
	Scope.Channels.Add();
	Scope.XAxis.AdditionalAxes.Add();
	Scope.YAxis.AdditionalAxes.Add();

	Scope.Channels[ 0 ].XAxisIndex = 0;
	Scope.Channels[ 0 ].YAxisIndex = 0;

	Scope.Channels[ 1 ].XAxisIndex = 1;
	Scope.Channels[ 1 ].YAxisIndex = 1;

	VCL_Loaded();
	
	// Start data flow.
	SetTimer( 1, 10, NULL );	

	Counter = 0;

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMultiAxesScopeDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMultiAxesScopeDemoDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMultiAxesScopeDemoDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMultiAxesScopeDemoDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	
	
	float SampleDataArray[ 100 ];
	int i;
	for( i = 0; i < 100; i ++ )
		SampleDataArray[ i ] = (float)( rand() - 16000 );

	Scope.Channels[ 0 ].Data.SetYData( SampleDataArray, 100 );

	for( i = 0; i < 100; i ++ )
		SampleDataArray[ i ] = (float)( ( Counter++ % 15 ) - 7 ) * 2000;

	Scope.Channels[ 1 ].Data.SetYData( SampleDataArray, 100 );

	CDialog::OnTimer(nIDEvent);
}

void CMultiAxesScopeDemoDlg::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	if( m_Scope.m_hWnd )
	{
		m_Scope.MoveWindow( 11, 11, cx - 22, cy - 22 );
		Scope.Width = cx - 22;
		Scope.Height = cy - 22;
	}
		
}
