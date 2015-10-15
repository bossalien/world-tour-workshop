public class Task2 {
  public Task2(int n)
  {
    for (int i = 3; i < n; i++)
    {
      boolean isPrime = true;
      for(int j = 2; j < i; j++)
      {
        if(i % j == 0)
        {
          isPrime = false;
          break;
        }
      }
      if(isPrime)
      {
        System.out.println(i);
      }
    }
  }

  public static void main(String[] args)
  {
    new Task2(Integer.parseInt(args[0]));
  }
}