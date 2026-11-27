# [Platinum V] Moo Decomposition - 33763 

[문제 링크](https://acmicpc.net/problem/33763) 

### 성능 요약

메모리: 11500 KB, 시간: 120 ms

### 분류

조합론, 분할 정복을 이용한 거듭제곱, 수학, 모듈로 곱셈 역원, 정수론

### 제출 일자

2025년 07월 11일 13:39:15

### 문제 설명

<p>You have a long string $S$ of Ms and Os and an integer $K \geq 1$. Count the number of ways of ways to decompose $S$ into subsequences such that each subsequence is MOOOO....O with exactly $K$ Os, modulo $10^9+7$.</p>

<p>Since the string is very long, you are not given it explicitly. Instead, you are given an integer $L$ ($1 \leq L \leq 10^{18}$), and a string $T$ of length $N$ ($1 \leq N \leq 10^6$). The string $S$ is the concatenation of $L$ copies of the string $T$.</p>

### 입력 

 <p>The first line contains $K$, $N$, and $L$.</p>

<p>The second line contains the string $T$ of length $N$. Every character is either an M or an O.</p>

<p>It is guaranteed that the number of decompositions of $S$ is nonzero.</p>

### 출력 

 <p>Output the number of decompositions of string $S$, modulo $10^9+7$.</p>

