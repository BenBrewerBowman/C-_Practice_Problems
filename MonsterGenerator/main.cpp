#include <iostream>
#include <ctime> // for time()
#include <cstdlib> // for rand() and srand()
#include <string>
#include "monster.h" // monster and gen monster classes

int main()
{
  srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock
	rand(); // If using Visual Studio, discard first random value

	Monster m = MonsterGenerator::generateMonster();
	m.print();

  return 0;
}
