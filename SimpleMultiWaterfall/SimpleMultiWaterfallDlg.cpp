// SimpleMultiWaterfallDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SimpleMultiWaterfall.h"
#include "SimpleMultiWaterfallDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace std;

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
// CSimpleMultiWaterfallDlg dialog

CSimpleMultiWaterfallDlg::CSimpleMultiWaterfallDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSimpleMultiWaterfallDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSimpleMultiWaterfallDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSimpleMultiWaterfallDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSimpleMultiWaterfallDlg)
	DDX_Control(pDX, IDC_WATERFALL, m_MultiWaterfall);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSimpleMultiWaterfallDlg, CDialog)
	//{{AFX_MSG_MAP(CSimpleMultiWaterfallDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSimpleMultiWaterfallDlg message handlers

BOOL CSimpleMultiWaterfallDlg::OnInitDialog()
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
	MultiWaterfall.Open( m_MultiWaterfall.m_hWnd );

	MultiWaterfall.Title.Text = "RGB Histogram Waterfall";

	MultiWaterfall.Hold = false;
	MultiWaterfall.Channels.Add(3);
	MultiWaterfall.Channels[0].Name = "Red";
	MultiWaterfall.Channels[0].Levels.Axis.ScaleMode = smLogarithmic;
	MultiWaterfall.Channels[1].Name = "Green";
	MultiWaterfall.Channels[1].Levels.Axis.ScaleMode = smLogarithmic;
	MultiWaterfall.Channels[2].Name = "Blue";
	MultiWaterfall.Channels[2].Levels.Axis.ScaleMode = smLogarithmic;

	CString FilePath = GetCommandLine();
	FilePath.MakeLower();
	FilePath = FilePath.Left( FilePath.Find( _T( "plotlabdemos\\simplemultiwaterfall" )) ) + _T( "AVIFiles\\RedData.bin" );
	if( FilePath[ 0 ] == '\"' )
		FilePath.Delete( 0, 1 );

	binary_file_red.open( FilePath, ios_base::binary );

	FilePath = GetCommandLine();
	FilePath.MakeLower();
	FilePath = FilePath.Left( FilePath.Find( _T( "plotlabdemos\\simplemultiwaterfall" )) ) + _T( "AVIFiles\\GreenData.bin" );
	if( FilePath[ 0 ] == '\"' )
		FilePath.Delete( 0, 1 );

	binary_file_green.open( FilePath, ios_base::binary );

	FilePath = GetCommandLine();
	FilePath.MakeLower();
	FilePath = FilePath.Left( FilePath.Find( _T( "plotlabdemos\\simplemultiwaterfall" )) ) + _T( "AVIFiles\\BlueData.bin" );
	if( FilePath[ 0 ] == '\"' )
		FilePath.Delete( 0, 1 );

	binary_file_blue.open( FilePath, ios_base::binary );


	SetTimer( 1, 10, NULL );
	
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSimpleMultiWaterfallDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSimpleMultiWaterfallDlg::OnPaint() 
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
HCURSOR CSimpleMultiWaterfallDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSimpleMultiWaterfallDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
    double Buffer[256];

	if( ! binary_file_red.fail() )
	{
		binary_file_red.read( (char *)Buffer, 256 * sizeof( double ) );
		if( binary_file_red.gcount() == 256 * sizeof( double ) )
		    MultiWaterfall.Channels[ 0 ].Data.AddData( Buffer, 256 );

		else 
		{
			binary_file_red.clear();
    		binary_file_red.seekg( 0, ios_base::beg );
		}
	}

	if( ! binary_file_green.fail() )
	{
		binary_file_green.read( (char *)Buffer, 256 * sizeof( double ) );
		if( binary_file_green.gcount() == 256 * sizeof( double ) )
		    MultiWaterfall.Channels[ 1 ].Data.AddData( Buffer, 256 );

		else 
		{
			binary_file_green.clear();
    		binary_file_green.seekg( 0, ios_base::beg );
		}
	}

	if( ! binary_file_blue.fail() )
	{
		binary_file_blue.read( (char *)Buffer, 256 * sizeof( double ) );
		if( binary_file_blue.gcount() == 256 * sizeof( double ) )
		    MultiWaterfall.Channels[ 2 ].Data.AddData( Buffer, 256 );

		else 
		{
			binary_file_blue.clear();
    		binary_file_blue.seekg( 0, ios_base::beg );
		}
	}

	CDialog::OnTimer(nIDEvent);
}

void CSimpleMultiWaterfallDlg::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	if( m_MultiWaterfall.m_hWnd )
	{
		m_MultiWaterfall.MoveWindow( 11, 11, cx - 22, cy - 22 );
		MultiWaterfall.Width = cx - 22;
		MultiWaterfall.Height = cy - 22;
	}
	
}
