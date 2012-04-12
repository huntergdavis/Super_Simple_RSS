// ssrss.h : main header file for the SSRSS application
//

#if !defined(AFX_SSRSS_H__7F13515A_0A41_4546_A4E2_6E1EB005A79A__INCLUDED_)
#define AFX_SSRSS_H__7F13515A_0A41_4546_A4E2_6E1EB005A79A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSsrssApp:
// See ssrss.cpp for the implementation of this class
//

class CSsrssApp : public CWinApp
{
public:
	CSsrssApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSsrssApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSsrssApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SSRSS_H__7F13515A_0A41_4546_A4E2_6E1EB005A79A__INCLUDED_)
