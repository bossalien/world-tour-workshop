#include <iostream>	//cin cout
#include <algorithm>//std::swap
#include <vector>
#include <string>
/*
	Brief :
	Create a command line program that efficiently generates prime numbers.
	When run, the program should read two integer values from the command line arguments.
	All the prime numbers between the two input values should be output to the console as quickly as possible.
*/
int main(void)
{

	bool exit = false;
	do
	{
		int limitT = -1;
		int limitB = -1;
		//Gather input
		std::cout << "Input two numbers between which we are going to search all possible primes: ";
		std::cin >>limitB >> limitT;
		if(limitT == -1 || limitB == -1)
		{
			std::cout << "Invalid input" << std::endl;
			return -1;
		}
		else
		{
			if(limitB > limitT)//ensure we have the correct numbers
				std::swap(limitB, limitT);

			//we are going to use a simple naive approach of starting with 2
			//and 3 progressively discard all the prime numbers on an array
			//vector is used in order to use random access iterator
			//Using a table to store previously computed values is a technique of
			//dynamic programming, which trades memory in order to be faster
			std::vector<bool> vPrimes(limitT + 1, true);
			//We will not consider 1 as a prime
			vPrimes[0] = false;
			vPrimes[1] = false;
			unsigned uLimitT = limitT;//making this unsigned will give us more space to play
			for(unsigned i = 2; i <= uLimitT; ++i)
			{
				//this number is not prime, so continue
				if(vPrimes[i] == false)
					continue;

				//compute this number combination wich each posible prime number in front it and set it
				//to not prime
				for(unsigned j = i; j * i <= uLimitT; ++j)
				{
					//do not know if inserting this condition will make it faster or not
					//with the condition there are 1 comparison + 1 memory acess in the
					//average case, while  1 comparison + 2 memory acesses + 1 multiplication + 1 assign in
					//the worst case. Without it it'll be 1 multiplication + 1 memory acesses + 1 assign
					//in all the cases. So I guess the comparison proves worth when the limitT is big enough
					//Actually this makes us jump over some non-prime numbers (eg: 2 * 4 = 8 but because 4 was set
					//as non prime 8 is never set as false)
					/*if(vPrimes[j] == false)
						continue;*/
					//ok, so this is not prime
					vPrimes[j * i] = false;
				}

			}
			//output result
			for(int i = limitB; i <= limitT; ++i)
			{
				if(vPrimes[i])
					std::cout << i << " ";
			}
			//exit condition
			std::cout << "Do you want to exit? (Y/N)";
			std::string aux;
			std::cin >> aux;
			if(aux[0] == 'Y' || aux[0] == 'y')
				exit = true;
			std::cout << std::endl;
		}

	}while(!exit);

	return 0;
}