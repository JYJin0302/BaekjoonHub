# [Platinum V] Minimal Product - 19825 

[문제 링크](https://acmicpc.net/problem/19825) 

### 성능 요약

메모리: 276892 KB, 시간: 752 ms

### 분류

애드 혹, 그리디, 수학, 정렬

### 제출 일자

2026년 01월 01일 16:20:56

### 문제 설명

<p>You are given an array of integers $a_1,\dots,a_n$. Find two indices $i$ and $j$ such that $i<j$, $a_i<a_j$, and the product $a_i \cdot a_j$ is as small as possible.</p>

### 입력 

 <p>The input consists of several tests. The first line contains a single integer $t$ --- the number of tests ($1 \leq t \leq 10^4$). Each of the following $t$ lines describes one test.</p>

<p>Each test is generated using the following algorithm. The test is described by integers $n$, $l$, $r$, $x$, $y$, $z$, $b_1$, $b_2$ ($2 \leq n \leq 10^7$, $-2\cdot10^9 \leq l \leq r \leq 2\cdot10^9$, $0 \leq x,y,z,b_1,b_2 < 2^{32}$), where $n$ is the length of the array.</p>

<p>First, the sequence $b_i$ of length $n$ is generated. Elements $b_1$ and $b_2$ are given. For $i>2$ let $b_i=(b_{i-2}x+b_{i-1}y+z) \bmod 2^{32}$. For each $i$ between $1$ and $n$, $a_i=(b_i \bmod (r - l + 1)) + l$ (thus, $-2\cdot10^9 \leq a_i \leq 2\cdot10^9$).</p>

<p>It is recommended to use 64-bit integers to generate the sequence to avoid integer overflow.</p>

<p>The sum of $n$ in all tests does not exceed $2 \cdot 10^7$.</p>

### 출력 

 <p>For each test, print the smallest possible product $a_i \cdot a_j$ in a separate line. If there are no such $i$ and $j$ that $i<j$ and $a_i<a_j$, print "<code>IMPOSSIBLE</code>".</p>

