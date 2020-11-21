 /*
  Eric Meehan
  2020-11-21
  
  Bomb Baby
 */

#include <iostream>

// Function Prototypes
int GCD(int, int);
int Dividend(int, int);
int ConditionedSubtraction(int * [2]);

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
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

int Dividend(int x, int y)
{
    // Returns the dividend of the two numbers to skip redundant subtractions
    int dividend;
    if (x > y)
    {
        dividend = x / y;
        // In order to be useful for subraction, the remainder must not be 0
        if (x % y == 0)
        {
            dividend -= 1;
        }
    }
    else
    {
        dividend = y / x;
        if (y % x == 0)
        {
            dividend -= 1;
        }
    }
    return dividend;
}

int ConditionedSubtraction(int * node[2])
{
    // Subtracts the smaller from the larger until their positions invert
    int SubtractionCount = Dividend(*node[0], *node[1]);
    // Perform the subtraction operation
    if (node[0] > node[1])
    {
        node[0] -= *node[1] * SubtractionCount;
    }
    else
    {
        node[1] -= *node[0] * SubtractionCount;
    }
    return SubtractionCount;
}
