// SimpleScopeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SimpleScope.h"
#include "SimpleScopeDlg.h"

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
// CSimpleScopeDlg dialog

CSimpleScopeDlg::CSimpleScopeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSimpleScopeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSimpleScopeDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSimpleScopeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSimpleScopeDlg)
	DDX_Control(pDX, ID_VCSCOPE, m_Scope);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSimpleScopeDlg, CDialog)
	//{{AFX_MSG_MAP(CSimpleScopeDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_PLOT_DATA_BUTTON, OnPlotDataButton)
	ON_BN_CLICKED(IDC_CLEAR_BUTTON, OnClearButton)
	ON_BN_CLICKED(IDC_LINES_BUTTON, OnLinesButton)
	ON_BN_CLICKED(IDC_BARS_BUTTON, OnBarsButton)
	ON_BN_CLICKED(IDC_POINTS_BUTTON, OnPointsButton)
	ON_BN_CLICKED(IDC_PLUS_BUTTON, OnPlusButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSimpleScopeDlg message handlers

BOOL CSimpleScopeDlg::OnInitDialog()
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
	Scope.Channels[ 0 ].Name = "Random";
	Scope.Channels[ 1 ].Name = "Ramp";

	Scope.RefreshInterval = 100;

	VCL_Loaded();

	Counter = 0;
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSimpleScopeDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSimpleScopeDlg::OnPaint() 
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
HCURSOR CSimpleScopeDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSimpleScopeDlg::OnPlotDataButton() 
{
	// TODO: Add your control notification handler code here
	float SampleDataArray[ 1000 ];
	int i;
	for( i = 0; i < 1000; i ++ )
		SampleDataArray[ i ] = rand() - 16000;

	Scope.Channels[ 0 ].Data.SetYData( SampleDataArray, 1000 );

	for( i = 0; i < 1000; i ++ )
		SampleDataArray[ i ] = (float)( Counter++ % 120 ) * 300 - 16000;

	Scope.Channels[ 1 ].Data.SetYData( SampleDataArray, 1000 );
}

void CSimpleScopeDlg::OnClearButton() 
{
	// TODO: Add your control notification handler code here
	Scope.Channels[ 0 ].Data.Clear();
	Scope.Channels[ 1 ].Data.Clear();
	Scope.Hold = false;
}

void CSimpleScopeDlg::OnLinesButton()
{
	// TODO: Add your control notification handler code here
	Scope.Channels[ 0 ].ChannelMode = cmLine;
	Scope.Channels[ 0 ].Points.Visible = false;
	Scope.Channels[ 0 ].Width = 1;
	Scope.Channels[ 1 ].ChannelMode = cmLine;
	Scope.Channels[ 1 ].Points.Visible = false;
	Scope.Channels[ 1 ].Width = 1;

	Scope.Title.Text = "Scope Lines";
}

void CSimpleScopeDlg::OnBarsButton()
{
	// TODO: Add your control notification handler code here
	Scope.Channels[ 0 ].ChannelMode = cmBar;
	Scope.Channels[ 0 ].Points.Visible = false;
	Scope.Channels[ 0 ].Width = 3;

	Scope.Channels[ 1 ].ChannelMode = cmBar;	
	Scope.Channels[ 1 ].Points.Visible = false;
	Scope.Channels[ 1 ].Width = 3;

	Scope.Title.Text = "Scope Bars";
}

void CSimpleScopeDlg::OnPointsButton()
{
	// TODO: Add your control notification handler code here
	Scope.Channels[ 0 ].ChannelMode = cmPoint;
	Scope.Channels[ 0 ].Points.Visible = false;
	Scope.Channels[ 1 ].ChannelMode = cmPoint;	
	Scope.Channels[ 1 ].Points.Visible = false;

	Scope.Title.Text = "Scope Points";
}

void CSimpleScopeDlg::OnPlusButton() 
{
	// TODO: Add your control notification handler code here
	Scope.Channels[ 0 ].ChannelMode = cmPoint;
	Scope.Channels[ 0 ].Points.Visible = true;
	Scope.Channels[ 0 ].Points.Shape = psPlus;
	Scope.Channels[ 1 ].ChannelMode = cmPoint;	
	Scope.Channels[ 1 ].Points.Visible = true;
	Scope.Channels[ 1 ].Points.Shape = psPlus;

	Scope.Title.Text = "Scope (+)Points";
}
