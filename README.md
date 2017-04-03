# Cpp_Practice_Problems

## BallTowerDrop

A short program to simulate a ball being dropped off of a tower. To start, the user should be asked for the initial height of the tower in meters. Assume normal gravity (9.8 m/s2), and that the ball has no initial velocity (the ball is not moving to start). The program outputs the height of the ball above the ground after 0, 1, 2, 3, etc until the ball reaches the ground. The ball should not go underneath the ground (height 0).

##### Sample output:

```
Enter the initial height of the tower in meters: 100
At 0 seconds, the ball is at height: 100 meters
At 1 seconds, the ball is at height: 95.1 meters
At 2 seconds, the ball is at height: 80.4 meters
At 3 seconds, the ball is at height: 55.9 meters
At 4 seconds, the ball is at height: 21.6 meters
At 5 seconds, the ball is on the ground.
```

###### Note: Depending on the initial height, the ball may not reach the ground in 5 seconds -- that’s okay. We’ll improve this program once we’ve covered loops.
###### Note: The ^ symbol isn’t an exponent in C++. Implement the formula using multiplication instead of exponentiation.


## MonsterGenerator

1. First, create an enumeration of monster types named MonsterType. Include the following monster types: Dragon, Goblin, Ogre, Orc, Skeleton, Troll, Vampire, and Zombie. Add an additional MAX_MONSTER_TYPES enum so we can count how many enumerators there are.

2. Now, create a Monster class. The Monster will have 4 attributes (member variables): a type (MonsterType), a name (std::string), a roar (std::string), and the number of hit points (int). 

3. Move the enum inside the class as a public declaration.

4. Create a constructor that allows you to initialize all of the member variables.

5. Print to user the details of the monster. Write a function that converts a MonsterType into a std::string. Write that function (called getTypeString()), as well as a print() member function.

6. Create a random monster generator. How will the generator class work? Ideally, ask it to create a Monster, and it will create a random one. There only needs to be one MonsterGenerator. This is a good candidate for a static class (one in which all functions are static). Create an empty MonsterGenerator class. Create a static function named generateMonster(). This should return a Monster. Make it return anonymous Monster(Monster::Skeleton, “Bones”, “*rattle*”, 4);

7. Make MonsterGenerator generate some random attributes. However, because MonsterGenerator relies directly on this function, let’s put it inside the class, as a static function.

8. Edit function generateMonster() to generate a random MonsterType (between 0 and Monster::MAX_MONSTER_TYPES-1) and a random hit points (between 1 and 100). This should be fairly straightforward. Define two static fixed arrays of size 6 inside the function (named s_names and s_roars) and initialize them with 6 names and 6 sounds of your choice. Pick a random name from these arrays.

```
The following program should compile:

#include <ctime> // for time()
#include <cstdlib> // for rand() and srand()
int main()
{
	srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock
	rand(); // If using Visual Studio, discard first random value
 
	Monster m = MonsterGenerator::generateMonster();
	m.print();
 
    return 0;
}
```
