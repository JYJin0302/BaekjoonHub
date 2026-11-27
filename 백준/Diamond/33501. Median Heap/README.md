# [Diamond V] Median Heap - 33501 

[문제 링크](https://acmicpc.net/problem/33501) 

### 성능 요약

메모리: 195324 KB, 시간: 440 ms

### 분류

분할 정복, 다이나믹 프로그래밍, 오프라인 쿼리, 트리, 트리DP

### 제출 일자

2025년 07월 05일 16:19:32

### 문제 설명

<p>Farmer John has a binary tree with $N$ nodes where the nodes are numbered from $1$ to $N$ ($1 \leq N < 2\cdot 10^5$ and $N$ is odd). For $i>1$, the parent of node $i$ is $\lfloor i/2\rfloor$. Each node has an initial integer value $a_i$, and a cost $c_i$ to change the initial value to any other integer value ($0\le a_i,c_i\le 10^9$).</p>

<p>He has been tasked by the Federal Bovine Intermediary (FBI) with finding an approximate median value within this tree, and has devised a clever algorithm to do so.</p>

<p>He starts at the last node $N$ and works his way backward. At every step of the algorithm, if a node would not be the median of it and its two children, he swaps the values of the current node and the child value that would be the median. At the end of this algorithm, the value at node $1$ (the root) is the median approximation.</p>

<p>The FBI has also given Farmer John a list of $Q$ $(1 \leq Q \leq 2\cdot 10^5)$ independent queries each specified by a target value $m$ ($0\le m\le 10^9$). For each query, FJ will first change some of the node's initial values, and then execute the median approximation algorithm. For each query, determine the minimum possible total cost for FJ to make the output of the algorithm equal to $m$.</p>

### 입력 

 <p>The first line of input contains $N$.</p>

<p>The next $N$ lines each contain two integers $a_i$ and $c_i$.</p>

<p>The next line contains $Q$.</p>

<p>The next $Q$ lines each contain a target value $m$.</p>

### 출력 

 <p>Output $Q$ lines, the minimum possible total cost for each target value $m$.</p>

