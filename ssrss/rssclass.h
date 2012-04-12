#ifndef SSRSSDLG_H_
#define SSRSSDLG_H_

#include "StdAfx.h"

class RssEntry
{

public:
	RssEntry(CString NewEntry, CString cEntryTitle, CString cEntryLink);
	RssEntry();

	void ChangeEntry(CString NewEntry, CString cEntryTitle, CString cEntryLink);
	void ChangeEntryWithDate(CString NewEntry, CString cEntryTitle, CString EntryDate, CString cEntryLink);
	CString GetEntry();
	CString GetDateTime();
	CString GetEntryTitle();
	CString GetEntryLink();
	void SetEqual(RssEntry RS);
	void Clear();


private:
	CString Entry;
	CString EntryTitle;
	CString EntryDate;
	CString EntryLink;

};
#endif

