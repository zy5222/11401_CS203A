# Stacks & Queues

## Concepts & Definitions
Stacks and Queues are **Linear Data Structures**, differentiated primarily by the order in which data is added and removed.

### Stack (LIFO)
- **Principle**: **LIFO (Last-In, First-Out)**. The last element added is the first one to be removed.
- **Concept**: Analogous to a stack of plates; you can only add or remove the top plate.
- **Access Point**: Operations are restricted to one end, called the **Top**.

### Queue (FIFO)
- **Principle**: **FIFO**. The first element added is the first one to be removed.
- **Concept**: Analogous to a checkout line; the person at the front is served first, and new people join at the back.
- **Access Points**:
    - **Rear**: Where elements are added (**Enqueue**).
    - **Front**: Where elements are removed (**Dequeue**).
      
## Visualization
### Stack (LIFO)
```text
      |     |
      |  C  | <- Top (Push/Pop happens here)
      |  B  |
      |  A  |
      +-----+
      Bottom
```
### Queue (FIFO)
```
Dequeue (Remove) <--- [ A | B | C | D ] <--- Enqueue (Insert)
                      ^           ^
                    Front        Rear
```
## Implementation Deep Dive
Both data structures can be implemented using either Arrays or Linked Lists.
### Stack Implementation
  -  Array Implementation 
     -Uses an array `stack[MAX_SIZE]`and an integer `top`.
       - **Variables**: `top` tracks the index of the current top element (initialized to -1).
       - **Push**: `stack[++top] = value` (Increment top, then store).
       - **Pop**: `return stack[top--]` (Return value, then decrement top).
       - **Constraint**: Must check for **Overflow** (Top == MAX_SIZE - 1) and **Underflow** (Top == -1).

- linked List Implementation
    - Uses a pointer `Node* top` pointing to the head node.
      - **Push**: Create a new node, set `newNode->next = top`, then update `top = newNode` (Insert at head).
      - **Pop**: Check if not empty, move `top` to `top->next`, and free the old node.
      - **Pros**: Dynamic size; no overflow unless memory is exhausted.
      - **Cost**: Requires `malloc/free` overhead for every operation.
### Queue Implementation
  - Array Implementation (Circular Queue)
    - A simple array implementation suffers from "false overflow" (empty space at the beginning cannot be reused). The solution is a Circular Buffer.
      - Key Logic (Modulo Arithmetic):
        - **Enqueue**: `rear = (rear + 1) % MAX_SIZE`
        - **Dequeue**: `front = (front + 1) % MAX_SIZE`
       - State Detection:
         - **Full**: `(rear + 1) % MAX_SIZE == front` (Often requires keeping one slot empty or using a `count` variable to distinguish from empty).
         - **Empty**: `front == rear`.
  - Linked List Implementation
    - Uses two pointers: `front` (head) and `rear` (tail).
      - **Enqueue**: Create a new node, set `rear->next = newNode`, then update `rear = newNode`.
      - **Dequeue**: Store `front` node, move `front` to `front->next`, and free the old node.
      - Note: Special handling is required when the queue becomes empty (must set `rear = NULL`).
## Comparison & Trade-offs

| Feature | Array Implementation | Linked List Implementation |
| :--- | :--- | :--- |
| **Memory Management** | **Static**: Pre-allocated fixed size. May waste unused space or overflow. | **Dynamic**: Allocated per node. Incurs extra memory overhead for pointers. |
| **Performance** | **$O(1)$**: Very fast, no allocation overhead during operations. | **$O(1)$**: But involves `malloc`/`free` overhead for each operation. |
| **Overflow Risk** | **Yes**: Occurs when capacity is reached (`MAX_SIZE`). | **No**: Unless system heap memory is exhausted. |
| **Implementation Complexity** | **Moderate**: Requires index tracking and modulo math (for circular queues). | **Moderate**: Requires careful pointer management (avoiding leaks, dangling pointers). |
| **Resizing** | **Expensive**: Requires copying the entire array to a larger one. | **Not required**: The structure grows naturally. |

## Time Complexity

For both Stacks and Queues, core operations are generally $O(1)$, but with some nuances regarding memory allocation and resizing.

| Operation | Array Implementation | Linked List Implementation | Note |
| :--- | :--- | :--- | :--- |
| **Push / Enqueue** | **$O(1)$** | **$O(1)$** | Array is amortized $O(1)$ (resizing takes $O(n)$). Linked List involves `malloc`. |
| **Pop / Dequeue** | **$O(1)$** | **$O(1)$** | Both are constant time operations. Linked List involves `free`. |
| **Peek (Top/Front)**| **$O(1)$** | **$O(1)$** | Direct access to the tracked index or pointer. |
| **Space Complexity**| **$O(N)$** | **$O(N)$** | Array may waste space (pre-allocated); Linked List uses extra space per node (pointers). |

## Use Cases
### Stack (LIFO) Applications 
- **Function Calls**: Managing the call stack (recursion, local variables).
- **Undo/Redo**: Editors store history states in a stack.
- **Expression Evaluation**: Parsing mathematical expressions (e.g., Postfix/Reverse Polish Notation).
- **Browser History**: The "Back" button functionality.

### Queue (FIFO) Applications 
- **Task Scheduling**: OS process scheduling (Round Robin).
- **Buffering**: I/O buffers (keyboard strokes, video streaming).
- **Printer Spooling**: Print jobs are processed in the order received.
- **Breadth-First Search (BFS)**: Core data structure for graph exploration.

## ADT Definitions (Abstract Data Type)
### Standard operations defined in the course lectures:
- Stack ADT 
  - `CreateS(maxSize)`: Create an empty stack.
  - `Push(stack, item)`: Insert item at the top (if not full).
  - `Pop(stack)`: Remove and return the top item (if not empty).
  - `IsFull(stack)` / `IsEmpty(stack)`: Check state.
    
- Queue ADT 
  - `CreateQ(maxSize)`: Create an empty queue.
  - `AddQ(queue, item)`: Insert item at the rear (if not full).
  - `DeleteQ(queue)`: Remove and return the front item (if not empty).
  - `IsFullQ(queue)` / `IsEmptyQ(queue)`: Check state.

  ## Basic Exercises(QUIZ II)
  <img width="828" height="579" alt="image" src="https://github.com/user-attachments/assets/c0987799-39f8-43b0-ae28-4d5ace1eeb0b" />
  
## Note
- This study note is based on the CS203A lecture slides and was summarized and formatted with the assistance of Google Gemini.
