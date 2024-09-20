// demo2Dlg.h : header file
//

#if !defined(AFX_DEMO2DLG_H__B4B140D4_A67D_4ECF_A188_EEB8E83D4DB8__INCLUDED_)
#define AFX_DEMO2DLG_H__B4B140D4_A67D_4ECF_A188_EEB8E83D4DB8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDemo2Dlg dialog

class CDemo2Dlg : public CDialog
{
// Construction
public:
	CDemo2Dlg(CWnd* pParent = NULL);	// standard constructor
	int count;
	int happy30warn_count;
// Dialog Data
	//{{AFX_DATA(CDemo2Dlg)
	enum { IDD = IDD_DEMO2_DIALOG };
	int		m_day;
	int		m_happy;
	CString	m_out;
	int		m_remain;
	double	m_hap;
	double	m_sco;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDemo2Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation


	void morning_to_night_change();

protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDemo2Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBUTTONclass();
	afx_msg void OnBUTTONrest();
	afx_msg void OnBUTTONoutplay();
	afx_msg void OnBUTTONmeal();
	afx_msg void OnBUTTONactivity();
	afx_msg void OnBUTTONselfstudy();
	afx_msg void OnButtonhajime();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEMO2DLG_H__B4B140D4_A67D_4ECF_A188_EEB8E83D4DB8__INCLUDED_)
