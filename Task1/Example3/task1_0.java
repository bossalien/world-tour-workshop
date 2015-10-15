public class Task1 {

  public Task1()
  {
    for(int i = 1; i <= 30; i++)
    {
      String line = Integer.toString(i);
      if(i % 3 == 0)
      {
        line += " three";
      }
      if(i % 5 == 0)
      {
        line += " five";
      }
      System.out.println(line);
    }
  }

  public static void main(String[] args)
  {
    new Task1();
  }
}
