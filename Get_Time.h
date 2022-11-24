#pragma once
#include <time.h>
#include <windows.h>
using i64 = long long;
/**
 * 时间戳结构体.
 */
struct Timeval
{
	i64 Second; /*秒*/
	i64 Millisecond; /*毫秒*/
}Time_Begin, Time_End;
/**
 * 获取时间戳.
 * 
 * \param tp 记录当前时间戳的空间
 */
void Get_Time_Of_Day(struct Timeval* tp)
{
	time_t Clock;
	struct tm Time;
	SYSTEMTIME Windows_Time;
	GetLocalTime(&Windows_Time);
	Time.tm_year = Windows_Time.wYear - 1900;
	Time.tm_mon = Windows_Time.wMonth - 1;
	Time.tm_mday = Windows_Time.wDay;
	Time.tm_hour = Windows_Time.wHour;
	Time.tm_min = Windows_Time.wMinute;
	Time.tm_sec = Windows_Time.wSecond;
	Time.tm_isdst = -1;
	Clock = mktime(&Time);
	tp->Second = Clock;
	tp->Millisecond = Windows_Time.wMilliseconds;
}