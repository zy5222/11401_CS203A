# Linked Lists
## Concepts & Definitions
- A **Linked List** is a linear data structure where elements are not stored at contiguous memory locations. Instead, the elements are linked using **pointers**.
### Characteristics
* **Node-Based**: Each element is called a **Node**, which contains:
    1.  **Data**: The value or information.
    2.  **Next Pointer**: A reference (address) to the next node in the sequence.
- **Dynamic Size**: Unlike arrays, linked lists can grow or shrink dynamically during program execution .
- **Sequential Access**: Elements must be accessed sequentially starting from the first node (**Head**). Random access is not possible.
  
## Visualization

### Singly Linked List
- Each node points to the next node. The last node points to `NULL`.

```text
 [Head]      Node 1            Node 2            Node 3
   |        +------+------+   +------+------+   +------+------+
   +----->  | Data | Next |-->| Data | Next |-->| Data | NULL |
            +------+------+   +------+------+   +------+------+
```
### Doubly Linked List
- Each node has two pointers: Prev (previous) and Next. Allows traversal in both directions.
```text
Node 1                 Node 2
   +------+------+------+   +------+------+------+
   | NULL | Data | Next |-->| Prev | Data | Next |--> ...
   +------+------+------+   +------+------+------+
             ^  |             |  ^
             |  +-------------+  |
             +-------------------+
```

## Types of Linked Lists
- Singly Linked List: Navigation is forward only.
- Doubly Linked List: Navigation is forward and backward. Uses more memory for the extra pointer.
- Circular Linked List: The last node points back to the first node instead of NULL. Can be singly or doubly circular.

## Implementation Deep Dive
- Node Structure (C/C++ Style)
```
struct Node {
    int data;
    struct Node* next;
};
```
- Core Operations
  - Traversal: Start from Head and move to next until NULL.
  - Insertion:
    - At Head: Create new node, point its next to current head, update Head pointer. ($O(1)$)
    - At Tail: Traverse to the end, point last node's next to new node. ($O(n)$ without tail pointer)
    - At Middle: Traverse to position, adjust pointers to insert new node between two existing nodes.
  - Deletion:
    - Find the node (and its predecessor).
    - Update predecessor's next to skip the target node.
    - Free the memory of the target node.
      
## Comparison: Array vs. Linked List

| Feature | Array | Linked List |
| :--- | :--- | :--- |
| **Memory Structure** | **Contiguous**: Stored in a solid block. | **Non-Contiguous**: Scattered in memory, linked by pointers. |
| **Size** | **Fixed**: Static size (usually). Resizing is expensive (copying). | **Dynamic**: Grows/shrinks as needed. No pre-allocation. |
| **Access** | **Random Access (O(1))**: Direct index access `arr[i]`. | **Sequential Access (O(n))**: Must traverse from Head. |
| **Insertion/Deletion** | **Costly (O(n))**: Shifting elements is required. | **Efficient (O(1))**: Only pointer updates (if position is known). |
| **Memory Efficiency** | High for data, but may waste space if array is not full. | Lower per element due to **pointer overhead** (extra 4-8 bytes per node). |

## Time Complexity 

| Operation | Time Complexity | Explanation |
| :--- | :--- | :--- |
| **Access (Index)** | **$O(n)$** | Must traverse $k$ nodes to reach the $k$-th element. |
| **Search (Value)** | **$O(n)$** | Linear search through the list. |
| **Insert (at Head)** | **$O(1)$** | Only need to update the `Head` pointer. |
| **Insert (at Tail)** | **$O(n)$** | Must traverse to end (unless a `Tail` pointer is maintained, then $O(1)$). |
| **Delete (at Head)** | **$O(1)$** | Move `Head` to `Head->next` and free old head. |
| **Delete (at Middle)** | **$O(n)$** | Search takes $O(n)$; pointer update is $O(1)$. |

## Advanced Concepts & Techniques
- Based on the "AI Prompt for Studying" section in the slides
- Two-Pointer Technique (Fast & Slow Pointers):
  - Cycle Detection (Floyd’s Algorithm): Use a slow pointer (move 1 step) and a fast pointer (move 2 steps). If they meet, there is a cycle.
  - Find Middle: When fast pointer reaches the end, the slow pointer is at the middle.
- Sentinel Nodes (Dummy Nodes):
  - Using a dummy node at the head (or tail) eliminates edge cases (like inserting into an empty list or deleting the head), simplifying code logic.
- Memory Management:
  - Crucial to avoid Memory Leaks (freeing deleted nodes) and Dangling Pointers (pointers referring to freed memory).
    
## Pros, Cons & Trade-offs
- Pros
  - **Dynamic Size**: No need to predict the number of elements beforehand.
  - **Efficient Insertion/Deletion**: Can add/remove items without shifting other elements (unlike arrays).
  - **Flexible Memory Usage**: Utilizes fragmented memory effectively.
- Cons
  - **No Random Access**: Cannot jump to the 10th element directly; must walk through 0-9.
  - **Memory Overhead**: Extra memory is required for pointers (significant for small data types like `bool` or `char`).
  - **Cache Unfriendly**: Non-contiguous memory leads to poor CPU cache locality compared to arrays.
    
## Use Cases
- **Implementing Stacks & Queues**: Linked lists allow `O(1)` push/pop or enqueue/dequeue without size limits.
- **Adjacency Lists for Graphs**: Storing graph connections where the number of neighbors varies dynamically.
- **Undo Functionality**: Storing a history of operations where new states are added constantly.
- **Music Playlist**: A circular linked list allows looping back to the first song after the last one ends.
  
## ADT Definitions
- Create(): Initialize an empty list.
- IsEmpty(): Return true if the list has no nodes.
- InsertFront(item): Add item to the beginning.
- InsertBack(item): Add item to the end.
- Remove(item): Find and remove the first occurrence of item.
- Contains(item): Check if item exists in the list.
- Size(): Return the number of nodes.
  
## Basic Exercises(Assignment III)
<img width="1088" height="790" alt="image" src="https://github.com/user-attachments/assets/af0ea49e-fa46-4f98-83da-f666aada301c" />
<img width="1150" height="811" alt="image" src="https://github.com/user-attachments/assets/5cdc7360-022a-4241-83e6-532df8c5816b" />
<img width="1154" height="854" alt="image" src="https://github.com/user-attachments/assets/e0cab2fd-8dc5-4183-9085-990b4a776c9d" />
<img width="568" height="440" alt="image" src="https://github.com/user-attachments/assets/2b01de04-e7c9-42c7-a918-016a23521ea7" />
<img width="789" height="848" alt="image" src="https://github.com/user-attachments/assets/77533af9-6e34-4f4b-8cbc-71fa9b3d4354" />

## Note
- This study note is based on the CS203A lecture slides and was summarized and formatted with the assistance of Google Gemini.
