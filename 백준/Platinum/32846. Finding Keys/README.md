# [Platinum III] Finding Keys - 32846 

[문제 링크](https://acmicpc.net/problem/32846) 

### 성능 요약

메모리: 14044 KB, 시간: 144 ms

### 분류

문자열, 접미사 배열과 LCP 배열

### 제출 일자

2026년 01월 01일 18:15:26

### 문제 설명

<p>Wolfgang Amadeus Mozart has too many keys! He has $n$ keys of distinct lengths on his circular keychain. Unfortunately, Wolfgang can only judge whether a key fits into a door by its relative size compared to the keys surrounding it. Let the $k$-pattern of a key $x$ be the sequence of relative key lengths of the $k$ keys following key $x$ in clockwise order on the keychain. For example, if keychain has keys of lengths $1, 5, 3, 4, 2$ in clockwise order, then the $3$-pattern of the key of length $3$ can be expressed as the string “<code><>></code>”, since $3$ <code><</code> $4$, $4$ <code>></code> $2$, and $2$ <code>></code> $1$. Note that the last key of length $2$ is followed by the first key of length $1$.</p>

<p>Please help Wolfgang determine for each key the smallest $k$ such that the $k$-pattern of the key is unique (no other key’s $k$-pattern is the same).</p>

### 입력 

 <p>The first line of input contains a single integer $n$ ($2 ≤ n ≤ 2 \cdot 10^5$), the number of keys on Wolfgang’s circular keychain.</p>

<p>The next $n$ lines each contain an integer between $1$ and $10^9$ representing the length of one key. The key lengths are given in their clockwise order on the keychain. It is guaranteed that all key lengths are unique.</p>

### 출력 

 <p>Output $n$ lines, one integer per line. The $i$<sup>th</sup> integer should be the smallest $k$ such that the $k$-pattern of key $i$ (in input order) is unique among all $k$-patterns. If there exists no such $k$, then the $i$<sup>th</sup> integer should be $-1$.</p>

