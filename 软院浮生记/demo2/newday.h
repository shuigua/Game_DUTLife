#if !defined(AFX_NEWDAY_H__A0A33AC3_21DB_4C12_B7AE_824356239816__INCLUDED_)
#define AFX_NEWDAY_H__A0A33AC3_21DB_4C12_B7AE_824356239816__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// newday.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// newday dialog

class newday : public CDialog
{
// Construction
public:
	newday(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(newday)
	enum { IDD = IDD_DIALOG_newday };
	CString	m_newday;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(newday)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(newday)
	afx_msg void OnButton_ok();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NEWDAY_H__A0A33AC3_21DB_4C12_B7AE_824356239816__INCLUDED_)
