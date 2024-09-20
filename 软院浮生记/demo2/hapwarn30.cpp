// hapwarn30.cpp : implementation file
//

#include "stdafx.h"
#include "demo2.h"
#include "hapwarn30.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// hapwarn30 dialog


hapwarn30::hapwarn30(CWnd* pParent /*=NULL*/)
	: CDialog(hapwarn30::IDD, pParent)
{
	//{{AFX_DATA_INIT(hapwarn30)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void hapwarn30::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(hapwarn30)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(hapwarn30, CDialog)
	//{{AFX_MSG_MAP(hapwarn30)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// hapwarn30 message handlers
