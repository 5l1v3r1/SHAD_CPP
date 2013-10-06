#include <iostream>
#include <exception>
#include <string>

using std::exception;
using std::cout;
using std::string;
using std::endl;

namespace integer_arithmetic
{
	const string BAD_MOD_EXCEPTION_MESSAGE("MOD CAN`T BE SMALLER THAN 1");

	int gcdex(int a, int b, int & x, int & y)
	{
		if (a > b)
		return gcdex(b, a, y, x);
		if (a == 0)
		{
			x = 0;
			y = 1;
			return b;
		}
		long long d = gcdex(a, b % a, x, y);
		x = x - ( b / a ) * y;
		return d;
	}

	int remainder(int x, int mod)
	{
		return ( (x % mod) + mod ) % mod;
	}

	void inverce(int a, int mod, int & a_inverce, bool & has_inverce)
	{
		if ( mod < 1 )
		{
			throw exception(BAD_MOD_EXCEPTION_MESSAGE.c_str());
		}		

		int x, y;

		int gcd = gcdex(a, mod, x, y);

		has_inverce = ( gcd == 1 );
		a_inverce = remainder(x, mod);		
	}
}

void print_inverce(int a,int mod)
{
	int inverse;
	bool has_inverce;
	integer_arithmetic::inverce(a, mod, inverse, has_inverce);

	cout << a << " mod " << mod;
	if (has_inverce)
	{
		cout << " inverce : " << inverse;
	}
	else
	{
		cout << " no inverce ";
	}
	cout<<endl;
}

int main()
{
	cout << "\t\t" << "INVERCE TEST" << endl;
	print_inverce(7, 8);
	print_inverce(5, 7);
	print_inverce(88, 79);
	print_inverce(14, 7);
	print_inverce(5, 15);
	print_inverce(5, 5);	
	print_inverce(1, 1);
	
	return 0;
}