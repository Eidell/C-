#pragma once
#include <iostream>
using namespace std;

class Date
{
public:
	// 获取某年某月的天数
	int GetMonthDay(int year, int month)
	{
		static int monthDayArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			return 29;
		}
		else
		{
			return monthDayArray[month];
		}
	}
	// 全缺省的构造函数
	Date(int year = 1, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;

		// 检查日期是否合法
		if (!(year >= 1
			&& (month >= 1 && month <= 12)
			&& (day >= 1 && day <= GetMonthDay(year, month))))
		{
			cout << "非法日期" << endl;
		}
	}
	// 拷贝构造函数
  // d2(d1)
	Date(const Date& d);
	// 赋值运算符重载
  // d2 = d3 -> d2.operator=(&d2, d3)
	Date& operator=(const Date& d);
	// 析构函数
	~Date();
	// 日期+=天数
	Date& operator+=(int day);
	// 日期+天数
	Date operator+(int day);
	// 日期-天数
	Date operator-(int day);
	// 日期-=天数
	Date& operator-=(int day);
	// 前置++
	Date& operator++();
	// 后置++
	Date operator++(int);
	// 后置--

	Date operator--(int);

	// 前置--
	Date& operator--();
	// >运算符重载
	bool operator>(const Date& d);

	// ==运算符重载

	bool operator==(const Date& d);

	// >=运算符重载

	bool operator >= (const Date& d);

	// <运算符重载
	bool operator < (const Date& d);
	// <=运算符重载
	bool operator <= (const Date& d);
	// !=运算符重载
	bool operator != (const Date& d);
	// 日期-日期 返回天数
	int operator-(const Date& d);
private:
	int _year;
	int _month;
	int _day;
};