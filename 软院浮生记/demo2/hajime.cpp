// hajime.cpp : implementation file
//

#include "stdafx.h"
#include "demo2.h"
#include "hajime.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// hajime dialog


hajime::hajime(CWnd* pParent /*=NULL*/)
	: CDialog(hajime::IDD, pParent)
{
	//{{AFX_DATA_INIT(hajime)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void hajime::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(hajime)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(hajime, CDialog)
	//{{AFX_MSG_MAP(hajime)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// hajime message handlers
