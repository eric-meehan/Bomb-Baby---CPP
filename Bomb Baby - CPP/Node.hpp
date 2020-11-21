  /*
   Eric Meehan
   2020-11-21
   
   Bomb Baby
   Node Class
   */

#ifndef Node_hpp
#define Node_hpp

#include <string>

class Node
{
private:
    int X;
    int Y;
    int Dividend;
    int OperationCount;
public:
    // CONSTRUCTORS
    Node(int, int);
    // MUTATORS
    void CalculateDividend();
    void ConditionedSubtraction();
    // ACCESSORS
    std::string GetOperationCount();
    // OPERATORS
    bool operator!=(const Node&) const;
    bool operator<(const Node&) const;
};

#endif /* Node_hpp */
