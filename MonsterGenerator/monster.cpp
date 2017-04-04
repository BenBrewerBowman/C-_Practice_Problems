#include <iostream>
#include <ctime> // for time()
#include <cstdlib> // for rand() and srand()
#include <string>
#include "monster.h" // monster and gen monster classes

Monster::Monster(MonsterType type, std::string name, std::string roar, int hitPoints): m_type(type), m_name(name), m_roar(roar), m_hitPoints(hitPoints) {}

std::string Monster::getMonsterType() const
{
  switch (m_type) {
    case Dragon:    return "dragon";
    case Goblin:    return "goblin";
    case Ogre:      return "ogre";
    case Orc:       return "orc";
    case Skeleton:  return "skeleton";
    case Troll:     return "troll";
    case Vampire:   return "vampire";
    case Zombie:    return "zombie";
    default:        return "???";
  }
}

void Monster::print() const
{
  std::cout<<m_name<<" the "<< getMonsterType() <<" has "<<m_hitPoints<<" hit points and says "<<m_roar<<".\n";
}


// Generates a random number between min and max. Assumes srand() has already been called
int MonsterGenerator::getRandomNumber(int min, int max)
{
  // static used for efficiency, so we only calculate this value once
  static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
  // evenly distribute the random number across our range
  return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

Monster MonsterGenerator::generateMonster()
{
  Monster::MonsterType type = static_cast<Monster::MonsterType>(getRandomNumber(0, Monster::MAX_MONSTER_TYPES - 1));

  static std::string s_names[6] = { "Blarg", "Moog", "Pksh", "Tyrn", "Mort", "Hans" };
  std::string name = s_names[getRandomNumber(0, 5)];

  static std::string s_roars[6] = { "*ROAR*", "*peep*", "*squeal*", "*whine*", "*hum*", "*burp*"};
  std::string roar = s_roars[getRandomNumber(0, 5)];

  int hitPoints = getRandomNumber(1,100);

  return Monster(type, name, roar, hitPoints);
}
