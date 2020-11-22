 /*
  Eric Meehan
  2020-11-21
  
  Bomb Baby
 */

#include "Node.hpp"
#include <iostream>

int main(int argc, const char * argv[]) {
    // Positions of the desired goal
    long X;
    long Y;
    // The user may specify X and Y values through command line arguments
    if (argc > 1)
    {
        try
        {
            // These arguments will need to be cast as integers
            std::string arg;
            // Get X from the first argument
            arg = argv[1];
            X = std::stol(arg);
            // Get Y from the second argument
            arg = argv[2];
            Y = std::stol(arg);
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
