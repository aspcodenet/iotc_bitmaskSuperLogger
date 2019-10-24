#define _CRT_SECURE_NO_WARNINGS
#include "superlogger.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

const char* GetDayOfWeek(int dow)
{
	const char* weekdays[] = {"Sunday", "Monday", "Tuesday", 
		"Wednesday", "Thursday", "Friday", "Saturday"};
	return weekdays[dow];
}

void AddWithSpaceIfNotEmpty(char* chBuf, char* chWhat, size_t size)
{
	if (*chBuf != 0)
		strncat(chBuf, " ", size);
	strncat(chBuf, chWhat, size);
}

void WriteLogMessage(char* message,
	bool toFile, bool toConsole, bool includeDate,
	bool includeDayOfWeek,
	bool includeTime,
	bool uppercaseMessage)
{
	time_t t = time(NULL);
	struct tm* d = localtime(&t);
	char buf[512];
	buf[0] = 0;
	if (includeDate)
	{
		char date[12];
		sprintf(date, "%d-%02d-%02d", d->tm_year+1900, d->tm_mon+1, d->tm_mday);
		AddWithSpaceIfNotEmpty(buf,date, sizeof(buf) );
	}
	if (includeTime)
	{
		char time[10];
		sprintf(time, "%02d:%02d:%02d", d->tm_hour, d->tm_min, d->tm_sec);
		AddWithSpaceIfNotEmpty(buf, time, sizeof(buf));
	}
	if (includeDayOfWeek)
	{
		AddWithSpaceIfNotEmpty(buf, GetDayOfWeek(d->tm_wday), sizeof(buf));
	}
	if (uppercaseMessage)
	{
		char* ch = message;
		while (*ch != NULL)
		{
			message = toupper(*ch);
		}
		AddWithSpaceIfNotEmpty(buf, message, sizeof(buf));
	}
	else
	{
		AddWithSpaceIfNotEmpty(buf, message, sizeof(buf));
	}

	if (toConsole)
	{
		printf("%s\n", buf);
	}
	if (toFile)
	{
		FILE* f = fopen("log.txt", "a");
		fprintf(f, "%s\n", buf);
		close(f);
	}


}

