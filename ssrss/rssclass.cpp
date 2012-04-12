//implementation file for rssclass.h

#include "stdafx.h"
#include "rssclass.h"

//lazy programming !! this should be encapsulated higher!
 
CString GetRightDate(){
   TIME_ZONE_INFORMATION tz;
    int bias;
	char formattedDate[100];
	int bufSize = 100;

    if (GetTimeZoneInformation(&tz) == TIME_ZONE_ID_DAYLIGHT)
	{
	bias = tz.Bias + tz.DaylightBias;
	}
    else
	{
	bias = tz.Bias;
	}

    char biasStr[60];
    sprintf(biasStr,"%+.2d%.2d",-bias/60, bias%60);

    time_t currentTime = time(0);
    struct tm *tmPtr = localtime(&currentTime);

    strftime(formattedDate,bufSize,"%a, %d %b %Y %H:%M:%S ",tmPtr);
    strcat(formattedDate,biasStr);
	CString returnvalue = formattedDate;
	return returnvalue;
}



RssEntry::RssEntry(CString NewEntry, CString cEntryTitle, CString cEntryLink)
{
	EntryTitle = cEntryTitle;
	Entry = NewEntry;
	SYSTEMTIME systime;
	GetLocalTime(&systime);
	CTime ctime(systime.wYear,systime.wMonth,systime.wDay, systime.wHour, systime.wMinute, systime.wSecond, -1);
	EntryDate = GetRightDate();
	EntryLink = cEntryLink;
}

RssEntry::RssEntry()
{
}

void RssEntry::ChangeEntry(CString NewEntry, CString cEntryTitle, CString cEntryLink)
{
	Entry = NewEntry;
	EntryTitle = cEntryTitle;
	SYSTEMTIME systime;
	GetLocalTime(&systime);
	CTime ctime(systime.wYear,systime.wMonth,systime.wDay, systime.wHour, systime.wMinute, systime.wSecond, -1);
	EntryDate = GetRightDate();
	EntryLink = cEntryLink;
}
void RssEntry::ChangeEntryWithDate(CString NewEntry, CString cEntryTitle, CString cEntryDate, CString cEntryLink)
{
	Entry = NewEntry;
	EntryTitle = cEntryTitle;
	EntryDate = cEntryDate;
	EntryLink = cEntryLink;

}


CString RssEntry::GetEntry()
{
	return Entry;
}
CString RssEntry::GetEntryTitle()
{
	return EntryTitle;
}

CString RssEntry::GetDateTime()
{
	return EntryDate;
}

void RssEntry::SetEqual(RssEntry RS)
{
	Entry = RS.GetEntry();
	EntryDate = RS.GetDateTime();
	EntryTitle = RS.GetEntryTitle();
	EntryLink = RS.GetEntryLink();
}
void RssEntry::Clear()
{
	Entry = "";
	EntryTitle = "";
	EntryDate = "";
	EntryLink = "";
}
CString RssEntry::GetEntryLink()
{
	return EntryLink;
}
