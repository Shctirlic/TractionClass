#include <iostream>
#include <vector>
using namespace std;

class Fraction
{
private:
	int numerator;
	int denominator;

public:
	Fraction(int a, int b)
	{
		numerator = a;
		denominator = b;
	}
	Fraction()
	{
		numerator = 0;
		denominator = 0;
	}

	void set_numerator(int v)
	{
		numerator = v;
	}
	void set_denominator(int v)
	{
		denominator = v;
	}

	int  get_numerator()   const { return numerator; }
	int  get_denominator() const { return denominator; }

	Fraction operator+(Fraction& b)
	{
		int common;
		if (denominator > b.denominator) common = b.denominator;
		else                             common = denominator;

		while (common % denominator != 0 || common % b.denominator != 0) common++;

		/*
		for ( ; ; )
		{
			if (denominator % common == 0 && b.denominator % common == 0) break;
			common++;
			cout << "*" << endl;
		}
		*/



		int new_numerator_a = common / denominator * numerator;
		int new_numerator_b = common / b.denominator * b.numerator;

		return Fraction(new_numerator_a + new_numerator_b, common);
	}
	Fraction operator-(Fraction& b)
	{
		int common;
		if (denominator > b.denominator) common = b.denominator;
		else                             common = denominator;

		while (common % denominator != 0 || common % b.denominator != 0) common++;

		/*
		for ( ; ; )
		{
			if (denominator % common == 0 && b.denominator % common == 0) break;
			common++;
			cout << "*" << endl;
		}
		*/

		int new_numerator_a = common / denominator * numerator;
		int new_numerator_b = common / b.denominator * b.numerator;

		return Fraction(new_numerator_a - new_numerator_b, common);
	}
	Fraction operator*(Fraction& b)
	{
		return Fraction(numerator * b.numerator, denominator * b.denominator);
	}
	Fraction operator/(Fraction& b)
	{
		return Fraction(numerator * b.denominator, denominator * b.numerator);
	}


};

ostream& operator<<(ostream& out, const  Fraction& obj)
{
	out << obj.get_numerator() << "/" << obj.get_denominator();
	return out;
}

int main()
{
	Fraction a(3, 2), b(1, 5);


	char operation;

	do
	{
		system("cls");
		cout << "a = " << a << endl;
		cout << "b = " << b << endl;
		cout << "enter a mathematical operation( * , / , + , -) : ";
		cin >> operation;

		switch (operation)
		{
		case '*':
		{
			cout << a * b << endl;
			break;
		}
		case '/':
		{
			cout << a / b << endl;
			break;
		}
		case '+':
		{
			cout << a + b << endl;
			break;
		}
		case '-':
		{
			cout << a - b << endl;
			break;
		}
		default:
		{
			cout << "invalid operation entered" << endl;
			break;
		}
		}
		cout << " continue? (y/n) : "; cin >> operation; cin.get();
	} while (operation != 'n');

}