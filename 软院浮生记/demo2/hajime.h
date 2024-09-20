#if !defined(AFX_HAJIME_H__55649203_A7D5_4793_9CD8_3BE94991F531__INCLUDED_)
#define AFX_HAJIME_H__55649203_A7D5_4793_9CD8_3BE94991F531__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// hajime.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// hajime dialog

class hajime : public CDialog
{
// Construction
public:
	hajime(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(hajime)
	enum { IDD = IDD_DIALOG_hajime };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(hajime)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(hajime)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HAJIME_H__55649203_A7D5_4793_9CD8_3BE94991F531__INCLUDED_)
