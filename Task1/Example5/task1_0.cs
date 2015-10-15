using System;

namespace MultiplesCheck
{
	class Program
	{
		static void Main(string[] args)
		{
			// Set start and end for loop of integer values
			int start = 0;
			int end = 30;

			// Loop through and check each integer
			for (int i = start; i <= end; i++)
			{
				// Output the integer value
				Console.Write(i);

				// Finish line and move to next integer if integer is 0,
				// as 0 will show as a multiple which is not desired
				if (i == 0)
				{
					Console.WriteLine();
					continue;
				}

				// If remainder of diving integer by 3 or 5 is zero,
				// integer is a multiple of three or five
				if (i%3 == 0)
				{
					Console.Write(" is a mutliple of three.");
				}
				else if (i%5 == 0)
				{
					Console.Write(" is a multiple of five.");
				}

				// Write line to move output to next line
				Console.WriteLine();
			}

			// User can close program by entering key after program has executed
			Console.ReadKey();
		}
	}
}