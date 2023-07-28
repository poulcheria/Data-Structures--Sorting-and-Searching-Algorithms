# Data-Structures--Sorting-and-Searching-Algorithms

Data Structures in C++: Sorting &amp; Searching Explore sorting &amp; searching algorithms in C++. 
Overview &amp;
This repository contains C++ implementations and performance analysis of essential sorting and searching algorithms as part of my university project for the Computer Engineering and Informatics department (CEID) . The algorithms were tested on a dataset consisting of temperature and humidity measurements.

## Sorting Algorithms
### 1. Merge Sort and Quick Sort
Merge Sort execution time: 21.643 sec  
Quick Sort execution time: 24.844 sec

**Theoretical complexities:**
Merge Sort: O(nlogn) comparisons and O(nlogn) swaps in the worst case.
Quick Sort: O(n^2) comparisons and O(logn) swaps in the worst case, but O(nlogn) comparisons and O(logn) swaps on average.

**Explanation:**
Merge Sort's worst-case complexity is O(nlogn) for both comparisons and swaps. Quick Sort has a worst-case complexity of O(n^2) for comparisons and O(logn) swaps. However, on average, Quick Sort's performance improves significantly to O(nlogn) comparisons and O(logn) swaps due to its randomized pivot selection strategy.

### 2. Heap Sort and Counting Sort
Heap Sort execution time: 22.949 sec
Counting Sort execution time: 20.513 sec

**Theoretical complexities:**
Heap Sort: O(nlogn) comparisons and O(1) swaps in the worst case.
Counting Sort: O(n + k) comparisons and O(n + k) swaps, where k is the range of input elements.

**Explanation:**
Heap Sort's worst-case complexity is O(nlogn) for comparisons and performs a constant number of swaps (O(1)) per comparison. Counting Sort, on the other hand, has a complexity of O(n + k) for both comparisons and swaps, where k is the range of input elements. Counting Sort can be particularly efficient when the range of input elements is relatively small.

## Searching Algorithms
### 1. Binary Search and Interpolation Search
Binary Search execution time: 4.717 sec
Interpolation Search execution time: 4.492 sec

**Theoretical complexity:**
Both Binary Search and Interpolation Search have an average time complexity of O(logn).

**Explanation:**
The theoretical complexity for the searching algorithms is correct. Both Binary Search and Interpolation Search have an average time complexity of O(logn) for sorted arrays.
