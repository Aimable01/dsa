
# Algorithm Complexity Testing

This document provides a summary of the algorithm complexity tests performed for various algorithms. The outputs correspond to different types of algorithmic complexities, such as O(n), O(n^2), O(n^3), O(log n), etc. Below is a detailed list of the commands executed, the corresponding C++ files, and the output from each run.

---

### 1. **Consecutive Statements (`O(n^2)`)**

```bash
$ ./comp.exe
N = 100, Number of instructions O(n^2) :: 4950
```

### 2. **Double Iteration Variable (`O(n^2)`)**

```bash
$ g++ -o comp complexity/consecutiveStatements.cpp
$ ./comp.exe
N = 100, Number of instructions O(n^2) :: 20000
```

### 3. **Geometry Progression (`O(log(n))`)**

```bash
$ g++ -o comp complexity/doubleIterationVariable.cpp
$ ./comp.exe
N = 100, Number of instructions O(log(n)) :: 7
```

### 4. **Factorial Calculation (`O(n)`)**

```bash
$ g++ -o comp complexity/factorialCalc.cpp
$ ./comp.exe
Factorial: 120
```

### 5. **Fibonacci Calculation (`O(2^n)`)**

```bash
$ g++ -o comp complexity/fibonacciCalc.cpp
$ ./comp.exe
55
```

### 6. **Geometry Progression (`O(log n)`)**

```bash
$ g++ -o comp complexity/geometryProgression.cpp
$ ./comp.exe
N = 100, Number of instructions O(log n) :: 134
```

### 7. **Nested Loops (`O(n^2)`)**

```bash
$ g++ -o comp complexity/nestedLoop.cpp
$ ./comp.exe
N = 100, Number of instructions O(n^2) :: 10000
```

### 8. **Nested Loops 1 (`O(n^3)`)**

```bash
$ g++ -o comp complexity/nestedLoop1.cpp
$ ./comp.exe
N = 100, Number of instructions O(n^3) :: 180
```

### 9. **Single Loop (`O(n)`)**

```bash
$ g++ -o comp complexity/singleLoop.cpp
$ ./comp.exe
N = 100, Number of instructions O(n) :: 100
```

---

## Summary

The outputs provided above demonstrate the number of instructions executed by various algorithms based on their time complexity. The number of instructions is dependent on the size of the input `n`, and the complexity of each algorithm is reflected in how the instructions scale as `n` increases. For example:

- **O(n^2)** algorithms grow quadratically with `n`.
- **O(log n)** algorithms grow logarithmically with `n`.
- **O(n^3)** algorithms grow cubically with `n`.

This testing helps in understanding the performance of different algorithms and their scalability.
