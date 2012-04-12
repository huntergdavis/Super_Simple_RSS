; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSsrssDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ssrss.h"

ClassCount=5
Class1=CSsrssApp
Class2=CSsrssDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_RSSOPTIONS
Resource2=IDR_MAINFRAME
Resource3=IDD_SSRSS_DIALOG
Class4=rssoptionsdlg
Resource4=IDD_ABOUTBOX
Class5=httpaddressdlg
Resource5=IDC_HTTP

[CLS:CSsrssApp]
Type=0
HeaderFile=ssrss.h
ImplementationFile=ssrss.cpp
Filter=N

[CLS:CSsrssDlg]
Type=0
HeaderFile=ssrssDlg.h
ImplementationFile=ssrssDlg.cpp
Filter=D
LastObject=IDC_BUTTON_DOWN
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=ssrssDlg.h
ImplementationFile=ssrssDlg.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=5
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_STATIC,static,1342308352

[DLG:IDD_SSRSS_DIALOG]
Type=1
Class=CSsrssDlg
ControlCount=26
Control1=IDC_LIST_ENTRIES,listbox,1352728835
Control2=IDC_DELETE_ENTRY,button,1342242816
Control3=ID_Close,button,1342242817
Control4=IDLoad,button,1342242817
Control5=IDC_FILEBOX,edit,1350631552
Control6=ID_SAVE,button,1342242817
Control7=IDC_RSS_ENTRY_TIME,edit,1350631552
Control8=IDC_RSS_ENTRY_TITLE,edit,1350631552
Control9=IDC_RSS_EDIT_MAIN,edit,1352732740
Control10=IDC_NEW_ENTRY,button,1342242816
Control11=IDC_ADD_ENTRY,button,1342242816
Control12=IDC_INSERT_LINK,button,1342242816
Control13=IDC_CLEAR,button,1342242816
Control14=IDRSS,button,1342242817
Control15=IDOK,button,1342242817
Control16=IDC_BUTTON1,button,1342242816
Control17=IDC_STATIC_ENTRY_BOX,static,1342308352
Control18=IDC_STATIC,static,1342308352
Control19=IDC_STATIC_ENTRY_TITLE,static,1342308352
Control20=IDC_STATIC_CHANNEL_TITLE,static,1342308352
Control21=IDC_STATIC_ENTRY_TIME,static,1342308352
Control22=IDC_RSS_ENTRY_LINK,edit,1350631552
Control23=IDC_STATIC_ENTRY_Link,static,1342308352
Control24=IDC_UPDATE_ENTRY,button,1342242816
Control25=IDC_BUTTON_DOWN,button,1342242816
Control26=IDC_BUTTON_UP,button,1342242816

[DLG:IDD_RSSOPTIONS]
Type=1
Class=rssoptionsdlg
ControlCount=14
Control1=IDC_RSS_TITLE,edit,1350631552
Control2=IDC_RSS_TTL,edit,1350631552
Control3=IDC_EDIT_LINK,edit,1350631552
Control4=IDC_EDIT_DESC,edit,1350631552
Control5=IDC_EDIT_COPYRIGHT,edit,1350631552
Control6=IDC_EDIT_WEBMASTER,edit,1350631552
Control7=IDOK,button,1342242817
Control8=IDCANCEL,button,1342242816
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352

[CLS:rssoptionsdlg]
Type=0
HeaderFile=rssoptionsdlg.h
ImplementationFile=rssoptionsdlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDOK
VirtualFilter=dWC

[CLS:httpaddressdlg]
Type=0
HeaderFile=httpaddressdlg.h
ImplementationFile=httpaddressdlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

[DLG:IDC_HTTP]
Type=1
Class=httpaddressdlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDC_HTTP_EDIT,edit,1350631552
Control3=IDC_STATIC,static,1342308352

