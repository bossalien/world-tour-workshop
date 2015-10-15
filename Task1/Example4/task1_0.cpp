#include <iostream>

using namespace std;

int main(int argc, char** argv) {
  for(int num = 0; num <= 30; num++){
    if(num % 3 == 0){
      if(num % 5 == 0){
        std::cout<<num<<" "<<"three"<<" "<<"five"<<std::endl;
      }
      else{
        std::cout<<num<<" "<<"three"<<std::endl;
      }
    }
    else if(num % 5 == 0){
      std::cout<<num<<" "<<"five"<<std::endl;
    }
    else{
      std::cout<<num<<std::endl;
    }
  }
}
