#include <iostream>
#include "PrimeChecker.h"

using namespace std;

//Reference Used: Algorithms, 4th Edition, by Robert Sedgewick & Kevin Wayne
int main(int argc, char** argv) {

  PrimeChecker myPrimeChecker = PrimeChecker();

  if(argc == 3){ //must have correct number of arguments.
    int a = atoi(argv[1]); //assumes integers
    int b = atoi(argv[2]);

    //get which number is smaller, which is greater
    //case for equality handled in upcoming for loop
    int smaller;
    int larger;

    if(a < b){
      smaller = a;
      larger = b;
    }
    else {
      smaller = b;
      larger = a;
    }

    //outputs numbers if prime
    if(a != b){ //if equal, no prime #'s between
      for(int num = smaller + 1; num < larger; num++){ //only check inner numbers
        if(myPrimeChecker.PrimeTest(num)){
          std::cout<<num<<std::endl;
        }
      }
    }
  }
  else{
    std::cout<<"Not enough arguments!"<<endl;
    std::cout<<"Please run via the command line in the following form:"<<endl;
    std::cout<<"Task2_Primes.exe a b"<<endl;
    std::cout<<"Where a and b are integer values. Thank you! :)"<<endl;
  }
}