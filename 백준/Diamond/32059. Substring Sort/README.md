# [Diamond IV] Substring Sort - 32059 

[문제 링크](https://acmicpc.net/problem/32059) 

### 성능 요약

메모리: 11112 KB, 시간: 280 ms

### 분류

자료 구조, 해싱, 세그먼트 트리

### 제출 일자

2024년 09월 24일 16:51:44

### 문제 설명

<p>In this problem, all strings are one-based indexed. Let $s_i$ be the $i$<sup>th</sup> character of a string $s$. Let $s_{l..r}$ be a substring of $s$ with the characters $s_ls_{l+1} \cdots s_r$.</p>

<p>You are given three strings each of length $N$: $A$, $B$, and $C$. You are asked to simulate $Q$ queries according to the given order.</p>

<p>For each query, you are given two integers $l$ and $r$ as parameters, and must performs the following procedures:</p>

<ol>
	<li>Copy substrings $A_{l..r}$, $B_{l..r}$, and $C_{l..r}$. Let $x$, $y$ and $z$ be the copied substrings.</li>
	<li>Sort $[x, y, z]$ in lexicographical order. Let $[x', y', z']$ be the sorted results.</li>
	<li>Replace substring $A_{l..r}$ with $x'$, substring $B_{l..r}$ with $y'$ and substring $C_{l..r}$ with $z'$ respectively.</li>
</ol>

<p>Determine the value of $A$, $B$, and $C$ after all queries.</p>

### 입력 

 <p>Input begins with two integers $N$ $Q$ ($1 ≤ N ≤ 100\, 000$; $1 ≤ Q ≤ 100\, 000$) representing the length of the given strings and the number of queries. Each of the next $3$ lines contains a string of length $N$. The first, second, and third lines contain $A$, $B$, and $C$ respectively. The strings consist of lowercase characters. Each of the next Q lines contains two integers $l$ $r$ ($1 ≤ l ≤ r ≤ N$) representing the parameters of each query.</p>

### 출력 

 <p>The output consists of $3$ lines. In each line, output the final value of $A$, $B$ and $C$ after all queries in that order.</p>

