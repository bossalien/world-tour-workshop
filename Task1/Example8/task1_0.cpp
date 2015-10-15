#pragma once


#include <stdio.h>

int main(){

  for (int i=0; i<=30; i++){

    char buffer[30];
    bool check = false;

    if (!(i%3 && i%5)){ //If either are divisble by 3 or 5
      if (!(i%3 || i%5)){ //If Both are divisible

        sprintf(buffer,"Three and Five");


      } else {

        if (!(i%3)){ //If only 3 is divisble

          sprintf(buffer,"Three");

        } else if (!(i%5)){ //If only 5 is divisble (for completeness)

          sprintf(buffer,"Five");

        }

      }
      check = true;
    } else {
      check = false;
    }

    if (check){
      printf("%d, %s\n", i, buffer);
    } else {
      printf("%d\n", i);
    }

  }
  printf("Press any key to exit");
  getchar();
  return 0;
}