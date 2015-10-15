#include <iostream>
#include <string>

int main(void)
{
  int number = -1;
  bool exit = false;
  do
  {
    std::cout << "Input number between 0 and 30: ";
    std::cin >>number;
    //valid input
    if(number >= 0 && number <= 30)
    {
      std::cout << number;
      if(number % 3 == 0)
        std::cout << " Three ";
      if(number % 5 == 0)
        std::cout << " Five ";
      std::cout << std::endl;
    }
    else // invalid input
    {
      std::cout << "Invalid input" << std::endl;
      return -1;
    }
    //exit condition
    std::cout << "Do you want to exit? (Y/N)";
    std::string aux;
    std::cin >> aux;
    if(aux[0] == 'Y' || aux[0] == 'y')
      exit = true;


  }while(!exit);

  std::cout << "Bye" << std::endl;

  return 0;
}
