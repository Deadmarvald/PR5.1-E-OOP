#include <iostream>
#include<Windows.h>
#include "Money.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "Fraction count: " << Object::Count() << endl << endl;

	bool res;
	Money a, b;
	double x;

	cout << a.Count() << endl;

	do
	{
		try
		{
			res = true;

			cout << "Enter a value of \"a\":"; cin >> a;
			cout << "Enter a value of \"b\":"; cin >> b;

			Money c(a - b);
			cout << "Вiднiмання суми: " << c;
			cout << endl << endl;

			cout << "Дрiб = "; cin >> x;
			cout << endl;

			Money d(a * x);
			cout << "Результата множення: " << d;
			cout << endl << endl;

			cout << "Порiвняння сум: " << endl;

			if (a == b)
			{
				cout << a.GetHrn() << "," << a.GetKop() << " == "
					<< b.GetHrn() << "," << b.GetKop() << endl << endl;
			}

			if (a != b)
			{
				cout << a.GetHrn() << "," << a.GetKop() << " != "
					<< b.GetHrn() << "," << b.GetKop() << endl << endl;
			}

			if (a > b)
			{
				cout << a.GetHrn() << "," << a.GetKop() << " > "
					<< b.GetHrn() << "," << b.GetKop() << endl << endl;
			}

			if (a < b)
			{
				cout << a.GetHrn() << "," << a.GetKop() << " < "
					<< b.GetHrn() << "," << b.GetKop() << endl << endl;
			}

			if (a >= b)
			{
				cout << a.GetHrn() << "," << a.GetKop() << " >= "
					<< b.GetHrn() << "," << b.GetKop() << endl << endl;
			}

			if (a <= b)
			{
				cout << a.GetHrn() << "," << a.GetKop() << " <= "
					<< b.GetHrn() << "," << b.GetKop() << endl << endl;
			}

			cout << "Iнкремент/декремент в обох формах: " << endl;

			cout << "a++: " << a++ << endl;
			cout << "res: " << a << endl;
			cout << "++a: " << ++a << endl;

			cout << "a--: " << a-- << endl;
			cout << "res: " << a << endl;
			cout << "--a: " << --a << endl;
			cout << endl;
		}
		catch (invalid_argument ex)
		{
			res = false;
			cerr << ex.what() << endl;
		}
		catch (MyException& ex)
		{
			res = false;
			cerr << ex.What() << endl;
		}
		catch (Exception* ex)
		{
			res = false;
			cerr << ex->What() << endl;
		}
	} while (!res);

	cout << "Fraction count: " << Object::Count() << endl << endl;

	system("pause");
	return 0;
}