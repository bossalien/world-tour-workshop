public class QuestionTwo {


	public QuestionTwo()
	{

	}


	public void printPrimeNumbersBetween(int x, int y)
	{
		int workingX = x;
		int workingY = y;

		if((workingX <= 2)||(workingY <= 2)){System.out.println(""+2);} //First check, if the input is 2, then it's prime, so output "2".
		if(workingX <2){workingX = 3;} //Now set the X and Y values to 3 if they are less than 2, as a value of 1 or 0 can mess with the algorithm
		if(workingY <2){workingX = 3;}
		if(workingX % 2 == 0) //Second check, make sure the input is not even. We can skip all the even values as they are definitely not prime.
		{
			workingX+=1;
		}

		for(int i = workingX; i <= workingY; i=i+2)
		{
			int checkingValue = (int)(Math.sqrt(i)); //Third, get the square root of the checkingValue, as there will be no prime higher than this (Reference FOR IDEA FOR THIS LINE SPECIFICALLY: https://en.wikibooks.org/wiki/Efficient_Prime_Number_Generating_Algorithms "PGsimple3")

			boolean isThisValuePrime = true;
			while(checkingValue > 2)
			{
				if(i%checkingValue == 0){isThisValuePrime = false;}
				checkingValue--;
			}

			if(isThisValuePrime)
			{
				System.out.println(i);
			}

		}
	}

	public static void main(String[] args)
	{

		System.out.println("-------------------");
		System.out.println("Output for Question 2:");
		QuestionTwo q2 = new QuestionTwo();
		q2.printPrimeNumbersBetween(0, 1000);

	}
}