// gameover.cpp : implementation file
//

#include "stdafx.h"
#include "demo2.h"
#include "gameover.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// gameover dialog


gameover::gameover(CWnd* pParent /*=NULL*/)
	: CDialog(gameover::IDD, pParent)
{
	//{{AFX_DATA_INIT(gameover)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void gameover::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(gameover)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(gameover, CDialog)
	//{{AFX_MSG_MAP(gameover)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// gameover message handlers
