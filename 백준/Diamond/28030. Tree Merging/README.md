# [Diamond III] Tree Merging - 28030 

[문제 링크](https://acmicpc.net/problem/28030) 

### 성능 요약

메모리: 7176 KB, 시간: 0 ms

### 분류

다이나믹 프로그래밍, 트리, 트리DP

### 제출 일자

2024년 09월 10일 21:35:44

### 문제 설명

<p>Having just completed a course in graph algorithms, Bessie the cow has begun coding her very own graph visualizer! Currently, her graph visualizer is only capable of visualizing rooted trees with nodes of distinct values, and it can only perform one kind of operation: merging.</p>

<p>In particular, a merging operation takes any two distinct nodes in a tree with the same parent and merges them into one node, with value equal to the maximum of the values of the two nodes merged, and children a union of all the children of the nodes merged (if any).</p>

<p>Unfortunately, after Bessie performed some merging operations on a tree, her program crashed, losing the history of the merging operations she performed. All Bessie remembers is the tree she started with and the tree she ended with after she performed all her merging operations.</p>

<p>Given her initial and final trees, please determine a sequence of merging operations Bessie could have performed. It is guaranteed that a sequence exists.</p>

<p>Each input consists of $T$ ($1\le T\le 100$) independent test cases. It is guaranteed that the sum of $N$ over all test cases does not exceed $1000$.</p>

### 입력 

 <p>The first line contains $T$, the number of independent test cases. Each test case is formatted as follows.</p>

<p>The first line of each test case contains the number of nodes $N$ ($2 \leq N \leq 1000$) in Bessie's initial tree, which have values $1\dots N$.</p>

<p>Each of the next $N-1$ lines contains two space-separated node values $v_i$ and $p_i$ ($1 \leq v_i, p_i \leq N$) indicating that the node with value $v_i$ is a child node of the node with value $p_i$ in Bessie's initial tree.</p>

<p>The next line contains the number of nodes $M$ ($2 \leq M \leq N$) in Bessie's final tree.</p>

<p>Each of the next $M-1$ lines contains two space-separated node values $v_i$ and $p_i$ ($1 \leq v_i, p_i \leq N$) indicating that the node with value $v_i$ is a child node of the node with value $p_i$ in Bessie's final tree.</p>

### 출력 

 <p>For each test case, output the number of merging operations, followed by an ordered sequence of merging operations of that length, one per line.</p>

<p>Each merging operation should be formatted as two distinct space-separated integers: the values of the two nodes to merge in any order.</p>

<p>If there are multiple solutions, output any.</p>

