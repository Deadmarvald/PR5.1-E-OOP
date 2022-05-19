#pragma once

#include "Object.h"
#include <iostream>
#include <string>
#include <sstream>
#include "Exception.h"
#include "MyException.h"

using namespace std;

class Money : public Object
{
private:
	long hrn;
	unsigned int kop;

public:
	Money();
	Money(const long x, const unsigned long y);
	Money(double z);
	Money(const Money&);
	~Money();

	long GetHrn() const { return hrn; }
	unsigned int GetKop() const { return kop; }

	void SetHrn(long hrn);
	void SetKop(unsigned int kop);

	operator string() const;

	friend Money operator -(const Money&, const Money&);
	friend Money operator *(const Money&, const double);
	friend Money operator *(const double, const Money&);

	bool operator ==(const Money&);
	bool operator !=(const Money&);
	bool operator >(const Money&);
	bool operator <(const Money&);
	bool operator >=(const Money&);
	bool operator <=(const Money&);

	friend ostream& operator << (ostream&, const Money&);
	friend istream& operator >> (istream&, Money&);

	Money& operator ++();
	Money& operator --();
	Money operator ++(int);
	Money operator --(int);
};