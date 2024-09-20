// warn30result.cpp : implementation file
//

#include "stdafx.h"
#include "demo2.h"
#include "warn30result.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// warn30result dialog


warn30result::warn30result(CWnd* pParent /*=NULL*/)
	: CDialog(warn30result::IDD, pParent)
{
	//{{AFX_DATA_INIT(warn30result)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void warn30result::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(warn30result)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(warn30result, CDialog)
	//{{AFX_MSG_MAP(warn30result)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// warn30result message handlers
