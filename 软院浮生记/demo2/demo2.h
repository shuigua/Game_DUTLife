// demo2.h : main header file for the DEMO2 application
//

#if !defined(AFX_DEMO2_H__057B3862_C9D5_4A71_9254_81975F9CDACE__INCLUDED_)
#define AFX_DEMO2_H__057B3862_C9D5_4A71_9254_81975F9CDACE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDemo2App:
// See demo2.cpp for the implementation of this class
//

class CDemo2App : public CWinApp
{
public:
	CDemo2App();
	
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDemo2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDemo2App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEMO2_H__057B3862_C9D5_4A71_9254_81975F9CDACE__INCLUDED_)
