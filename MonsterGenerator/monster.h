#ifndef MONSTER_H
#define MONSTER_H

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
    Monster(MonsterType type, std::string name, std::string roar, int hitPoints);
    // return a string of the monstertype based on enum
    std::string getMonsterType() const;
    // print the monster's properties to user
    void print() const;
};

class MonsterGenerator
{
  public:
    // Generates a random number between min and max. Assumes srand() has already been called
    static int getRandomNumber(int min, int max);

    static Monster generateMonster();
};


#endif
