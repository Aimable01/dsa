#include <iostream>
using namespace std;

int factorial(int i) {
    // Base Case or Termination Condition
    if (i <= 1)
        return 1; // Base case: factorial of 1 or 0 is 1

    // Recursive Expansion
    return i * factorial(i - 1);
}

int main() {
    std::cout << "Factorial: " << factorial(5) << std::endl;
    return 0;
}
