#include <iostream>

// define gravity if not defined
#ifndef GRAVITY_CONSTANT
  const double gravity_constant (9.8);  //gravity = 9.8 m^2/s
#endif

// height types and time types
typedef float height;
typedef float timeSecs;

// Arguments: height(m) that ball is at a certain time(s)
// Returns: time(s) that ball hits the ground
// Recursive call, if height is too great, stack overflow could result
timeSecs gravity(height ballHeight, timeSecs seconds)
{
  // gravity function to calc new height
  height currentBallHeight = ballHeight - (gravity_constant * (seconds * seconds) / 2);
  // if ball is still falling (above the ground(0))
  if(currentBallHeight > 0)
  {
    // print time and height
    std::cout<<"At "<<seconds<<" seconds, the ball is at height: "<<currentBallHeight<<" meters"<<std::endl;
    ++seconds;
    // recursively call self until on ground
    seconds = gravity(ballHeight, seconds);
    return seconds;
  }
  // once it hits ground must unwind recursive to get time at ground
  else return seconds;
}

int main()
{
  // user prompted to enter tower height
  std::cout<<"Enter the initial height of the tower in meters: ";
  // user entered height in meters
  int towerHeightMeters;
  std::cin>>towerHeightMeters;

  // seconds it takes till ball hits the ground. Start timer at 0
  timeSecs seconds (0);
  // gravity function. Prints the time and height of ball at each second
  seconds = gravity(towerHeightMeters,seconds);
  // print the time(seconds) it took for the ball to hit the ground
  std::cout<<"At "<<seconds<<" seconds, the ball is on the ground."<<std::endl;
  return 0;
}
