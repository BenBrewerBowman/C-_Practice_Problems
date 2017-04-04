#include <iostream>
#include "isPrime.h"

int main()
{
  int num;
  do
  {
    std::cout << "Enter a number (0 to stop): ";
    std::cin >> num;
    if (num)
    {
      if (isPrime(num))
        std::cout << num << " is a prime number " << std::endl;
      else
        std::cout << num << " is NOT a prime numebr " << std::endl;
    }
  } while (num > 0);

  return 0;
}
