/*
 Eric Meehan
 2020-11-21
 
 Bomb Baby
 Node Class
 */

#include "Node.hpp"

// CONSTRUCTOR
Node::Node(long x, long y)
{
    // Initialize the class with the specified parameters and calculate the current dividend
    X = x;
    Y = y;
    CalculateDividend();
}

// MUTATORS
void Node::CalculateDividend()
{
    // Calculates the dividend between X and Y to reduce redundant subtractions between the two
    if (X > Y)
    {
        Dividend = int(X / Y);
        // Reduce the dividend by one if the remainder is zero
        // This is done so the subtraction method does not immediately reduce both X and Y to zero
        if (X % Y == 0)
        {
            Dividend -= 1;
        }
    }
    else
    {
        Dividend = int(Y / X);
        if (Y % X == 0)
        {
            Dividend -= 1;
        }
    }
    
}

void Node::ConditionedSubtraction()
{
    // Subtracts the smaller number from the larger repeatedly until the smaller becomes the larger
    if (X > Y)
    {
        X -= Y * Dividend;
    }
    else
    {
        Y -= X * Dividend;
    }
    // Calculate the new dividend
    OperationCount += Dividend;
    CalculateDividend();
}

// ACCESSORS

std::string Node::GetOperationCount()
{
    return std::to_string(OperationCount);
}

// OPERATORS

bool Node::operator!=(const Node& other) const
{
    // Returns true if this and other have equivalent X and Y values
    return X != other.X || Y != other.Y;
}

bool Node::operator<(const Node& other) const
{
    return X < other.X || Y < other.Y;
}
