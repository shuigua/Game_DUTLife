#if !defined(AFX_HAPWARN30_H__AC5660FB_B94B_474D_A385_AD6529283E39__INCLUDED_)
#define AFX_HAPWARN30_H__AC5660FB_B94B_474D_A385_AD6529283E39__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// hapwarn30.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// hapwarn30 dialog

class hapwarn30 : public CDialog
{
// Construction
public:
	hapwarn30(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(hapwarn30)
	enum { IDD = IDD_DIALOG_low_hap_warn };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(hapwarn30)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(hapwarn30)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HAPWARN30_H__AC5660FB_B94B_474D_A385_AD6529283E39__INCLUDED_)
