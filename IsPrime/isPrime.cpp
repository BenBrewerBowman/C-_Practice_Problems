#include <iostream>
#include <math.h>
#include "isPrime.h"

// Returns 1 (true) if its prime, or 0 (false) if not
int isPrime(long num)
{
  if (num < 2) // 1 is not a prime number
    return 0;

  // if it is > 2 and an even number, then it definitely is not a prime
  if (num > 2 && (num % 2) == 0)
    return 0;

  //considering the fact all can be divided by 1 and itself,
  //start checking if there is any other divisor, if found one then no need to continue, it is not a prime
  for(int i = 2; i <= sqrt(num); i++ )
  {
    std::cout << " divisor: " << i << std::endl;
    if ( (num % i) == 0) // if it is divisible by i
    {
      // a divisor other than 1 and the number itself
      return 0; // no need for further checking
    }
  }
  return 1; // if all hurdles/checks are crossed, heyyyy, its a prime
}
