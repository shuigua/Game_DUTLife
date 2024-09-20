// gamepass.cpp : implementation file
//

#include "stdafx.h"
#include "demo2.h"
#include "gamepass.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// gamepass dialog


gamepass::gamepass(CWnd* pParent /*=NULL*/)
	: CDialog(gamepass::IDD, pParent)
{
	//{{AFX_DATA_INIT(gamepass)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void gamepass::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(gamepass)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(gamepass, CDialog)
	//{{AFX_MSG_MAP(gamepass)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// gamepass message handlers
