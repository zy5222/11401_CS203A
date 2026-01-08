# Tree

## Definition
- A tree is a non-linear hierarchical data structure consisting of nodes connected by edges.
- Unlike Arrays and Linked Lists which are linear data structures, a Tree is a `non-linear`, `hierarchical` data structure consisting of `nodes` connected by `edges`.
## Key Characteristics
- **Hierarchical:** Represents relationships like file systems, organizational charts, or family trees.
- **Acyclic:** Trees contain no cycles (loops).
- **Rooted:** Every tree has exactly one Root node.
## Terminology
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

## Type of Binary Trees

<img width="800" height="600" alt="image" src="https://github.com/user-attachments/assets/ac82f0f1-f953-4e49-8470-d2d11f188440"  />

*Image source: Course Lecture Slides, Chapter 12.*

- **Strict:** Every node has either 0 or 2 children. No node has just 1 child.
- **Complete:** All levels are completely filled, except possibly the last level, which is filled from `left to right`. (This is important for Heaps).
- **Degenerate (Skewed):** Every parent has only one child. It looks like a linked list and has the worst performance (O(n).
- **Perfect:** All internal nodes have 2 children, and all leaf nodes are at the same level.
  
## Definitions of Tree Variants(general → specialized)
<img width="800" height="600" alt="image" src="https://github.com/user-attachments/assets/56e44c6d-78f0-4706-89fc-c41c4146da11" />

*Image Source: Self-made using draw.io*
  
| Term | Definition |
| :--- | :--- | 
| **General Tree** | It is a hierarchical data structure consisting of a set of nodes. It has a single root node, and every node can have an unlimited number of children (subtrees). There is no constraint on how many branches a node can possess.|
| **Binary Tree** |  It is a tree data structure in which each node has at most two children, which are distinctively referred to as the "left child" and the "right child,and it is a shape-based definition, not value-based.There is no ordering constraint on the values in the tree. |
| **Binary Search Tree (BST)**| It is a binary tree that satisfies a specific ordering property: for every node, all keys in its left subtree are smaller than the node's key, and all keys in its right subtree are larger than the node's key.|
| **AVL Tree** |  It is a self-balancing Binary Search Tree. It enforces a strict condition where the difference in height between the left and right subtrees of any node (called the balance factor) must be no more than 1. If this property is violated during modification, the tree performs rotations to rebalance itself.|
|**Red-Black Tree** | It is a self-balancing Binary Search Tree where each node stores an extra bit representing a color (red or black). It uses specific rules (e.g., the root is black, red nodes cannot have red children) to ensure the longest path from the root to a leaf is no more than twice as long as the shortest path, guaranteeing O(log n) search time.|
|**Complete Binary Tree** | It is a binary tree where every level is fully filled, except possibly for the last level. In the last level, all nodes must be filled from the left side to the right without leaving any gaps between them.|
|**Max Heap** |It is a specific type of complete binary tree that satisfies the heap property: the value of every parent node is greater than or equal to the values of its children. Consequently, the largest element is always found at the root.|
|**Min Heap**|It is a specific type of complete binary tree that satisfies the heap property: the value of every parent node is less than or equal to the values of its children. Therefore, the smallest element is always located at the root.|

## Tree Constructions Using Given Integers(Assignment V)

Given integers (fixed for all parts): 
37, 142, 5, 89, 63, 117, 24, 176, 58, 133, 92, 11, 151, 72, 39, 184, 7, 101, 54, 160 
Task: For each tree type below, construct the tree using these integers, take a screenshot of the tree from your chosen tool, record the tool name/URL, and describe the insertion / heap-building procedure. 

### Binary Tree

- Tool name / URL: https://treeconverter.com/
- Description: I constructed the Binary Tree using **Level-Order** Insertion based on the given list of integers. I mapped the array indices directly to the tree nodes: the first integer (37) becomes the root, and subsequent integers fill the tree level by level, from left to right. This systematic approach ensures every node has at most two children, satisfying the definition of a Binary Tree.
- Screenshot of Binary Tree: <img width="1015" height="341" alt="image" src="https://github.com/user-attachments/assets/0eefba2f-b50a-494f-9184-990942514e63" />
### Binary Search Tree (BST) 

- Tool name / URL: [USFCA BST Visualization](https://www.cs.usfca.edu/~galles/visualization/BST.html)
- Description: I inserted the integers sequentially in the given order (37, 142, 5, ...). I followed standard BST rules: for each insertion, I compared the new value with the current node—navigating to the **left child if smaller** and the **right child if larger** — until an empty spot was found. No re-balancing or rotation was performed. 
- Screenshot of BST: <img width="1000" height="369" alt="image" src="https://github.com/user-attachments/assets/808c8da8-3306-40d3-b969-abd196572625" />

###  AVL Tree

- Tool name / URL: [USFCA AVL Tree Visualization](https://www.cs.usfca.edu/~galles/visualization/AVLtree.html)
- Description: I inserted the integers sequentially in the given order. After each insertion, the tree automatically checked the **balance factor** (height of left subtree minus height of right subtree) for every ancestor node. Whenever a node's balance factor magnitude exceeded 1 (i.e., became -2 or +2), the tree performed the necessary **rotations (LL, RR, LR, or RL)** to restore balance and ensure the tree height remained logarithmic (O(log n)). 
- Screenshot of AVL Tree: <img width="1000" height="369" alt="image" src="https://github.com/user-attachments/assets/87153323-0921-4227-9bb9-e07989eb7ba9" />

###  Red-Black Tree
- Tool name / URL: [USFCA Red-Black Tree Visualization ](https://www.cs.usfca.edu/~galles/visualization/RedBlack.html)
- Description: I inserted the integers sequentially following standard BST placement rules, with new nodes initially colored **Red**. Upon insertion, if a 'Double Red' violation occurred (a red child with a red parent), the tree applied **Recoloring** and/or **Rotations** to restore Red-Black properties (such as ensuring equal black height on all paths). This process guarantees that the longest path is no more than twice the length of the shortest path, keeping the tree approximately balanced.
- Screenshot of Red-Black Tree: <img width="1015" height="266" alt="image" src="https://github.com/user-attachments/assets/1632aceb-e984-43e3-876d-2eab04823d3f" />

### Complete Binary Tree

- Tool name / URL: https://treeconverter.com/
- Description: I constructed the tree by inserting the given integers sequentially, filling the nodes **level by level**, **from left to right**. This method ensures that every level of the tree is completely filled, except possibly for the last level, where all nodes are as far left as possible. This structure strictly satisfies the definition of a **Complete Binary Tree**.
- Screenshot of Complete Binary Tree: <img width="1015" height="341" alt="image" src="https://github.com/user-attachments/assets/70de7d14-94b3-4e64-9b9d-083c5420c8e1" />

### Max Heap

- Tool name / URL: Visualgo (https://visualgo.net/en/heap)
- Description: I constructed the Max Heap by inserting the integers one by one (Successive Insertion). Upon each insertion, the new element was placed at the next available leaf position, and the **Sift-Up** operation was performed. This involves swapping the new node with its parent if the child is larger than the parent. This process ensures the Max Heap property (**Parent ≥ Child**) is maintained at every step, resulting in the largest element (184) at the root.
- Screenshot of Max Heap: <img width="1015" height="230" alt="image" src="https://github.com/user-attachments/assets/539fae0c-a528-417a-85a5-d49a5fa08e08" />

### Min Heap
- Tool name / URL: [USFCA Heap Visualization](https://www.cs.usfca.edu/~galles/visualization/Heap.html)
- Description: I constructed the Min Heap by inserting the integers one by one. After each insertion, the **Sift-Up** operation was performed to maintain the heap property. This involves swapping the new node with its parent if the child is smaller than the parent. This process ensures the Min Heap property (**Parent ≤ Child**) is preserved, resulting in the smallest element (5) located at the root.
- Screenshot of Min Heap: <img width="988" height="406" alt="image" src="https://github.com/user-attachments/assets/c8a0545c-f974-4f14-9b47-9a10ad5e0785" />
