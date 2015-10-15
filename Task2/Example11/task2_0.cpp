// BossAlienTest2.cpp : I am using the sieve of Eratosthenes for calculating the prime numbers
// Details can be found in here:
// http://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
// 1433^1433 is the theorical maximum number that can be tested by this algorithm
// I used a look up table to check against prime numbers
//
// I' ll come back later to it to set boundaries better

#include "stdafx.h"
#include <cmath>
#include <bitset>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <fstream>


using namespace std;

static int look_up_prime[296] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
73, 79, 83, 89, 97, 101, 103, 107, 109, 113,
127, 131, 137, 139, 149, 151, 157, 163, 167, 173,
179, 181, 191, 193, 197, 199, 211, 223, 227, 229,
233, 239, 241, 251, 257, 263, 269, 271, 277, 281,
283, 293, 307, 311, 313, 317, 331, 337, 347, 349,
353, 359, 367, 373, 379, 383, 389, 397, 401, 409,
419, 421, 431, 433, 439, 443, 449, 457, 461, 463,
467, 479, 487, 491, 499, 503, 509, 521, 523, 541,
547, 557, 563, 569, 571, 577, 587, 593, 599, 601,
607, 613, 617, 619, 631, 641, 643, 647, 653, 659,
661, 673, 677, 683, 691, 701, 709, 719, 727, 733,
739, 743, 751, 757, 761, 769, 773, 787, 797, 809,
811, 821, 823, 827, 829, 839, 853, 857, 859, 863,
877, 881, 883, 887, 907, 911, 919, 929, 937, 941,
947, 953, 967, 971, 977, 983, 991, 997, 1009, 1013,
1019, 1021, 1031, 1033, 1039, 1049, 1051, 1061, 1063, 1069,
1087, 1091, 1093, 1097, 1103, 1109, 1117, 1123, 1129, 1151,
1153, 1163, 1171, 1181, 1187, 1193, 1201, 1213, 1217, 1223,
1229, 1231, 1237, 1249, 1259, 1277, 1279, 1283, 1289, 1291,
1297, 1301, 1303, 1307, 1319, 1321, 1327, 1361, 1367, 1373,
1381, 1399, 1409, 1423, 1427, 1429, 1433 };

void printPrimes(unsigned int first, unsigned int second)
{

	int num_primes = 0;
	for (unsigned int i = first; i < second + 1; i++)
	{
		bool found = false;
		int j = 0;
		while (look_up_prime[j] * look_up_prime[j] < i && !found)
		{
			if (i % look_up_prime[j] == 0)
			{
				found = true;
			}
			j++;
		}

		if (!found)
		{
			num_primes++;
			cout << " " << i;
		}
	}

	if (num_primes == 0)
	{
		cout << "I have not found any prime numbers";
	}
}


int main() {

	unsigned int first, second = 0;
	unsigned int quit,num = 0;
	while (true)
	{
		cout << "Enter lower and upper bounds:" << endl;
		cin >> first;
		cin >> second;

		if (first >= second)
		{
			cout << "Second number must be greater than first one!" << endl;
		}
		else
		{
			printPrimes(first, second);
		}

		cout << "Do you want to quit? press 0:" << endl;
		cin >> quit;
		if (quit == 0)
			break;
	}
	return 0;
}
