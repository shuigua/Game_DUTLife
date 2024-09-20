#if !defined(AFX_GAMEPASS_H__9377BE34_6002_4F31_A1CE_B0210999945B__INCLUDED_)
#define AFX_GAMEPASS_H__9377BE34_6002_4F31_A1CE_B0210999945B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// gamepass.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// gamepass dialog

class gamepass : public CDialog
{
// Construction
public:
	gamepass(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(gamepass)
	enum { IDD = IDD_DIALOG_gamepass };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(gamepass)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(gamepass)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GAMEPASS_H__9377BE34_6002_4F31_A1CE_B0210999945B__INCLUDED_)
