// #pragma once

#ifndef __TEXTWIZ_STDAFX_INCLUDED_BY_XIAOBSH
#define __TEXTWIZ_STDAFX_INCLUDED_BY_XIAOBSH

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__) || defined(WINNT) || defined(__WINNT) || defined(__WINNT__) || defined(__WIN64) || defined(_WIN64)
// Windows
#include <Windows.h>
#define LONG_INTEGER long long
int gettimeofday(struct timeval* tp, void* tzp)
{
	time_t clock;
	struct tm tm;
	SYSTEMTIME systemTime;
	GetLocalTime(&systemTime);
	tm.tm_year = systemTime.wYear - 1900;
	tm.tm_mon = systemTime.wMonth - 1;
	tm.tm_mday = systemTime.wDay;
	tm.tm_hour = systemTime.wHour;
	tm.tm_min = systemTime.wMinute;
	tm.tm_sec = systemTime.wSecond;
	tm.tm_wday = systemTime.wDayOfWeek;
	tm.tm_isdst = -1;
	clock = mktime(&tm);
	tp->tv_sec = clock;
	tp->tv_usec = systemTime.wMilliseconds * 1000;
	return (0);
}

errno_t localtime_r(const time_t* timep, struct tm* result)
{
	return localtime_s(result, timep);
}

#elif defined(__linux__) || defined(__gnu_linux__) || defined(linux) || defined(__linux)
// Linux
#include <sys/time.h>
#define LONG_INTEGER long
#endif

#endif

