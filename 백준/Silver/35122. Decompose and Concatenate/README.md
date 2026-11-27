# [Silver II] Decompose and Concatenate - 35122 

[문제 링크](https://acmicpc.net/problem/35122) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

그리디, 문자열

### 제출 일자

2026년 02월 01일 23:26:43

### 문제 설명

<p>You are given an integer greater than or equal to $2$. When this number is decomposed into the sum of two <em>positive</em> integers, a new integer number can be formed as the concatenation of the decimal representations of the two integers. Find the maximum possible number formed in this way.</p>

<p>For example, $102$ can be decomposed and concatenated as follows.</p>

<p>$ \begin{array}{l l l} 1 + 101 &\rightarrow& 1101 \\ 2 + 100 &\rightarrow& 2100 \\ 3 + 99  &\rightarrow& 399 \\ 4 + 98  &\rightarrow& 498 \\ & \vdots & \\ 101 + 1 &\rightarrow& 1011 \end{array} $</p>

<p>Among them, $92 + 10 \rightarrow 9210$ is the largest.</p>

### 입력 

 <p>The input consists of a single test case in a single line. The line contains an integer between $2$ and $10^{17}$, inclusive, which is the integer to be decomposed and concatenated.</p>

### 출력 

 <p>Output the maximum possible number in a line.</p>

