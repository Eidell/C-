#include "Date.h"

bool Date::operator==(const Date& d)  const
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}

bool Date::operator>(const Date& d)  const
{
	if (_year > d._year)
	{
		return true;
	}
	else if (_year == d._year && _month > d._month)
	{
		return true;
	}
	else if (_year == d._year && _month == d._month && _day > d._day)
	{
		return true;
	}

	return false;
}

bool Date::operator>=(const Date& d)  const
{
	return *this > d || *this == d;
}

bool Date::operator<=(const Date& d)  const
{
	return !(*this > d);
}

bool Date::operator<(const Date& d)  const
{
	return !(*this >= d);
}

bool Date::operator!=(const Date& d)  const
{
	return !(*this == d);
}

Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		//return *this -= -day;
		return *this -= abs(day);
	}

	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;

		if (_month == 13)
		{
			++_year;
			_month = 1;
		}
	}

	return *this;
}

// d1 + 100
Date Date::operator+(int day) const
{
	Date ret(*this);
	ret += day;
	return ret;
}

// d1 -= 100
Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		//return *this -= -day;
		return *this += abs(day);
	}

	_day -= day;
	while (_day <= 0)
	{
		--_month;
		if (_month == 0)
		{
			--_year;
			_month = 12;
		}

		_day += GetMonthDay(_year, _month);
	}

	return *this;
}

// d1 - 100
Date Date::operator-(int day) const
{
	Date ret(*this);
	ret -= day;

	return ret;
}

Date& Date::operator++()
{
	*this += 1;
	return *this;
}

// 后置 -- 多一个int参数主要是为了根前置区分
// 构成函数重载
Date Date::operator++(int)
{
	Date tmp(*this);

	*this += 1;

	return tmp;
}

// 前置
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}

// 后置
Date Date::operator--(int)
{
	Date tmp = *this;
	*this -= 1;

	return tmp;
}

//d1-d2 的天数
int Date::operator-(const Date& d) const
{
	Date max = *this;
	Date min = d;
	int flag = 1;

	if (*this < d)
		//if (d > *this)
	{
		max = d;
		min = *this;
		flag = -1;
	}

	int n = 0;
	while (min != max)
	{
		++n;
		++min;
	}

	return n * flag;
}