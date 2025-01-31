#include <iostream>
#include <climits>

class WholeNum {
private:
    unsigned int value;

public:
    // Constructor
    WholeNum(unsigned int v = 0) : value(v) {}

    // Getter for value
    unsigned int getValue() const { return value; }

    // Addition (with overflow check)
    WholeNum operator+(const WholeNum& other) const {
        if (UINT_MAX - value < other.value) return WholeNum(UINT_MAX);
        return WholeNum(value + other.value);
    }

    // Subtraction (prevent negative values)
    WholeNum operator-(const WholeNum& other) const {
        return WholeNum(value < other.value ? 0 : value - other.value);
    }

    // Equality Check
    bool operator==(const WholeNum& other) const {
        return value == other.value;
    }

    // Get Successor
    WholeNum getSuccessor() const {
        return WholeNum(value == UINT_MAX ? UINT_MAX : value + 1);
    }

    // Print function
    void print() const { std::cout << value << std::endl; }
};

int main() {
    WholeNum zero, one = zero.getSuccessor();
    WholeNum sum = one + one;

    zero.print();
    one.print();
    sum.print();

    if (zero == WholeNum(0)) std::cout << "0 is zero" << std::endl;
    if (one == sum) std::cout << "Something is wrong: 1 is equal to sum" << std::endl;
    else std::cout << "Correct: 1 is not equal to sum (1 != 2)" << std::endl;

    return 0;
}
