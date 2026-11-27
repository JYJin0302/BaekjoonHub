# [Diamond V] Election Queries - 33764 

[문제 링크](https://acmicpc.net/problem/33764) 

### 성능 요약

메모리: 14080 KB, 시간: 956 ms

### 분류

자료 구조, 세그먼트 트리, 집합과 맵, 제곱근 분할법, 트리를 사용한 집합과 맵, 두 포인터

### 제출 일자

2025년 07월 11일 18:17:08

### 문제 설명

<p>Farmer John has $N$ ($2 \leq N \leq 2 \cdot 10^5$) cows numbered from $1$ to $N$. An election is being held in FJ's farm to determine the two new head cows in his farm. Initially, it is known that cow $i$ will vote for cow $a_i$ ($1 \leq a_i \leq N$).</p>

<p>To determine the two head cows, FJ will hold his election in the following process:</p>

<ul>
	<li>Choose an arbitrary subset $S$ of his cows that contains at least one cow but not all cows. FJ is able to choose cow $x$ as the first head cow if its votes appear most frequently among all votes cast by cows in $S$.</li>
	<li>FJ is able to choose cow $y$ as the second head cow if its votes appear most frequently among votes cast by cows not in $S$.</li>
	<li>For a fixed subset $S$, FJ denotes the <strong> diversity </strong> between his head cows as $|x - y|$. As FJ does not like having leaders with similar numbers, he wants to choose $S$ such that the <strong> diversity </strong> is maximized. Note that if FJ is not able to choose two distinct head cows, then the diversity is $0$.</li>
</ul>

<p>However, some cows keep changing their minds, and FJ may have to rerun the election many times! Therefore, he asks you $Q$ ($1 \leq Q \leq 10^5$) queries. In each query, a cow changes their vote. After each query, he asks you for the maximum possible <strong>diversity</strong> among his new head cows.</p>

### 입력 

 <p>The first line contains $N$ and $Q$.</p>

<p>The following line contains $a_1, a_2, \ldots, a_N$.</p>

<p>The following $Q$ lines contain two integers $i$ and $x$, representing the update $a_i = x$ ($1 \leq i, x \leq N$).</p>

### 출력 

 <p>Output $Q$ lines, the $i$'th of which is the maximum possible <strong> diversity </strong> after the first $i$ queries.</p>

