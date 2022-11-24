#pragma once
#include <time.h>
#include <windows.h>
using i64 = long long;
/**
 * ʱ����ṹ��.
 */
struct Timeval
{
	i64 Second; /*��*/
	i64 Millisecond; /*����*/
}Time_Begin, Time_End;
/**
 * ��ȡʱ���.
 * 
 * \param tp ��¼��ǰʱ����Ŀռ�
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