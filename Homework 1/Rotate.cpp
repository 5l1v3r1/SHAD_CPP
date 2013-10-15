#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::swap;
using std::endl;

namespace array_utils
{
	template <typename T>
	void reverse(T begin, T end)
	{	
		while(begin != end && begin + 1 != end)
		{
			--end;
			swap(*begin, *end);
			++begin;		
		}
	}

	template <typename T>
	void rotate(T begin, T end, int k)
	{
		int n = end - begin;
		if (n == 0)
			return;
		k = ( (k % n) + n ) % n;
		array_utils::reverse(begin, end);
		array_utils::reverse(begin, begin + k);
		array_utils::reverse(begin + k, end);	
	}
}

template <typename T>
void print(T begin, T end)
{
	cout << "{" ;
	if ( (begin - end) != 0)
	{
		cout << (*begin);	
		for (T current = begin + 1; current != end; ++current)
		{
			cout << ", " << (*current);
		}
	}
	cout<< "}" << endl;
}

int main()
{
	cout << "\t\t" << "Rotate Test" << endl; 
	
	int first_array[] = {1, 2, 3, 4, 5};
	array_utils::rotate(first_array, first_array + 5, 3);
	cout << "Rotate {1, 2, 3, 4, 5} by 3 : ";
	print(first_array, first_array + 5);


	int second_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	array_utils::rotate(second_array, second_array + 10, -3);
	cout << "Rotate {1, 2, 3, 4, 5, 6, 7, 8, 9, 10} by -3 : ";
	print(second_array,second_array + 10);

	vector<int> first_vector;
	for(int i = 0; i < 5; ++i)
	{
		first_vector.push_back(i + 1);
	}
	array_utils::rotate(first_vector.begin(), first_vector.end(), 8);
	cout << "Rotate {1, 2, 3, 4, 5} by 8 : ";
	print(first_vector.begin(),first_vector.end());

	vector<int> second_vector;
	for(int i=0; i < 10; ++i)
	{
		second_vector.push_back(i + 1);
	}
	array_utils: