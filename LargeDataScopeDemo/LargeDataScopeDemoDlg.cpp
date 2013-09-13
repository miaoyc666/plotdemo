// LargeDataScopeDemoDlg.cpp : implementation file
//

#include "stdafx.h"

#include <fstream>

#include "LargeDataScopeDemo.h"
#include "LargeDataScopeDemoDlg.h"

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
// CLargeDataScopeDemoDlg dialog

CLargeDataScopeDemoDlg::CLargeDataScopeDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLargeDataScopeDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLargeDataScopeDemoDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLargeDataScopeDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLargeDataScopeDemoDlg)
	DDX_Control(pDX, ID_VCSCOPE, m_Scope);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CLargeDataScopeDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CLargeDataScopeDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLargeDataScopeDemoDlg message handlers

BOOL CLargeDataScopeDemoDlg::OnInitDialog()
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

	Scope.Cursors.Add( 2 );
	Scope.Cursors[ 0 ].Position.X = 150000;
	Scope.Cursors[ 1 ].Position.X = 200000;

	Scope.Cursors[ 0 ].Color = RGB( 0, 128, 128 );
	Scope.Cursors[ 1 ].Color = RGB( 0, 128, 128 );

	Scope.Cursors[ 0 ].Channels.Add();
	Scope.Cursors[ 1 ].Channels.Add();

	Scope.CursorLinks.Add();
	Scope.CursorLinks[ 0 ].Selection.Visible = true;

	Scope.Channels[ 0 ].Points.Visible = true;
	Scope.Channels[ 0 ].Points.Pen.Color = RGB( 0, 0, 255 );
	Scope.Channels[ 0 ].Points.Brush.Color = RGB( 0, 255, 255 );
	Scope.Channels[ 0 ].Points.UseChannelColor = false;
	
	CString FilePath = GetCommandLine();
	FilePath.MakeLower();
	FilePath = FilePath.Left( FilePath.Find( _T( "plotlabdemos\\largedatascopedemo" )) ) + _T( "AVIFiles\\WaveData.bin" );
	if( FilePath[ 0 ] == '\"' )
		FilePath.Delete( 0, 1 );

	std::ifstream binary_file;

	binary_file.open( FilePath, std::ios_base::binary );

	binary_file.seekg( 0, std::ios_base::end );

	int ALength = binary_file.tellg() / sizeof( double );

	double *ABuffer = new double[ ALength ];

	binary_file.seekg( 0, std::ios_base::beg );
	binary_file.read( (char *)ABuffer, ALength * sizeof( double ) );

	Scope.Channels[ 0 ].Data.SetYData( ABuffer, ALength );

	delete [] ABuffer;

	Scope.RefreshView();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CLargeDataScopeDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CLargeDataScopeDemoDlg::OnPaint() 
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
HCURSOR CLargeDataScopeDemoDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CLargeDataScopeDemoDlg::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	if( m_Scope.m_hWnd )
	{
		m_Scope.MoveWindow( 11, 33, cx - 22, cy - 44 );
		Scope.Width = cx - 22;
		Scope.Height = cy - 44;
	}
		
}
