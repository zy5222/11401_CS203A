# Hash Table

## Definition
- Hashing is a data structure technique that uses a hash function to convert a key into an index (or bucket) within an array to store key-value pairs.
- It solves the problem of efficiently retrieving data from large datasets without scanning the entire list, achieving an average constant-time complexity `O(1)` for search operations.
## Visualization

- **Chaining**: Uses a Linked List at each bucket to store multiple items that hash to the same index.
  ```text
  Index
  +---+
  | 0 |
  +---+
  | 1 |
  +---+      +------+    +------+    +------+
  | 3 | ---> |  15  | -> |  23  | -> |  7   | -> NULL
  +---+      +------+    +------+    +------+
  | 4 |
  +---+
- **Linear Probing**: Everything is stored in the array itself. If a spot is taken, find the next open spot.
  ```text
  Hash Table (Linear Probing)
  ===========================
  Scenario: Insert 33 (Hash=3), but Index 3 is full.
  
  Index |  Data  | Status
  ------+--------+-----------------------------
    0   |        |
    1   |        |
    2   |        |
    3   |   23   | [Occupied] Collision!
    4   |   33   | [OK] Probed & Inserted here
    5   |        |
    6   |        |
    ```

## Collision Resolution
Since the universe of keys is larger than our table size, **Collisions** (two keys hashing to the same index) are inevitable.
- **Separate Chaining**:
  - Mechanism: Each bucket stores a pointer to a Linked List.
  - Pros: Simple; performance degrades gracefully (linearly) as the table fills.
  - Cons: Uses extra memory for pointers; creating new nodes requires memory allocation.
- **Open Addressing**:
  - Stores all elements in the array. Requires a Probing Sequence to find an empty slot.
    
| Method | Formula | Description & Issue |
| :--- | :--- | :--- |
| **Linear Probing** | $(h(k) + i) \% m$ | Checks next slot (+1, +2...). Causes **Primary Clustering** (blocks of occupied slots grow larger). |
| **Quadratic Probing** | $(h(k) + c_1 i + c_2 i^2) \% m$ | Jumps by squares (+1, +4, +9...). Reduces primary clustering but can cause **Secondary Clustering**. |
| **Double Hashing** | $(h_1(k) + i \cdot h_2(k)) \% m$ | Uses a **second hash function** for the step size. Best distribution; minimal clustering. |
    

## Characteristics
- Ordering:
  
  - **Unordered**: The data is not stored in a sorted order (like alphabetical or numerical).The position is determined by the hash function.
    
- Indexing:
  - **Computed Indexing**: It is inherently index-based (using an array), but the index is computed from the key using a **Hash Function** `(Key -> Index)`.

- Key Uniqueness:
  - **Keys must be unique**: No two pairs have the same key.(values can be duplicated)
  - **Collisions are allowed**: Multiple different keys can map to the same index (Collision), which must be handled via Chaining or Open Addressing.
    
- Load Factor ($\alpha$):
  - Formula: $\alpha = \frac{n \text{ (number of elements)}}{m \text{ (table size)}}$
  - Significance: Measures how full the table is.
  - Threshold: when **$\alpha > 0.75$**, the table must **resize**

- Dynamic size:
  - **Dynamic Hashing**: The table can grow or shrink automatically when the load factor (α) exceeds a threshold (e.g., resize when full).
  - **Static Hashing**: Size is fixed at creation.

- Memory layout:
  - **Hybrid (Array + Pointers)**:
    - **Buckets**: Contiguous memory (Array) is used for the main buckets.
    - **Chaining**: Uses Pointers (Linked Lists) for collisions, which are non-contiguous.
    - **Open Addressing**: Uses purely contiguous memory (Entire Array).

- Typical operations:
  - **Create(size)**: Initializes an empty hash table with a specified number of buckets `(m)`.
  - **Insert(key, value)**: Adds a new key-value pair to the table. If the key already exists, it typically updates the value.
  - **Retrieve(key)**: Finds and returns the **value** associated with the specific key. Throws an exception or returns null if not found.
  - **Search(key)**: Checks if a key exists in the table and returns a Boolean (TRUE/FALSE).
  - **Delete(key)**: Removes the key-value pair associated with the specific key from the table.
  - **Traverse()**: Returns an iterator to visit all key-value pairs in the table (typically iterating through buckets).
  - **IsEmpty()**: Checks whether the table contains no elements(size is 0).
  
## Time/Space Complexity
| Operation | Time (Average) | Description |
| :--- | :--- | :--- |
| **Access / Search** |  O(1)  | Direct access via computed index (Hash Function). |
| **Insert** |  O(1)  | Add to bucket or list head immediately. |
| **Delete** |  O(1)  | Remove directly from bucket or list. |

- **Space Complexity:**  O(n)  (Stores  n  elements).
- **Extra Memory:**
  - **Chaining:** Requires extra space for **pointers** (Linked List nodes).
  - **Open Addressing:** Requires **empty slots** (larger table size) to prevent clustering and keep load factor low.

## Limitations
- **Collisions**: Inevitable when multiple keys map to the same index. Poor hash functions lead to many collisions, degrading performance from O(1) to O(n).

- **Clustering**: In Open Addressing (especially Linear Probing), occupied slots tend to form clusters. This increases probe lengths and slows down operations significantly.
  
- **No Ordering**: The data is strictly unordered. It is awkward to use for range queries (e.g., "find values between X and Y") or when sorted data is required.
  
- **Static Sizing**: Static hash tables have a fixed size. They perform poorly or fail when the dataset grows unexpectedly large, requiring expensive resizing operations.
  
## Pros, Cons & Trade-offs
- Pros
  - **Fast Retrieval**: Provides average constant-time complexity (O(1)) for insertion, deletion, and search operations.
  
  - **Efficiency**: Eliminates unnecessary search candidates early, making it ideal for quick lookups compared to scanning an entire list.
    
  - **Flexibility**: Dynamic hashing allows the table to grow or shrink to adapt to the dataset size.
    
- Cons
  - **Collisions**: Unavoidable; requires handling techniques like Chaining or Open Addressing, which adds complexity.
  - **Performance Degradation**:
    - In the worst case (many collisions), performance drops to O(n).
    - **Clustering** (in open addressing) can cause "traffic jams," slowing down insertions and searches as the table gets full.
  - **Unordered**: Data is not stored in any logical order (like numerical or alphabetical), making range queries (e.g., "find all items > 100") difficult.
 
- When to Use?
  | Scenario | Decision | Reason |
  | :--- | :--- | :--- |
  | **Exact Match Lookups** | ✅ **Use** | Best for finding a specific item by a unique key (e.g., Dictionary, Student ID). |
  | **Caching (e.g., DNS)** | ✅ **Use** | Critical for applications needing high-speed retrieval of mapped data (e.g., Domain $\to$ IP). |
  | **Ordered Data Required** | ❌ **Do Not Use** | Hash tables do not maintain order. Use a Binary Search Tree (BST) or Sorted Array instead. |
  | **Range Queries** | ❌ **Do Not Use** | Finding values "between X and Y" is inefficient because the hash function scatters data randomly. |

## Use Cases
### 1. DNS Caching (Real-world Application)
- **Problem:** Browsers need to resolve domain names (e.g., `example.com`) to IP addresses frequently.
- **Solution:** Use a hash table to cache recent lookups.
  - **Key:** Domain Name (`example.com`)
  - **Value:** IP Address (`192.0.0.15`)
- **Benefit:** Reduces network latency by providing `O(1)` access to frequently visited sites.

### 2. Digital Dictionary
- **Problem:** Users need to look up word definitions instantly.
- **Solution:** Store words in a hash table (like the "Fruit Dictionary" example).
  - **Key:** Word (e.g., "Apple")
  - **Value:** Definition or Description
- **Benefit:** Allows instant retrieval of meanings without scanning through an alphabetical list.

### 3. Student Record Retrieval (Database Indexing)
- **Problem:** A university needs to access specific student records from a database of thousands.
- **Solution:** Use Student ID as a unique key for hashing.
  - **Key:** Student ID
  - **Value:** Student Record (Name, Courses, Grades)
- **Benefit:** Enables direct access to a specific student's file in constant time.
  
## Basic Exercises on Hash Table Concepts (QUIZ III)
<img width="1144" height="843" alt="image" src="https://github.com/user-attachments/assets/590b7e6e-cf7f-4a18-9178-a42669742e6b" />

## Note
- This study note is based on the CS203A lecture slides and was summarized and formatted with the assistance of Google Gemini.
