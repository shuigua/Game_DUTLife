#if !defined(AFX_WARN30RESULT_H__51B17E0A_F206_440E_A733_19240F18C8F2__INCLUDED_)
#define AFX_WARN30RESULT_H__51B17E0A_F206_440E_A733_19240F18C8F2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// warn30result.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// warn30result dialog

class warn30result : public CDialog
{
// Construction
public:
	warn30result(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(warn30result)
	enum { IDD = IDD_DIALOG_low_hap_result };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(warn30result)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(warn30result)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WARN30RESULT_H__51B17E0A_F206_440E_A733_19240F18C8F2__INCLUDED_)
