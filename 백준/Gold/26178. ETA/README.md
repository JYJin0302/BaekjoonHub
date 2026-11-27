# [Gold I] ETA - 26178 

[문제 링크](https://acmicpc.net/problem/26178) 

### 성능 요약

메모리: 2160 KB, 시간: 0 ms

### 분류

해 구성하기, 그래프

### 제출 일자

2026년 01월 20일 13:31:45

### 문제 설명

<p>You want to design a level for a computer game. The level can be described as a connected undirected graph with vertices numbered from $1$ to $n$. In the game, the player's character is dropped at one of the $n$ vertices uniformly at random and their goal is to reach the exit located at vertex $1$ as quickly as possible. Traversing an edge takes exactly $1$ second.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 300px; height: 213px;"></p>

<p style="text-align: center;">Figure E.1: Illustration of Sample Output 3, a level where the average optimal time to reach vertex $1$ is $\frac{7}{4}$.</p>

<p>The difficulty of the level is determined by the average optimal time to reach the exit. Given a target value for this average optimal time, construct a level so that this target value is reached. See Figure E.1 for an example.</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>One line with two coprime integers $a$ and $b$ ($1 \le a,b \le 1000$) separated by a '<code>/</code>', giving the desired average optimal time to reach the exit as the fraction $\frac{a}{b}$.</li>
</ul>

### 출력 

 <p>If no connected graph with the average optimal time $\frac{a}{b}$ to reach vertex $1$ exists, output "<code>impossible</code>". Otherwise, output one such graph in the following format:</p>

<ul>
	<li>Two integers $n$ and $m$ ($1 \le n, m \le 10^6$), the number of vertices and the number of edges.</li>
	<li>$m$ pairs of integers $u$ and $v$ ($1 \le u,v \le n$), indicating an edge between vertices $u$ and $v$.</li>
</ul>

<p>The graph may include self loops and parallel edges. You are given that if there exists a valid graph, then there also exists one with $1 \le n, m \le 10^6$.</p>

<p>If there are multiple valid solutions, you may output any one of them.</p>

