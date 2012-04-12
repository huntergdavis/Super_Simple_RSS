// httpaddressdlg.cpp : implementation file
//

#include "stdafx.h"
#include "ssrss.h"
#include "httpaddressdlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CString cHttpAddress;
/////////////////////////////////////////////////////////////////////////////
// httpaddressdlg dialog


httpaddressdlg::httpaddressdlg(CWnd* pParent /*=NULL*/)
	: CDialog(httpaddressdlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(httpaddressdlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void httpaddressdlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(httpaddressdlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(httpaddressdlg, CDialog)
	//{{AFX_MSG_MAP(httpaddressdlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// httpaddressdlg message handlers

void httpaddressdlg::OnOK() 
{
	
	GetDlgItemText(IDC_HTTP_EDIT,cHttpAddress);
	CDialog::OnOK();
}
