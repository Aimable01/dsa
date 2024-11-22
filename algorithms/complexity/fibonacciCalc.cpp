#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n < 2) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    std::cout << fibonacci(10) << std::endl; // Outputs the 10th Fibonacci number
    return 0;
}
