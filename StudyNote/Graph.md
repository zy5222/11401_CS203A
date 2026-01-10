# Graphs 

## Introduction & Definitions
- A **Graph** is a non-linear data structure consisting of **Vertices** (nodes) and **Edges** (links) used to model relationships between objects, such as social networks, transportation systems, or web pages.
-  **Definition**: `G = (V, E)`
    * V: A set of vertices (also called nodes or points).
    * E: A set of edges (also called links or lines), which connect pairs of vertices.

## Terminology
| Term | Definition | Example |
| :--- | :--- | :--- |
| **Vertex (Node)** | The fundamental unit of a graph representing an entity | City, User, Web Page |
| **Edge (Link)** | A line connecting two vertices representing a relationship | Road, Friendship, Hyperlink |
| **Directed Graph (Digraph)** | Edges have a specific direction (Arrow: $A \to B$) | Instagram "Following", One-way street |
| **Undirected Graph** | Edges have no direction ($A - B$ implies $B - A$) | Facebook "Friends", Two-way road |
| **Weighted Graph** | Each edge has an associated cost or weight | Google Maps (distance/time) |
| **Degree** |The number of edges incident to a vertex | Number of roads connected to an intersection |
| **In-degree** | (Directed) Number of edges pointing *into* a vertex | Number of followers |
| **Out-degree** |(Directed) Number of edges pointing *out of* a vertex. | Number of people you follow |
| **Subgraph** | A graph $G'$ where $V(G') \subseteq V(G)$ and $E(G') \subseteq E(G)$ | A specific region within a larger map |
| **Connected Graph** | A graph where there is a path between every pair of vertices | A road network where every city is reachable |
| **Acyclic Graph** | A graph containing no cycles (loops). | A Family Tree |

## Graph Representations
There are two primary ways to represent a graph in memory: **Adjacency Matrix** and **Adjacency List** 

### Adjacency Matrix
A 2D array `matrix[V][V]` where `matrix[i][j] = 1` (or weight) if an edge exists between $i$ and $j$, and `0` otherwise
- **Pros**:
    - **$O(1)$ Edge Lookup**: Checking if an edge exists is instant.
    - **Simple Implementation**: Easy to visualize and code.
    - **Best for Dense Graphs**: Efficient when the graph has many edges (close to $V^2$).
- **Cons**:
    - **$O(V^2)$ Space Complexity**: Consumes memory even for empty edges (sparse graphs).
    - **Slow Iteration**: Finding all neighbors of a node takes $O(V)$.

### Adjacency List
An array of Linked Lists (or dynamic arrays).Each vertex stores a list of only its adjacent neighbors.
- **Pros**:
    - **$O(V + E)$ Space Complexity**: Memory efficient; ideal for sparse graphs.
    - **Fast Traversal**: Iterating over neighbors takes proportional time to the degree `O(deg(v))`.
    - **Scalable**: Handles large, dynamic graphs well.
- **Cons**:
    - **Slower Edge Lookup**: Checking if edge $(u, v)$ exists takes `O(deg(u))`.
      
### Comparison

| Feature | Adjacency Matrix | Adjacency List |
| :--- | :--- | :--- |
| **Edge Lookup** | **$O(1)$** (Fastest) | $O(deg(v))$ |
| **Add Edge** | $O(1)$ | $O(1)$ |
| **Remove Edge** | $O(1)$ | $O(deg(v))$ |
| **Space Complexity** | **$O(V^2)$** (High) | **$O(V + E)$** (Efficient) |
| **Best For** | **Dense Graphs** | **Sparse Graphs** (Social Networks, Maps) |
| **Implementation** | Simple | (requires pointers) |
| **Best For** | **Dense Graphs** | **Sparse Graphs** (Social Networks, Maps) |

## Graph Traversal
Traversal involves visiting all vertices in a graph systematically.

### 1. Breadth-First Search (BFS)
- **Data Structure**: **Queue** (FIFO)
- **Strategy**: **Level-order**. Explore all immediate neighbors first before moving deeper.
- **Key Concept**: "Ripples in a pond" — expanding uniformly from the source.
- **Use Cases**: Finding the **shortest path** in unweighted graphs, peer-to-peer networks.
- **Algorithm**:
    1. Enqueue start node and mark as visited.
    2. While queue is not empty:
       - Dequeue vertex $v$.
       - Enqueue all unvisited neighbors of $v$ and mark them as visited.
         
### 2. Depth-First Search (DFS)
- **Strategy**: **Backtracking**. Follow one path as deep as possible, then backtrack when stuck
- **Key Concept**: "Maze solving" — go deep, hit a dead end, retreat, try next path.
- **Use Cases**: Cycle detection, topological sorting, puzzle solving.
- **Algorithm**:
    1. Push start node to stack.
    2. While stack is not empty:
       - Pop vertex $v$.
       - If $v$ is not visited, mark as visited.
       - Push all unvisited neighbors to stack.

## Graph vs. Tree

A Tree is technically a special type of Graph (Connected Acyclic Graph).

| Property | Tree | Graph |
| :--- | :--- | :--- |
| **Cycles** | **None** (Acyclic) | **Yes** (Cycles allowed) |
| **Connectivity** | Always Connected | Can be Disconnected (requires full traversal) |
| **Hierarchy** | Rooted (Parent-Child relationship) | No inherent hierarchy (Neighbors) |
| **Paths** | Unique path between any two nodes | Multiple paths possible |
| **Traversal** | Pre/In/Post/Level-order | DFS / BFS (requires `visited[]`) |

## Graph ADT 
- `Create()`: Returns an empty graph.
- `InsertVertex(G, v)`: Adds a new vertex $v$ to the graph.
- `InsertEdge(G, v1, v2)`: Adds an edge connecting $v1$ and $v2$.
- `DeleteVertex(G, v)`: Removes vertex $v$ and all incident edges.
- `DeleteEdge(G, v1, v2)`: Removes the edge between $v1$ and $v2$.
- `IsEmpty(G)`: Returns `TRUE` if the graph has no vertices.
- `Adjacent(G, v)`: Returns a list of all vertices connected to $v$.

## Graph Classifications

Graphs can be classified based on their properties:

| Type | Description |
| :--- | :--- |
| **Undirected** | Edges work both ways ($A-B$). |
| **Directed (Digraph)** | Edges have a strict direction ($A \to B$). |
| **Weighted** | Edges carry a value (cost, distance, time). |
| **Unweighted** | All edges are considered equal. |
| **Cyclic** | Contains at least one loop (path starts/ends at same node). |
| **Acyclic** | Contains no loops (e.g., Trees, DAGs). |
| **Connected** | All nodes are reachable from any other node. |
| **Disconnected** | Contains isolated vertices or separate components. |

## Note
- This study note is based on the CS203A lecture slides and was summarized and formatted with the assistance of Google Gemini.

