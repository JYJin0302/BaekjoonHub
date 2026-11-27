# [Diamond V] Fair Distribution - 31756 

[문제 링크](https://acmicpc.net/problem/31756) 

### 성능 요약

메모리: 3664 KB, 시간: 60 ms

### 분류

비트 집합, 배낭 문제, 수학, 정수론

### 제출 일자

2024년 06월 04일 18:54:28

### 문제 설명

<p>An entrepreneur has $N$ blueprints, each describing a type of building. Each blueprint specifies the building’s height through two integers $G$ and $R$.</p>

<blockquote>
<p>$G$: Height of the ground floor. It can be zero, indicating that the building has no ground floor.</p>

<p>$R$: Height of each residential floor. Each building has at least one residential floor.</p>
</blockquote>

<p>The entrepreneur wants to distribute all of these blueprints among their two children Alice and Bob. Each child will build exactly one building from each blueprint allocated to them, choosing the number of residential floors for each building.</p>

<p>The entrepreneur wants to avoid showing favoritism towards either child, so they are looking for a fair distribution of the blueprints. They decided that a fair distribution is one in which it is possible to construct the buildings in such a way that the sum of the heights of the buildings constructed by each child is the same. Can you tell whether a fair distribution exists?</p>

<p>Consider the following example for $N = 3$ blueprints:</p>

<ol>
	<li>$G = 1$ and $R = 1$ (possible heights are $2, 3, 4, \dots$);</li>
	<li>$G = 0$ and $R = 3$ (no ground floor, possible heights are $3, 6, 9, \dots$);</li>
	<li>$G = 2$ and $R = 1$ (possible heights are $3, 4, 5, \dots$).</li>
</ol>

<p>In this case a possible fair distribution is assigning the second blueprint to Alice and the rest to Bob. Even though Alice receives a single blueprint while Bob receives two, they may construct two residential floors on the first building type (height $3$), two residential floors on the second (height $6$), and one residential floor on the third (height $3$). In this way, the sum of the heights of the buildings constructed by each child would be $6$.</p>

### 입력 

 <p>The first line contains an integer $N$ ($1 ≤ N ≤ 2 \cdot 10^5$) indicating the number of blueprints.</p>

<p>Each of the next $N$ lines contains two integers $G$ ($0 ≤ G ≤ 2 \cdot 10^5$) and $R$ ($1 ≤ R ≤ 10^9$) denoting respectively the height of the ground floor and the height of each residential floor specified by the corresponding blueprint. The sum of the heights of the ground floors of all blueprints is at most $2 \cdot 10^5$.</p>

### 출력 

 <p>Output a single line with the uppercase letter “<code>Y</code>” if there exists a fair distribution of the blueprints, and the uppercase letter “<code>N</code>” otherwise.</p>

