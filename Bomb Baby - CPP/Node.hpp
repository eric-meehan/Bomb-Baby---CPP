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
    long X;
    long Y;
    long Dividend;
    long OperationCount;
public:
    // CONSTRUCTORS
    Node(long, long);
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
