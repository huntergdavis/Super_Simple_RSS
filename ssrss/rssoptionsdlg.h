#if !defined(AFX_RSSOPTIONSDLG_H__0768D90E_5298_4E2C_8DEC_816BCDFBD15F__INCLUDED_)
#define AFX_RSSOPTIONSDLG_H__0768D90E_5298_4E2C_8DEC_816BCDFBD15F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// rssoptionsdlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// rssoptionsdlg dialog

class rssoptionsdlg : public CDialog
{
// Construction
public:
	rssoptionsdlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(rssoptionsdlg)
	enum { IDD = IDD_RSSOPTIONS };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(rssoptionsdlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(rssoptionsdlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RSSOPTIONSDLG_H__0768D90E_5298_4E2C_8DEC_816BCDFBD15F__INCLUDED_)
