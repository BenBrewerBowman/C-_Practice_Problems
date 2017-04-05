# Cpp_Practice_Problems

## BallTowerDrop

A short program to simulate a ball being dropped off of a tower. To start, the user should be asked for the initial height of the tower in meters. Assume normal gravity (9.8 m/s2), and that the ball has no initial velocity (the ball is not moving to start). The program outputs the height of the ball above the ground after 0, 1, 2, 3, etc until the ball reaches the ground. The ball should not go underneath the ground (height 0).

##### Sample output:

```
>Enter the initial height of the tower in meters: 100
>At 0 seconds, the ball is at height: 100 meters
>At 1 seconds, the ball is at height: 95.1 meters
>At 2 seconds, the ball is at height: 80.4 meters
>At 3 seconds, the ball is at height: 55.9 meters
>At 4 seconds, the ball is at height: 21.6 meters
>At 5 seconds, the ball is on the ground.
```

###### Note: Depending on the initial height, the ball may not reach the ground in 5 seconds -- that’s okay. We’ll improve this program once we’ve covered loops.
###### Note: The ^ symbol isn’t an exponent in C++. Implement the formula using multiplication instead of exponentiation.

## IsPrime

A function to tell if any given number is prime. It works by testing for initially testing for 0, 1 or 2 case. It then checks if it is divisible by two (time optimization). Afterward, it takes the square root of the number and evaluates its divisibility by all numbers lower than it. If the square root is not divisible by any numbers other than 1 and itself, the number is prime.


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

## OperatorOvld

### Fraction

1. Write a class named Fraction that has a integer numerator and denominator member. Write a print() function that prints out the fraction.

The following code should compile:
```
#include <iostream>
 
int main()
{
    Fraction f1(1, 4);
    f1.print();
 
    Fraction f2(1, 2);
    f2.print();
}
```
This should print:
```
>1/4
>1/2
```

2. Add overloaded multiplication operators to handle multiplication between a Fraction and integer, and between two Fractions. Use the friend function method.

###### Hint: To multiply two fractions, first multiply the two numerators together, and then multiply the two denominators together. To multiply a fraction and an integer, multiply the numerator of the fraction by the integer and leave the denominator alone.

The following code should compile:
```
#include <iostream>
 
int main()
{
    Fraction f1(2, 5);
    f1.print();
 
    Fraction f2(3, 8);
    f2.print();
 
    Fraction f3 = f1 * f2;
    f3.print();
 
    Fraction f4 = f1 * 2;
    f4.print();
 
    Fraction f5 = 2 * f2;
    f5.print();
 
    Fraction f6 = Fraction(1, 2) * Fraction(2, 3) * Fraction(3, 4);
    f6.print();
}
```
This should print:
```
>2/5
>3/8
>6/40
>4/5
>6/8
>6/24
```

3. Extra credit: the fraction 2/4 is the same as 1/2, but 2/4 is not reduced to the lowest terms. We can reduce any given fraction to lowest terms by finding the greatest common divisor (GCD) between the numerator and denominator, and then dividing both the numerator and denominator by the GCD.

The following should compile:
```
#include <iostream>
 
int main()
{
    Fraction f1(2, 5);
    f1.print();
 
    Fraction f2(3, 8);
    f2.print();
 
    Fraction f3 = f1 * f2;
    f3.print();
 
    Fraction f4 = f1 * 2;
    f4.print();
 
    Fraction f5 = 2 * f2;
    f5.print();
 
    Fraction f6 = Fraction(1, 2) * Fraction(2, 3) * Fraction(3, 4);
    f6.print();
 
    return 0;
}
```
And produce the result:
```
>2/5
>3/8
>3/20
>4/5
>3/4
>1/4
```
