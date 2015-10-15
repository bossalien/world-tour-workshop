// QuestionTwo.cpp : Defines the entry point for the console application.
//

#pragma once

#include <stdio.h>
#include <stdlib.h>

int main (){
	
	unsigned max=0; //Number to find out if prime

	//Verify input. Must be greater than 2. If non-integer input, conversion does not take place and max remains at 0.
	while (max<=2){
		printf ("Enter a positive integer: "); //Print command
		bool check;

		char str [80];
		scanf ("%str",&str); //Wait for input

		max = atoi(str);
	}
	const static int prsize = 2056; //Size of prime number array
	int primes[prsize]; //Create array to store primes

	int i=0;
	primes[i] = 2; //Initial prime number
	
	//n = number to check
	//i = index of highest found prime in array
	for (int n=primes[i]+1; n<=max; n++){
		bool isPrime;

		//iterate through primes array. if n is divisible by a prime, break
		for (int j=0; j<=i; j++){

			isPrime = (n%primes[j]);
			if (!isPrime)break;
		}
		if (isPrime) {
			primes[++i] = n;
			if (i >= prsize-1)break;
		}
	}
	for (int k=0; k<i; k++){
		printf("%d: %d\n", k, primes[k]);
	}
	if (i+1 >= prsize) printf("Note: Prime number array out of bounds. Not all primes may be listed,\n");
	getchar();
	return 0;
}