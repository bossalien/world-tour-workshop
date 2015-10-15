using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
  class Program
  {
    static void Main(string[] args)
    {
      string line;

      for (int i = 0; i <= 30; i++)
      {
        System.Diagnostics.Debug.WriteLine(i);
        line = i.ToString();

        //multiple checking, modulo dived by it

        //to make some nice looking output, test for both 3 & 5 (thus 15) together
        if (i % 15 == 0)
          line += " - a multiple of three and five!";

        //if not a mulitple of 15, then check for 3 and 5 intidivually
        else
        {
          if (i % 3 == 0)
            line += " - a multiple of three!";

          if (i % 5 == 0)
            line += " - a multiple of five!";
        }

        Console.WriteLine(line);
      }

      Console.WriteLine("Press enter to close");
      Console.ReadLine();
      return;
    }
  }
}