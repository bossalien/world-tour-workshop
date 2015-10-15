<?php
 function isPrime($n) {
  $i = 2;

  if ($n == 2) {
   return true;
  }

  while ($i <= $n/2) {
   if ($n % $i == 0) {
    return false;
   }
   $i++;
  }

  return true;
 }

 // prints the prime numbers between 2 and 100
 // 3, 5, 7, ..., 97
 for ($i = 3; $i < 100; $i++) {
  if (isPrime($i)) {
   echo $i;
  }
 }
?>