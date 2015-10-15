#include "PrimeChecker.h"

PrimeChecker::PrimeChecker(){

}

bool PrimeChecker::PrimeTest(int num){
  if(num < 2){
    return false;
  }
  for(int i = 2; i*i <= num; i++){
    if(num % i == 0){
      return false;
    }
  }
  return true;
}