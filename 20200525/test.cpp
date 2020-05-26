#include <iostream>
using namespace std;

class Date {
public:
	//构造函数
	Date(int year = 1, int month = 1, int day = 1)
		:_year(year)
		,_month(month)
		,_day(day)
	{}
	//拷贝构造
	Date (const Date& date) {
		_year = date._year;
		_month = date._month;
		_day = date._day;
	}
	//赋值运算符重载
	Date& operator=(const Date& date) {
		if (this != &date) {
			_year = date._year;
			_month = date._month;
			_day = date._day;
		}
		return *this;
	}
	Date* operator&() {
		return this;
	}
	const Date* operator& ()const {
		return this;
	}
	void Display() {
		cout << _year << endl;
	}
	/*void Display(Date* const this) {
		cout << this->_year << endl;
	}*/
	friend ostream& operator<<(ostream& _cout, const Date& d);
	friend istream& operator>>(istream& _cin, const Date& d);

private:
	int _year;
	int _month;
	int _day;
};
ostream& operator<<(ostream& _cout, const Date& d) {
	_cout << d._year << "-" << d._month << "-" << d._day << endl;
	return _cout;
}
istream& operator>>(istream& _cin, const Date& d) {
	_cin >> d._year >> d._month >> d._day;
	return _cin;
}
void test() {
	Date d1(2020,4,20);
	Date d2(2020, 5, 20);
	d1 = d2;  //如果对象都存在,就调用赋值运算符重载函数
	Date d3 = d2;//如果左边对象不存在,就调用拷贝构造函数
	d1 = d2 = d3;//也可以连续赋值
}
class Person {
public:
	void SetInfo();
private:
	char* _name;
	char* _sex;
	int _age;
};

void test1() {
	Person p1; //类的实例化
	Person p2;//可以实例化多个对象
}

class A {
	int _a;
};

class B {
	int _b;
	void fun1() {
		int a = 1;
		int b = 2;
		int c = 3;
	}
};

class C {
	void fun1() {
		int a = 1;
		int b = 2;
		int c = 3;
	}
};

class D {
	//空类
};


int main() {
	//cout << sizeof(A) << endl;  //4
	//cout << sizeof(B) << endl;  //4
	//cout << sizeof(C) << endl;  //1
	//cout << sizeof(D) << endl;  //1
	Date d(2018, 8, 8);
	cout << d;
	system("pause");
	return 0;
}

