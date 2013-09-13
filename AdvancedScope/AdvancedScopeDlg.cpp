// AdvancedScopeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "AdvancedScope.h"
#include "AdvancedScopeDlg.h"

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
// CAdvancedScopeDlg dialog

CAdvancedScopeDlg::CAdvancedScopeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAdvancedScopeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAdvancedScopeDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAdvancedScopeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAdvancedScopeDlg)
	DDX_Control(pDX, IDC_VERTICAL_CHECK, m_VerticalCheck);
	DDX_Control(pDX, IDC_REVERSED_CHECK, m_ReversedCheck);
	DDX_Control(pDX, IDC_LOGARITHMIC_Y_CHECK, m_LogarithmicYCheck);
	DDX_Control(pDX, IDC_LOGARITHMIC_X_CHECK, m_LogarithmicXCheck);
	DDX_Control(pDX, IDC_CUSTOM_STEP_Y_CHECK, m_CustomStepYCheck);
	DDX_Control(pDX, IDC_CUSTOM_STEP_X_CHECK, m_CustomStepXCheck);
	DDX_Control(pDX, IDC_CUSTOM_LABEL_Y_CHECK, m_CustomLabelYCheck);
	DDX_Control(pDX, IDC_CUSTOM_LABEL_X_CHECK, m_CustomLabelXCheck);
	DDX_Control(pDX, IDC_LINKS_LEGEND_CHECK, m_LinksLegendCheckBox);
	DDX_Control(pDX, IDC_SELECTION_CHECK, m_SelectionCheckBox);
	DDX_Control(pDX, IDC_MEASUREMENT_CHECK, m_MeasurementCheckBox);
	DDX_Control(pDX, IDC_CURSORS_LEGEND_CHECK, m_CursorsLegendCheckBox);
	DDX_Control(pDX, IDC_CHANNEL1_LINK_CHECK, m_Channel1LinkCheckBox);
	DDX_Control(pDX, IDC_CHANNEL0_LINK_CHECK, m_Channel0LinkCheckBox);
	DDX_Control(pDX, IDC_H_CURSOR_CHECK, m_HCursorCheckBox);
	DDX_Control(pDX, IDC_V_CURSOR_CHECK, m_VCursorCheckBox);
	DDX_Control(pDX, IDC_MARKERS_LEGEND_CHECK, m_MarkersLegendCheckBox);
	DDX_Control(pDX, IDC_MARKERS_CHECK, m_MarkersCheckBox);
	DDX_Control(pDX, IDC_CHANNELS_LEGEND_CHECK, m_ChannelsLegendCheckBox);
	DDX_Control(pDX, IDC_CHANNEL1_CHECK, m_Channel1CheckBox);
	DDX_Control(pDX, IDC_CHANNEL0_CHECK, m_Channel0CheckBox);
	DDX_Control(pDX, ID_VCSCOPE, m_Scope);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAdvancedScopeDlg, CDialog)
	//{{AFX_MSG_MAP(CAdvancedScopeDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_CHANNEL0_CHECK, OnChannel0Check)
	ON_BN_CLICKED(IDC_CHANNEL1_CHECK, OnChannel1Check)
	ON_BN_CLICKED(IDC_CHANNELS_LEGEND_CHECK, OnChannelsLegendCheck)
	ON_BN_CLICKED(IDC_MARKERS_CHECK, OnMarkersCheck)
	ON_BN_CLICKED(IDC_MARKERS_LEGEND_CHECK, OnMarkersLegendCheck)
	ON_BN_CLICKED(IDC_V_CURSOR_CHECK, OnVCursorCheck)
	ON_BN_CLICKED(IDC_H_CURSOR_CHECK, OnHCursorCheck)
	ON_BN_CLICKED(IDC_CHANNEL0_LINK_CHECK, OnChannel0LinkCheck)
	ON_BN_CLICKED(IDC_CHANNEL1_LINK_CHECK, OnChannel1LinkCheck)
	ON_BN_CLICKED(IDC_CURSORS_LEGEND_CHECK, OnCursorsLegendCheck)
	ON_BN_CLICKED(IDC_MEASUREMENT_CHECK, OnMeasurementCheck)
	ON_BN_CLICKED(IDC_SELECTION_CHECK, OnSelectionCheck)
	ON_BN_CLICKED(IDC_LINKS_LEGEND_CHECK, OnLinksLegendCheck)
	ON_BN_CLICKED(IDC_LOGARITHMIC_Y_CHECK, OnLogarithmicYCheck)
	ON_BN_CLICKED(IDC_LOGARITHMIC_X_CHECK, OnLogarithmicXCheck)
	ON_BN_CLICKED(IDC_CUSTOM_LABEL_X_CHECK, OnCustomLabelXCheck)
	ON_BN_CLICKED(IDC_CUSTOM_STEP_X_CHECK, OnCustomStepXCheck)
	ON_BN_CLICKED(IDC_CUSTOM_LABEL_Y_CHECK, OnCustomLabelYCheck)
	ON_BN_CLICKED(IDC_CUSTOM_STEP_Y_CHECK, OnCustomStepYCheck)
	ON_BN_CLICKED(IDC_REVERSED_CHECK, OnReversedCheck)
	ON_BN_CLICKED(IDC_VERTICAL_CHECK, OnVerticalCheck)
	ON_BN_CLICKED(IDC_LOGARITHMIC_X_CHECK, OnLogarithmicXCheck)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAdvancedScopeDlg message handlers

BOOL CAdvancedScopeDlg::OnInitDialog()
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

	// Setup the Scope.
	Scope.Open( m_Scope.m_hWnd );
	Scope.Channels.Clear();
	Scope.Channels.Add( 2 );
	Scope.Channels[ 0 ].Name = "Channel0";
	Scope.Channels[ 0 ].Color = RGB( 0, 128, 128 );

	Scope.Channels[ 1 ].Name = "Channel1";
	Scope.Channels[ 1 ].Color = RGB( 128, 128, 0 );

	Scope.MarkerGroups.Clear();
	Scope.MarkerGroups.Add( 4 );

	Scope.MarkerGroups[ 0 ].Name = "Max";
	Scope.MarkerGroups[ 0 ].Shape = msTriangleDown;
	Scope.MarkerGroups[ 0 ].Size = 5;
	Scope.MarkerGroups[ 0 ].Pen.Color = RGB( 255, 0, 0 );
	Scope.MarkerGroups[ 0 ].Labels.Text = "Max value %Y at %X";


	Scope.MarkerGroups[ 1 ].Name = "Min";
	Scope.MarkerGroups[ 1 ].Shape = msTriangleUp;
	Scope.MarkerGroups[ 1 ].Size = 5;
	Scope.MarkerGroups[ 1 ].Pen.Color = RGB( 0, 255, 0 );
	Scope.MarkerGroups[ 1 ].Labels.Text = "Min value %Y at %X";

	Scope.MarkerGroups[ 2 ].Name = "Above 12000";
	Scope.MarkerGroups[ 2 ].Shape = msPlus;
	Scope.MarkerGroups[ 2 ].Pen.Color = RGB( 255, 255, 0 );
	Scope.MarkerGroups[ 2 ].Brush.Color = RGB( 255, 255, 0 );

	Scope.MarkerGroups[ 3 ].Name = "Below -12000";
	Scope.MarkerGroups[ 3 ].Shape = msCircle;
	Scope.MarkerGroups[ 3 ].Pen.Color = RGB( 0, 0, 255 );
	Scope.MarkerGroups[ 3 ].Brush.Color = RGB( 0, 0, 255 );

	Scope.XAxis.MajorTicks.Step = 3;
	Scope.YAxis.MajorTicks.Step = 2000;
	
	Scope.Cursors.Clear();
	Scope.Cursors.Add( 4 );

	Scope.Cursors[ 0 ].Position.X =  30.0;
	Scope.Cursors[ 1 ].Position.X =  70.0;

	Scope.Cursors[ 2 ].Kind = ckHorizontal;
	Scope.Cursors[ 3 ].Kind = ckHorizontal;

	Scope.Cursors[ 2 ].Position.Y =  5500.0;
	Scope.Cursors[ 3 ].Position.Y =  -5500.0;

	Scope.CursorLinks.Clear();
	Scope.CursorLinks.Add( 2 );

	Scope.CursorLinks[ 0 ].MeasurementLine.Y = 50.0;

	Scope.CursorLinks[ 1 ].BeginCursorIndex = 2;
	Scope.CursorLinks[ 1 ].EndCursorIndex = 3;

	Scope.XAxis.OnCustomLabel.Set( this, &CAdvancedScopeDlg::OnCustomXAxesLabel );
	Scope.YAxis.OnCustomLabel.Set( this, &CAdvancedScopeDlg::OnCustomYAxesLabel );
	Scope.XAxis.OnCustomStep.Set( this, &CAdvancedScopeDlg::OnCustomXAxesStep );
	Scope.YAxis.OnCustomStep.Set( this, &CAdvancedScopeDlg::OnCustomYAxesStep );

	// Setup the check boxes.
	m_Channel0CheckBox.SetCheck( 1 );
	m_Channel1CheckBox.SetCheck( 1 );
	m_ChannelsLegendCheckBox.SetCheck( 1 );

	m_MarkersCheckBox.SetCheck( 1 );
	m_MarkersLegendCheckBox.SetCheck( 1 );

	m_VCursorCheckBox.SetCheck( 1 );
	m_HCursorCheckBox.SetCheck( 1 );
	m_CursorsLegendCheckBox.SetCheck( 1 );

	m_MeasurementCheckBox.SetCheck( 1 );
	m_LinksLegendCheckBox.SetCheck( 1 );

	// Start data flow.
	SetTimer( 1, 10, NULL );	

	Counter = 0;
	
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CAdvancedScopeDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CAdvancedScopeDlg::OnPaint() 
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
HCURSOR CAdvancedScopeDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CAdvancedScopeDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	
	float SampleDataArray[ 100 ];
	int i;
	for( i = 0; i < 100; i ++ )
		SampleDataArray[ i ] = (float)( rand() - 16000 );

	Scope.Channels[ 0 ].Data.SetYData( SampleDataArray, 100 );

	double MaxValue = -20000;
	double MinValue = 20000;
	int MaxPosition = 0;
	int MinPosition = 0;

	CTSLScopeChannel AChannel = Scope.Channels[ 0 ];
	AChannel.Markers.Clear();

	for( i = 0; i < 100; i ++ )
	{
		if( MaxValue < SampleDataArray[ i ] )
		{
			MaxValue = SampleDataArray[ i ];
			MaxPosition = i;
		}

		if( MinValue > SampleDataArray[ i ] )
		{
			MinValue = SampleDataArray[ i ];
			MinPosition = i;
		}

		if( SampleDataArray[ i ] > 12000 )
		{
			AChannel.Markers.Add();
			CTSLScopeChannelMarker AMarker = AChannel.Markers[ AChannel.Markers.Count - 1 ];
			AMarker.MarkerGroupIndex = 2;
			AMarker.Position = i;
		}

		if( SampleDataArray[ i ] < -12000 )
		{
			AChannel.Markers.Add();
			CTSLScopeChannelMarker AMarker = AChannel.Markers[ AChannel.Markers.Count - 1 ];
			AMarker.MarkerGroupIndex = 3;
			AMarker.Position = i;
		}

	}

	AChannel.Markers.Add();
	CTSLScopeChannelMarker AMarkerMax = AChannel.Markers[ AChannel.Markers.Count - 1 ];
	AMarkerMax.MarkerGroupIndex = 0;
    AMarkerMax.Position = MaxPosition;

	AChannel.Markers.Add();
	CTSLScopeChannelMarker AMarkerMin = AChannel.Markers[ AChannel.Markers.Count - 1 ];
	AMarkerMin.MarkerGroupIndex = 1;
    AMarkerMin.Position = MinPosition;

	for( i = 0; i < 100; i ++ )
		SampleDataArray[ i ] = (float)( ( Counter++ % 15 ) - 7 ) * 2000;

	Scope.Channels[ 1 ].Data.SetYData( SampleDataArray, 100 );

	CDialog::OnTimer(nIDEvent);
}

void CAdvancedScopeDlg::OnChannel0Check() 
{
	// TODO: Add your control notification handler code here
	Scope.Channels[ 0 ].Visible = ( m_Channel0CheckBox.GetCheck() != 0 );
}

void CAdvancedScopeDlg::OnChannel1Check() 
{
	// TODO: Add your control notification handler code here
	Scope.Channels[ 1 ].Visible = ( m_Channel1CheckBox.GetCheck() != 0 );
}

void CAdvancedScopeDlg::OnChannelsLegendCheck() 
{
	// TODO: Add your control notification handler code here
	Scope.Legend.Channels.Visible = ( m_ChannelsLegendCheckBox.GetCheck() != 0 );
}

void CAdvancedScopeDlg::OnMarkersCheck() 
{
	// TODO: Add your control notification handler code here
	for( int i = 0; i < Scope.MarkerGroups.Count; i ++ )
		Scope.MarkerGroups[ i ].Visible = ( m_MarkersCheckBox.GetCheck() != 0 );
    
}

void CAdvancedScopeDlg::OnMarkersLegendCheck() 
{
	// TODO: Add your control notification handler code here
	Scope.Legend.MarkerGroups.Visible = ( m_MarkersLegendCheckBox.GetCheck() != 0 );
}

void CAdvancedScopeDlg::OnVCursorCheck() 
{
	// TODO: Add your control notification handler code here
	for( int i = 0; i < Scope.Cursors.Count; i ++ )
		if( Scope.Cursors[ i ].Kind == ckVertical )
			Scope.Cursors[ i ].Visible = ( m_VCursorCheckBox.GetCheck() != 0 );

}

void CAdvancedScopeDlg::OnHCursorCheck() 
{
	// TODO: Add your control notification handler code here
	for( int i = 0; i < Scope.Cursors.Count; i ++ )
		if( Scope.Cursors[ i ].Kind == ckHorizontal )
			Scope.Cursors[ i ].Visible = ( m_HCursorCheckBox.GetCheck() != 0 );

}

void CAdvancedScopeDlg::OnChannel0LinkCheck() 
{
	// TODO: Add your control notification handler code here
	UpdateCnannelLinks();
}

void CAdvancedScopeDlg::OnChannel1LinkCheck() 
{
	// TODO: Add your control notification handler code here
	UpdateCnannelLinks();
}

void CAdvancedScopeDlg::OnCursorsLegendCheck() 
{
	// TODO: Add your control notification handler code here
	Scope.Legend.Cursors.Visible = ( m_CursorsLegendCheckBox.GetCheck() != 0 );
}

void CAdvancedScopeDlg::OnMeasurementCheck() 
{
	// TODO: Add your control notification handler code here
	for( int i = 0; i < Scope.CursorLinks.Count; i ++ )
		Scope.CursorLinks[ i ].MeasurementLine.Visible = ( m_MeasurementCheckBox.GetCheck() != 0 );

}

void CAdvancedScopeDlg::OnSelectionCheck() 
{
	// TODO: Add your control notification handler code here
	for( int i = 0; i < Scope.CursorLinks.Count; i ++ )
		Scope.CursorLinks[ i ].Selection.Visible = ( m_SelectionCheckBox.GetCheck() != 0 );

}

void CAdvancedScopeDlg::OnLinksLegendCheck() 
{
	// TODO: Add your control notification handler code here
	Scope.Legend.CursorLinks.Visible = ( m_LinksLegendCheckBox.GetCheck() != 0 );
}

void CAdvancedScopeDlg::UpdateCnannelLinks()
{
	for( int i = 0; i < Scope.Cursors.Count; i ++ )
	{
		Scope.Cursors[ i ].Channels.Clear();
	    if( m_Channel0LinkCheckBox.GetCheck() )
		{
			Scope.Cursors[ i ].Channels.Add();
			CTSLDisplayCursorChannelLink AChannelLink = Scope.Cursors[ i ].Channels[ Scope.Cursors[ i ].Channels.Count - 1 ];
			AChannelLink.ChannelIndex = 0;
		}

	    if( m_Channel1LinkCheckBox.GetCheck() )
		{
			Scope.Cursors[ i ].Channels.Add();
			CTSLDisplayCursorChannelLink AChannelLink = Scope.Cursors[ i ].Channels[ Scope.Cursors[ i ].Channels.Count - 1 ];
			AChannelLink.ChannelIndex = 1;
		}
	}
}

void CAdvancedScopeDlg::OnCustomLabelXCheck() 
{
	Scope.InvalidateRefresh();
}

void CAdvancedScopeDlg::OnCustomStepXCheck() 
{
	if( m_CustomStepXCheck.GetCheck() != 0 )
		Scope.XAxis.MajorTicks.Mode = mtmCustom;

	else
		Scope.XAxis.MajorTicks.Mode = mtmAuto;

}

void CAdvancedScopeDlg::OnCustomLabelYCheck() 
{
	Scope.InvalidateRefresh();
}

void CAdvancedScopeDlg::OnCustomStepYCheck() 
{
	if( m_CustomStepYCheck.GetCheck() != 0 )
		Scope.YAxis.MajorTicks.Mode = mtmCustom;

	else
		Scope.YAxis.MajorTicks.Mode = mtmAuto;

}

void __stdcall CAdvancedScopeDlg::OnCustomXAxesLabel( void *Sender, double Value, CString & )
{
	if( m_CustomLabelXCheck.GetCheck() != 0 )
	{
		CString str;
		str.Format( "Sample : %d", (int)( Value + 0.5 ));

		Scope.XAxis.SetTickText( str );
	}
}

void __stdcall CAdvancedScopeDlg::OnCustomYAxesLabel( void *Sender, double Value, CString & )
{
	if( m_CustomLabelYCheck.GetCheck() != 0 )
	{
		CString str;
		str.Format( "%d K", (int)( Value / 1000 + 0.5 ));

		Scope.YAxis.SetTickText( str );
	}
}

void __stdcall CAdvancedScopeDlg::OnCustomXAxesStep(VCLHANDLE Sender, double SampleValue, double & Step, bool & Draw)
{
	if( m_CustomStepXCheck.GetCheck() == 0 )
		return;
    
	if( (int)( SampleValue + 0.5 ) == 12 )
		Draw = false;

	if( (int)( SampleValue + 0.5 ) == 24 )
		Draw = false;

	if( (int)( SampleValue + 0.5 ) == 48 )
	    Step = 20;

	if( (int)( SampleValue + 0.5 ) > 80 )
		Step = 2;

}

void __stdcall CAdvancedScopeDlg::OnCustomYAxesStep(VCLHANDLE Sender, double SampleValue, double & Step, bool & Draw)
{
	if( m_CustomStepYCheck.GetCheck() == 0 )
		return;

	if( SampleValue >= 8000 )
		Step = 4000;
}

void CAdvancedScopeDlg::OnReversedCheck() 
{
	Scope.YAxis.Reversed = ( m_ReversedCheck.GetCheck() != 0 );	
}

void CAdvancedScopeDlg::OnVerticalCheck() 
{
	Scope.Vertical = ( m_VerticalCheck.GetCheck() != 0 );	
}

void CAdvancedScopeDlg::OnLogarithmicYCheck() 
{
	if( m_LogarithmicYCheck.GetCheck() != 0 )
		Scope.YAxis.ScaleMode = smLogarithmic;

	else
		Scope.YAxis.ScaleMode = smLinear;
}

void CAdvancedScopeDlg::OnLogarithmicXCheck() 
{
	if( m_LogarithmicXCheck.GetCheck() != 0 )
		Scope.XAxis.ScaleMode = smLogarithmic;

	else
		Scope.XAxis.ScaleMode = smLinear;
}
