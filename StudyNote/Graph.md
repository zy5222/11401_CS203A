# Data Structures: Graphs (圖論資料結構)

## 1. 簡介與定義 (Introduction & Definitions)

### 什麼是圖 (Graph)?
圖是一種由頂點 (Vertices) 和邊 (Edges) 組成的資料結構，用於模擬物件之間的關係，如社交網絡、交通系統或網頁連結 。

* **定義**: G = (V, E)
    * V: 頂點的集合 (Set of vertices/nodes)。
    * E: 邊的集合 (Set of edges/links)，連接一對頂點。

### 圖的起源
圖論起源於 1736 年 Leonhard Euler 解決的「柯尼斯堡七橋問題 (Seven Bridges of Königsberg)」，探討是否能在不重複經過任何一座橋的情況下走遍所有橋。

### 關鍵術語 (Key Terminology)
| 術語 (Term) | 定義 (Definition) | 範例 (Example) |
| :--- | :--- | :--- |
| **Vertex (Node)** | 圖中的節點 | 城市、使用者、網頁|
| **Edge (Link)** | 連接節點的線 | 道路、好友關係、超連結|
| **Directed Graph (Digraph)** | 邊具有方向性 (A -> B) | Instagram 追蹤、單行道|
| **Undirected Graph** | 邊沒有方向性 (A - B) | Facebook 好友、雙向道 |
| **Weighted Graph** | 邊具有權重 (Cost/Weight) | Google Maps 距離、機票價格|
| **Degree (度)** | 連接該頂點的邊的數量 |  |
| **In-degree (入度)** | 指向該頂點的邊數 (Directed only) | 有多少人追蹤你|
| **Out-degree (出度)** | 從該頂點指出的邊數 (Directed only) | 你追蹤了多少人 |
| **Subgraph** | G' 是 G 的子圖，若 V(G')包含於 V(G) 且 E(G')包含於 E(G) ||
| **Connected Graph** | 所有節點都可互相抵達 | 城市環狀道路|
| **Acyclic Graph** | 沒有迴圈 (Cycle) 的圖 | 家譜 (Family Tree) |

---

## 2. 圖的表示法 (Graph Representations)

在電腦中儲存圖主要有兩種方式：**鄰接矩陣 (Adjacency Matrix)** 與 **鄰接串列 (Adjacency List)**。

### 1. 鄰接矩陣 (Adjacency Matrix)
使用二維陣列 `matrix[V][V]` 來記錄節點間是否有邊連接。
* 若節點 i 與 j 有邊，則 `matrix[i][j] = 1` (或權重)；否則為 `0` 。

### 2. 鄰接串列 (Adjacency List)
使用陣列搭配鏈結串列 (Linked List)。每個節點都有一個串列，記錄它所有鄰居 (Neighbors)。

### 比較與分析 (Comparison)

| 特性 (Feature) | 鄰接矩陣 (Adjacency Matrix) | 鄰接串列 (Adjacency List) |
| :--- | :--- | :--- |
| **Edge Lookup** (檢查邊是否存在) | **O(1)** (極快) | O(deg(v)) (需遍歷串列) |
| **Add/Remove Edge** | $O(1)$ | Add: O(1), Remove: O(deg(v)) |
| **Space Complexity** (空間) | **O(V^2)** (耗空間) | **O(V + E)** (省空間) |
| **Traversal (BFS/DFS)** | O(V^2) | **O(V + E)** |
| **適合場景 (Best for)** | **稠密圖 (Dense Graphs)** | **稀疏圖 (Sparse Graphs)** (如社交網絡、地圖) |
| **Implementation** | 簡單 (Simple) | 中等 (Moderate, 需指標) |

> **總結**: 大多數現實世界的圖 (如地圖、社交網絡) 都是**稀疏圖**，因此 **Adjacency List** 通常是較佳的選擇 。

---

## 3. 圖的遍歷 (Graph Traversal)

圖的遍歷與樹 (Tree) 類似，但必須處理 **迴圈 (Cycles)** 的問題，因此必須使用 `visited[]` 陣列來記錄已訪問的節點。

### 1. 廣度優先搜尋 (BFS - Breadth-First Search)
* **資料結構**: **Queue (佇列)** (FIFO) 。
* **概念**: 分層搜索 (Level-order)。先訪問所有鄰居，再往下一層走。
* **用途**: 尋找無權重圖的**最短路徑**。
* **演算法**:
    1. 將起始點放入 Queue 並標記為 Visited。
    2. 當 Queue 不為空時：
       * Dequeue 取出點 v。
       * 訪問 v 的所有**未訪問**鄰居，將其 Enqueue 並標記為 Visited。

### 2. 深度優先搜尋 (DFS - Depth-First Search)
* **資料結構**: **Stack (堆疊)** (LIFO) 或 **遞迴 (Recursion)**。
* **概念**: 走迷宮策略 (Backtracking)。一條路走到黑，撞牆後回溯。
* **演算法**:
    1. 將起始點 Push 入 Stack (或呼叫遞迴) 並標記為 Visited。
    2. 當 Stack 不為空時：
       * Pop 取出點 v。
       * 若 v 未訪問，標記並處理。
       * 將 v 的所有**未訪問**鄰居 Push 入 Stack。

---

## 4. 圖 vs. 樹 (Graph vs. Tree) 
樹 (Tree) 其實是一種特殊的圖 (Connected Acyclic Graph) [cite: 540]。

| 比較項目 | Tree (樹) | Graph (圖) |
| :--- | :--- | :--- |
| **迴圈 (Cycles)** | **無 (None)** | **有 (Possible)** (必須用 `visited[]`) |
| **連通性 (Connectivity)** | 總是連通 | 可能不連通 (Disconnected) |
| **方向 (Direction)** | 通常無方向 (父子關係) | 有向或無向 |
| **層級 (Hierarchy)** | 有 (Root -> Leaf) | 無 (任意拓樸結構) |
| **路徑 (Paths)** | 兩點間只有一條路徑 | 兩點間可能有多條路徑 |
| **遍歷 (Traversal)** | Pre/In/Post/Level-order | DFS / BFS |

---

## 5. Graph ADT (抽象資料型別)
常見的圖操作定義如下 [cite: 420-437]:
* `Create()`: 建立空圖。
* `InsertVertex(G, v)`: 新增頂點。
* `InsertEdge(G, v1, v2)`: 新增邊。
* `DeleteVertex(G, v)`: 刪除頂點及相關連的邊。
* `DeleteEdge(G, v1, v2)`: 刪除邊。
* `IsEmpty(G)`: 檢查是否為空。
* `Adjacent(G, v)`: 回傳 $v$ 的所有鄰居。

---

