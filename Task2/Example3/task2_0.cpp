#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

// Sieve of Eratosthenes implementation as: http://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
// Assumes that lowBound > 1 and lowBound < highBound.
std::vector<unsigned long> generatePrimes(const unsigned long lowBound, const unsigned long highBound)
{
	assert(lowBound > 1 && lowBound < highBound);

	std::vector<bool> primeMap{};

	// Note that the first two elements are wasted, but included for simplicity.
	primeMap.resize(highBound + 2);
	std::fill(primeMap.begin(), primeMap.end(), true);

	const auto sqrtHighBound = static_cast<unsigned long>(std::ceil(std::sqrt(highBound)));

	for (auto i = 2u; i <= sqrtHighBound; ++i)
	{
		if (!primeMap[i])
		{
			continue;
		}

		const auto elemSquared = static_cast<unsigned long>(std::pow(i, 2));

		for (auto j = elemSquared; j <= highBound; j += i)
		{
			primeMap[j] = false;
		}
	}

	std::vector<unsigned long> primes{};

	// Reserving this amount of data might not be needed, but done for speed.
	primes.reserve(highBound / 2);

	for (auto i = lowBound; i < highBound; ++i)
	{
		if (primeMap[i])
		{
						primes.push_back(i);
		}
	}

	return std::move(primes);
}

int main()
{
	long lowBound;
	long highBound;

	std::cout << "Enter low bound (>=2): ";
	std::cin >> lowBound;

	if (lowBound < 2)
	{
		std::cout << "Invalid low bound!" << std::endl;
		return -1;
	}

	std::cout << "Enter high bound (>low bound): ";
	std::cin >> highBound;

	if (highBound <= lowBound)
	{
		std::cout << "Invalid high bound!" << std::endl;
		return -1;
	}

	std::vector<unsigned long> primes = generatePrimes(static_cast<unsigned long>(lowBound), static_cast<unsigned long>(highBound));

	for (auto elem : primes)
	{
		std::cout << elem << "\n";
	}
}