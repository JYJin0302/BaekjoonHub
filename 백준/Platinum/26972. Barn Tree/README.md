# [Platinum IV] Barn Tree - 26972 

[문제 링크](https://acmicpc.net/problem/26972) 

### 성능 요약

메모리: 32664 KB, 시간: 264 ms

### 분류

방향 비순환 그래프, 깊이 우선 탐색, 다이나믹 프로그래밍, 그래프, 그래프 탐색, 그리디, 트리, 트리DP

### 제출 일자

2023년 02월 06일 21:02:45

### 문제 설명

<p>Farmer John's farm has $N$ barns ($2 \leq N \leq 2\cdot 10^5$) numbered $1 \dots N$. There are $N-1$ roads, where each road connects two barns and it is possible to get from any barn to any other barn via some sequence of roads. Currently, the $j$th barn has $h_j$ hay bales ($1\le h_j\le 10^9$).</p>

<p>To please his cows, Farmer John would like to move the hay such that each barn has an equal number of bales. He can select any pair of barns connected by a road and order his farmhands to move any positive integer number of bales less than or equal to the number of bales currently at the first barn from the first barn to the second.</p>

<p>Please determine a sequence of orders Farmer John can issue to complete the task in the minimum possible number of orders. It is guaranteed that a sequence of orders exists.</p>

### 입력 

 <p>The first line of input contains the value of $N.$</p>

<p>The second line of input contains the space-separated values of $h_j$ for $j = 1 \dots N$.</p>

<p>The final $N-1$ lines of input each contain two space-separated barn numbers $u_i \ v_i$, indicating that there is a bidirectional road connecting $u_i$ and $v_i$.</p>

### 출력 

 <p>Output the minimum possible number of orders, followed a sequence of orders of that length, one per line.</p>

<p>Each order should be formatted as three space-separated positive integers: the source barn, the destination barn, and the third describes the number of hay bales to move from the source to the destination.</p>

<p>If there are multiple solutions, output any.</p>

