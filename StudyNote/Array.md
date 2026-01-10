# Array

## Concepts & Definitions

An **Array** is a fundamental data structure consisting of a collection of elements, typically of the same data type.

### Key Characteristics
- **Contiguous Memory**: Elements are stored in consecutive memory locations.
- **Direct Access**: Each element can be accessed directly using an index in constant time (`O(1)`).
- **Fixed vs. Variable Size**:
    - **Static Array**: Size is determined at compile time and cannot change.
    - **Dynamic Array**: Size can be allocated or resized at runtime (e.g., using `malloc`/`realloc` in C).

## Representation & Types
### One-dimensional (1D) Static Array
- **Declaration**: `int array[5];`
- **Initialization**: `int array[5] = {10, 20, 30, 40, 50};`
- **Visualization**: Indices map linearly to memory addresses.


```text
Index:   0    1    2    3    4
Value: [ 10 | 20 | 30 | 40 | 50 ]
```
### Multi-dimensional Arrays
- 2D Array: Visualized as a matrix (Rows $\times$ Columns).
  - Declaration: int array2d[3][4]; (3 Rows, 4 Cols)
  - Access: array2d[row][col]
- 3D Array: Visualized as a collection of 2D planes (Blocks $\times$ Rows $\times$ Cols).

## Dynamic Arrays

Dynamic arrays allow resizing during runtime, solving the fixed-size limitation of static arrays.

**Memory Management in C**
- **Allocation**: Use `malloc(n * sizeof(type))` to reserve memory block.
- **Resizing** (`realloc`):
  - When the array is full, create a new larger block (usually double the size: n = n * 2).
  - Copy existing elements to the new block.
  - **Critical Detail**: The starting memory address **changes** after reallocation because the system finds a new contiguous chunk of memory.
- **Deallocation**: Must use `free()` to **prevent memory leaks**.
  ```text
  // Example of Resizing Logic
  int *array = (int*) malloc(n * sizeof(int)); // Initial
  // ... fill array ...
  n = n * 2; // Double size
  array = (int*) realloc(array, n * sizeof(int)); // Resize (Address may change!)
  ```
## C++ STL: std::array vs. std::vector

C++ Standard Template Library (STL) provides optimized array implementations.

| Aspect | std::array (Static) | std::vector (Dynamic) |
| :--- | :--- | :--- |
| **Size** | **Fixed** at compile-time | **Variable** at runtime |
| **Memory Location** | **Stack** (usually) | **Heap** |
| **Performance** | **Fastest access** (minimal overhead) | **Fast**, but with slight overhead for management |
| **Memory Usage** | **Minimal** | Uses **extra capacity buffer** to minimize resizing cost |
| **Use Case** | **Known, fixed data size** | **Varying data requirements** |

**Common Operations**
- at(index): Access with bounds checking.
- size(): Current number of elements.
- capacity(): (Vector only) Allocated storage size.

## Core Algorithms: Sorting & Searching
- Searching
  - Linear Search:
    - Used for **Unsorted Arrays**.
    - Iterate through all elements to find the target.
    - Complexity: O(n).
  - Binary Search:
    - Used for **Sorted Arrays** only.
    - Divides search interval in half repeatedly.
    - Complexity: O(\log n).
- Sorting Algorithms
  - **Bubble Sort**: Repeatedly swaps adjacent elements if they are in the wrong order. "Bubbles" the largest element to the end.
  - **Selection Sort**: Repeatedly finds the minimum element from the unsorted part and puts it at the beginning
  - **Insertion Sort**: Builds the sorted array one item at a time, inserting elements into their correct position (efficient for small or nearly sorted data).

## Complexity Analysis

| Aspect | std::array (Static) | std::vector (Dynamic) |
| :--- | :--- | :--- |
| **Size** | **Fixed** at compile-time | **Variable** at runtime |
| **Memory Location** | **Stack** (usually) | **Heap** |
| **Performance** | **Fastest access** (minimal overhead) | **Fast**, but with slight overhead for management |
| **Memory Usage** | **Minimal** | Uses **extra capacity buffer** to minimize resizing cost |
| **Use Case** | **Known, fixed data size** | **Varying data requirements** |

## Pros, Cons & Trade-offs

**Pros**
- Fast Access: Ideal for scenarios requiring frequent read operations ($O(1)$ random access).
- Cache Friendliness: Contiguous memory location improves CPU cache performance compared to Linked Lists.

**Cons**
- **Costly Insertion/Deletion**: Inserting or deleting elements (especially in the middle) requires shifting subsequent elements, leading to `O(n)` complexity16.
- **Fixed Size (Static)**: Must know size in advance, potentially leading to wasted space or overflow.
- **Resizing Cost (Dynamic)**: Expanding a vector is expensive ($O(n)$) because it involves allocating new memory and copying data.

## ADT Definitions (Abstract Data Type)

Objects: A set of pairs <index, value> where index is an ordered set.

Standard Operations:
- `Create(n)`: Create an array of size n.
- `Retrieve(A, i)`: Return value at index $i$ ($O(1)$).
- `Store(A, i, x)`： Update index i with value x.
- `Resize(A, m)`: Change size to m (Dynamic).

## Real-World Application: Nginx

**Use Case**: IP-based access control module.
- **Function**: Restrict client access based on IP addresses (e.g., allow 192.168.1.0/24).
- **Implementation**: Uses **Arrays** (ngx_array_t) to store lists of access rules.
- **Why Arrays?**: Fast sequential access is needed to check a client IP against a list of rules during request processing.
  
## Basic Exercises(Assignment II)
<img width="1141" height="818" alt="image" src="https://github.com/user-attachments/assets/edeb0bec-d2c3-4024-86d0-930f42c6791d" />

## Note
- This study note is based on the CS203A lecture slides and was summarized and formatted with the assistance of Google Gemini.
