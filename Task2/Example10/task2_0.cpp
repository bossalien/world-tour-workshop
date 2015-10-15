#include <iostream>
#include <vector>
using namespace std;

/**
I'm using the sieve of Eratosthenes. (http://en.wikipedia.org/wiki/Sieve_of_Eratosthenes) I'm using this algorithm because I used it before. Sieve of Atkin would be faster if done properly.
I don't have any experience with the sieve of Atkin, though and if done incorrectly it is actually slower... So in the interest of time: Sieve of Eratosthenes!


This is definitely not optimal:
- Does a lot of unnecessary work if the chosen interval is small but the lower bound is high, then a simple slow division check might be faster..
- Memory intensive if upper bound is very high..
- Takes a while to start if the lower bound is very high...

I need to revisit this if I have time to spare... moving on to Pong!
*/

int lowerBound;
int upperBound;

void getInput();
void generatePrimeNumbers();
void generatePrimeNumbersSegmented();

int main()
{
	cout << "Starting up..." << endl;
	cout << "Generating prime numbers..." << endl;

	getInput();

	cout << "Generating drumroll.." << endl;
	cout << "Your prime numbers are:" << endl;

	generatePrimeNumbers();

	cout << endl << "Done!" << endl;

	return 1;
}


void getInput()
{
	cout << "Please input the lower bound:" << endl;

	cin >> lowerBound;					//Weak check that the input is actually an integer.. Goes haywire if you input a character instead :)

	while (lowerBound < 0)
	{
		cout << "Please enter a number greater than zero.." << endl;
		cin >> lowerBound;
	}

	cout << endl << "Please input the upper bound:" << endl;

	cin >> upperBound;					//Same weak check

	while (upperBound < lowerBound)
	{
		cout << "Please enter a number greater than " << lowerBound << endl;
		cin >> upperBound;
	}
}

void generatePrimeNumbers()
{
	vector<bool> primes(upperBound +1, true);

	primes[0] = false;
	primes[1] = false;

	for (unsigned int i = 2; i <= upperBound; i++)
	{
		if (primes[i] == false) continue;

		if (lowerBound <= i) cout << i << endl;

		for (unsigned int j = i; j <= upperBound; j += i)
		{
			primes[j] = false;
		}
	}
}
