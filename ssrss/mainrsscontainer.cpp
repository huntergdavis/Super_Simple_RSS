#include "StdAfx.h"
#include "mainrsscontainer.h"
#include <sys/stat.h>
#include <io.h>
#include <fstream>
#include <string>
#include <ios> 

using namespace std;

RssContainer::RssContainer()
{
	cLink = "";
	cDesc = "";
	cCopy = "";
	cWeb = "";
	cTitle = "";
	NumberOfEntries = 0;
	bSaved = 1;
};

void RssContainer::AddEntry(CString Entry,CString EntryTitle, CString EntryLink)
{
	RSE[NumberOfEntries].ChangeEntry(Entry,EntryTitle, EntryLink);
	NumberOfEntries++;
}
void RssContainer::AddEntryWithDate(CString Entry,CString EntryTitle,CString EntryDate, CString EntryLink)
{
	RSE[NumberOfEntries].ChangeEntryWithDate(Entry,EntryTitle,EntryDate, EntryLink);
	NumberOfEntries++;
}
void RssContainer::ChangeEntry(int Num, CString Entry,CString EntryTitle, CString EntryLink)
{
	if(Num > NumberOfEntries)
	{
		MessageBox(NULL,"Not A Valid Update Number","ERROR",NULL);
	}
	else
	{
		RSE[Num].ChangeEntry(Entry,EntryTitle,EntryLink);
	}
}
void RssContainer::SwapEntries(int NumA, int NumB)
{
	if( (NumA > NumberOfEntries) || (NumB > NumberOfEntries) )
	{
		MessageBox(NULL,"Not A Valid Update Number","ERROR",NULL);
	}
	else
	{
		RssEntry RssTemp;
		RssTemp.SetEqual(RSE[NumA]);
		RSE[NumA].SetEqual(RSE[NumB]);
		RSE[NumB].SetEqual(RssTemp);
	}
}
void RssContainer::ChangeLink(CString Link)
{
	cLink = Link;
}
void RssContainer::ChangeDescription(CString Desc)
{
	cDesc = Desc;
}
void RssContainer::ChangeCopyRight(CString Copy)
{
	cCopy = Copy;
}
void RssContainer::ChangeWebmaster(CString Web)
{
	cWeb = Web;
}
void RssContainer::ChangeTTL(CString TTL)
{
	cTTL = TTL;
}
void RssContainer::ChangeTitle(CString Title)
{
	cTitle = Title;
}
	
CString RssContainer::GetEntryByDate(CString EntryDate)
{
	
	for(int i = 0;i<NumberOfEntries;i++)
	{
		if(RSE[i].GetDateTime() == EntryDate)
		{
			return RSE[i].GetEntry();
		}
	}
	CString something = "Sorry Entry Not Found";
	return something;
}

void RssContainer::RemoveEntryByDate(CString EntryDate)
{
	RssEntry *RSECopy;
	RSECopy = new RssEntry[NumberOfEntries];
	int iEntryNumber = -1;

	for(int i = 0;i<NumberOfEntries;i++)
	{
		if(RSE[i].GetDateTime() == EntryDate)
			iEntryNumber = i;			
	}

	if(iEntryNumber != -1)
	{
		for(i = iEntryNumber;i<NumberOfEntries;i++)
		{
			RSECopy[i] = RSE[i];
		}
		for(i = iEntryNumber+1;i<NumberOfEntries;i++)
		{
			RSE[i-1].SetEqual(RSECopy[i]);
		}
		NumberOfEntries--;
	}
		
}

void RssContainer::RemoveEntryByTitle(CString EntryTitle)
{
	RssEntry *RSECopy;
	RSECopy = new RssEntry[NumberOfEntries];
	int iEntryNumber = -1;

	for(int i = 0;i<NumberOfEntries;i++)
	{
		if(RSE[i].GetEntryTitle() == EntryTitle)
			iEntryNumber = i;			
	}

	if(iEntryNumber != -1)
	{
		for(i = iEntryNumber;i<NumberOfEntries;i++)
		{
			RSECopy[i] = RSE[i];
		}
		for(i = iEntryNumber+1;i<NumberOfEntries;i++)
		{
			RSE[i-1].SetEqual(RSECopy[i]);
		}
		NumberOfEntries--;
	}
		
}
int RssContainer::GetNumberOfEntries()
{
	return NumberOfEntries;
}

CString RssContainer::GetDateByNumber(int Num)
{
	return RSE[Num].GetDateTime();
}

CString RssContainer::GetTitleByNumber(int Num)
{
	return RSE[Num].GetEntryTitle();
}
CString RssContainer::GetEntryByNumber(int Num)
{
	return RSE[Num].GetEntry();
}
CString RssContainer::GetLinkByNumber(int Num)
{
	return RSE[Num].GetEntryLink();
}

CString RssContainer::GetLink()
{
	return cLink;
}
CString RssContainer::GetDesc()
{
	return cDesc;
}
CString RssContainer::GetCopy()
{
	return cCopy;
}
CString RssContainer::GetTitle()
{
	return cTitle;
}
CString RssContainer::GetWeb()
{
	return cWeb;
}
CString RssContainer::GetTTL()
{
	return cTTL;
}
bool RssContainer::ReadInRssAndPopulate(CString FileName)
{
	//Read in the file
	struct stat my_stat;
	CString RssFileString;
	if((stat(FileName, &my_stat) == 0))
	{
		ifstream input_file (FileName, ios::in );
		char singledigit[9000];
			while(input_file.getline(singledigit,8000,'\n'))
			{
				RssFileString += singledigit;
			}
			input_file.close();
	}
	else
	{
		AfxMessageBox("File Not Found");
		return 0;
	}	
	//Ok Enough of reading in the file

	//parse the rss file
	CString RssFileStringCopy = RssFileString;
	RssFileStringCopy.MakeLower();

	//test for if was created using ssrss
	CString SSRSSCopy = RssFileStringCopy;
	CString CrappycCopy = "";
	int iSsfind = SSRSSCopy.Find("<generator>");
	int iSsfindpoo = SSRSSCopy.Find("</generator>");
	if(iSsfind == -1 || iSsfindpoo == -1)
	{
		return 0;
	}
	else
	{
		for(int i = iSsfind+11;i<iSsfindpoo;i++)
		{
			CrappycCopy += RssFileString.GetAt(i);
		}
		if(CrappycCopy != "Super Simple RSS")
		{
			AfxMessageBox("This File Was Not Created With SSRSS and cannot be read in.");
			return 0;
		}
	}

	//Get the Channel Title/////////
	int poo = RssFileStringCopy.Find("<title>");
	int poopoo = RssFileStringCopy.Find("</title>");
	if(poo == -1 || poopoo == -1)
	{
		return 0;
	}
	else
	{
		for(int i = poo+7;i<poopoo;i++)
		{
			cTitle += RssFileString.GetAt(i);
		}
		
		RssFileStringCopy = RssFileStringCopy.Right(RssFileStringCopy.GetLength() - poopoo);
		RssFileString = RssFileString.Right(RssFileString.GetLength() - poopoo);

	}

	//Get the channel link
	poo = RssFileStringCopy.Find("<link>");
	poopoo = RssFileStringCopy.Find("</link>");
	if(poo == -1 || poopoo == -1)
	{
		return 0;
	}
	else
	{
		for(int i = poo+6;i<poopoo;i++)
		{
			cLink += RssFileString.GetAt(i);
		}
		RssFileStringCopy = RssFileStringCopy.Right(RssFileStringCopy.GetLength() - poopoo);
		RssFileString = RssFileString.Right(RssFileString.GetLength() - poopoo);
	}

	//get the channel time to live
	poo = RssFileStringCopy.Find("<ttl>");
	poopoo = RssFileStringCopy.Find("</ttl>");
	if((poo == -1) && (poopoo == -1))
	{
		
	}
	else if(poo == -1 || poopoo == -1)
	{
		AfxMessageBox("we are sorry but this version of ssrss is not compatible with this file, most likely due to a missing <ttl></ttl> tag after the link tag");
		return 0;
	}
	else
	{
		for(int i = poo+5;i<poopoo;i++)
		{
			cTTL += RssFileString.GetAt(i);
		}
		RssFileStringCopy = RssFileStringCopy.Right(RssFileStringCopy.GetLength() - poopoo);
		RssFileString = RssFileString.Right(RssFileString.GetLength() - poopoo);
	}
	

	//Get the channel description
	poo = RssFileStringCopy.Find("<description>");
	poopoo = RssFileStringCopy.Find("</description>");
	if(poo == -1 || poopoo == -1)
	{
		return 0;
	}
	else
	{
		for(int i = poo+13;i<poopoo;i++)
		{
			cDesc += RssFileString.GetAt(i);
		}
		RssFileStringCopy = RssFileStringCopy.Right(RssFileStringCopy.GetLength() - poopoo);
		RssFileString = RssFileString.Right(RssFileString.GetLength() - poopoo);
	}

	//Get the channel copyright
	poo = RssFileStringCopy.Find("<copyright>");
	poopoo = RssFileStringCopy.Find("</copyright>");
	if(poo == -1 || poopoo == -1)
	{
		return 0;
	}
	else
	{
		for(int i = poo+11;i<poopoo;i++)
		{
			cCopy += RssFileString.GetAt(i);
		}
		RssFileStringCopy = RssFileStringCopy.Right(RssFileStringCopy.GetLength() - poopoo);
		RssFileString = RssFileString.Right(RssFileString.GetLength() - poopoo);
	}


	//Get the channel webmaster
	poo = RssFileStringCopy.Find("<webmaster>");
	poopoo = RssFileStringCopy.Find("</webmaster>");
	if(poo == -1 || poopoo == -1)
	{
		return 0;
	}
	else
	{
		for(int i = poo+11;i<poopoo;i++)
		{
			cWeb += RssFileString.GetAt(i);
		}
		RssFileStringCopy = RssFileStringCopy.Right(RssFileStringCopy.GetLength() - poopoo);
		RssFileString = RssFileString.Right(RssFileString.GetLength() - poopoo);
	}

	CString cTempTitle = "";
	CString cTempEntry = "";
	CString cTempDate = "";
	CString cTempLink = "";
	int iItemEndFind = -1;
	int KeepGoing = 0;

	while(KeepGoing != -1)
	{
		iItemEndFind = RssFileStringCopy.Find("</item>");
		//Get the item title
		poo = RssFileStringCopy.Find("<title>");
		poopoo = RssFileStringCopy.Find("</title>");
		if(poo == -1 || poopoo == -1)
		{
		}
		else
		{
			for(int i = poo+7;i<poopoo;i++)
			{
				cTempTitle += RssFileString.GetAt(i);
			}
		}

		//Get the item entry link
		poo = RssFileStringCopy.Find("<link>");
		poopoo = RssFileStringCopy.Find("</link>");
		if(poo == -1 || poopoo == -1)
		{
		}
		else
		{
			for(int i = poo+6;i<poopoo;i++)
			{
				cTempLink += RssFileString.GetAt(i);
			}
		}

		//Get the item entry
		poo = RssFileStringCopy.Find("<description>");
		poopoo = RssFileStringCopy.Find("</description>");
		if(poo == -1 || poopoo == -1)
		{
		}
		else
		{
			for(int i = poo+13;i<poopoo;i++)
			{
				cTempEntry += RssFileString.GetAt(i);
			}
		}

		//Get the item published date
		poo = RssFileStringCopy.Find("<pubdate>");
		poopoo = RssFileStringCopy.Find("</pubdate>");
		if(poo == -1 || poopoo == -1)
		{
		}
		else
		{
			for(int i = poo+9;i<poopoo;i++)
			{
				cTempDate += RssFileString.GetAt(i);
			}
		}

		AddEntryWithDate(cTempEntry,cTempTitle,cTempDate, cTempLink);
		RssFileStringCopy = RssFileStringCopy.Right(RssFileStringCopy.GetLength() - iItemEndFind - 6);
		RssFileString = RssFileString.Right(RssFileString.GetLength() - iItemEndFind - 6);	
		cTempTitle = "";
		cTempEntry = "";
		cTempDate = "";
		cTempLink = "";
		iItemEndFind = -1;		
		KeepGoing = RssFileStringCopy.Find("<item>");
	}

	ReplaceIllegalCharactersCode();
	return 1;
}
void RssContainer::ReplaceIllegalCharactersCode()
{
	cLink.Replace("&amp;","&");
	cLink.Replace("&lt;","<");
	cLink.Replace("&gt;",">");
	cLink.Replace("&apos;","'");
	cLink.Replace("&quot;","\"");

	cDesc.Replace("&amp;","&");
	cDesc.Replace("&lt;","<");
	cDesc.Replace("&gt;",">");
	cDesc.Replace("&apos;","'");
	cDesc.Replace("&quot;","\"");
	
	cCopy.Replace("&amp;","&");
	cCopy.Replace("&lt;","<");
	cCopy.Replace("&gt;",">");
	cCopy.Replace("&apos;","'");
	cCopy.Replace("&quot;","\"");

	cWeb.Replace("&amp;","&");
	cWeb.Replace("&lt;","<");
	cWeb.Replace("&gt;",">");
	cWeb.Replace("&apos;","'");
	cWeb.Replace("&quot;","\"");

	cTitle.Replace("&amp;","&");
	cTitle.Replace("&lt;","<");
	cTitle.Replace("&gt;",">");
	cTitle.Replace("&apos;","'");
	cTitle.Replace("&quot;","\"");

	CString cEntryChanger;
	CString cEntryTitleChanger;
	CString cEntryLinkChanger;
	for(int i = 0;i<NumberOfEntries;i++)
	{
		cEntryChanger = "";
		cEntryTitleChanger = "";
		cEntryChanger = RSE[i].GetEntry();
		cEntryTitleChanger = RSE[i].GetEntryTitle();
		cEntryLinkChanger = RSE[i].GetEntryLink();

		cEntryLinkChanger.Replace("&amp;","&");
		cEntryLinkChanger.Replace("&lt;","<");
		cEntryLinkChanger.Replace("&gt;",">");
		cEntryLinkChanger.Replace("&apos;","'");
		cEntryLinkChanger.Replace("&quot;","\"");


		cEntryChanger.Replace("&amp;","&");
		cEntryChanger.Replace("&lt;","<");
		cEntryChanger.Replace("&gt;",">");
		cEntryChanger.Replace("&apos;","'");
		cEntryChanger.Replace("&quot;","\"");

		cEntryTitleChanger.Replace("&amp;","&");
		cEntryTitleChanger.Replace("&lt;","<");
		cEntryTitleChanger.Replace("&gt;",">");
		cEntryTitleChanger.Replace("&apos;","'");
		cEntryTitleChanger.Replace("&quot;","\"");

		RSE[i].ChangeEntryWithDate(cEntryChanger,cEntryTitleChanger,RSE[i].GetDateTime(),cEntryLinkChanger);
	}

}

void RssContainer::InverseReplaceIllegalCharactersCode()
{

	cLink.Replace("&","&amp;");
	cLink.Replace("<","&lt;");
	cLink.Replace(">","&gt;");
	cLink.Replace("'","&apos;");
	cLink.Replace("\"","&quot;");

	cDesc.Replace("&","&amp;");
	cDesc.Replace("<","&lt;");
	cDesc.Replace(">","&gt;");
	cDesc.Replace("'","&apos;");
	cDesc.Replace("\"","&quot;");
	
	cCopy.Replace("&","&amp;");
	cCopy.Replace("<","&lt;");
	cCopy.Replace(">","&gt;");
	cCopy.Replace("'","&apos;");
	cCopy.Replace("\"","&quot;");

	cWeb.Replace("&","&amp;");
	cWeb.Replace("<","&lt;");
	cWeb.Replace(">","&gt;");
	cWeb.Replace("'","&apos;");
	cWeb.Replace("\"","&quot;");

	cTitle.Replace("&","&amp;");
	cTitle.Replace("<","&lt;");
	cTitle.Replace(">","&gt;");
	cTitle.Replace("'","&apos;");
	cTitle.Replace("\"","&quot;");

	CString cEntryChanger;
	CString cEntryTitleChanger;
	CString cEntryLinkChanger;
	for(int i = 0;i<NumberOfEntries;i++)
	{
		cEntryChanger = "";
		cEntryTitleChanger = "";
		cEntryChanger = RSE[i].GetEntry();
		cEntryTitleChanger = RSE[i].GetEntryTitle();
		cEntryLinkChanger = RSE[i].GetEntryLink();

		

		cEntryLinkChanger.Replace("&","&amp;");
		cEntryLinkChanger.Replace("<","&lt;");
		cEntryLinkChanger.Replace(">","&gt;");
		cEntryLinkChanger.Replace("'","&apos;");
		cEntryLinkChanger.Replace("\"","&quot;");

		cEntryChanger.Replace("&","&amp;");
		cEntryChanger.Replace("<","&lt;");
		cEntryChanger.Replace(">","&gt;");
		cEntryChanger.Replace("'","&apos;");
		cEntryChanger.Replace("\"","&quot;");

		cEntryTitleChanger.Replace("&","&amp;");
		cEntryTitleChanger.Replace("<","&lt;");
		cEntryTitleChanger.Replace(">","&gt;");
		cEntryTitleChanger.Replace("'","&apos;");
		cEntryTitleChanger.Replace("\"","&quot;");



		RSE[i].ChangeEntryWithDate(cEntryChanger,cEntryTitleChanger,RSE[i].GetDateTime(),cEntryLinkChanger);
	}

}

void RssContainer::WriteOutRss(CString FileName)
{
	CString cOutToFile = "";
	InverseReplaceIllegalCharactersCode();
	//rss version
	cOutToFile += "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
	cOutToFile += "<rss version=\"2.0\">\n";

	//channel header
	cOutToFile += "<channel>\n";

	//Title
	CString TitleFile = "";
	TitleFile.Format("<title>%s</title>\n",cTitle); 
	cOutToFile += TitleFile;

	//Link
	CString LinkFile = "";
	LinkFile.Format("<link>%s</link>\n",cLink);
	cOutToFile += LinkFile;

	//Time To Live
	if(!(cTTL == ""))
	{
		CString TTLFile = "";
		TTLFile.Format("<ttl>%s</ttl>\n",cTTL);
		cOutToFile += TTLFile;
	}

	//Description
	CString DescFile = "";
	DescFile.Format("<description>%s</description>\n",cDesc);
	cOutToFile += DescFile;

	//copyright
	CString CopyFile = "";
	CopyFile.Format("<copyright>%s</copyright>\n",cCopy);
	cOutToFile += CopyFile;

	//Last Build Date
	SYSTEMTIME systime;
	GetLocalTime(&systime);
	CString BuildDate = "";
	BuildDate.Format("<lastBuildDate>%s</lastBuildDate>\n",GetCurrentRSSFormattedDate());
	cOutToFile += BuildDate;

	//	<Fri, 14 May 2004 21:56:00 EST>  instead of <2004-05-14,21:56>

	//generator
	cOutToFile += "<generator>Super Simple RSS</generator>\n";

	//webmaster
	CString WebFile = "";
	WebFile.Format("<webMaster>%s</webMaster>\n",cWeb);
	cOutToFile += WebFile;

	//Entries
	CString EntriesFile = "";
	CTime DateFile;
	CString EntriesTitle = "";
	CString EntriesLink = "";
	CString DateTimeFile;
	CString EntriesAndDateToFile = "";
	for(int i = 0;i<NumberOfEntries;i++)
	{
		EntriesFile = RSE[i].GetEntry();
		DateTimeFile = RSE[i].GetDateTime();
		EntriesTitle = RSE[i].GetEntryTitle();
		EntriesLink = RSE[i].GetEntryLink();

		EntriesAndDateToFile.Format("<item>\n<title>%s</title>\n<link>%s</link>\n<description>\n"
			"%s\n</description>\n<pubDate>%s</pubDate>\n</item>\n",
			EntriesTitle,EntriesLink,EntriesFile,DateTimeFile);

		cOutToFile += EntriesAndDateToFile;
	}

	//closing channel
	cOutToFile += "</channel>\n";

	//closing rss
	cOutToFile += "</rss>\n";

	int cOutToFileSize = cOutToFile.GetLength();
	FILE *stream;
	if( (stream = fopen( FileName, "w+t" )) != NULL )
	 {
		  int numwritten = fwrite( cOutToFile, cOutToFileSize, 1, stream );
		  printf( "Wrote %d items\n", numwritten );
		  fclose( stream );
	  }

	ReplaceIllegalCharactersCode();
}

void RssContainer::ClearAll()
{
	cLink = "";
	cDesc = "";
	cCopy = "";
	cWeb = "";
	cTitle = "";
	cTTL = "";
	NumberOfEntries = 0;
	for(int i = 0;i<1024;i++)
	{
		RSE[i].Clear();
	}


}
CString RssContainer::GetCurrentRSSFormattedDate()
    {
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
