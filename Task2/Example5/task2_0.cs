using System;

namespace PrimeNumbers
{
  class Program
  {
    // Function returns true when number is prime
    static bool IsPrime(int number)
    {
      // Prime number must be greater than 1
      if (number == 1)
      {
        return false;
      }
      // 2 is a prime number
      if (number == 2)
      {
        return true;
      }

      // Prime number above 2 cannot be even (multiple of 2)
      if (number%2 == 0)
      {
        return false;
      }

      // Check if number is divisible by odd numbers
      for (int i = 3; i < number; i += 2)
      {
        // Prime number cannot be divisible by odd number
        if (number%i == 0)
        {
          return false;
        }
      }

      // Number is a prime number, return true
      return true;
    }


    static void Main(string[] args)
    {
      // Check correct amount of arguments are given
      if (args.Length < 2)
      {
        Console.WriteLine("You did not provide 2 numbers\n" +
                  "Usage: PrimeNumbers.exe {First number} {Second number}");
        return;
      }

      // Read the numbers from arguments
      string firstNumberStr = args[0];
      string secondNumberStr = args[1];

      Console.WriteLine("This program will output all prime numbers between " +
                firstNumberStr + " and " + secondNumberStr);

      // Start and end for loop of integers
      int start = Int32.Parse(firstNumberStr);
      int end = Int32.Parse(secondNumberStr);

      // Loop through and check if each number is prime
      for (int i = start; i <= end; i++)
      {
        // If the number is prime, output it
        if (IsPrime(i))
        {
          Console.WriteLine(i);
        }
      }

      // User can close program by entering key after program has executed
      Console.ReadKey();
    }
  }
}
