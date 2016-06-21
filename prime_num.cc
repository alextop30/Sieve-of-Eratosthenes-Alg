#include "prime_num.h"

int main()
{
	int n;										//storage variable for upper limit input
	set < int > prime;								//initialize stl set prime with zero elements

	cout << "upper limit for the set of primes: ";					//console prompt for upper limit

	cin >> n;									//gather keyboard input for upper limit

	sieve(prime, n);								//call to sub routeine sieve with set and
											//upper limit as arguments

	print_primes(prime);								//call to sub routeine print_primes
											//with set as argument to print the set

	return 0;									//return 0 out of main

}

/*
* Function Sieve responsible for initializing a set of numbbers from 2
* the first prime number through the upper limit entered by user in "n",
* after initialization all non prime numbers are removed from the set.
* The function uses optimization method m^2 <= n
*
* Function accepts a reference of an a set and an int size for arguments
* and it will ont output or return anything.
*
*/
void sieve(set < int >& s, int n)
{
	typedef set<int>::iterator sii;							//define sii type as an iterator of
											//integer set

	int i = 2;									//set starting value for set to
											//2 as it is the smallest prime numbber

	for (int j = 0; j < n - 1; j++)							//fill up set with all numbers up to N
	{										//starting from 2

		s.insert(i);								//fill up set using insert function
		i++;									//insertinng i and every consecutive num after
	}

	sii first = s.begin();								//initialize 1st poinnter and set it to
											//beginning of the set

	int test;									//initialize test var to hold if number
											//is completely divisible by
											//the first iterator

	while (pow(*first, 2) <= n)							//loop which encorporates optimization
	{										//while the element being compared to
											//the rest of the set (squared) is
											//smaller than the upper limit continue
											//to test the next prime num in the set

		for (sii second = s.begin(); second != s.end(); ++second)		//initialize second iterator and use
		{									//it to step through the loop

			test = (*second) % (*first);					//test if the second iterrator value
											//is divisible without remainder

			if (test == 0 && second != first)				//if the second iterator value is completely
			{								//divisible by the first and it is not equal
											//to itself
				int val = *second;					//store the value of second into val
				second--;						//decrement the iterator back to the
											//previous position so erase function does
											//not delete iterator

				s.erase(val);						//erase the non prime value from the set
			}

		}

		first++;								//increment the 1st iterator to the next
											//prime num to be compared in the set
	}

}

/*
* Print Primes function responsible for printing the
* set of primary numbers to the console using 4 space
* number width right alligned
*
* Function takes in a constant set of integers and
* prints the contents to the console as output
*/

void print_primes(const set < int >& s)
{
	cout << endl;									//blank line for readability
	cout << endl;

	int count = 0;									//inialize counter to be used for numbers
											//per line coparisonn

	int item_line;									//new line storage var used in modulus div
											//to determine the numbbers per line

	for (set <int> :: const_iterator j = s.cbegin(); j != s.cend(); ++j)		//step through a set using a constant itterator
	{
		cout << setw(ITEM_W) << *j << " ";					//output each value to the console

		count++;								//increment counter after each value outputed

		item_line = count % NO_ITEMS;						//store modulus division between count
											//NO_Items --16 into item_line

		if (item_line == 0)							//if modulus division is completely divisible
			cout << endl;							//shift data on to a new line
	}

	cout << endl;									//blank line for readability in output

}
