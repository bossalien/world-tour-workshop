#include <iostream>
#include "NumberTranslator.h"

using namespace std;

int main(int argc, char** argv) {
  NumberTranslator numberTranslator;

  // Read the given number and translate it
  unsigned int number;
  cout << "Please insert a number between 0 and 30: ";
  cin >> number;
  cout << "Number " << numberTranslator.translate(number);

  // See if the number is divisible by 3 or 5
  bool divisibleBy3, divisibleBy5;
  if(number != 0) {
    divisibleBy3 = (number % 3 == 0);
    divisibleBy5 = (number % 5 == 0);
  }
  else {
    divisibleBy3 = divisibleBy5 = false;
  }

  // Print the whole phrase
  if(divisibleBy3) {
    if(divisibleBy5) {
      cout << " is divisible by three and five" << endl;
    }
    else {
      cout << " is divisible by three" << endl;
    }
  }
  else if(divisibleBy5) {
    cout << " is divisible by five" << endl;
  }
  else {
    cout << endl;
  }

  return 0;
}