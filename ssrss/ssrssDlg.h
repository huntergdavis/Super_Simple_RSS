// ssrssDlg.h : header file
//

#if !defined(AFX_SSRSSDLG_H__AD329FEF_C680_43FA_9F7D_95A8C33A406D__INCLUDED_)
#define AFX_SSRSSDLG_H__AD329FEF_C680_43FA_9F7D_95A8C33A406D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSsrssDlg dialog

class CSsrssDlg : public CDialog
{
// Construction
public:
	CSsrssDlg(CWnd* pParent = NULL);	// standard constructor
	void PopulateEntries();
	void ClearListBox();

// Dialog Data
	//{{AFX_DATA(CSsrssDlg)
	enum { IDD = IDD_SSRSS_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSsrssDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSsrssDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnRss();
	afx_msg void OnLoad();
	afx_msg void OnSave();
	afx_msg void OnDeleteEntry();
	afx_msg void OnAddEntry();
	afx_msg void OnInsertLink();
	afx_msg void OnSelchangeListEntries();
	afx_msg void OnButton1();
	afx_msg void OnNewEntry();
	afx_msg void OnClose();
	afx_msg void OnClear();
	virtual void OnOK();
	afx_msg void OnUpdateRssEntryTime();
	afx_msg void OnUpdateRssEntryTitle();
	afx_msg void OnUpdateRssEditMain();
	afx_msg void OnUpdateEntry();
	afx_msg void OnButtonUp();
	afx_msg void OnButtonDown();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SSRSSDLG_H__AD329FEF_C680_43FA_9F7D_95A8C33A406D__INCLUDED_)
