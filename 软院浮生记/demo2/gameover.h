#if !defined(AFX_GAMEOVER_H__BDAEBDF8_BD64_45D5_A5F5_080786C5A067__INCLUDED_)
#define AFX_GAMEOVER_H__BDAEBDF8_BD64_45D5_A5F5_080786C5A067__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// gameover.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// gameover dialog

class gameover : public CDialog
{
// Construction
public:
	gameover(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(gameover)
	enum { IDD = IDD_DIALOG_gameover };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(gameover)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(gameover)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GAMEOVER_H__BDAEBDF8_BD64_45D5_A5F5_080786C5A067__INCLUDED_)
