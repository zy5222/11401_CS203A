# Heap

## Definition
- A heap is a **complete binary tree** that satisfies the **heap-order property**.
## Shape Property: Structure
- **Definition**: The heap is a complete binary tree.
- **Rules**: (1) Every level is completely filled, except possibly the last level. (2) The last level's nodes are filled from left to right.
- **Benefit**: This property guarantees that the heap can be stored efficiently in an array with no gaps.

## Heap-Order Property: Ordering
There are two types of heaps based on **node ordering**:
- **Max Heap**:
   - Each parent node's key is always **greater than or equal to** their children (Parent >= Children).
   - The **maximum element** is always **at the root**.
  <img width="800" height="400" alt="image" src="https://github.com/user-attachments/assets/3b6157a4-330d-48fc-bf53-ef2b54bb213f" />
  
  *Image Source: Self-made using Visualgo.*

- **Min Heap**:
   - Each parent node's key is always **less than or equal to** their children (Parent <= Children).
   - The **minimum element** is always **at the root**.
  <img width="800" height="400" alt="image" src="https://github.com/user-attachments/assets/d0dbd553-5350-4ab7-8e41-43b5edfd1b0b" />
  
  *Image Source: Self-made using USFCA Heap Visualization.*

## Array Representation

- Example: Max Heap
  - Tree Structure:
    ```text
          50
         /  \
       30    40
      /  \
    10    20
    ```
  - Array: [50, 30, 40, 10, 20].

- Example: Min Heap
  - Tree Structure:
    ```text
          10
         /  \
       15    30
      /  \
    40    50
    ```
  - Array: [10, 15, 30, 40, 50].

 ## Priority Concept
 In a heap, the specific order represents "Priority".

 - **Priority Definition**: A higher (or lower) value means "more important" or "should be handled first"
 - **Encoded Rule**:
     - **Max-Heap**: Largest key = Highest priority.
     - **Min-Heap**: Smallest key = Highest priority.
 - **Applications**: Emergency triage, OS job scheduling, Network QoS.(急診檢傷分類、作業系統排程、網路服務品質控制)

## Core Operations
Heap operations must maintain the Complete Binary Tree shape first, then fix the order.

- Insertion: Sift-Up
    - Goal: Add a new element and restore heap-order.
    - Steps :
       ```text      
       1.Insert: Place the new node at the leftmost empty position on the last level (maintain shape).
       2.Compare: Compare the new node with its parent.
       3.Swap: If the order is violated (e.g., child > parent in Max Heap), swap them. 
       4.Repeat: Continue moving up until the property holds or root is reached. 
       ```
- Extract Root: Sift-Down
    - Goal: Remove the max (or min) element.
    - Steps :
       ```text
       1.Replace: Replace the root with the last leaf (maintain shape). 
       2.Compare: Compare the new root with its children.
       3.Swap: Swap with the larger child (Max Heap) or smaller child (Min Heap).
       4.Repeat: Continue moving down until the property holds or a leaf is reached. 
       ```
## Time Complexity
| Operation | Time (Average) | Description | why? |
| :--- | :--- | :--- | :--- |
| **peek_root** |  O(1)  | Access max/min element 存取最大/最小值| Root is at index 0|
| **insert(x)** |  O(log n)  | Add element (Sift-up)| Moves leaf -> root (height)|
| **extract root()** |  O(log n)  | Remove max/min (Sift-down)| Moves root -> leaf (height)|
| **build heap** |  O(n)  | Convert array to heap| More efficient than n insertions |
| **heapsort** |  O(n log n)  | Sort array using heap|n times extract-max|

## Summary
- **Data Structure**: Complete Binary Tree.
- **Storage**: Array (most efficient).
- **Typical Uses**: Priority Queue, Scheduling, Heapsort.
- **Performance**: Logarithmic insertion and removal (O(log n)).
