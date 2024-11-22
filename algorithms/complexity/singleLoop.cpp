#include <iostream>

int fun1(int n) {
    int m = 0; // Initialize m to 0
    for (int i = 0; i < n; i++) {
        m += 1;
    }
    return m;
}

// Testing Code
int main() {
    std::cout << "N = 100, Number of instructions O(n) :: " << fun1(100);
    return 0;
}
