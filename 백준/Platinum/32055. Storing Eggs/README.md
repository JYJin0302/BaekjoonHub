# [Platinum I] Storing Eggs - 32055 

[문제 링크](https://acmicpc.net/problem/32055) 

### 성능 요약

메모리: 2044 KB, 시간: 0 ms

### 분류

이분 탐색, 비트마스킹, 비트필드를 이용한 DP, 다이나믹 프로그래밍, 기하학

### 제출 일자

2025년 02월 21일 19:17:24

### 문제 설명

<p>You have an egg carton that can be represented as a $3 \times N$ grid. The grid consists of $3$ rows, numbered from $1$ to $3$, and $N$ columns, numbered from $1$ to $N$. The cell at row $r$ and column $c$ is denoted as $(r, c)$. Each cell can be either usable or unusable; each usable cell can only hold at most $1$ egg while unusable cells, as the name implies, cannot be used.</p>

<p>You want to put exactly $K$ eggs into usable cells of your carton such that the distance between any two closest eggs is maximized. The distance between an egg in cell $(r_1, c_1)$ and another egg in cell $(r_2, c_2)$ can be calculated using Euclidean distance, i.e. $\sqrt{(r_1-r_2)^2 + (c_1-c_2)^2}$.</p>

<p>Determine the maximum possible distance between any two closest eggs, or determine if it is impossible to put $K$ eggs into your carton.</p>

### 입력 

 <p>Input begins with two integers $N$ $K$ ($1 ≤ N ≤ 100$; $2 ≤ K ≤ 3N$) representing the number of columns of your egg carton and the number of eggs. Each of the next $3$ lines contains a string $S_r$ of length $N$ that consists of either character ‘<code>.</code>’ or ‘<code>#</code>’. The c<sup>th</sup> character of string $S_r$ represents the condition of cell $(r, c)$ of the carton. Cell $(r, c)$ is usable if $S_{r,c} =$ ‘<code>.</code>’ and unusable if $S_{r,c} =$ ‘<code>#</code>’.</p>

### 출력 

 <p>If $K$ eggs can be put into your carton, then output a real number in a single line representing the maximum possible distance between any two closest eggs. Your answer is considered correct if its absolute or relative error does not exceed $10^{-6}$.</p>

<p>If $K$ eggs cannot be put into your carton, then output <code>-1</code> in a single line.</p>

