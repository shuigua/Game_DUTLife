// newday.cpp : implementation file
//

#include "stdafx.h"
#include "demo2.h"
#include "newday.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// newday dialog


newday::newday(CWnd* pParent /*=NULL*/)
	: CDialog(newday::IDD, pParent)
{
	//{{AFX_DATA_INIT(newday)
	m_newday = _T("");
	//}}AFX_DATA_INIT
}


void newday::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(newday)
	DDX_Text(pDX, IDC_STATIC_newday, m_newday);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(newday, CDialog)
	//{{AFX_MSG_MAP(newday)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton_ok)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// newday message handlers

void newday::OnButton_ok() 
{
	// TODO: Add your control notification handler code here
	EndDialog(0);
}
