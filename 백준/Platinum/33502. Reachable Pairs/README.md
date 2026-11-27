# [Platinum II] Reachable Pairs - 33502 

[문제 링크](https://acmicpc.net/problem/33502) 

### 성능 요약

메모리: 19872 KB, 시간: 168 ms

### 분류

조합론, 자료 구조, 분리 집합, 그래프, 수학

### 제출 일자

2025년 07월 05일 15:06:33

### 문제 설명

<p>Consider an undirected graph with $N$ nodes labeled $1\dots N$ and $M$ edges ($1\le N\le 2\cdot 10^5, 0\le M\le 4\cdot 10^5$). You're given a binary string $s_1s_2\dots s_N$. At time $t$ for each $t\in [1,N]$,</p>

<ul>
	<li>If $s_t=0$, node $t$ is removed from the graph.</li>
	<li>If $s_t=1$, node $t$ is removed from the graph, and edges are added between every pair of neighbors that node $t$ had just before removal.</li>
</ul>

<p>Note that in both cases, when a node is removed from the graph all of its incident edges are removed as well.</p>

<p>Count the number of pairs of nodes that can reach each other via some sequence of edges just before each of timesteps $1\ldots N$.</p>

### 입력 

 <p>The first line contains $N$ and $M$.</p>

<p>The second line contains the bit string $s$ of length $N$.</p>

<p>The next $M$ lines each contain two integers denoting an edge of the graph.</p>

### 출력 

 <p>$N$ lines, the number of pairs before each timestep.</p>

