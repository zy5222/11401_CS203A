# Tree

## Definition
- A tree is a non-linear hierarchical data structure consisting of nodes connected by edges.
- Unlike Arrays and Linked Lists which are linear data structures, a Tree is a `non-linear`, `hierarchical` data structure consisting of `nodes` connected by `edges`.
## Key Characteristics:
- **Hierarchical:** Represents relationships like file systems, organizational charts, or family trees.
- **Acyclic:** Trees contain no cycles (loops).
- **Rooted:** Every tree has exactly one Root node.
## Terminology:
<img width="800" height="600" alt="image" src="https://github.com/user-attachments/assets/8b5ad0fb-7859-4b74-9288-254fa410d5af" />
<img width="800" height="600" alt="image" src="https://github.com/user-attachments/assets/c480ba06-e8b9-4d07-8262-2256ab4db1de" />

*Image source: Course Lecture Slides, Chapter 12.*

| Term | Definition |
| :--- | :--- | 
| **Root** | The topmost node of the tree.|
| **Parent** |  A node that has branches leading to other nodes.|
| **Child** | A node connected to a parent (descendant). | 
| **Leaf** |  A node with no children (external node). | 
| **Sibling** | Nodes that share the same parent.|
| **Fan-out(Degree)** | The number of children a node has. |
| **Height(depth)** | Longest path from the node to a leaf (Root height = max depth). |

## Definitions of Tree Variants(general → specialized)
<img width="800" height="600" alt="image" src="https://github.com/user-attachments/assets/56e44c6d-78f0-4706-89fc-c41c4146da11" />

*Image Source: Self-made using draw.io*

| Term | Definition |
| :--- | :--- | 
| **General Tree** | It is a hierarchical data structure consisting of a set of nodes. It has a single root node, and every node can have an unlimited number of children (subtrees). There is no constraint on how many branches a node can possess.|
| **Binary Tree** |  It is a tree data structure in which each node has at most two children, which are distinctively referred to as the "left child" and the "right child,and it is a shape-based definition, not value-based.There is no ordering constraint on the values in the tree."|
| **Binary Search Tree (BST)**| It is a binary tree that satisfies a specific ordering property: for every node, all keys in its left subtree are smaller than the node's key, and all keys in its right subtree are larger than the node's key.|
| **AVL Tree** |  It is a self-balancing Binary Search Tree. It enforces a strict condition where the difference in height between the left and right subtrees of any node (called the balance factor) must be no more than 1. If this property is violated during modification, the tree performs rotations to rebalance itself.|h|**Red-Black Tree** | It is a self-balancing Binary Search Tree where each node stores an extra bit representing a color (red or black). It uses specific rules (e.g., the root is black, red nodes cannot have red children) to ensure the longest path from the root to a leaf is no more than twice as long as the shortest path, guaranteeing O(log n) search time.|
|**Max Heap** |It is a specific type of complete binary tree that satisfies the heap property: the value of every parent node is greater than or equal to the values of its children. Consequently, the largest element is always found at the root.|
|**Min Heap**|It is a specific type of complete binary tree that satisfies the heap property: the value of every parent node is less than or equal to the values of its children. Therefore, the smallest element is always located at the root.|
|# Type of Binary Trees
simg width="800" height="600" alt="image" src="https://github.com/user-attachments/assets/ac82f0f1-f953-4e49-8470-d2d11f188440" " 
*Image source: Course Lecture Slides, Chapter 12.*

- **Strict:** Every node has either 0 or 2 children. No node has just 1 child.
- **Complete:** All levels are completely filled, except possibly the last level, which is filled from `left to right`. (This is important for Heaps).
- **Degenerate (Skewed):** Every parent has only one child. It looks like a linked list and has the worst performance (O(n).
- **Perfect:** All internal nodes have 2 children, and all leaf nodes are at the same level.

