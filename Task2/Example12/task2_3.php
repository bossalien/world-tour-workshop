<?php
	function eratosthenes_sieve(&$sieve, $n) {
		$i = 2;
	 	while ($i <= $n) {
	  	if ($sieve[$i] == 0) {
	   		echo $i;
	   		$j = $i;
	   		while ($j <= $n) {
	    		$sieve[$j] = 1;
	    		$j += $i;
	   		}
	  	}

	 		$i++;
	 	}
	}

	$n = 100;
	$sieve = array_fill(0, $n, 0);

	// 2, 3, 5, 7, ..., 97
	eratosthenes_sieve($sieve, $n);
?>