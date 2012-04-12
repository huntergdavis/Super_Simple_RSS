#if !defined(AFX_HTTPADDRESSDLG_H__C5CC01B4_B6B6_45C9_A450_6AFF2468D6F3__INCLUDED_)
#define AFX_HTTPADDRESSDLG_H__C5CC01B4_B6B6_45C9_A450_6AFF2468D6F3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// httpaddressdlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// httpaddressdlg dialog

class httpaddressdlg : public CDialog
{
// Construction
public:
	httpaddressdlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(httpaddressdlg)
	enum { IDD = IDC_HTTP };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(httpaddressdlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(httpaddressdlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HTTPADDRESSDLG_H__C5CC01B4_B6B6_45C9_A450_6AFF2468D6F3__INCLUDED_)
