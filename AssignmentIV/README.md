# Homework Assignment IV: Hash Function Design & Observation (C/C++ Version)

This assignment focuses on the design and observation of hash functions using C/C++. 
Students are expected to implement and analyze the behavior of hash functions, 
evaluate their efficiency, and understand their applications in computer science.

Developer: 王芷芸

Email: s1131547@mail.yzu.edu.tw

## Development Platform

OS: Windows 11

Toolchain: MinGW-w64 (MSYS2)

IDE: VS Code
## My Hash Function
### Integer Keys 
- Formula / pseudocode:
  ```c
  if (m <= 0) return 0;
  return key % m;
  ```
- Rationale:  I used the basic Division Method. This is the most fundamental hashing technique where the key is divided by the table size m, and the remainder is used as the index. The uniformity depends on the table size m.

### Non-integer Keys
- Formula / pseudocode:
  ```c
  if (m <= 0 || str == NULL || *str == '\0') {
    return 0;
  }
  unsigned long hash = 0;
  while (*str != '\0') {
    hash = hash * 31 + (unsigned char)(*str);
    str++;
  }
  return (int)(hash % m);
  ```
- Rationale: I implemented the Polynomial Rolling Hash using P = 31. I used a while loop to iterate through the string pointer. This method minimizes collisions by considering the position of each character.

## Experimental Setup
- Table sizes tested (m): 10, 11, 37
- Test dataset:
  - Integers: 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60
  - Strings: "cat", "dog", "bat", "cow", "ant", "owl", "bee", "hen", "pig", "fox"
- Compiler: GCC and G++
- Standard: C23 and C++23

## Results
| Table Size (m) | Index Sequence         | Observation              |
|----------------|------------------------|--------------------------|
| 10             | 1, 2, 3, 4, ...        | Pattern repeats every 10 |
| 11             | 10, 0, 1, 2, ...       | More uniform             |
| 37             | 20, 21, 22, 23, ...    | Near-uniform             |

## Compilation, Build, Execution, and Output

### Compilation
- Command for C:
  ```bash
  gcc -std=c23 -o hash_function main.c
  ```
- Command for C++:
  ```bash
  g++ -std=c++23 -o hash_function_cpp main.cpp
  ```

### Make Binary
- Use the following `Makefile` to automate the build process:
  ```makefile
  all:
      gcc -std=c23 -o hash_function main.c
      g++ -std=c++23 -o hash_function_cpp main.cpp
  clean:
      rm -f hash_function hash_function_cpp
  ```

### Execution
- Run the compiled binary:
  ```bash
  ./hash_function
  ```
  or
  ```bash
  ./hash_function_cpp
  ```

### Result Snapshot
- Output for integers:
  ```
  === Hash Function Observation (C Version) ===

  === Table Size m = 10 ===
  Key     Index
  -----------------
  21      1
  22      2
  23      3
  24      4
  25      5
  26      6
  27      7
  28      8
  29      9
  30      0
  51      1
  52      2
  53      3
  54      4
  55      5
  56      6
  57      7
  58      8
  59      9
  60      0

  === Table Size m = 11 ===
  Key     Index
  -----------------
  21      10
  22      0
  23      1
  24      2
  25      3
  26      4
  27      5
  28      6
  29      7
  30      8
  51      7
  52      8
  53      9
  54      10
  55      0
  56      1
  57      2
  58      3
  59      4
  60      5

  === Table Size m = 37 ===
  Key     Index
  -----------------
  21      21
  22      22
  23      23
  24      24
  25      25
  26      26
  27      27
  28      28
  29      29
  30      30
  51      14
  52      15
  53      16
  54      17
  55      18
  56      19
  57      20
  58      21
  59      22
  60      23

  === String Hash (m = 10) ===
  Key     Index
  -----------------
  cat     2
  dog     4
  bat     1
  cow     9
  ant     3
  owl     8
  bee     0
  hen     5
  pig     0
  fox     3

  === String Hash (m = 11) ===
  Key     Index
  -----------------
  cat     10
  dog     6
  bat     6
  cow     7
  ant     9
  owl     6
  bee     5
  hen     5
  pig     0
  fox     9

  === String Hash (m = 37) ===
  Key     Index
  -----------------
  cat     27
  dog     3
  bat     28
  cow     20
  ant     25
  owl     23
  bee     26
  hen     29
  pig     27
  fox     18

  === Hash Function Observation (C++ Version) ===
  === Table Size m = 10 ===
  Key     Index
  -----------------
  21      1
  22      2
  23      3
  24      4
  25      5
  26      6
  27      7
  28      8
  29      9
  30      0
  51      1
  52      2
  53      3
  54      4
  55      5
  56      6
  57      7
  58      8
  59      9
  60      0

  === Table Size m = 11 ===
  Key     Index
  -----------------
  21      10
  22      0
  23      1
  24      2
  25      3
  26      4
  27      5
  28      6
  29      7
  30      8
  51      7
  52      8
  53      9
  54      10
  55      0
  56      1
  57      2
  58      3
  59      4
  60      5

  === Table Size m = 37 ===
  Key     Index
  -----------------
  21      21
  22      22
  23      23
  24      24
  25      25
  26      26
  27      27
  28      28
  29      29
  30      30
  51      14
  52      15
  53      16
  54      17
  55      18
  56      19
  57      20
  58      21
  59      22
  60      23

  === String Hash (m = 10) ===
  Key     Index
  -----------------
  cat     2
  dog     4
  bat     1
  cow     9
  ant     3
  owl     8
  bee     0
  hen     5
  pig     0
  fox     3

  === String Hash (m = 11) ===
  Key     Index
  -----------------
  cat     10
  dog     6
  bat     6
  cow     7
  ant     9
  owl     6
  bee     5
  hen     5
  pig     0
  fox     9

  === String Hash (m = 37) ===
  Key     Index
  -----------------
  cat     27
  dog     3
  bat     28
  cow     20
  ant     25
  owl     23
  bee     26
  hen     29
  pig     27
  fox     18
  ```

- Observations: Outputs align with the analysis, showing better distribution with prime table sizes.
- Example output for integers:
  ```
  Hash table (m=10): [1, 2, 3, 4, 5, 6, 7, 8, 9, 0]
  Hash table (m=11): [10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
  Hash table (m=37): [20, 21, 22, 23, 24, 25, 26, 27, 28, 29, ...]
  ```
- Example output for strings:
  ```
  Hash table (m=10): ["cat", "dog", "bat", "cow", "ant", ...]
  Hash table (m=11): ["fox", "cat", "dog", "bat", "cow", ...]
  Hash table (m=37): ["bee", "hen", "pig", "fox", "cat", ...]
  ```
- Observations: Outputs align with the analysis, showing better distribution with prime table sizes.

## Analysis
- Prime vs non-prime `m`: Prime table sizes generally result in better distribution and fewer collisions.
- Patterns or collisions: Non-prime table sizes tend to produce repetitive patterns, leading to more collisions.
- Improvements: Use a prime table size and a well-designed hash function to enhance distribution.

## Reflection
1. Designing hash functions requires balancing simplicity and effectiveness to minimize collisions.
2. Table size significantly impacts the uniformity of the hash distribution, with prime sizes performing better.
3. The design using a prime table size and a linear transformation formula produced the most uniform index sequence.
