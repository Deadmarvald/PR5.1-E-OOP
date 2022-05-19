#include "Money.h"

void Money::SetHrn(long value)
{
	if (value < 0)
	{
		throw Exception("Numbers must be bigger than 0!");
	}
	else
	{
		hrn = value;
	}
}

void Money::SetKop(unsigned int value)
{
	if (value < 0)
	{
		throw Exception("Numbers must be bigger than 0!");
	}
	else
	{
		kop = value;
	}
}


Money::Money() : hrn(0), kop(0)
{ }

Money::Money(const long x, const unsigned long y)
{
	if (hrn < 0 || kop < 0)
	{
		throw invalid_argument("Numbers must be bigger than 0!");
	}
	else
	{
		long a = hrn;
		unsigned long b = kop;

		while (b > 99)
		{
			b -= 100;
			a++;
		}

		SetHrn(a);
		SetKop(b);
	}
}

Money::Money(double z)
{
	long a = (long)z;
	z -= a;
	z *= 100;
	unsigned long b = (unsigned long)z;

	while (b > 99)
	{
		b -= 100;
		a++;
	}
	while (b < -99)
	{
		b += 100;
		a--;
	}

	SetHrn(a);
	SetKop(b);
}

Money::Money(const Money& r)
{
	int a = r.GetHrn();
	int b = r.GetKop();

	while (b > 99)
	{
		b -= 100;
		a++;
	}
	while (b < -99)
	{
		b += 100;
		a--;
	}

	SetHrn(a);
	SetKop(b);
}

Money::~Money(void)
{ }

Money operator -(const Money& l, const Money& r)
{
	Money t;

	long a = l.GetHrn() - r.GetHrn();
	unsigned long b = l.GetKop() - r.GetKop();

	t.SetHrn(a);
	t.SetKop(b);

	return t;
}

Money operator *(const Money& l, const double k)
{
	Money t;

	long a = (l.GetHrn() * k);
	unsigned long b = (l.GetKop() * k);

	while (b > 99)
	{
		b -= 100;
		a++;
	}

	t.SetHrn(a);
	t.SetKop(b);

	return t;
}

Money operator *(const double k, const Money& r)
{
	Money t;

	long a = r.GetHrn() * k;
	unsigned long b = r.GetKop() * k;

	while (b > 99)
	{
		b -= 100;
		a++;
	}

	t.SetHrn(a);
	t.SetKop(b);

	return t;
}

string format(unsigned long b)
{
	stringstream ss;

	if (b < 10)
	{
		ss << "0";
	}

	ss << b;

	return ss.str();
}

Money::operator string() const
{
	stringstream ss;

	ss << endl;
	ss << GetHrn() << "," << format(GetKop()) << " hrn.";

	return ss.str();
}

ostream& operator << (ostream& out, const Money& r)
{
	out << string(r);

	return out;
}

istream& operator >> (istream& in, Money& x)
{
	long hrn;
	unsigned int kop;

	cout << endl;
	cout << "UAH = "; in >> hrn;
	cout << "Coin = "; in >> kop;
	cout << endl;

	if (hrn < 0 || kop < 0)
	{
		throw MyException("Numbers must be bigger than 0!!!");
	}
	else
	{
		x.SetHrn(hrn);
		x.SetKop(kop);
	}

	return in;
}

bool Money::operator ==(const Money& x)
{
	return this->GetHrn() == x.GetHrn() && this->GetKop() == x.GetKop();
}

bool Money::operator !=(const Money& x)
{
	return !(this->GetHrn() == x.GetHrn() && this->GetKop() == x.GetKop());
}

bool Money::operator >(const Money& x)
{
	if (this->GetHrn() > x.GetHrn())
	{
		return true;
	}

	if (this->GetHrn() == x.GetHrn())
	{
		if (this->GetKop() > x.GetKop())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	if (this->GetHrn() < x.GetHrn())
	{
		return false;
	}
}

bool Money::operator <(const Money& x)
{
	if (this->GetHrn() < x.GetHrn())
	{
		return true;
	}

	if (this->GetHrn() == x.GetHrn())
	{
		if (this->GetKop() < x.GetKop())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	if (this->GetHrn() > x.GetHrn())
	{
		return false;
	}
}

bool Money::operator >=(const Money& x)
{
	if (this->GetHrn() > x.GetHrn())
	{
		return true;
	}

	if (this->GetHrn() == x.GetHrn())
	{
		if (this->GetKop() > x.GetKop())
		{
			return true;
		}

		if (this->GetKop() == x.GetKop())
		{
			return true;
		}

		if (this->GetKop() < x.GetKop())
		{
			return false;
		}
	}

	if (this->GetHrn() < x.GetHrn())
	{
		return false;
	}
}

bool Money::operator <=(const Money& x)
{
	if (this->GetHrn() < x.GetHrn())
	{
		return true;
	}

	if (this->GetHrn() == x.GetHrn())
	{
		if (this->GetKop() < x.GetKop())
		{
			return true;
		}

		if (this->GetKop() == x.GetKop())
		{
			return true;
		}

		if (this->GetKop() > x.GetKop())
		{
			return false;
		}
	}

	if (this->GetHrn() > x.GetHrn())
	{
		return false;
	}
}

Money& Money::operator ++()
{
	int a = this->GetHrn();
	int b = this->GetKop();
	a++;
	b++;

	this->SetHrn(a);
	this->SetKop(b);

	return *this;
}

Money& Money::operator --()
{
	int a = this->GetHrn();
	int b = this->GetKop();
	a--;
	b--;

	this->SetHrn(a);
	this->SetKop(b);

	return *this;
}

Money Money::operator ++(int)
{
	Money t(*this);

	int a = this->GetHrn();
	int b = this->GetKop();
	a++;
	b++;

	this->SetHrn(a);
	this->SetKop(b);

	return t;
}

Money Money::operator --(int)
{
	Money t(*this);

	int a = this->GetHrn();
	int b = this->GetKop();
	a--;
	b--;

	this->SetHrn(a);
	this->SetKop(b);

	return t;
}