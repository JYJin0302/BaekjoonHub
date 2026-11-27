# [Diamond III] Back and Forth - 23493 

[문제 링크](https://acmicpc.net/problem/23493) 

### 성능 요약

메모리: 7120 KB, 시간: 40 ms

### 분류

데이크스트라, 플로이드–워셜, 그래프, 최단 경로

### 제출 일자

2024년 05월 01일 12:22:56

### 문제 설명

<p>There are $n$ stations and $m$ <em>directed</em> roads between them.</p>

<p>One day, Chiaki is going from the $s$-th station to the $t$-th station, then back to the $s$-th station. Doing so, he needs to buy tickets for stations he passes. The price the tickets for the $i$-th station is $p_i$. If Chiaki buys a ticket for the $i$-th station, he can passes the station as many times as he wants. Find the minimum price of tickets to buy.</p>

### 입력 

 <p>There are multiple test cases. The first line of the input contains an integer $T$ ($1 \leq T \leq 200$) indicating the number of test cases. For each test case:</p>

<p>The first line of each test case contains four integers $n$, $m$, $s$ and $t$ ($1 \leq n \leq 200$, $0 \leq m \leq n \times (n - 1)$, $1 \leq s, t \leq n$). The second line contains $n$ integers $p_1, p_2, \dots, p_n$ ($1 \leq p_i \leq 100$). The $i$-th of the following $m$ lines contains two integers $a_i$ and $b_i$, which denote a road from the $a_i$ station to the $b_i$-th station ($1 \leq a_i, b_i \leq n$).</p>

<p>The sum of all $n$ does not exceed $200$.</p>

### 출력 

 <p>For each test case, output an integer denoting the answer. Print $-1$ for no solution.</p>

