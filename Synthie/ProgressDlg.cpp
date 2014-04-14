// ProgressDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Synthie.h"
#include "ProgressDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProgressDlg dialog


CProgressDlg::CProgressDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CProgressDlg::IDD, pParent), m_abort(false)
	, m_master(0)
{
	//{{AFX_DATA_INIT(CProgressDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CProgressDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CProgressDlg)
	//}}AFX_DATA_MAP
	DDX_Slider(pDX, IDC_MASTER, m_master);
	DDV_MinMaxInt(pDX, m_master, 0, 10);

}


BEGIN_MESSAGE_MAP(CProgressDlg, CDialog)
	//{{AFX_MSG_MAP(CProgressDlg)
	ON_BN_CLICKED(IDC_STOP, OnStop)
	//}}AFX_MSG_MAP
	ON_WM_VSCROLL()

END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProgressDlg message handlers

void CProgressDlg::OnStop() 
{
   m_abort = true;	
}

void CProgressDlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)  
{
	m_organ = m_synth.GetOrgan();
	m_master = nPos;
	m_organ->SetMaster(m_master);
}

bool CProgressDlg::Abort()
{
   // Allow any messages to be processed
   MSG msg;
   while (::PeekMessage(&msg, NULL, 
        NULL, NULL, PM_NOREMOVE)) {
        AfxGetThread()->PumpMessage();
   }

   return m_abort;
}
