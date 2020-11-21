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
    Node Goal = Node(4, 7);
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
