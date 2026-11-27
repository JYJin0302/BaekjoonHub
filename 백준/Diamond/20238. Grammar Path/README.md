# [Diamond IV] Grammar Path - 20238 

[문제 링크](https://acmicpc.net/problem/20238) 

### 성능 요약

메모리: 3320 KB, 시간: 260 ms

### 분류

임의 정밀도 및 큰 수 연산, 다이나믹 프로그래밍, 그래프

### 제출 일자

2023년 08월 11일 14:26:25

### 문제 설명

<p>You are given a context-free formal grammar in Chomsky reduced form (see Notes section for an explanation of these terms), and a directed graph with each edge labeled with a terminal of the grammar.</p>

<p>Find the length of the shortest path in the graph from vertex $s$ to vertex $t$ such that concatenation of the labels on this path is in the language of the grammar, or state that there is no such path.</p>

### 입력 

 <p>The first line contains the number of productions in the grammar $p$ ($1 \le p \le 100$).</p>

<p>Each of the next $p$ lines contains a production in the form of either '<code>A -> BC</code>' or '<code>A -> a</code>'. The lowercase English letters are terminals, the uppercase English letters are nonterminals, and the uppercase letter '<code>S</code>' is the starting nonterminal. It's guaranteed that <code>S</code> appears as left hand side of at least one production. </p>

<p>The next line contains four integers $n$, $m$, $s$, and $t$ ($1 \le s, t \le n \le 26$; $0 \le m \le n^2$), denoting the number of vertices in the graph, the number of edges in the graph, and indices of the start and the finish.</p>

<p>Each of the next $m$ lines contains a description of an edge in the form '<code>u v x</code>', denoting an edge from vertex $u$ to vertex $v$ labeled with $x$ ($1 \le u, v \le n$; $x$ is a lowercase English letter). There are no multiedges in the graph, but there might be loops and different edges from $u$ to $v$ and from $v$ to $u$.</p>

### 출력 

 <p>If there is no path from $s$ to $t$ with labels forming a string from the language, output '<code>NO</code>'. Otherwise, output the length of the shortest such path.</p>

