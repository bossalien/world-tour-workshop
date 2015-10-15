using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace BossAlienTask2
{
    //using the algorithm found here: https://en.wikipedia.org/wiki/Primality_test
    class Program
    {
        static void Main(string[] args)
        {
            int input1 = getInput(1);
            int input2 = getInput(2);
            
            int[] primes;

            //make sure to give the inputs in the right order
            if (input1 > input2)
                primes = findPrimes(input2, input1);
            else
                primes = findPrimes(input1, input2);

            if (primes.Length < 1)
                Console.WriteLine("No Primes found!");
            else
            {
                Console.WriteLine("Primes found are:");
                foreach (int prime in primes)
                {
                    Console.WriteLine(prime);
                }
            }

            Console.WriteLine("Press enter to close");
            Console.ReadLine();
            return;
        }

        private static int getInput(int number)
        {
            string inputNumber;
            int input;

            if (number == 1)
                inputNumber = "first";
            else
                inputNumber = "second";

            while (true)
            {
                Console.WriteLine("Please input " + inputNumber + " number");

                //if we can parse the input, then return it, else try again
                if (Int32.TryParse(Console.ReadLine(), out input))
                    return input;
                else
                    Console.WriteLine("Number not recognised, please try again");
            }
        }

        private static int[] findPrimes(int lowerBound, int upperBound)
        {
            //build a list of prime numbers between the lower and upper bounds
            List<int> primes = new List<int>();

            for (int i = lowerBound + 1; i < upperBound; i++)
            {
                if (isPrime(i))
                    primes.Add(i);
            }
            return primes.ToArray();
        }

        public static bool isPrime(int n)
        {
            //if less than 3, return true if the number is 2
            if (n <= 3)
                return n > 1;
            //if multiple of 2 or 3 (or even 6), then it's not prime
            else if (n % 2 == 0 || n % 3 == 0)
                return false;

            //start at 5 as we have already determined everything up to 4
            //jump up by 6 each time as we can express all primes as 6y + i
            for (int i = 5; i * i <= n; i += 6)
            {
                if (n % i == 0 || n % (i + 2) == 0)
                    return false;
            }
            return true;
        }
    }
}
