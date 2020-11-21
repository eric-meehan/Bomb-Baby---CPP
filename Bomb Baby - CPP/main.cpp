 /*
  Eric Meehan
  2020-11-21
  
  Bomb Baby
 */

#include "Node.hpp"
#include <iostream>

// Function Prototypes
int GCD(int, int);
int Dividend(int, int);
int ConditionedSubtraction(int * [2]);

int main(int argc, const char * argv[]) {
    // Positions of the desired goal
    int X;
    int Y;
    // The user may specify X and Y values through command line arguments
    if (argc > 1)
    {
        try
        {
            // These arguments will need to be cast as integers
            std::string arg;
            // Get X from the first argument
            arg = argv[1];
            X = std::stoi(arg);
            // Get Y from the second argument
            arg = argv[2];
            Y = std::stoi(arg);
        }
        catch (std::invalid_argument)
        {
            std::cout << "Invalid argument - using default arguments 4 and 7." << std::endl;
        }
    }
    // Alternatively, the default values of 4 and 7 will be used
    else
    {
        X = 4;
        Y = 7;
    }
    Node Goal = Node(X, Y);
    Node Source = Node(1, 1);
    // Assume the goal is possible
    bool Possible = true;
    while (Goal != Source)
    {
        Goal.ConditionedSubtraction();
        if (Goal < Source)
        {
            std::cout << "Impossible" << std::endl;
            Possible = false;
            break;
        }
    }
    if (Possible)
    {
        std::cout << Goal.GetOperationCount() << std::endl;
    }
    return 0;
}

int GCD(int x, int y)
{
    // Returns the greatest common divisor of two numbers
    if (y != 0)
    {
        return GCD(y, x % y);
    }
    else
    {
        return x;
    }
}
