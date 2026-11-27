# [Platinum V] Accumulator Apex - 33015 

[문제 링크](https://acmicpc.net/problem/33015) 

### 성능 요약

메모리: 13764 KB, 시간: 56 ms

### 분류

자료 구조, 그리디, 우선순위 큐, 큐

### 제출 일자

2025년 06월 30일 14:19:25

### 문제 설명

<p>Allyn is playing a new strategy game called "Accumulator Apex". In this game, Allyn is given the initial value of an integer $x$, referred to as the accumulator, and $k$ lists of integers. Allyn can make multiple turns. On each turn, Allyn can withdraw the leftmost element from any non-empty list and add it to the accumulator $x$ if the resulting $x$ is non-negative. Allyn can end the game at any moment. The goal of the game is to get the largest possible value of the accumulator $x$. Please help Allyn find the largest possible value of the accumulator $x$ they can get in this game.</p>

### 입력 

 <p>The first line of the input contains two integers $x$ and $k$ ($0 \leq x \leq 10^9, 1 \leq k \leq 10^5$) --- the initial value of the accumulator $x$ and the number of lists. The next $k$ lines contain the description of lists: an integer $l_i$ ($l_i \ge 1$) followed on the same line by $l_i$ elements of the list in the order from left to right. Each element of lists does not exceed $10^9$ by the absolute value, and the total size of all lists does not exceed $10^5$.</p>

### 출력 

 <p>The sole line of the output should contain the largest value of the accumulator $x$ Allyn can get.</p>

