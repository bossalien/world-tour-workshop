using System;
using System.Collections;

public class Primes {

  // Find all primes up to and including the limit
  public static BitArray SieveOfEratosthenes(int limit)
  {
    var bits = new BitArray(limit + 1, true);
    bits[0] = false;
    bits[1] = false;
    for (int i = 0; i * i <= limit; i++)
    {
      if (bits[i])
      {
        for (int j = i * i; j <= limit; j += i)
        {
          bits[j] = false;
        }
      }
    }
    return bits;
  }

  // Then just print primes in the range given from command line
  public static void Main(string[] args)
  {
    // Check correct amount of arguments are given
    if (args.Length < 2)
    {
      Console.WriteLine("You need to provide a range\n" +
          "Usage: {0} <start> <end>", AppDomain.CurrentDomain.FriendlyName);
      return;
    }

    // Read the numbers from arguments
    string firstNumberStr = args[0];
    string secondNumberStr = args[1];

    int start, end;

    // Sanity checks
    bool parseResult = Int32.TryParse(firstNumberStr, out start);
    if (!parseResult)
    {
      Console.WriteLine("Could not parse '{0}' to an int", firstNumberStr);
      return;
    }
    parseResult = Int32.TryParse(secondNumberStr, out end);
    if (!parseResult)
    {
      Console.WriteLine("Could not parse '{0}' to an int", secondNumberStr);
      return;
    }
    if (start < 0 || end < 0)
    {
      Console.WriteLine("Range limits should be positive");
      return;
    }
    if (end < start)
    {
      int temp = start;
      start = end;
      end = temp;
    }

    var primes = SieveOfEratosthenes(end);
    for (int i = start; i <= end; i++)
    {
      if (primes[i]) Console.WriteLine(i);
    }
  }
}