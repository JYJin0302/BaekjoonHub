# [Gold I] Miswritten DFS - 23734 

[문제 링크](https://acmicpc.net/problem/23734) 

### 성능 요약

메모리: 6588 KB, 시간: 24 ms

### 분류

깊이 우선 탐색, 다이나믹 프로그래밍, 그래프, 그래프 탐색, 재귀, 트리, 트리DP

### 제출 일자

2023년 02월 04일 17:27:43

### 문제 설명

<p>Yunee is working on a data structures assignment. Yunee wrote a function <code>DFS</code> that traverses a binary tree in pre-order. However, Yunee's code recursively called <code>DFS</code> on the left subtree twice, by mistake.</p>

<pre><code>function DFS(node v):
    visit v
    if v → left exists:
        DFS(v → left)
        DFS(v → left)
    if v → right exists:
        DFS(v → right)</code></pre>

<p>The pseudocode of Yunee's <code>DFS</code> is as above. Now consider the following example.</p>

<p style="text-align: center;"><img alt="" src="" style="max-width: 100%; width: 200px;"></p>

<p>If we pre-order traverse the above tree, the nodes $1, 2, 3, 4, 5$ are visited in order. However, Yunee's <code>DFS</code> visits the nodes $1, 2, 3, 3, 4, 2, 3, 3, 4, 5$ in order.</p>

<p>Given a binary tree, find the $K$-th node visited by Yunee's <code>DFS</code>. It is guaranteed that $K$ is not greater than the total number of visits. The nodes are numbered from $1$ to $N$ and the root node is always node $1$.</p>

### 입력 

 <p>The first line contains two integers $N$ and $K$ $(1\leq N \leq 10^5, 1\leq K \leq 10^{18})$. $N$ represents the number of nodes in the tree. $K$ is not greater than the total number of visits.</p>

<p>The next $N$ lines describe the tree. The $i$-th line contains two integers $l_i$ and $r_i$ $(0 \leq l_i, r_i \leq N)$. $l_i$ represents the left child of node $i$ and $r_i$ represents the right child of node $i$. If there is no corresponding child, $0$ is given in place of $l_i$ or $r_i$.</p>

<p>The root node is always node $1$.</p>

### 출력 

 <p>Output the $K$-th node visited by Yunee's <code>DFS</code>.</p>

