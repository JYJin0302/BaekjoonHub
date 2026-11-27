# [Gold II] Range Reconstruction - 26974 

[문제 링크](https://acmicpc.net/problem/26974) 

### 성능 요약

메모리: 2376 KB, 시간: 4 ms

### 분류

애드 혹, 해 구성하기

### 제출 일자

2023년 01월 26일 15:57:00

### 문제 설명

<p>Bessie has an array $a_1, \ldots, a_N$, where $1 \leq N \leq 300$ and $0 \leq a_i \leq 10^9$ for all $i$. She won't tell you $a$ itself, but she will tell you the range of each subarray of $a$. That is, for each pair of indices $i \leq j$, Bessie tells you $r_{i, j} = \max a[i\ldots j] - \min a[i\ldots j]$. Given these values of $r$, please construct an array that could have been Bessie's original array. The values in your array should be in the range $[-10^9, 10^9]$.</p>

<p> </p>

### 입력 

 <p>The first line contains $N$.</p>

<p>Another $N$ lines follow. The $i$th of these lines contains the integers $r_{i, i}, r_{i, i + 1}, \ldots, r_{i, N}$.</p>

<p>It is guaranteed that there is some array $a$ with values in the range $[0, 10^9]$ such that for all $i \leq j$, $r_{i, j} = \max a[i\ldots j] - \min a[i\ldots j]$.</p>

### 출력 

 <p>Output one line containing $N$ integers $b_1, b_2, \ldots, b_N$ in the range $[-10^9, 10^9]$ representing your array. They must satisfy $r_{i, j} = \max b[i\ldots j] - \min b[i\ldots j]$ for all $i \leq j$.</p>

