
# 40 Sorting Algorithms

This document provides a list of 40 sorting algorithms, covering a wide range of techniques, from simple comparison-based methods to more advanced and parallelized algorithms.

---

### 1. **Bubble Sort**
   A simple comparison-based algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order.

### 2. **Selection Sort**
   Works by repeatedly selecting the smallest (or largest) element from the unsorted portion of the list and swapping it with the first unsorted element.

### 3. **Insertion Sort**
   Builds the sorted list one item at a time by comparing the current element to the already sorted portion and inserting it into its correct position.

### 4. **Cocktail Shaker Sort**
   A bidirectional version of bubble sort where the sorting goes in both directions, left to right and right to left.

### 5. **Gnome Sort**
   Similar to insertion sort, but it only moves the element backward if it's smaller than the previous one, or forward if it's larger.

### 6. **Odd-Even Sort**
   A variation of bubble sort where the array is traversed in two phases: odd indexed elements are compared first, then even indexed elements are compared.

### 7. **Pancake Sort**
   Repeatedly flips the largest unsorted portion of the list to the top, then places it in its correct position.

### 8. **Comb Sort**
   An improvement over bubble sort by using a larger gap sequence to reduce the number of comparisons faster.

### 9. **BogoSort**
   A highly inefficient sorting algorithm that generates random permutations of the input array until it finds one that is sorted.

### 10. **Cycle Sort**
   A non-comparison-based sorting algorithm that works by minimizing the number of writes to the array, ideal for situations where write operations are expensive.

---

### Divide and Conquer Algorithms

### 11. **Merge Sort**
   A comparison-based algorithm that divides the list into smaller sublists, sorts them, and merges them back together.

### 12. **Quick Sort**
   A divide-and-conquer algorithm that selects a pivot and partitions the array into two parts—those less than the pivot and those greater—and recursively sorts them.

### 13. **Heap Sort**
   A comparison-based sorting algorithm that builds a binary heap and repeatedly extracts the maximum (or minimum) element from the heap.

### 14. **Tim Sort**
   A hybrid sorting algorithm derived from merge sort and insertion sort, designed to perform well on many kinds of real-world data.

### 15. **Intro Sort**
   A hybrid sorting algorithm that begins with quicksort, switches to heap sort when the recursion depth exceeds a certain limit, and uses insertion sort for small arrays.

### 16. **Bin Sort (Bucket Sort)**
   Divides the elements into a finite number of buckets, sorts each bucket individually, and finally concatenates the buckets.

### 17. **Counting Sort**
   A non-comparison-based algorithm that counts the occurrences of each element and uses that count to determine each element's position in the sorted array.

### 18. **Radix Sort**
   A non-comparison-based sorting algorithm that sorts numbers digit by digit, from least significant to most significant (or vice versa).

### 19. **Flash Sort**
   A hybrid sorting algorithm that uses a distribution technique to classify elements into "buckets" and then uses a linear pass to sort the elements.

### 20. **Shell Sort**
   A generalization of insertion sort that allows the exchange of items that are far apart, progressively shrinking the gap between compared items.

---

### Hybrid Algorithms

### 21. **Block Sort (Pigeonhole Sort)**
   Similar to counting sort, it divides elements into "pigeonholes" based on their value range, which are then sorted individually.

### 22. **Smooth Sort**
   An adaptive sorting algorithm that works by creating a binary heap, but using an efficient structure based on the Fibonacci sequence.

### 23. **Merge-Insertion Sort**
   A hybrid approach combining merge sort with insertion sort for small subarrays.

### 24. **Patience Sorting**
   A variation of the longest increasing subsequence problem, often used for card sorting or patience games.

### 25. **Timsort**
   A hybrid sorting algorithm based on merge sort and insertion sort, used in real-world programming environments, such as Python and Java.

---

### Non-Comparison Based Sorting Algorithms

### 26. **Bucket Sort**
   Similar to counting sort, but the range of elements is divided into smaller intervals or "buckets", which are then sorted individually.

### 27. **Counting Sort**
   Works by counting the occurrences of each element and calculating their final positions.

### 28. **Radix Sort**
   Sorts integers by processing individual digits and sorting based on each digit from least significant to most significant.

### 29. **Flash Sort**
   Combines aspects of bucket sort and quicksort, by classifying elements into "buckets" and sorting them within.

### 30. **Cyclic Sort**
   It works by placing each element in its correct position based on its value (typically used when the elements are in a specific range).

---

### Parallel Sorting Algorithms

### 31. **Parallel Merge Sort**
   A parallelized version of merge sort where the merge step is done in parallel to speed up the process.

### 32. **Parallel Quick Sort**
   A parallelized version of quicksort, where each partitioning step is done in parallel for multiple threads.

### 33. **Bitonic Sort**
   A comparison-based parallel sorting algorithm that works by repeatedly creating "bitonic" sequences in the array, ideal for parallel hardware.

### 34. **Sample Sort**
   A parallel sorting algorithm that partitions data into smaller segments using sampling, then sorts the segments in parallel.

---

### Advanced Algorithms

### 35. **Patience Sort**
   A technique used in card games where cards are sorted using a series of piles, each pile following the patience principle (a sequence of cards that can be arranged into a sorted pile).

### 36. **Tree Sort**
   A sorting algorithm based on binary search trees, where elements are inserted into a binary search tree and then traversed in-order to extract a sorted list.

### 37. **K-th Order Statistic**
   A variation of quickselect, used to find the K-th smallest element and is often used in statistical analysis.

### 38. **Wave Sort**
   Sorts the array in a wave-like pattern where the elements are arranged such that every other element is greater than its adjacent elements.

### 39. **N-way Merge Sort**
   A generalization of merge sort, which merges more than two subarrays in each step.

### 40. **Merge Insertion Sort**
   A hybrid sorting algorithm that uses insertion sort on small subarrays and merges them recursively.

---

These sorting algorithms provide a broad spectrum of techniques for sorting arrays and lists with different time complexities, ranging from simple methods like Bubble Sort to more advanced and hybrid methods like Tim Sort.
