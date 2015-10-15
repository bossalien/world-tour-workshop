using System;
using System.Collections.Generic;

namespace Task2
{
  class Program
  {
    static void Main(string[] args)
    {
      int firstNum = -1;
      int secondNum = -1;

      if (errorCheck(args, out firstNum, out secondNum))
      {
        calculatePrimesEra(firstNum, secondNum);
      }
      else
      {
        Console.WriteLine("A command-line argument passed in is either missing, or not a positive number. Please insert two positive integer values as arguments ");
      }

      Console.WriteLine("Press any Key to exit");
      Console.ReadKey();
    }

    //Calculate prime numbers using the Sieve of Eratosthenes.
    //Referenced: http://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
    private static void calculatePrimesEra(int _firstNum, int _secondNum)
    {
      bool[] markedList = new bool[_secondNum+1];

      int p = 2;

      //in first case, print 2 if within range
      if (_firstNum <= p && _secondNum >= p)
      {
        Console.WriteLine(p);
      }

      //setup the list of marked numbers
      for (int i = 0; i <= _secondNum; i++)
      {
        markedList[i] = false;
      }

      //count up to target rage
      for (int count = 0; count < _secondNum; count++)
      {
        for (int j = p; j < _secondNum; j += p)
        {
          if (j != p)
          {
            markedList[j] = true;
          }
        }

        for (int k = p + 1; k < _secondNum; k++)
        {
          if (markedList[k] == false)
          {
            //only output numbers in range
            if (k >= _firstNum)
            {
              Console.WriteLine(k);
            }

            p = k;
            break;
          }
        }
      }
    }

    //Process the command-line arguments and check they are valid
    private static bool errorCheck(string[] args, out int val0, out int val1)
     {
      val0 = -1;
      val1 = -1;

      if (args.Length != 2)
      {
        return false;
      }

      bool input0Safe = true;
      bool input1Safe = true;
      input0Safe = int.TryParse(args[0],out val0);
      input1Safe = int.TryParse(args[1],out val1);

      if (!input0Safe || !input1Safe)
      {
        return false;
      }

      if (val0 < 0 || val1 < 0)
      {
        return false;
      }

      return true;
    }
  }
}
