#include <iostream>
using namespace std;

int fun3(int n) {
    int m = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Empty loop body for j
        }
    }
    for (int k = 0; k < n; k++) {
        m += 1;
    }
    return m;
}

// Testing Code
int main() {
    std::cout << "N = 100, Number of instructions O(n^3) :: " << fun3(180);
    return 0;
}
