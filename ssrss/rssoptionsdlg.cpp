// rssoptionsdlg.cpp : implementation file
//

#include "stdafx.h"
#include "ssrss.h"
#include "rssoptionsdlg.h"
#include "mainrsscontainer.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern RssContainer Rss;

/////////////////////////////////////////////////////////////////////////////
// rssoptionsdlg dialog


rssoptionsdlg::rssoptionsdlg(CWnd* pParent /*=NULL*/)
	: CDialog(rssoptionsdlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(rssoptionsdlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void rssoptionsdlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(rssoptionsdlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(rssoptionsdlg, CDialog)
	//{{AFX_MSG_MAP(rssoptionsdlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// rssoptionsdlg message handlers

BOOL rssoptionsdlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	SetDlgItemText(IDC_EDIT_LINK,Rss.GetLink());
	SetDlgItemText(IDC_EDIT_DESC,Rss.GetDesc());
	SetDlgItemText(IDC_EDIT_COPYRIGHT,Rss.GetCopy());
	SetDlgItemText(IDC_EDIT_WEBMASTER,Rss.GetWeb());
	SetDlgItemText(IDC_RSS_TITLE,Rss.GetTitle());
	SetDlgItemText(IDC_RSS_TTL,Rss.GetTTL());

	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void rssoptionsdlg::OnOK() 
{
	AfxGetApp()->DoWaitCursor(1);
	CString cLink = "",cDesc = "",cCopy = "",cWeb = "";
	CString cTitleName = "", cTTL = "";
	GetDlgItemText(IDC_EDIT_LINK,cLink);
	GetDlgItemText(IDC_EDIT_DESC,cDesc);
	GetDlgItemText(IDC_EDIT_COPYRIGHT,cCopy);
	GetDlgItemText(IDC_EDIT_WEBMASTER,cWeb);
	GetDlgItemText(IDC_RSS_TITLE,cTitleName);
	GetDlgItemText(IDC_RSS_TTL,cTTL);
	Rss.ChangeTTL(cTTL);
	Rss.ChangeTitle(cTitleName);
	Rss.ChangeLink(cLink);
	Rss.ChangeDescription(cDesc);
	Rss.ChangeCopyRight(cCopy);
	Rss.ChangeWebmaster(cWeb);
	AfxGetApp()->DoWaitCursor(-1);
	Rss.bSaved = 0;
	CDialog::OnOK();
}
