#include "Date.h"

void TestDate1()
{
	Date d1(2022, 10, 8);
	Date d3(d1);
	Date d4(d1);

	d1 -= 10000;
	d1.Print();

	Date d2(d1);
	/*Date d3 = d2 - 10000;
	d3.Print();*/
	(d2 - 10000).Print();
	d2.Print();

	d3 -= -10000;
	d3.Print();

	d4 += -10000;
	d4.Print();
}

void TestDate2()
{
	Date d1(2022, 10, 8);
	Date d2(d1);
	Date d3(d1);
	Date d4(d1);

	(++d1).Print(); // d1.operator++()
	d1.Print();

	(d2++).Print(); // d2.operator++(1)
	d2.Print();


	(--d1).Print(); // d1.operator--()
	d1.Print();

	(d2--).Print(); // d2.operator--(1)
	d2.Print();
}

void TestDate3()
{
	Date d1(2022, 10, 10);
	Date d2(2023, 7, 1);

	cout << d2 - d1 << endl;
	cout << d1 - d2 << endl;
}

void TestDate4()
{
	Date d1, d2;
	//cin >> d1;  // 流提取
	//cout << d1;   // 流插入

	//d1 << cout; // d1.operator<<(cout);

	cin >> d1 >> d2;
	cout << d1 << d2 << endl; // operator<<(cout, d1);
	cout << d1 - d2 << endl;
}

void TestDate5()
{
	Date d1(2022, 10, 10);
	d1.Print();

	const Date d2(2022, 10, 10);
	d2.Print();

	//d2 += 10;
	cout << d2 + 1000 << endl;

	cout << &d1 << endl;
	cout << &d2 << endl;
}