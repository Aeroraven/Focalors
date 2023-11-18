# Focalors
Solutions to some algorithm problems. (Mainly from leetcode)


## License
This repository is mainly for personal use, however, it's licensed under AGPL-v3.

So use it as free as you can.


## List of Solved Problems

*. Time complexity is calculated using the worst case (i.e. all hash conflict)


| ID | Problem | Solution Adopted | Perceived Difficulty | Annotated Difficulty | Time Complxity | Lang | Status | 
| -- | -- | -- | -- | -- | -- | -- | -- |
| 4 | Median of Two Sorted Arrays | Binary Search | 7 | Hard | O(logn) | C++ |
| 5 | Longest Palindromic Substring | Manacher | 4 | Med | O(n) | C++ |
| 8 | String to Integer | Simulation | 1 | Med | O(n) | CSharp |
| 10 | Regular Expression Matching | Dynamic Programming | 5 | Hard | | C++ |
| 11 | Container with Most Water | Dual Pointer | 7 | Med | O(n) | CSharp |
| 15 | 3 Sum | Hashing | 5 | Med | O(n^3) | CSharp |
| 16 | 3 Sum Closest | Dual Pointer | 5 | Med | O(n^2) | CSharp |
| 23 | Merge k Sorted Lists | Simulation | 2 | Hard |   | C++ |
| 25 | Reverse Nodes in k-Group | Simulation | 3 | Hard |   | C++ |
| 30 | Substring with Concatenation of All Words | Sliding Window | 7 | Hard |   | C++ |
| 32 | Longest Valid Parentheses | Dynamic Programming + Stack | 4 | Hard |   | C++ |
| 37 | Sudoku Solver | Simulation | 2 | Hard |   | C++ |
| 41 | First Missing Positive | Simulation (Inplace) | 8 | Hard |   | C++ |
| 42 | Trapping Rain Water | Simulation | 4 | Hard |   | C++ |
| 44 | Wildcard Matching | Dynamic Programming |  | Hard |  | C++ | T | 
| 50 | Pow(x,n) | Fast Power Algorithm | 3 | Med |   | C++ |
| 51 | N-Queens | Simulation | 1 | Hard |   | C++ |
| 52 | N-Queens II | Simulation | 1 | Hard |   | C++ |
| 60 | Permutation Sequence | Combinatorics | 5 | Hard |   | C++ |
| 65 | Valid Number | Simulation | 2 | Hard |   | C++ |
| 68 | Text Justification | Simulation | 2 | Hard |   | C++ |
| 70 | Climbing Stairs | <s>Meta-Programming (C++ Macro & Template)</s> + Dynamic Programming  | 0 | Easy |   | C++ |
| 76 | Minimum Window Substring | Sliding Window | 6 | Hard |   | C++ |
| 84 | Largest Rectangle in Histogram | Stack | 6 | Hard |   | C++ |
| 85 | Maximal Rectangle | Prefix Sum | 5 | Hard |   | C++ |
| 123 | Best Time to Buy and Sell Stock III | Dynamic Programming | 5 | Hard |   | C++ |
| 124 | Binary Tree Maximum Path Sum | Dynamic Programming | 3 | Hard |   | C++ |
| 127 | Word Ladder | Breadth\-first Search |   | Hard |  | C++ |  T |
| 135 | Candy | Greedy Strategy \+ Sort | 4  | Hard |   | C++ |
| 140 | Word Break II | Dynamic Programming + Depth-First Search + String Hash | 5  | Hard |   | C++ |
| 174 | Dungeon Game | Dynamic Programming | 7  | Hard |   | C++ |
| 184 | Best Time to Buy and Sell Stock IV | Dynamic Programming | 5 | Hard |   | C++ |
| 214 | Shortest Palindrome | Rabin-Karp |  | Hard |   | C++ |
| 218 | The Skyline Problem | Heap + Sort | 5 | Hard |   | C++ |
| 233 | Number of Digit One | Combinatorics + Dynamic Programming | 6 | Hard |   | C++ |
| 292 | Nim Game | Gaming Theory + Dynamic Programming | 3 | Easy |   | C++ |
| 295 | Find Median from Data Stream | Heap | 5 | Hard |   | C++ |
| 312 | Burst Balloons | Dynamic Programming | 6 | Hard |   | C++ |
| 315 | Count of Smaller Numbers After Self | Binary Index Tree | 3 | Hard |   | C++ |
| 327 | Count of Range Sum | Binary Index Tree + Hash + Binary Search Tree + Prefix Sum | 6 | Hard |   | C++ |
| 403 | Frog Jump | Breadth-first Search | 3 | Hard |   | C++ |
| 410 | Split Array Largest Sum | Dynamic Programming |  | Hard |   | C++ |  T |
| 679 | 24 Game | Simulation | 2 | Hard |   | C++ |
| 793 | Preimage Size of Factorial Zeroes Function | Primary Math + Binary Search | 6 | Hard |   | C++ |
| 829 | Consecutive Numbers Sum | Primary Math | 2 | Hard |   | C++ |
| 878 | Nth Magical Number | Math Theory + Binary Search | 7 | Hard |   | C++ |
| 1137 | N-th Tribonacci Number | <s>Meta-Programming (C++ Macro & Template)</s> + Dynamic Programming  | 0 | Easy |   | C++ |
| 1345 | Jump Game IV | Breadth-first Search | 3 | Hard |   | C++ |
| 1610 | Maximum Number of Visible Points | Computational Geometry + Sort | 4 | Hard |   | C++ |
| LCR126 | Fibonacci Number | <s>Meta-Programming (C++ Macro & Template)</s> + Dynamic Programming  | 0 | Easy |   | C++ |


`Simulation` means the problem can be solved using `Brute Force` algorithm (Do what you are asked to do)



## List of Unsolved Problems

| ID | Problem | Annotated Difficulty | Status |
| -- | -- | -- | -- |
| 87 | Scramble String  | Hard |


## List of Problems Solved in Suboptimal Method

| ID | Problem | Solution Adopted | Time Complexity | Optimal Solution | Time Complexity |  
| -- | -- | -- | -- | -- | -- |
| 15 | 3 Sum | Hashing | O(n^3)* | Dual Pointer | O(n^2)
| 70 | Climbing Stairs |  Dynamic Programming | O(n) | Dynamic Programming + Matrix Fast Power Algorithm | O(logn) |
| 214 | Shortest Palindrome | Rabin-Karp | O(n^2)* | Manacher | O(n)
| LCR126 | Fibonacci Number |  Dynamic Programming | O(n) | Dynamic Programming + Matrix Fast Power Algorithm | O(logn) |

*. Worst case of hash function


## Annotations
- `T`: An accepted but time-consuming algorithm
