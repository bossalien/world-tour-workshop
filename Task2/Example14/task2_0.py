import sys
import math

# Prints out the prime numbers between the two values low and high
# (inclusive). Assumes that low and high are valid bounds. The
# algorithm used here is the Sieve of Eratosthones described in the
# following Wikipedia article:
# http://en.wikipedia.org/wiki/Sieve_of_Eratosthenes#Implementation
#
# We only need to check for numbers p where p^2 <= high, since we know
# that any number with p < high and p^2 > high will only have one multiple
# (itself) within the range of the sieve. Since we need to check for
# multiples of numbers less than the lower bound, we actually just do
# a sieve from 2 to high, and then don't print out any primes less
# than low at the end.
def generate_primes(low, high):

    A = [True for i in xrange(high+1)]
    sqrt_high = int(math.floor(math.sqrt(high)))

    for p in xrange(2, sqrt_high+1):
        print p
        if A[p]:
            j = p*p
            print j

            while j <= high:
                A[j] = False
                j += p
                print j

    for k in range(len(A)):
        if k >= low and A[k]:
            print k

if __name__ == '__main__':
    if len(sys.argv) != 3:
        print 'Usage: python task2.py <low> <high>'
        quit()

    # Validate the input.
    str_low = sys.argv[1]
    str_high = sys.argv[2]

    try:
        low = int(str_low)
        high = int(str_high)
    except:
        print 'Error: could not convert input bounds to integers.'
        quit()

    if high < low:
        print 'Error: upper bound must be greater than or equal to lower bound.'
        quit()

    # Prime numbers are natural numbers greater than 1.
    if high < 2:
        quit()

    if low < 2:
        low = 2

    # Call the prime number generator.
    generate_primes(low, high)

