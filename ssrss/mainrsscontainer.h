#ifndef RSSCONTAINER_H_
#define RSSCONTAINER_H_

#include "rssclass.h"
#include "StdAfx.h"

class RssContainer
{

public:
	RssContainer();
	void AddEntry(CString Entry,CString EntryTitle, CString EntryLink);
	void AddEntryWithDate(CString Entry,CString EntryTitle,CString EntryDate, CString EntryLink);
	void ChangeEntry(int Num, CString Entry,CString EntryTitle, CString EntryLink);
	void ChangeLink(CString Link);
	void ChangeDescription(CString Desc);
	void ChangeCopyRight(CString Copy);
	void ChangeWebmaster(CString Web);
	void ChangeTitle(CString Title);
	void ChangeTTL(CString TTL);
	CString GetCurrentRSSFormattedDate();

	void SwapEntries(int NumA, int NumB);
	
	CString GetEntryByDate(CString EntryDate);
	void RemoveEntryByDate(CString EntryDate);
	void RemoveEntryByTitle(CString EntryTitle);
	int GetNumberOfEntries();
	CString GetDateByNumber(int Num);
	CString GetTitleByNumber(int Num);
	CString GetEntryByNumber(int Num);
	CString GetLinkByNumber(int Num);
	CString GetLink();
	CString GetDesc();
	CString GetCopy();
	CString GetTitle();
	CString GetWeb();
	CString GetTTL();

	bool ReadInRssAndPopulate(CString FileName);
	void WriteOutRss(CString FileName);
	void ReplaceIllegalCharactersCode();
	void InverseReplaceIllegalCharactersCode();
	void ClearAll();
	bool bSaved;

private:
	RssEntry RSE[1024];
	CString cLink;
	CString cDesc;
	CString cCopy;
	CString cWeb;
	CString cTitle;
	CString cTTL;
	int NumberOfEntries;

};
#endif