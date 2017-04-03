#include <iostream>
#include<ctime> // for time()
#include <cstdlib> // for rand() and srand()

// Monster class
class Monster{
  public:
    // types of possible monsters
    enum MonsterType
    {
      Dragon,
      Goblin,
      Ogre,
      Orc,
      Skeleton,
      Troll,
      Vampire,
      Zombie,
      MAX_MONSTER_TYPES
    };
  // monster properties
  private:
    MonsterType   m_type;
    std::string   m_name;
    std::string   m_roar;
    int           m_hitPoints;
  // monster functionality
  public:
    // construct a monster
    Monster(MonsterType type, std::string name, std::string roar, int hitPoints): m_type(type), m_name(name), m_roar(roar), m_hitPoints(hitPoints) {};
    // return a string of the monstertype based on enum
    std::string const getMonsterType ()
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
    // print the monster's properties to user
    void const print ()
    {
      std::cout<<m_name<<" the "<< getMonsterType() <<" has "<<m_hitPoints<<" hit points and says "<<m_roar<<".\n";
    }
};

class MonsterGenerator
{
  public:
    // Generates a random number between min and max. Assumes srand() has already been called
    static int getRandomNumber(int min, int max)
    {
      // static used for efficiency, so we only calculate this value once
      static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
      // evenly distribute the random number across our range
      return static_cast<int>(rand() * fraction * (max - min + 1) + min);
    }

    static Monster generateMonster()
    {
      Monster::MonsterType type = static_cast<Monster::MonsterType>(getRandomNumber(0, Monster::MAX_MONSTER_TYPES - 1));

      static std::string s_names[6] = { "Blarg", "Moog", "Pksh", "Tyrn", "Mort", "Hans" };
      std::string name = s_names[getRandomNumber(0, 5)];

      static std::string s_roars[6] = { "*ROAR*", "*peep*", "*squeal*", "*whine*", "*hum*", "*burp*"};
      std::string roar = s_roars[getRandomNumber(0, 5)];

      int hitPoints = getRandomNumber(1,100);

      return Monster(type, name, roar, hitPoints);
    }
};


int main()
{
  srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock
	rand(); // If using Visual Studio, discard first random value

	Monster m = MonsterGenerator::generateMonster();
	m.print();

  return 0;
}
