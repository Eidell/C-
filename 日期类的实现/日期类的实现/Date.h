#pragma once
#include <iostream>
using namespace std;

class Date
{
public:
	// ��ȡĳ��ĳ�µ�����
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
	// ȫȱʡ�Ĺ��캯��
	Date(int year = 1, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;

		// ��������Ƿ�Ϸ�
		if (!(year >= 1
			&& (month >= 1 && month <= 12)
			&& (day >= 1 && day <= GetMonthDay(year, month))))
		{
			cout << "�Ƿ�����" << endl;
		}
	}
	// �������캯��
  // d2(d1)
	Date(const Date& d);
	// ��ֵ���������
  // d2 = d3 -> d2.operator=(&d2, d3)
	Date& operator=(const Date& d);
	// ��������
	~Date();
	// ����+=����
	Date& operator+=(int day);
	// ����+����
	Date operator+(int day);
	// ����-����
	Date operator-(int day);
	// ����-=����
	Date& operator-=(int day);
	// ǰ��++
	Date& operator++();
	// ����++
	Date operator++(int);
	// ����--

	Date operator--(int);

	// ǰ��--
	Date& operator--();
	// >���������
	bool operator>(const Date& d);

	// ==���������

	bool operator==(const Date& d);

	// >=���������

	bool operator >= (const Date& d);

	// <���������
	bool operator < (const Date& d);
	// <=���������
	bool operator <= (const Date& d);
	// !=���������
	bool operator != (const Date& d);
	// ����-���� ��������
	int operator-(const Date& d);
private:
	int _year;
	int _month;
	int _day;
};