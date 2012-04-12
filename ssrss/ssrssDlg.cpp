// ssrssDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ssrss.h"
#include "ssrssDlg.h"
#include "rssoptionsdlg.h"
#include "httpaddressdlg.h"
#include "mainrsscontainer.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

RssContainer Rss;
CString cHttpAddress;
bool bEntrySaved;
bool bCTRL;
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSsrssDlg dialog

CSsrssDlg::CSsrssDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSsrssDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSsrssDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSsrssDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSsrssDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSsrssDlg, CDialog)
	//{{AFX_MSG_MAP(CSsrssDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDRSS, OnRss)
	ON_BN_CLICKED(IDLoad, OnLoad)
	ON_BN_CLICKED(ID_SAVE, OnSave)
	ON_BN_CLICKED(IDC_DELETE_ENTRY, OnDeleteEntry)
	ON_BN_CLICKED(IDC_ADD_ENTRY, OnAddEntry)
	ON_BN_CLICKED(IDC_INSERT_LINK, OnInsertLink)
	ON_LBN_SELCHANGE(IDC_LIST_ENTRIES, OnSelchangeListEntries)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_NEW_ENTRY, OnNewEntry)
	ON_BN_CLICKED(ID_Close, OnClose)
	ON_BN_CLICKED(IDC_CLEAR, OnClear)
	ON_EN_UPDATE(IDC_RSS_ENTRY_TIME, OnUpdateRssEntryTime)
	ON_EN_UPDATE(IDC_RSS_ENTRY_TITLE, OnUpdateRssEntryTitle)
	ON_EN_UPDATE(IDC_RSS_EDIT_MAIN, OnUpdateRssEditMain)
	ON_BN_CLICKED(IDC_UPDATE_ENTRY, OnUpdateEntry)
	ON_BN_CLICKED(IDC_BUTTON_UP, OnButtonUp)
	ON_BN_CLICKED(IDC_BUTTON_DOWN, OnButtonDown)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSsrssDlg message handlers

BOOL CSsrssDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	bCTRL = 0;
	bEntrySaved = 1;
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSsrssDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSsrssDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

HCURSOR CSsrssDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSsrssDlg::OnRss() 
{
	rssoptionsdlg rsod;
	rsod.DoModal();

	//set the channel title
	SetDlgItemText(IDC_STATIC_CHANNEL_TITLE,"Channel Title: " + Rss.GetTitle());

}

void CSsrssDlg::OnLoad() 
{
	if(Rss.bSaved == 0)
	{
		if(AfxMessageBox("You Have Unsaved Data, Continue?",MB_YESNO|MB_ICONQUESTION,NULL) == IDNO)
		{}
		else
		{
			// luanch the file selection dialog 
			CFileDialog *fdlg = (CFileDialog *) new CFileDialog(TRUE,_T("*"),NULL,OFN_HIDEREADONLY,_T("Rss Files (.rss/.xml)|*.xml"), NULL);

			if(fdlg->DoModal() == IDOK)
			{
				OnClose();
				AfxGetApp()->DoWaitCursor(1);
				CString FileName = fdlg->GetPathName();
				Rss.ReadInRssAndPopulate(FileName);
				SetDlgItemText(IDC_FILEBOX,FileName);
				Rss.bSaved = 1;
				PopulateEntries();	
			}
				AfxGetApp()->DoWaitCursor(-1);
		}
	}
	else
	{
		// luanch the file selection dialog 
		CFileDialog *fdlg = (CFileDialog *) new CFileDialog(TRUE,_T("*"),NULL,OFN_HIDEREADONLY,_T("Rss Files (.rss/.xml)|*.xml"), NULL);

		if(fdlg->DoModal() == IDOK)
		{
			OnClose();
			AfxGetApp()->DoWaitCursor(1);
			CString FileName = fdlg->GetPathName();
			Rss.ReadInRssAndPopulate(FileName);
			SetDlgItemText(IDC_FILEBOX,FileName);
			Rss.bSaved = 1;
			PopulateEntries();	
		}
			AfxGetApp()->DoWaitCursor(-1);
	}
	
}

void CSsrssDlg::PopulateEntries()
{
	CListBox* lbEntries;
	lbEntries = (CListBox*)GetDlgItem(IDC_LIST_ENTRIES);
	
	for(int i = 0;i < Rss.GetNumberOfEntries();i++)
	{
		lbEntries->InsertString(i,Rss.GetTitleByNumber(i));
	}
	//set the channel title
	SetDlgItemText(IDC_STATIC_CHANNEL_TITLE,"Channel Title: " + Rss.GetTitle());

}

void CSsrssDlg::OnSave() 
{
	// luanch the file selection dialog 
	CFileDialog *fdlg = (CFileDialog *) new CFileDialog(FALSE,_T("xml"),NULL,OFN_HIDEREADONLY,_T("Rss Files (.rss/.xml)|*"), NULL);

	if(fdlg->DoModal() == IDOK)
	{

		CString myFileName = fdlg->GetPathName();
		
		SetDlgItemText(IDC_FILEBOX,myFileName);
		
		AfxGetApp()->DoWaitCursor(1);
		CString FileName = "";
		GetDlgItemText(IDC_FILEBOX,FileName);

		if(FileName.GetLength() < 2)
		{
			AfxMessageBox("Please Input FileName to Write Out To");
		}
		else
		{
			Rss.WriteOutRss(FileName);
			Rss.bSaved = 1;
		}
		Sleep(300);
		AfxGetApp()->DoWaitCursor(-1);
	}

	

}

void CSsrssDlg::OnDeleteEntry() 
{

	CListBox* lbEntries;
	lbEntries = (CListBox*)GetDlgItem(IDC_LIST_ENTRIES);
	int iItemNumber = 0;
	iItemNumber = lbEntries->GetCurSel();
	if(iItemNumber < 0)
	{
		
	}
	else
	{
		if(AfxMessageBox("This Will Delete the currently selected entry!  Are you sure?", MB_OKCANCEL | MB_ICONQUESTION | MB_TASKMODAL) == IDCANCEL)
			return;
		else
		{
			iItemNumber = 0;
			iItemNumber = lbEntries->GetCurSel();
			Rss.RemoveEntryByTitle(Rss.GetTitleByNumber(iItemNumber));
			lbEntries->DeleteString(iItemNumber);
		}
	}
		
}

void CSsrssDlg::OnAddEntry() 
{
	CListBox* lbEntries;
	lbEntries = (CListBox*)GetDlgItem(IDC_LIST_ENTRIES);
	int iItemNumber = 0;
	iItemNumber = lbEntries->GetCurSel();
	CString cEntryText;
	CString cEntryTitle;
	CString cEntryTime;
	CString cEntryLink;
	GetDlgItemText(IDC_RSS_EDIT_MAIN,cEntryText);
	GetDlgItemText(IDC_RSS_ENTRY_TITLE,cEntryTitle);
	GetDlgItemText(IDC_RSS_ENTRY_TIME,cEntryTime);
	GetDlgItemText(IDC_RSS_ENTRY_LINK,cEntryLink);
	Rss.AddEntryWithDate(cEntryText,cEntryTitle,cEntryTime,cEntryLink);
	lbEntries->InsertString(Rss.GetNumberOfEntries()-1,cEntryTitle);
	lbEntries->SetCurSel(iItemNumber + 1);
	Rss.bSaved = 0;
	SetDlgItemText(IDC_ADD_ENTRY,"Add Entry");
	SetDlgItemText(IDC_STATIC_ENTRY_TITLE,"Rss Entry Title:");
	SetDlgItemText(IDC_STATIC_ENTRY_TIME,"Rss Entry Time:");
	SetDlgItemText(IDC_STATIC_ENTRY_BOX,"Entry:");
}

void CSsrssDlg::OnInsertLink() 
{
	cHttpAddress = "";
	CEdit *pEdit;
	pEdit = (CEdit*)GetDlgItem(IDC_RSS_EDIT_MAIN);
	int iBeginSel = 0,iEndSel = 0, iSelectedSomething = 0;
	pEdit->GetSel(iBeginSel,iEndSel);


	CString cEditText = "";
	CString cSelectedText = "";
	CString cFinalHttp = "";

	if((iEndSel - iBeginSel) > 0)
	{
		pEdit->GetWindowText(cEditText);
		for(int i = iBeginSel;i<iEndSel;i++)
		{
			cSelectedText += cEditText.GetAt(i);
			if(cEditText.GetAt(i) != ' ')
				iSelectedSomething = 1;
		}
	}
	if(iSelectedSomething == 1)
	{
		httpaddressdlg hdlg;
		if(hdlg.DoModal() == IDOK)
		{
			CString cLeftSide = "";
			CString cRightSide = "";
			cLeftSide = cEditText.Left(iBeginSel);
			cRightSide = cEditText.Right(cEditText.GetLength() - iEndSel);
			cFinalHttp.Format("<a href=\"%s\">%s</a>",cHttpAddress,cSelectedText);
			cEditText = cLeftSide;
			cEditText += cFinalHttp;
			cEditText += cRightSide;
			SetDlgItemText(IDC_RSS_EDIT_MAIN,cEditText);

		}
		else
		{

		}
	}
	else
	{
		MessageBox("Please Select Text in Entry Box to Become HyperLink, *NOTE 'Rss Entry Link' field items are entered as normal web address, no <a href> hyperlinking is needed. (good example: http://www.hunterdavis.com)");
	}
}

void CSsrssDlg::OnSelchangeListEntries() 
{
	CString cAddText;
	GetDlgItemText(IDC_ADD_ENTRY,cAddText);

	if(cAddText == "*Add Entry")
	{
		if(AfxMessageBox("Current Entry Has Not Been Added, Continue Without Adding?",MB_YESNO|MB_ICONQUESTION,NULL) == IDNO)
		{
		
		}
		else
		{
			
			CListBox* lbEntries;
			lbEntries = (CListBox*)GetDlgItem(IDC_LIST_ENTRIES);
			int iItemNumber = 0;
			iItemNumber = lbEntries->GetCurSel();
			SetDlgItemText(IDC_RSS_EDIT_MAIN,Rss.GetEntryByNumber(iItemNumber));
			SetDlgItemText(IDC_RSS_ENTRY_TITLE,Rss.GetTitleByNumber(iItemNumber));
			SetDlgItemText(IDC_RSS_ENTRY_TIME,Rss.GetDateByNumber(iItemNumber));
			SetDlgItemText(IDC_RSS_ENTRY_LINK,Rss.GetLinkByNumber(iItemNumber));
			SetDlgItemText(IDC_ADD_ENTRY,"Add Entry");
			SetDlgItemText(IDC_STATIC_ENTRY_TITLE,"Rss Entry Title:");
			SetDlgItemText(IDC_STATIC_ENTRY_TIME,"Rss Entry Time:");
			SetDlgItemText(IDC_STATIC_ENTRY_BOX,"Entry:");
		}
	}
	else
	{
			CListBox* lbEntries;
			lbEntries = (CListBox*)GetDlgItem(IDC_LIST_ENTRIES);
			int iItemNumber = 0;
			iItemNumber = lbEntries->GetCurSel();
			SetDlgItemText(IDC_RSS_EDIT_MAIN,Rss.GetEntryByNumber(iItemNumber));
			SetDlgItemText(IDC_RSS_ENTRY_TITLE,Rss.GetTitleByNumber(iItemNumber));
			SetDlgItemText(IDC_RSS_ENTRY_TIME,Rss.GetDateByNumber(iItemNumber));
			SetDlgItemText(IDC_RSS_ENTRY_LINK,Rss.GetLinkByNumber(iItemNumber));
			SetDlgItemText(IDC_ADD_ENTRY,"Add Entry");
			SetDlgItemText(IDC_STATIC_ENTRY_TITLE,"Rss Entry Title:");
			SetDlgItemText(IDC_STATIC_ENTRY_TIME,"Rss Entry Time:");
			SetDlgItemText(IDC_STATIC_ENTRY_BOX,"Entry:");	
	}
}

void CSsrssDlg::OnButton1() 
{
	CAboutDlg cabd;
	cabd.DoModal();	
}

void CSsrssDlg::OnNewEntry() 
{

	CString cAddText;
	GetDlgItemText(IDC_ADD_ENTRY,cAddText);
	if(cAddText == "*Add Entry")
	{
		if(AfxMessageBox("Current Entry Has Not Been Added, Continue Without Adding?",MB_YESNO|MB_ICONQUESTION,NULL) == IDNO)
		{
		
		}
		else
		{
			SetDlgItemText(IDC_RSS_ENTRY_TITLE,"Set Title Here");
			SetDlgItemText(IDC_RSS_EDIT_MAIN,"Enter Text Here");
			SetDlgItemText(IDC_RSS_ENTRY_LINK,"Add Entry Link Here");

			//date
			CString EntryDate = Rss.GetCurrentRSSFormattedDate();

			SetDlgItemText(IDC_RSS_ENTRY_TIME,EntryDate);
			SetDlgItemText(IDC_ADD_ENTRY,"Add Entry");
			SetDlgItemText(IDC_STATIC_ENTRY_TITLE,"Rss Entry Title:");
			SetDlgItemText(IDC_STATIC_ENTRY_TIME,"Rss Entry Time:");
			SetDlgItemText(IDC_STATIC_ENTRY_BOX,"Entry:");
		}
	}
	else
	{


			SetDlgItemText(IDC_RSS_ENTRY_TITLE,"Set Title Here");
			SetDlgItemText(IDC_RSS_EDIT_MAIN,"Enter Text Here");
			SetDlgItemText(IDC_RSS_ENTRY_LINK,"Add Entry Link Here");

			//date
			CString EntryDate = Rss.GetCurrentRSSFormattedDate();

			SetDlgItemText(IDC_RSS_ENTRY_TIME,EntryDate);
			SetDlgItemText(IDC_ADD_ENTRY,"Add Entry");
			SetDlgItemText(IDC_STATIC_ENTRY_TITLE,"Rss Entry Title:");
			SetDlgItemText(IDC_STATIC_ENTRY_TIME,"Rss Entry Time:");
			SetDlgItemText(IDC_STATIC_ENTRY_BOX,"Entry:");	
	}

}

void CSsrssDlg::OnClose() 
{
	if(Rss.bSaved == 0)
	{
//		if(AfxMessageBox("You Have Unsaved Data, Exit Without Saving?",MB_YESNO|MB_ICONQUESTION,NULL) == IDNO)
//		{}
//		else
//		{
			
			Rss.ClearAll();
			SetDlgItemText(IDC_RSS_ENTRY_TITLE,"");
			SetDlgItemText(IDC_RSS_EDIT_MAIN,"");
			SetDlgItemText(IDC_FILEBOX,"");


			SetDlgItemText(IDC_EDIT_LINK,"");
			SetDlgItemText(IDC_EDIT_DESC,"");
			SetDlgItemText(IDC_EDIT_COPYRIGHT,"");
			SetDlgItemText(IDC_EDIT_WEBMASTER,"");
			SetDlgItemText(IDC_RSS_ENTRY_TIME,"");
			SetDlgItemText(IDC_RSS_ENTRY_LINK,"");
			SetDlgItemText(IDC_STATIC_CHANNEL_TITLE,"Channel Title:");

			SetDlgItemText(IDC_ADD_ENTRY,"Add Entry");
			SetDlgItemText(IDC_STATIC_ENTRY_TITLE,"Rss Entry Title:");
			SetDlgItemText(IDC_STATIC_ENTRY_TIME,"Rss Entry Time:");
			SetDlgItemText(IDC_STATIC_ENTRY_BOX,"Entry:");


			CListBox * clLister;
			clLister = (CListBox*)GetDlgItem(IDC_LIST_ENTRIES);
			int CLISTCOUNT = clLister->GetCount();
			for(int i = 0;i<CLISTCOUNT;i++)
			{
					clLister->DeleteString(0);
			}
//		}
	}
	else
	{
			Rss.ClearAll();
			SetDlgItemText(IDC_RSS_ENTRY_TITLE,"");
			SetDlgItemText(IDC_RSS_EDIT_MAIN,"");
			SetDlgItemText(IDC_FILEBOX,"");

			SetDlgItemText(IDC_RSS_ENTRY_LINK,"");
			SetDlgItemText(IDC_EDIT_LINK,"");
			SetDlgItemText(IDC_EDIT_DESC,"");
			SetDlgItemText(IDC_EDIT_COPYRIGHT,"");
			SetDlgItemText(IDC_EDIT_WEBMASTER,"");
			SetDlgItemText(IDC_RSS_ENTRY_TIME,"");

			SetDlgItemText(IDC_STATIC_CHANNEL_TITLE,"Channel Title:");

			SetDlgItemText(IDC_ADD_ENTRY,"Add Entry");
			SetDlgItemText(IDC_STATIC_ENTRY_TITLE,"Rss Entry Title:");
			SetDlgItemText(IDC_STATIC_ENTRY_TIME,"Rss Entry Time:");
			SetDlgItemText(IDC_STATIC_ENTRY_BOX,"Entry:");


			CListBox * clLister;
			clLister = (CListBox*)GetDlgItem(IDC_LIST_ENTRIES);
			int CLISTCOUNT = clLister->GetCount();
			for(int i = 0;i<CLISTCOUNT;i++)
			{
					clLister->DeleteString(0);
			}

	}
	
	
}

void CSsrssDlg::OnClear() 
{

	CString cAddText;
	GetDlgItemText(IDC_ADD_ENTRY,cAddText);
	if(cAddText == "*Add Entry")
	{
		if(AfxMessageBox("Current Entry Has Not Been Added, Continue Without Adding?",MB_YESNO|MB_ICONQUESTION,NULL) == IDNO)
		{
		
		}
		else
		{
			SetDlgItemText(IDC_RSS_ENTRY_TITLE,"");
			SetDlgItemText(IDC_RSS_EDIT_MAIN,"");
			SetDlgItemText(IDC_RSS_ENTRY_TIME,"");
			SetDlgItemText(IDC_ADD_ENTRY,"Add Entry");
			SetDlgItemText(IDC_RSS_ENTRY_LINK,"");
			SetDlgItemText(IDC_STATIC_ENTRY_TITLE,"Rss Entry Title:");
			SetDlgItemText(IDC_STATIC_ENTRY_TIME,"Rss Entry Time:");
			SetDlgItemText(IDC_STATIC_ENTRY_BOX,"Entry:");

		}
	}
	else
	{
		SetDlgItemText(IDC_RSS_ENTRY_TITLE,"");
		SetDlgItemText(IDC_RSS_EDIT_MAIN,"");
		SetDlgItemText(IDC_RSS_ENTRY_TIME,"");
		SetDlgItemText(IDC_RSS_ENTRY_LINK,"");
		SetDlgItemText(IDC_ADD_ENTRY,"Add Entry");
		SetDlgItemText(IDC_STATIC_ENTRY_TITLE,"Rss Entry Title:");
		SetDlgItemText(IDC_STATIC_ENTRY_TIME,"Rss Entry Time:");
		SetDlgItemText(IDC_STATIC_ENTRY_BOX,"Entry:");

	}
}

void CSsrssDlg::OnOK() 
{
	if(Rss.bSaved == 0)
	{
		if(AfxMessageBox("You Have Unsaved Data, Exit Without Saving?",MB_YESNO|MB_ICONQUESTION,NULL) == IDNO)
		{}
		else
		{
			CDialog::OnOK();
		}
	}
	else
	{
		CDialog::OnOK();
	}

}

void CSsrssDlg::OnUpdateRssEntryTime() 
{
	SetDlgItemText(IDC_ADD_ENTRY,"*Add Entry");
	SetDlgItemText(IDC_STATIC_ENTRY_TIME,"*Rss Entry Time:");
	bEntrySaved = 0;
}

void CSsrssDlg::OnUpdateRssEntryTitle() 
{
	SetDlgItemText(IDC_ADD_ENTRY,"*Add Entry");
	SetDlgItemText(IDC_STATIC_ENTRY_TITLE,"*Rss Entry Title:");
	bEntrySaved = 0;
}

void CSsrssDlg::OnUpdateRssEditMain() 
{
	SetDlgItemText(IDC_ADD_ENTRY,"*Add Entry");
	SetDlgItemText(IDC_STATIC_ENTRY_BOX,"*Entry:");
	bEntrySaved = 0;
}

BOOL CSsrssDlg::PreTranslateMessage(MSG* pMsg) 
{
   BOOL   bControl = (GetKeyState(VK_CONTROL) < 0);

	switch(pMsg->message)
	{
		case WM_KEYDOWN:
		{
			if(bControl)
			{
				switch(pMsg->wParam)
				{
				case 'k':
				case 'K':
					{
						OnClose();
						return TRUE;
					}
				case 'l':
				case 'L':
					{
						OnLoad();
						return TRUE;
					}
				case 's':
				case 'S':
					{
						OnSave();
						return TRUE;
					}
				case 'r':
				case 'R':
					{
						OnRss();
						return TRUE;
					}
				case 'e':
				case 'E':
					{
						OnOK();
						return TRUE;
					}
				case 'h':
				case 'H':
					{

						OnButton1();
						return TRUE;
					}
				case 'n':
				case 'N':
					{

						OnNewEntry();
						return TRUE;
					}
				case 'a':
				case 'A':
					{
						OnAddEntry();
						return TRUE;
					}
				case 'i':
				case 'I':
					{
						OnInsertLink();
						return TRUE;
					}
				case 'd':
				case 'D':
					{
						OnDeleteEntry();
						return TRUE;
					}
				}
			}
		case VK_RETURN:
		case VK_ESCAPE:
		{
			return 0;
		}
		}
	}
	return CDialog::PreTranslateMessage(pMsg);
}

void CSsrssDlg::OnUpdateEntry() 
{
	CListBox* lbEntries;
	lbEntries = (CListBox*)GetDlgItem(IDC_LIST_ENTRIES);
	int iItemNumber = 0;
	iItemNumber = lbEntries->GetCurSel();
	if(iItemNumber < 0)
	{
		
	}
	else
	{
		CString cEntryText;
		CString cEntryTitle;
		CString cEntryLink;
		GetDlgItemText(IDC_RSS_EDIT_MAIN,cEntryText);
		GetDlgItemText(IDC_RSS_ENTRY_TITLE,cEntryTitle);
		GetDlgItemText(IDC_RSS_ENTRY_LINK,cEntryLink);
		Rss.ChangeEntry(iItemNumber,cEntryText,cEntryTitle,cEntryLink);
		Rss.bSaved = 0;
		SetDlgItemText(IDC_ADD_ENTRY,"Add Entry");
		SetDlgItemText(IDC_STATIC_ENTRY_TITLE,"Rss Entry Title:");
		SetDlgItemText(IDC_STATIC_ENTRY_TIME,"Rss Entry Time:");
		SetDlgItemText(IDC_STATIC_ENTRY_BOX,"Entry:");
	}
}

void CSsrssDlg::OnButtonUp() 
{
	CListBox* lbEntries;
	lbEntries = (CListBox*)GetDlgItem(IDC_LIST_ENTRIES);
	int iItemNumber = 0;
	iItemNumber = lbEntries->GetCurSel();
	if(iItemNumber < 1)
	{
		
	}
	else
	{

		Rss.SwapEntries(iItemNumber,iItemNumber -1);
		Rss.bSaved = 0;
		ClearListBox();
		lbEntries->SetCurSel(iItemNumber-1);
		SetDlgItemText(IDC_ADD_ENTRY,"Add Entry");
		SetDlgItemText(IDC_STATIC_ENTRY_TITLE,"Rss Entry Title:");
		SetDlgItemText(IDC_STATIC_ENTRY_TIME,"Rss Entry Time:");
		SetDlgItemText(IDC_STATIC_ENTRY_BOX,"Entry:");
	}	
}

void CSsrssDlg::OnButtonDown() 
{
	CListBox* lbEntries;
	lbEntries = (CListBox*)GetDlgItem(IDC_LIST_ENTRIES);
	int iItemNumber = 0;
	iItemNumber = lbEntries->GetCurSel();
	int NumberOfEntries = lbEntries->GetCount();
	if( (iItemNumber < 0) || (iItemNumber == NumberOfEntries) )
	{
		
	}
	else
	{
		Rss.SwapEntries(iItemNumber,iItemNumber +1);
		ClearListBox();
		lbEntries->SetCurSel(iItemNumber+1);
		Rss.bSaved = 0;
		SetDlgItemText(IDC_ADD_ENTRY,"Add Entry");
		SetDlgItemText(IDC_STATIC_ENTRY_TITLE,"Rss Entry Title:");
		SetDlgItemText(IDC_STATIC_ENTRY_TIME,"Rss Entry Time:");
		SetDlgItemText(IDC_STATIC_ENTRY_BOX,"Entry:");

	}	
}

void CSsrssDlg::ClearListBox()
{

	CListBox * clLister;
	clLister = (CListBox*)GetDlgItem(IDC_LIST_ENTRIES);
	int CLISTCOUNT = clLister->GetCount();
	for(int i = 0;i<CLISTCOUNT;i++)
	{
			clLister->DeleteString(0);
	}
	PopulateEntries();
}