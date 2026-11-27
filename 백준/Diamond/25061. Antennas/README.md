# [Diamond V] Antennas - 25061 

[문제 링크](https://acmicpc.net/problem/25061) 

### 성능 요약

메모리: 12948 KB, 시간: 452 ms

### 분류

너비 우선 탐색, 자료 구조, 그래프, 그래프 탐색, 세그먼트 트리, 집합과 맵

### 제출 일자

2023년 10월 11일 17:25:26

### 문제 설명

<p>There are $n$ equidistant antennas on a line, numbered from $1$ to $n$. Each antenna has a power rating, the power of the $i$-th antenna is $p_i$.</p>

<p>The $i$-th and the $j$-th antenna can communicate directly if and only if their distance is at most the minimum of their powers, i.e., $|i - j| ≤ \min{(p_i, p_j)}$. Sending a message directly between two such antennas takes $1$ second.</p>

<p>What is the minimum amount of time necessary to send a message from antenna $a$ to antenna $b$, possibly using other antennas as relays?</p>

### 입력 

 <p>Each test contains multiple test cases. The first line contains an integer $t$ ($1 ≤ t ≤ 100\,000$) — the number of test cases. The descriptions of the $t$ test cases follow.</p>

<p>The first line of each test case contains three integers $n$, $a$, $b$ ($1 ≤ a, b ≤ n ≤ 200\,000$) — the number of antennas, and the origin and target antenna.</p>

<p>The second line contains $n$ integers $p_1$, $p_2$, $\dots$, $p_n$ ($1 ≤ p_i ≤ n$) — the powers of the antennas. The sum of the values of $n$ over all test cases does not exceed $200\,000$.</p>

### 출력 

 <p>For each test case, print the number of seconds needed to trasmit a message from $a$ to $b$. It can be shown that under the problem constraints, it is always possible to send such a message.</p>

